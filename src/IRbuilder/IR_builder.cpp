#include "IR_builder.h"

#include <cstdlib>
#include <list>
#include <memory>
#include <string>

#include "AST_nodes.h"
#include "IR.h"
#include "IR_type.h"
#include "instr.h"
#include "my_any.hpp"
#include "my_exception.h"
#include "register.h"
#include "type.h"
using namespace std;
using namespace IR;

shared_ptr<Block> IRBuilder::MakeBlock(bool push_now) {
  auto ret = make_shared<Block>();
  if (push_now) now_func->blocks.push_back(ret);
  return ret;
}
shared_ptr<IRBuffer> IRBuilder::BuildIR(shared_ptr<AST::ProgNode> now) {
  shared_ptr<IRBuffer> ret = make_shared<IRBuffer>();
  result = ret.get();
  Visit(now);
  return ret;
}

shared_ptr<Struct> IRBuilder::BuildStructInfo(shared_ptr<AST::ClassDefNode> now) {
  now_class_node = now.get();
  auto struct_info = make_shared<Struct>();
  int now_idx = 0;
  string class_identifier = now->class_identifier;
  auto &class_info = (*gscope->classes)[class_identifier];
  struct_info->struct_identifier = class_identifier;
  for (auto var : (*class_info.member_vars)) {
    string var_identifier = var.first;
    IRType ir_type = var.second;
    BuildArrayStruct(var.second);
    struct_info->AddMemberVar(ir_type, var_identifier);
    // now->scope->GiveVarReg(var_identifier);
  }
  now_class_node = nullptr;
  return struct_info;
}

void IRBuilder::PushInitStmt(shared_ptr<AST::VarDefNode> now, shared_ptr<Func> func,
                             shared_ptr<Block> &now_init_block) {
  now_block = now_init_block;
  auto lst_func = now_func;
  now_func = func;
  for (auto var_def : now->var_defs) {
    if (var_def.have_expr) {
      auto expr_value = Visit(var_def.expr);
      auto reg = now->scope->GetVarReg(var_def.var_identifier);
      if (now_class_node && !reg) {
        // actually [id] refers to this.[id]
        reg = VisitMemberVarible(NowThis(), now_class_node->class_identifier, var_def.var_identifier).reg;
      }
      if (expr_value.is_null) {
        expr_value.type = reg->type.Deref();
      }
      now_block->PushInstr(StoreInstr(reg, expr_value));
    }
  }
  now_func = lst_func;
  now_init_block = now_block;
}

void IRBuilder::Visit(shared_ptr<AST::ProgNode> now) {
  gscope = now->gscope.get();
  global_init_func = make_shared<Func>();
  result->funcs.push_back(global_init_func);
  global_init_func->identifier = "_Global_Init_";
  global_init_func->ret_type = kVoidIRType;
  now_global_init_block = global_init_func->blocks.front();

  for (auto def : now->definitions) {
    if (auto class_def_node = AnyCastPtr<AST::ClassDefNode>(def)) {
      result->structs[class_def_node->class_identifier] = (BuildStructInfo(class_def_node));
    }
  }
  auto string_struct = make_shared<Struct>();
  string_struct->AddMemberVar(kCharPtrIRType, "_val");
  string_struct->AddMemberVar(kIntIRType, "_size");
  string_struct->struct_identifier = "string";
  result->structs["string"] = string_struct;
  for (auto def : now->definitions) {
    if (auto class_def_node = AnyCastPtr<AST::ClassDefNode>(def)) {
      Visit(class_def_node);
    } else if (auto var_def_node = AnyCastPtr<AST::VarDefNode>(def)) {
      Visit(var_def_node, true);

    } else if (auto func_def_node = AnyCastPtr<AST::FuncDefNode>(def)) {
      Visit(func_def_node);
    }
  }
  now_global_init_block->PushInstr(ReturnInstr());
}

void IRBuilder::Visit(shared_ptr<AST::ClassDefNode> now) {
  auto class_identifier = now->class_identifier;
  now_class_node = now.get();
  // collect member varible info
  // result->structs[class_identifier] = (BuildStructInfo(now));
  // build construct func
  auto init_func = make_shared<Func>();
  result->funcs.push_back(init_func);
  init_func->identifier = class_identifier + "_Init_";
  init_func->ret_type = kVoidIRType;
  init_func->args.push_back(IRType(ObjectType(now->class_identifier)));
  shared_ptr<Block> now_init_block = init_func->blocks.back();
  shared_ptr<AST::ConstructFuncDefNode> construct_func_node;
  // collect member func
  for (auto member_stmt : now->member_stmts) {
    if (auto member_func_def = AnyCastPtr<AST::FuncDefNode>(member_stmt)) {
      Visit(member_func_def);
    } else if (auto member_var_def = AnyCastPtr<AST::VarDefNode>(member_stmt)) {
      PushInitStmt(member_var_def, init_func, now_init_block);
    } else {
      construct_func_node = AnyCastPtr<AST::ConstructFuncDefNode>(member_stmt);
    }
  }
  if (construct_func_node) {
    now_func = init_func;
    now_block = now_init_block;
    Visit(construct_func_node->body);
    if (!now_block->closed) {
      now_init_block->PushInstr(ReturnInstr());
    }
  } else {
    now_init_block->PushInstr(ReturnInstr());
  }
  now_class_node = nullptr;
}

void IRBuilder::Visit(shared_ptr<AST::FuncDefNode> now) {
  auto func = make_shared<Func>();
  result->funcs.push_back(func);
  now_func = func;
  now_block = func->blocks.back();
  func->ret_type = now->type;
  string func_identifier = now->func_identifier;
  if (now_class_node) {
    func_identifier = now_class_node->class_identifier + "." + func_identifier;
    func->args.push_back(FuncArg(ObjectType(now_class_node->class_identifier)));
    NowThis() = func->args.front().reg;
  }
  func->identifier = func_identifier;
  Visit(now->args_def);
  if (now->func_identifier == "main" && !now_class_node) {
    now_block->PushInstr(RegisterAssignInstr(nullptr, FuncCallExpr({}, "_Global_Init_", kVoidIRType)));
  }
  Visit(now->body);
  if (!now_block->closed) {
    if (func->ret_type == kVoidIRType)
      now_block->PushInstr(ReturnInstr());
    else
      now_block->PushInstr(ReturnInstr(Value(0, func->ret_type)));
  }
  now_func = nullptr;
  now_block = nullptr;
}

void IRBuilder::Visit(shared_ptr<AST::VarDefNode> now, bool is_global) {
  BuildArrayStruct(now->type);
  if (is_global) {
    auto type = now->type;
    IRType ir_type = type;
    for (auto var_def : now->var_defs) {
      auto var_identifier = var_def.var_identifier;
      // collect varible info
      result->global_vars.push_back({var_identifier, ir_type});
      // give reg to AST
      now->scope->GiveVarReg(var_identifier, make_shared<GlobalRegister>(var_identifier, type, true));
    }
    // push into init func
    PushInitStmt(now, global_init_func, now_global_init_block);
    return;
  }
  for (auto var_def : now->var_defs) {
    auto var_identifier = var_def.var_identifier;
    now->scope->GiveVarReg(var_identifier);  // TODO : now class member var cant
                                             // be init outsides class init func
    now_block->PushInstr(
        RegisterAssignInstr(now->scope->GetVarReg(var_identifier), AllocaExpr(IRType(now->type, false))));
  }
  PushInitStmt(now, now_func, now_block);
}

void IRBuilder::Visit(shared_ptr<AST::ArgListDefNode> now) {
  for (auto arg_def : now->args) {
    BuildArrayStruct(arg_def.type);
    auto var_identifier = arg_def.arg_identifier;
    auto now_func_arg = FuncArg(arg_def.type);
    now_func->args.push_back(now_func_arg);
    // if (arg_def.type == kIntType || arg_def.type == kBoolType) {
    //   auto arg_var_ptr = make_shared<Register>();
    //   now->scope->GiveVarReg(var_identifier, arg_var_ptr);
    //   now_block->PushInstr(StoreInstr(arg_var_ptr, Value(now_func_arg.type,
    //   now_func_arg.reg)));
    // } else {
    //   now->scope->GiveVarReg(var_identifier, now_func_arg.reg);
    // }
    auto arg_var_ptr = make_shared<Register>(arg_def.type, true);
    now->scope->GiveVarReg(var_identifier, arg_var_ptr);
    now_block->PushInstr(RegisterAssignInstr(arg_var_ptr, AllocaExpr(arg_def.type)));
    now_block->PushInstr(StoreInstr(arg_var_ptr, Value(now_func_arg.reg)));
  }
}
void IRBuilder::Visit(shared_ptr<AST::StmtBlockNode> now) {
  for (auto stmt : now->stmts) {
    if (auto var_def_stmt = AnyCastPtr<AST::VarDefNode>(stmt)) {
      Visit(var_def_stmt);
    } else if (auto if_stmt = AnyCastPtr<AST::IfStmtNode>(stmt)) {
      Visit(if_stmt);
    } else if (auto while_stmt = AnyCastPtr<AST::WhileStmtNode>(stmt)) {
      Visit(while_stmt);
    } else if (auto for_stmt = AnyCastPtr<AST::ForStmtNode>(stmt)) {
      Visit(for_stmt);
    } else if (auto ret_stmt = AnyCastPtr<AST::ReturnStmtNode>(stmt)) {
      Visit(ret_stmt);
    } else if (auto stmt_block = AnyCastPtr<AST::StmtBlockNode>(stmt)) {
      Visit(stmt_block);
    } else if (auto expr_stmt = AnyCastPtr<AST::ExprStmtNode>(stmt)) {
      Visit(expr_stmt->expr);
    } else if (auto continue_stmt = AnyCastPtr<AST::ContinueStmtNode>(stmt)) {
      Visit(continue_stmt);
    } else if (auto break_stmt = AnyCastPtr<AST::BreakStmtNode>(stmt)) {
      Visit(break_stmt);
    }
    if (now_block->closed) return;
  }
}

void IRBuilder::Visit(shared_ptr<AST::IfStmtNode> now) {
  auto condition = Visit(now->condition_expr);
  auto then_block = MakeBlock();
  then_block->comment = "if_then";
  auto next_block = MakeBlock(false);
  next_block->comment = "if_next";
  bool br_to_next = false;
  if (now->have_else) {
    auto else_block = MakeBlock();
    now_block->PushInstr(ConditionBrInstr(condition, then_block, else_block));
    now_block = then_block;
    Visit(now->block);
    if (!now_block->closed) {
      now_block->PushInstr(BrInstr(next_block));
      br_to_next = true;
    }
    now_block = else_block;
    Visit(now->else_block);
    if (!now_block->closed) {
      now_block->PushInstr(BrInstr(next_block));
      br_to_next = true;
    }
    if (!br_to_next) return;
    now_block = next_block;
  } else {
    now_block->PushInstr(ConditionBrInstr(condition, then_block, next_block));
    now_block = then_block;
    Visit(now->block);
    if (!now_block->closed) now_block->PushInstr(BrInstr(next_block));
  }
  now_func->blocks.push_back(next_block);
  now_block = next_block;
}

void IRBuilder::Visit(shared_ptr<AST::WhileStmtNode> now) {
  auto condition_block = MakeBlock();
  condition_block->comment = "while_condition";
  auto body_block = MakeBlock();
  body_block->comment = "while_body";
  auto next_block = MakeBlock();
  next_block->comment = "while_next";
  break_target.push(next_block);
  continue_target.push(condition_block);
  now_block->PushInstr(BrInstr(condition_block));
  now_block = condition_block;
  auto condition = Visit(now->condition_expr);
  now_block->PushInstr(ConditionBrInstr(condition, body_block, next_block));
  now_block = body_block;
  Visit(now->block);
  if (!now_block->closed) now_block->PushInstr(BrInstr(condition_block));
  now_block = next_block;
  break_target.pop();
  continue_target.pop();
}
void IRBuilder::Visit(shared_ptr<AST::ForStmtNode> now) {
  auto body_block = MakeBlock();
  body_block->comment = "for_body";
  auto next_block = MakeBlock(false);
  next_block->comment = "for_next";
  if (now->have_init_expr) {
    Visit(now->init_expr);
  }
  break_target.push(next_block);
  if (now->have_condition_expr) {
    auto condition_block = MakeBlock();
    condition_block->comment = "for_condition";
    shared_ptr<Block> step_block;
    if (now->have_step_expr) {
      step_block = MakeBlock();
      step_block->comment = "for_step";
      continue_target.push(step_block);
    } else {
      continue_target.push(condition_block);
    }
    now_block->PushInstr(BrInstr(condition_block));
    now_block = condition_block;
    auto condition = Visit(now->condition_expr);
    now_block->PushInstr(ConditionBrInstr(condition, body_block, next_block));
    now_block = body_block;
    Visit(now->block);
    if (!now_block->closed) now_block->PushInstr(BrInstr(continue_target.top()));
    if (now->have_step_expr) {
      now_block = step_block;
      Visit(now->step_expr);
      now_block->PushInstr(BrInstr(condition_block));
    }
  } else {
    shared_ptr<Block> step_block;
    if (now->have_step_expr) {
      step_block = MakeBlock();
      step_block->comment = "for_step";
      continue_target.push(step_block);
    } else {
      continue_target.push(body_block);
    }
    now_block->PushInstr(BrInstr(body_block));
    now_block = body_block;
    Visit(now->block);
    if (!now_block->closed) now_block->PushInstr(BrInstr(continue_target.top()));
    if (now->have_step_expr) {
      now_block = step_block;
      Visit(now->step_expr);
      now_block->PushInstr(BrInstr(body_block));
    }
  }
  break_target.pop();
  continue_target.pop();
  now_func->blocks.push_back(next_block);
  now_block = next_block;
}

void IRBuilder::Visit(shared_ptr<AST::ReturnStmtNode> now) {
  if (!now->have_ret_expr) {
    now_block->PushInstr(ReturnInstr());
    return;
  }
  auto ret = Visit(now->ret_expr);
  if (ret.is_null) {
    ret.type = now_func->ret_type;
  }
  now_block->PushInstr(ReturnInstr(ret));
}

void IRBuilder::Visit(shared_ptr<AST::ContinueStmtNode> now) { now_block->PushInstr(BrInstr(continue_target.top())); }

void IRBuilder::Visit(shared_ptr<AST::BreakStmtNode> now) { now_block->PushInstr(BrInstr(break_target.top())); }

Value IRBuilder::GetRightValue(Value val) {
  if (!val.is_left) return val;
  auto now_right_val = make_shared<Register>(val.type.Deref());
  now_block->PushInstr(RegisterAssignInstr(now_right_val, LoadExpr(val.reg)));
  return Value(now_right_val, false);
}

void IRBuilder::BuildArrayStruct(ObjectType type) {
  auto identifier = IRType(type).identifier;
  if (!type.dim || result->structs.count(identifier)) {
    return;
  }
  --type.dim;
  BuildArrayStruct(type);
  auto struct_info = make_shared<Struct>();
  result->structs[identifier] = struct_info;
  struct_info->struct_identifier = identifier;
  struct_info->AddMemberVar(IRType(type, true), "_val");
  struct_info->AddMemberVar(kIntIRType, "_size");
  return;
}

Value IRBuilder::Visit(shared_ptr<AST::ExpressionNode> now) {
  // return Value(make_shared<Register>(kIntIRType));
  return GetRightValue(Visit(now->assign_expr));
}

Value IRBuilder::Visit(shared_ptr<AST::AssignExprNode> now) {
  // return Value(now->value_type.object_type, make_shared<Register>());
  if (!now->have_left_expr) return Visit(now->lor_expr);
  Value left = Visit(now->left_expr);
  Value val = GetRightValue(Visit(now->lor_expr));
  MyAssert(left.is_left, MyException("Assigning to a right value in ir"));
  if (val.is_null) {
    val.type = left.type.Deref();
  }
  now_block->PushInstr(StoreInstr(left, val));
  return val;
}

Value IRBuilder::NowThis() { return Value(now_func->args.front().reg, false); }
Value IRBuilder::Visit(shared_ptr<AST::LorExprNode> now) {
  if (now->land_exprs.size() == 1) {
    return Visit(now->land_exprs.front());
  }
  auto final_block = MakeBlock(false);
  Value ret = make_shared<Register>(kBoolIRType);
  PhiExpr expr = kBoolIRType;
  int cnt = 1;
  for (auto now_land_expr : now->land_exprs) {
    auto now_val = GetRightValue(Visit(now_land_expr));
    if (cnt != now->land_exprs.size()) {
      auto nxt_block = MakeBlock();
      now_block->PushInstr(ConditionBrInstr(now_val, final_block, nxt_block));
      expr.PushCase({now_block, Value(true)});
      now_block = nxt_block;
    } else {
      now_block->PushInstr(BrInstr(final_block));
      expr.PushCase({now_block, now_val});
      now_block = final_block;
    }
    ++cnt;
  }
  now_block->PushInstr(RegisterAssignInstr(ret.reg, expr));
  now_func->blocks.push_back(final_block);
  return ret;
}
Value IRBuilder::Visit(shared_ptr<AST::LandExprNode> now) {
  if (now->or_exprs.size() == 1) {
    return Visit(now->or_exprs.front());
  }
  auto final_block = MakeBlock(false);
  Value ret = make_shared<Register>(kBoolIRType);
  PhiExpr expr = kBoolIRType;
  int cnt = 1;
  for (auto now_or_expr : now->or_exprs) {
    auto now_val = GetRightValue(Visit(now_or_expr));
    if (cnt != now->or_exprs.size()) {
      auto nxt_block = MakeBlock();
      now_block->PushInstr(ConditionBrInstr(now_val, nxt_block, final_block));
      expr.PushCase({now_block, Value(false)});
      now_block = nxt_block;
    } else {
      now_block->PushInstr(BrInstr(final_block));
      expr.PushCase({now_block, now_val});
      now_block = final_block;
    }
    ++cnt;
  }
  now_block->PushInstr(RegisterAssignInstr(ret.reg, expr));
  now_func->blocks.push_back(final_block);
  return ret;
}
Value IRBuilder::Visit(shared_ptr<AST::OrExprNode> now) {
  if (now->xor_exprs.size() == 1) {
    return Visit(now->xor_exprs.front());
  }
  auto ret = GetRightValue(Visit(now->xor_exprs.front()));
  bool first_flag = true;
  for (auto now_xor_expr : now->xor_exprs) {
    if (first_flag) {
      first_flag = false;
      continue;
    }
    auto now_val = GetRightValue(Visit(now_xor_expr));
    auto new_reg = Value(kIntIRType);
    now_block->PushInstr(RegisterAssignInstr(new_reg.reg, BinaryExpr(ret, now_val, BinaryExpr::kOr, kIntIRType)));
    ret = new_reg;
  }
  return ret;
}
Value IRBuilder::Visit(shared_ptr<AST::XorExprNode> now) {
  if (now->and_exprs.size() == 1) {
    return Visit(now->and_exprs.front());
  }
  auto ret = GetRightValue(Visit(now->and_exprs.front()));
  bool first_flag = true;
  for (auto now_and_expr : now->and_exprs) {
    if (first_flag) {
      first_flag = false;
      continue;
    }
    auto now_val = GetRightValue(Visit(now_and_expr));
    auto new_reg = Value(kIntIRType);
    now_block->PushInstr(RegisterAssignInstr(new_reg.reg, BinaryExpr(ret, now_val, BinaryExpr::kXor, kIntIRType)));
    ret = new_reg;
  }
  return ret;
}
Value IRBuilder::Visit(shared_ptr<AST::AndExprNode> now) {
  if (now->equal_exprs.size() == 1) {
    return Visit(now->equal_exprs.front());
  }
  auto ret = GetRightValue(Visit(now->equal_exprs.front()));
  bool first_flag = true;
  for (auto now_equal_expr : now->equal_exprs) {
    if (first_flag) {
      first_flag = false;
      continue;
    }
    auto now_val = GetRightValue(Visit(now_equal_expr));
    auto new_reg = Value(kIntIRType);
    now_block->PushInstr(RegisterAssignInstr(new_reg.reg, BinaryExpr(ret, now_val, BinaryExpr::kAnd, kIntIRType)));
    ret = new_reg;
  }
  return ret;
}

Value IRBuilder::Visit(shared_ptr<AST::EqualityExprNode> now) {
  if (now->relation_exprs.size() == 1) {
    return Visit(now->relation_exprs.front());
  }
  auto ret = GetRightValue(Visit(now->relation_exprs.front()));
  bool first_flag = true;
  auto now_op_iter = now->equal_ops.begin();
  for (auto now_relation_expr : now->relation_exprs) {
    if (first_flag) {
      first_flag = false;
      continue;
    }
    auto now_val = GetRightValue(Visit(now_relation_expr));
    auto new_reg = Value(kBoolIRType);
    BinaryExpr::BinarayOp op;
    switch (*now_op_iter) {
      case AST::EqualityExprNode::kEqual:
        op = IR::BinaryExpr::kEqual;
        break;
      case AST::EqualityExprNode::kNotEqual:
        op = IR::BinaryExpr::kNotequal;
        break;
    }
    if (ret.type == kStringIRType) {
      list<Value> arg_list = {ret, now_val};
      string func_identifier;
      switch (op) {
        case IR::BinaryExpr::kEqual:
          func_identifier = "_string.eq";
          break;
        case IR::BinaryExpr::kNotequal:
          func_identifier = "_string.neq";
          break;
      }
      now_block->PushInstr(RegisterAssignInstr(new_reg.reg, FuncCallExpr(arg_list, func_identifier, kBoolIRType)));
    } else
      now_block->PushInstr(RegisterAssignInstr(new_reg.reg, BinaryExpr(ret, now_val, op, kBoolIRType)));
    ret = new_reg;
    ++now_op_iter;
  }
  return ret;
}
Value IRBuilder::Visit(shared_ptr<AST::RelationExprNode> now) {
  if (now->shift_exprs.size() == 1) {
    return Visit(now->shift_exprs.front());
  }
  auto ret = GetRightValue(Visit(now->shift_exprs.front()));
  bool first_flag = true;
  auto now_op_iter = now->relations_ops.begin();
  for (auto now_expr : now->shift_exprs) {
    if (first_flag) {
      first_flag = false;
      continue;
    }
    auto now_val = GetRightValue(Visit(now_expr));
    auto new_reg = Value(kBoolIRType);
    BinaryExpr::BinarayOp op;
    switch (*now_op_iter) {
      case AST::RelationExprNode::kLess:
        op = IR::BinaryExpr::kLess;
        break;
      case AST::RelationExprNode::kLessEqual:
        op = IR::BinaryExpr::kLessEqual;
        break;
      case AST::RelationExprNode::kGreater:
        op = IR::BinaryExpr::kGreater;
        break;
      case AST::RelationExprNode::kGreaterEqual:
        op = IR::BinaryExpr::kGreaterEqual;
        break;
    }
    if (ret.type == kStringIRType) {
      list<Value> arg_list;
      string func_identifier;
      switch (op) {
        case IR::BinaryExpr::kLess:
          func_identifier = "_string.lt";
          arg_list.push_back(ret);
          arg_list.push_back(now_val);
          break;
        case IR::BinaryExpr::kLessEqual:
          func_identifier = "_string.le";
          arg_list.push_back(ret);
          arg_list.push_back(now_val);
          break;
        case IR::BinaryExpr::kGreater:
          func_identifier = "_string.lt";
          arg_list.push_back(now_val);
          arg_list.push_back(ret);
          break;
        case IR::BinaryExpr::kGreaterEqual:
          func_identifier = "_string.le";
          arg_list.push_back(now_val);
          arg_list.push_back(ret);
          break;
      }
      now_block->PushInstr(RegisterAssignInstr(new_reg.reg, FuncCallExpr(arg_list, func_identifier, kBoolIRType)));
    } else
      now_block->PushInstr(RegisterAssignInstr(new_reg.reg, BinaryExpr(ret, now_val, op, kBoolIRType)));
    ret = new_reg;
    ++now_op_iter;
  }
  return ret;
}
Value IRBuilder::Visit(shared_ptr<AST::ShiftExprNode> now) {
  if (now->add_exprs.size() == 1) {
    return Visit(now->add_exprs.front());
  }
  auto ret = GetRightValue(Visit(now->add_exprs.front()));
  bool first_flag = true;
  auto now_op_iter = now->shift_ops.begin();
  for (auto now_expr : now->add_exprs) {
    if (first_flag) {
      first_flag = false;
      continue;
    }
    auto now_val = GetRightValue(Visit(now_expr));
    auto new_reg = Value(kIntIRType);
    BinaryExpr::BinarayOp op;
    switch (*now_op_iter) {
      case AST::ShiftExprNode::kLeftShift:
        op = IR::BinaryExpr::kLeftShift;
        break;
      case AST::ShiftExprNode::kRightShift:
        op = IR::BinaryExpr::kRightShift;
        break;
    }
    now_block->PushInstr(RegisterAssignInstr(new_reg.reg, BinaryExpr(ret, now_val, op, kIntIRType)));
    ret = new_reg;
    ++now_op_iter;
  }
  return ret;
}
Value IRBuilder::Visit(shared_ptr<AST::AddExprNode> now) {
  if (now->multi_exprs.size() == 1) {
    return Visit(now->multi_exprs.front());
  }
  auto ret = GetRightValue(Visit(now->multi_exprs.front()));
  bool first_flag = true;
  auto now_op_iter = now->add_ops.begin();
  for (auto now_expr : now->multi_exprs) {
    if (first_flag) {
      first_flag = false;
      continue;
    }
    auto now_val = GetRightValue(Visit(now_expr));
    auto new_reg = Value(kIntIRType);
    BinaryExpr::BinarayOp op;
    switch (*now_op_iter) {
      case AST::AddExprNode::kPlus:
        op = IR::BinaryExpr::kPlus;
        break;
      case AST::AddExprNode::kMinus:
        op = IR::BinaryExpr::kMinus;
        break;
    }
    if (ret.type == kStringIRType) {
      new_reg = Value(kStringIRType);
      now_block->PushInstr(
          RegisterAssignInstr(new_reg.reg, FuncCallExpr({ret, now_val}, "_string_add", kStringIRType)));
    } else
      now_block->PushInstr(RegisterAssignInstr(new_reg.reg, BinaryExpr(ret, now_val, op, kIntIRType)));
    ret = new_reg;
    ++now_op_iter;
  }
  return ret;
}
Value IRBuilder::Visit(shared_ptr<AST::MultiExprNode> now) {
  if (now->unary_exprs.size() == 1) {
    return Visit(now->unary_exprs.front());
  }
  auto ret = GetRightValue(Visit(now->unary_exprs.front()));
  bool first_flag = true;
  auto now_op_iter = now->multi_ops.begin();
  for (auto now_expr : now->unary_exprs) {
    if (first_flag) {
      first_flag = false;
      continue;
    }
    auto now_val = GetRightValue(Visit(now_expr));
    auto new_reg = Value(kIntIRType);
    BinaryExpr::BinarayOp op;
    switch (*now_op_iter) {
      case AST::MultiExprNode::kStar:
        op = IR::BinaryExpr::kStar;
        break;
      case AST::MultiExprNode::kDiv:
        op = IR::BinaryExpr::kDiv;
        break;
      case AST::MultiExprNode::kMod:
        op = IR::BinaryExpr::kMod;
        break;
    }
    now_block->PushInstr(RegisterAssignInstr(new_reg.reg, BinaryExpr(ret, now_val, op, kIntIRType)));
    ret = new_reg;
    ++now_op_iter;
  }
  return ret;
}
Value IRBuilder::Visit(shared_ptr<AST::UnaryExprNode> now) {
  Value ret(0);
  if (auto expr = AnyCastPtr<AST::PostfixExprNode>(now->expr)) {
    ret = Visit(expr);
  } else if (auto expr = AnyCastPtr<AST::NewExprNode>(now->expr)) {
    ret = Visit(expr);
  }
  for (auto op : now->prefix_unary_ops) {
    Value val = GetRightValue(ret);
    switch (op) {
      case AST::UnaryExprNode::kPlusPlus: {
        MyAssert(ret.is_left, MyException("++ to a r-value in ir"));
        Value result(kIntIRType);
        now_block->PushInstr(RegisterAssignInstr(result.reg, BinaryExpr(val, 1, IR::BinaryExpr::kPlus, kIntIRType)));
        now_block->PushInstr(StoreInstr(ret, result));
        break;
      }
      case AST::UnaryExprNode::kMinusMinus: {
        MyAssert(ret.is_left, MyException("-- to a r-value in ir"));
        Value result(kIntIRType);
        now_block->PushInstr(RegisterAssignInstr(result.reg, BinaryExpr(val, 1, IR::BinaryExpr::kMinus, kIntIRType)));
        now_block->PushInstr(StoreInstr(ret, result));
        break;
      }
      case AST::UnaryExprNode::kNot: {
        Value result(kBoolIRType);
        now_block->PushInstr(
            RegisterAssignInstr(result.reg, BinaryExpr(val, Value(1, kBoolIRType), IR::BinaryExpr::kXor, kBoolIRType)));
        ret = result;
        break;
      }
      case AST::UnaryExprNode::kTilde: {
        Value result(kIntIRType);
        now_block->PushInstr(RegisterAssignInstr(result.reg, BinaryExpr(val, -1, IR::BinaryExpr::kXor, kIntIRType)));
        ret = result;
        break;
      }
      case AST::UnaryExprNode::kMinus: {
        Value result(kIntIRType);
        now_block->PushInstr(RegisterAssignInstr(result.reg, BinaryExpr(0, val, IR::BinaryExpr::kMinus, kIntIRType)));
        ret = result;
        break;
      }
    }
  }
  return ret;
}
Value IRBuilder::Visit(shared_ptr<AST::PostfixExprNode> now) {
  Value ret = Visit(now->primary_expr);
  for (auto op_iter = now->suffix_ops.begin(); op_iter != now->suffix_ops.end(); ++op_iter) {
    auto op = *op_iter;
    if (AnyIs<AST::PostfixExprNode::SuffixUnaryOp>(op)) {
      switch (AnyCast<AST::PostfixExprNode::SuffixUnaryOp>(op)) {
        case AST::PostfixExprNode::kPlusPlus: {
          MyAssert(ret.is_left, MyException("++ to a r-value in ir"));
          Value val = GetRightValue(ret);
          Value result(kIntIRType);
          now_block->PushInstr(RegisterAssignInstr(result.reg, BinaryExpr(val, 1, IR::BinaryExpr::kPlus, kIntIRType)));
          now_block->PushInstr(StoreInstr(ret, result));
          ret = val;
          break;
        }
        case AST::PostfixExprNode::kMinusMinus: {
          MyAssert(ret.is_left, MyException("-- to a r-value in ir"));
          Value val = GetRightValue(ret);
          Value result(kIntIRType);
          now_block->PushInstr(RegisterAssignInstr(result.reg, BinaryExpr(val, 1, IR::BinaryExpr::kMinus, kIntIRType)));
          now_block->PushInstr(StoreInstr(ret, result));
          ret = val;
          break;
        }
      }
    } else if (auto arg_list_node = AnyCastPtr<AST::ArgListNode>(op)) {
      auto arg_lists = Visit(arg_list_node);
      if (ret.func.is_member) arg_lists.push_front(ret);
      // if (ret.func.ret_type == kVoidIRType) {
      //   now_block->PushInstr(
      //       RegisterAssignInstr(nullptr, FuncCallExpr(arg_lists, ret.func.identifier, ret.func.ret_type)));
      //   ret = 0;
      //   continue;
      // }
      auto result = make_shared<Register>(ret.func.ret_type);
      now_block->PushInstr(RegisterAssignInstr((ret.func.ret_type == kVoidIRType) ? nullptr : result,
                                               FuncCallExpr(arg_lists, ret.func.identifier, ret.func.ret_type)));
      ret = result;
    } else if (AnyIs<Member>(op)) {
      ret = GetRightValue(ret);
      if (ret.type.identifier.find("_array") != string::npos) {
        ++op_iter;
        auto ret_size_ptr = VisitMemberVarible(ret, ret.type.identifier, "_size");
        ret = GetRightValue(ret_size_ptr);
        continue;
      }
      auto member_identifier = AnyCast<Member>(op).member_identifier;
      auto class_identifier = ret.type.identifier;
      auto member_type = now->scope->GetClassMember(class_identifier, member_identifier);
      auto nxt_iter = op_iter;
      ++nxt_iter;
      if (nxt_iter != now->suffix_ops.end() && AnyCastPtr<AST::ArgListNode>(*nxt_iter)) {
        ret.func.identifier = class_identifier + "." + member_identifier;
        ret.func.is_member = true;
        ret.func.ret_type = IRType(member_type.func_type.ret_type, false);
      } else {
        ret = VisitMemberVarible(ret, class_identifier, member_identifier);
      }
    } else if (auto array_idx = AnyCastPtr<AST::ArrayIndexNode>(op)) {
      auto idx = Visit(array_idx->idx_expr);
      ret = GetRightValue(ret);
      Value ret_val = GetRightValue(VisitMemberVarible(ret, ret.type.identifier, "_val"));
      ret = ret_val.type;
      ret.is_left = true;
      now_block->PushInstr(RegisterAssignInstr(ret.reg, GetElementPtrExpr(ret_val, idx, 0, false)));
    }
  }
  return ret;
}
Value IRBuilder::Visit(shared_ptr<AST::PrimaryExprNode> now) {
  if (auto literal_node = AnyCastPtr<AST::LiteralNode>(now->expr)) {
    return Visit(literal_node);
  }
  if (auto expr_node = AnyCastPtr<AST::ExpressionNode>(now->expr)) {
    return Visit(expr_node);
  }
  if (AnyIs<This>(now->expr)) {
    return NowThis();
  }
  if (AnyIs<string>(now->expr)) {
    Value ret = 0;
    auto identifier = AnyCast<string>(now->expr);
    if (now->is_func) {
      if (now_class_node && now->scope->GetClassMember(now_class_node->class_identifier, identifier).have_func_type) {
        ret = NowThis();
        ret.func.identifier = now_class_node->class_identifier + "." + identifier;
        ret.func.is_member = true;
        ret.func.ret_type = IRType(now->value_type.func_type.ret_type, false);
      } else {
        ret.func.identifier = identifier;
        ret.func.is_member = false;
        ret.func.ret_type = IRType(now->value_type.func_type.ret_type, false);
      }
    } else {
      if (now_class_node && !now->value_type.var_info->reg) {
        // actually [id] refers to this.[id]
        ret = VisitMemberVarible(NowThis(), now_class_node->class_identifier, identifier);
      } else
        ret = Value(now->value_type.var_info->reg, true);
    }
    return ret;
  }
  return 0;
}
Value IRBuilder::InitArray(ObjectType type, list<Value>::const_iterator cend_iter, list<Value>::const_iterator iter) {
  Value ret = IRType(type);
  --type.dim;
  auto now_len = *iter;
  ++iter;
  // now_block->PushInstr(RegisterAssignInstr(ret.reg, AllocaExpr(ret.type.Deref())));
  Value tmp_malloc = kCharPtrIRType;
  now_block->PushInstr(RegisterAssignInstr(tmp_malloc.reg, FuncCallExpr({1}, "__Malloc_ptr", kCharPtrIRType)));
  now_block->PushInstr(RegisterAssignInstr(ret.reg, BitcastExpr(tmp_malloc, ret.type)));
  auto ret_val_ptr = VisitMemberVarible(ret, ret.type.identifier, "_val");
  Value malloc_ret_val = kCharPtrIRType;
  string func_identifier;
  if (type.dim)
    func_identifier = "__Malloc_array";
  else {
    if (type.type_identifier == "int") {
      func_identifier = "__Malloc_int";
    } else if (type.type_identifier == "bool") {
      func_identifier = "__Malloc_bool";
    } else
      func_identifier = "__Malloc_ptr";
  }
  now_block->PushInstr(
      RegisterAssignInstr(malloc_ret_val.reg, FuncCallExpr({now_len}, func_identifier, kCharPtrIRType)));
  auto ret_val = Value(ret_val_ptr.type.Deref());
  now_block->PushInstr(RegisterAssignInstr(ret_val.reg, BitcastExpr(malloc_ret_val, ret_val.type)));
  now_block->PushInstr(StoreInstr(ret_val_ptr, ret_val));
  auto ret_size_ptr = VisitMemberVarible(ret, ret.type.identifier, "_size");
  now_block->PushInstr(StoreInstr(ret_size_ptr, now_len));

  if (iter == cend_iter) return ret;
  // build the for part which is like this:
  // int idx = 0;
  // for (;idx < now_len;++idx){
  //   ret.val[idx] = new_obj;
  // }
  Value idx(kIntIRType.Ref());
  idx.is_left = true;
  now_block->PushInstr(RegisterAssignInstr(idx.reg, AllocaExpr(kIntIRType)));
  now_block->PushInstr(StoreInstr(idx, 0));
  auto condition_block = MakeBlock();
  condition_block->comment = "initarray_condition";
  auto step_block = MakeBlock();
  step_block->comment = "initarray_step";
  auto body_block = MakeBlock();
  body_block->comment = "initarray_body";
  auto next_block = MakeBlock(false);
  next_block->comment = "initarray_next";
  now_block->PushInstr(BrInstr(condition_block));
  {
    // condition block
    Value idx_val = kIntIRType;
    condition_block->PushInstr(RegisterAssignInstr(idx_val.reg, LoadExpr(idx.reg)));
    Value condition_result = kBoolIRType;
    condition_block->PushInstr(
        RegisterAssignInstr(condition_result.reg, BinaryExpr(idx_val, now_len, BinaryExpr::kLess, kIntIRType)));
    condition_block->PushInstr(ConditionBrInstr(condition_result, body_block, next_block));
  }
  {  // step block
    Value idx_val = kIntIRType;
    step_block->PushInstr(RegisterAssignInstr(idx_val.reg, LoadExpr(idx.reg)));
    Value new_idx_val = kIntIRType;
    step_block->PushInstr(RegisterAssignInstr(new_idx_val.reg, BinaryExpr(idx_val, 1, BinaryExpr::kPlus, kIntIRType)));
    step_block->PushInstr(StoreInstr(idx, new_idx_val));
    step_block->PushInstr(BrInstr(condition_block));
  }
  {  // body block
    Value idx_val = kIntIRType;
    body_block->PushInstr(RegisterAssignInstr(idx_val.reg, LoadExpr(idx.reg)));
    Value now_obj_ptr = ret_val.type;
    body_block->PushInstr(RegisterAssignInstr(now_obj_ptr.reg, GetElementPtrExpr(ret_val, idx_val, 0, false)));
    // Value now_obj = ret_val.type.Deref();
    // body_block->PushInstr(RegisterAssignInstr(now_obj.reg, AllocaExpr(now_obj.type.Deref())));
    // body_block->PushInstr(StoreInstr(now_obj_ptr, now_obj));
    now_block = body_block;
    Value now_obj_val = InitArray(type, cend_iter, iter);
    now_block->PushInstr(StoreInstr(now_obj_ptr, now_obj_val));
    now_block->PushInstr(BrInstr(step_block));
  }
  now_block = next_block;
  now_func->blocks.push_back(next_block);
  return ret;
}

Value IRBuilder::Visit(shared_ptr<AST::NewExprNode> now) {
  if (!now->is_array) {
    // new an object
    Value ret = IRType(now->type);
    int obj_size = result->structs[now->type.type_identifier]->size;
    Value tmp_malloc = kCharPtrIRType;
    now_block->PushInstr(
        RegisterAssignInstr(tmp_malloc.reg, FuncCallExpr({obj_size}, "__Malloc_bool", kCharPtrIRType)));
    // now_block->PushInstr(RegisterAssignInstr(ret, AllocaExpr(ret->type.Deref())));
    now_block->PushInstr(RegisterAssignInstr(ret.reg, BitcastExpr(tmp_malloc, ret.type)));
    now_block->PushInstr(
        RegisterAssignInstr(nullptr, FuncCallExpr({ret}, now->type.type_identifier + "_Init_", kVoidIRType)));
    return ret;
  }
  BuildArrayStruct(now->type);
  list<Value> idxs;
  for (auto idx : now->array_idxs) {
    idxs.push_back(Visit(idx->idx_expr));
  }
  return InitArray(now->type, idxs.cend(), idxs.cbegin());
}

Value IRBuilder::Visit(shared_ptr<AST::LiteralNode> now) {
  if (now->type == kIntType) {
    return Value(AnyCast<int>(now->value));
  }
  if (now->type == kBoolType) {
    return Value(AnyCast<bool>(now->value));
  }
  if (now->type == kNullType) {
    Value ret(0);
    ret.is_null = true;
    return ret;
  }
  if (now->type == kStringType) {
    auto val = AnyCast<string>(now->value);
    if (!result->string_literals.count(val)) {
      int now_idx = result->string_literals.size();
      string new_reg_label = "str.literal_" + to_string(now_idx);
      IRType type = kCharPtrIRType;
      type.size = val.length() + 1;
      result->string_literals[val] = make_shared<GlobalRegister>(new_reg_label, type);
    }
    auto literal_reg = result->string_literals[val];
    Value ret = kStringIRType;
    Value tmp_malloc = kCharPtrIRType;
    now_block->PushInstr(RegisterAssignInstr(tmp_malloc.reg, FuncCallExpr({16}, "__Malloc_bool", kCharPtrIRType)));
    now_block->PushInstr(RegisterAssignInstr(ret.reg, BitcastExpr(tmp_malloc, ret.type)));
    // now_block->PushInstr(RegisterAssignInstr(ret, AllocaExpr(kStringIRType.Deref())));
    auto val_ptr = VisitMemberVarible(ret, "string", "_val");
    auto literal_ptr = make_shared<Register>(kCharPtrIRType);
    now_block->PushInstr(RegisterAssignInstr(literal_ptr, BitcastExpr(literal_reg, kCharPtrIRType)));
    now_block->PushInstr(StoreInstr(val_ptr, literal_ptr));
    auto size_ptr = VisitMemberVarible(ret, "string", "_size");
    now_block->PushInstr(StoreInstr(size_ptr, int(val.length())));
    return ret;
  }
  return 0;
}

list<Value> IRBuilder::Visit(shared_ptr<AST::ArgListNode> now) {
  list<Value> ret;
  for (auto arg_expr : now->args) {
    ret.push_back(Visit(arg_expr));
  }
  return ret;
}

Value IRBuilder::VisitMemberVarible(Value obj_ptr, const string &class_identifier, const string &member_identifier) {
  int member_idx = result->structs[class_identifier]->member_idx[member_identifier];
  auto member_type = result->structs[class_identifier]->member_types[member_idx];
  auto result_type = member_type.Ref();
  auto nxt_reg = make_shared<Register>(result_type);
  now_block->PushInstr(RegisterAssignInstr(nxt_reg, GetElementPtrExpr(obj_ptr, 0, member_idx)));
  return Value(nxt_reg, true);
}