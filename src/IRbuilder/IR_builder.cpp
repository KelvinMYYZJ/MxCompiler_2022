#include "IR_builder.h"

#include <cstdlib>
#include <memory>

#include "AST_nodes.h"
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
  if (push_now)
    now_func->blocks.push_back(ret);
  return ret;
}
shared_ptr<IRBuffer> IRBuilder::BuildIR(shared_ptr<AST::ProgNode> now) {
  shared_ptr<IRBuffer> ret = make_shared<IRBuffer>();
  result = ret.get();
  Visit(now);
  return ret;
}

shared_ptr<Struct>
IRBuilder::BuildStructInfo(shared_ptr<AST::ClassDefNode> now) {
  auto struct_info = make_shared<Struct>();
  int now_idx = 0;
  string class_identifier = now->class_identifier;
  auto &class_info = (*gscope->classes)[class_identifier];
  struct_info->struct_identifier = class_identifier;
  for (auto var : (*class_info.member_vars)) {
    string var_identifier = var.first;
    IRType ir_type = var.second;
    struct_info->AddMemberVar(ir_type, var_identifier);
    now->scope->GiveVarReg(var_identifier);
  }
  return struct_info;
}

void IRBuilder::PushInitStmt(shared_ptr<AST::VarDefNode> now,
                             shared_ptr<Func> func,
                             shared_ptr<Block> &now_init_block) {
  now_block = now_init_block;
  for (auto var_def : now->var_defs) {
    if (var_def.have_expr) {
      auto expr_value = Visit(var_def.expr);
      auto reg = now->scope->GetVarReg(var_def.var_identifier);
      now_block->PushInstr(StoreInstr(reg, expr_value));
    }
  }
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
  result->structs.push_back(BuildStructInfo(now));
  // build construct func
  auto init_func = make_shared<Func>();
  result->funcs.push_back(init_func);
  init_func->identifier = class_identifier + "_Init_";
  init_func->ret_type = kVoidIRType;
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
    func_identifier = now_class_node->class_identifier + "_" + func_identifier;
    func->args.push_back(FuncArg(ObjectType(now_class_node->class_identifier)));
    now_this = func->args.front().reg;
  }
  func->identifier = func_identifier;
  Visit(now->args_def);
  Visit(now->body);
  if (!now_block->closed) {
    if (func->ret_type == kVoidIRType)
      now_block->PushInstr(ReturnInstr());
    else
      now_block->PushInstr(ReturnInstr(Value(func->ret_type, 0)));
  }
}

void IRBuilder::Visit(shared_ptr<AST::VarDefNode> now, bool is_global) {
  if (is_global) {
    auto type = now->type;
    IRType ir_type = type;
    for (auto var_def : now->var_defs) {
      auto var_identifier = var_def.var_identifier;
      // collect varible info
      result->global_vars.push_back({var_identifier, ir_type});
      // give reg to AST
      now->scope->GiveVarReg(var_identifier);
    }
    // push into init func
    PushInitStmt(now, global_init_func, now_global_init_block);
    return;
  }
  for (auto var_def : now->var_defs) {
    now->scope->GiveVarReg(var_def.var_identifier);
    PushInitStmt(now, now_func, now_block);
  }
}

void IRBuilder::Visit(shared_ptr<AST::ArgListDefNode> now) {
  for (auto arg_def : now->args) {
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
    now_block->PushInstr(
        RegisterAssignInstr(arg_var_ptr, AllocaExpr(arg_def.type)));
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
    }
    if (now_block->closed)
      return;
  }
}

void IRBuilder::Visit(shared_ptr<AST::IfStmtNode> now) {
  auto condition = Visit(now->condition_expr);
  auto then_block = MakeBlock();
  auto next_block = MakeBlock(false);
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
    if (!br_to_next)
      return;
    now_func->blocks.push_back(next_block);
    now_block = next_block;
  } else {
    now_block->PushInstr(ConditionBrInstr(condition, then_block, next_block));
    now_block = then_block;
    Visit(now->block);
    if (!now_block->closed)
      now_block->PushInstr(BrInstr(next_block));
    now_block = next_block;
  }
  break_target.pop();
  continue_target.pop();
}

void IRBuilder::Visit(shared_ptr<AST::WhileStmtNode> now) {
  auto condition_block = MakeBlock();
  auto body_block = MakeBlock();
  auto next_block = MakeBlock();
  break_target.push(next_block);
  continue_target.push(condition_block);
  now_block->PushInstr(BrInstr(condition_block));
  now_block = condition_block;
  auto condition = Visit(now->condition_expr);
  now_block->PushInstr(ConditionBrInstr(condition, body_block, next_block));
  now_block = body_block;
  Visit(now->block);
  if (!now_block->closed)
    now_block->PushInstr(BrInstr(condition_block));
  now_block = next_block;
}
void IRBuilder::Visit(shared_ptr<AST::ForStmtNode> now) {
  auto body_block = MakeBlock();
  auto next_block = MakeBlock();
  if (now->have_init_expr) {
    Visit(now->init_expr);
  }
  break_target.push(next_block);
  if (now->have_condition_expr) {
    auto condition_block = MakeBlock();
    shared_ptr<Block> step_block;
    if (now->have_step_expr) {
      step_block = MakeBlock();
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
    if (!now_block->closed)
      now_block->PushInstr(BrInstr(continue_target.top()));
    if (now->have_step_expr) {
      now_block = step_block;
      Visit(now->step_expr);
      now_block->PushInstr(BrInstr(condition_block));
    }
  } else {
    shared_ptr<Block> step_block;
    if (now->have_step_expr) {
      step_block = MakeBlock();
      continue_target.push(step_block);
    } else {
      continue_target.push(body_block);
    }
    now_block->PushInstr(BrInstr(body_block));
    now_block = body_block;
    Visit(now->block);
    if (!now_block->closed)
      now_block->PushInstr(BrInstr(continue_target.top()));
    if (now->have_step_expr) {
      now_block = step_block;
      Visit(now->step_expr);
      now_block->PushInstr(BrInstr(body_block));
    }
  }
  break_target.pop();
  continue_target.pop();
  now_block = next_block;
}

void IRBuilder::Visit(shared_ptr<AST::ReturnStmtNode> now) {
  if (!now->have_ret_expr) {
    now_block->PushInstr(ReturnInstr());
    return;
  }
  auto ret = Visit(now->ret_expr);
  now_block->PushInstr(ReturnInstr(ret));
}
Value IRBuilder::GetRightValue(Value val) {
  if (!val.is_left)
    return val;
  auto now_right_val = make_shared<Register>(val.type.Deref());
  now_block->PushInstr(RegisterAssignInstr(now_right_val, LoadExpr(val.reg)));
  return Value(now_right_val, false);
}
Value IRBuilder::Visit(shared_ptr<AST::ExpressionNode> now) {
  return Value(make_shared<Register>(kIntIRType));
  // return GetRightValue(Visit(now->assign_expr));
}
/*

Value IRBuilder::Visit(shared_ptr<AST::AssignExprNode> now) {
  // return Value(now->value_type.object_type, make_shared<Register>());
  if (!now->have_left_expr) return Visit(now->lor_expr);
  // TODO
}

Value IRBuilder::Visit(shared_ptr<AST::LorExprNode> now) {
  if (now->land_exprs.size() == 1) {
    return Visit(now->land_exprs.front());
  }
  auto ret = GetRightValue(Visit(now->land_exprs.front()));
  bool first_flag = true;
  for (auto now_land_expr : now->land_exprs) {
    if (first_flag) {
      first_flag = false;
      continue;
    }
    auto now_val = GetRightValue(Visit(now_land_expr));
    auto new_reg = make_shared<Register>();
    now_block->PushInstr(RegisterAssignInstr(new_reg, BinaryExpr()))
  }
}
Value IRBuilder::Visit(shared_ptr<AST::LandExprNode> now) {
  if (now->or_exprs.size() == 1) {
    return Visit(now->or_exprs.front());
  }
  // TODO
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
    auto new_reg = Value(kI32Type, make_shared<Register>(), false);
    now_block->PushInstr(RegisterAssignInstr(new_reg.reg, BinaryExpr(ret,
now_val, BinaryExpr::kOr))); ret = new_reg;
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
    auto new_reg = Value(kI32Type, make_shared<Register>(), false);
    now_block->PushInstr(RegisterAssignInstr(new_reg.reg, BinaryExpr(ret,
now_val, BinaryExpr::kXor))); ret = new_reg;
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
    auto new_reg = Value(kI32Type, make_shared<Register>(), false);
    now_block->PushInstr(RegisterAssignInstr(new_reg.reg, BinaryExpr(ret,
now_val, BinaryExpr::kAnd))); ret = new_reg;
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
    auto new_reg = Value(kI8Type, make_shared<Register>(), false);
    BinaryExpr::BinarayOp op;
    switch (*now_op_iter) {
      case AST::EqualityExprNode::kEqual:
        op = IR::BinaryExpr::kEqual;
        break;
      case AST::EqualityExprNode::kNotEqual:
        op = IR::BinaryExpr::kNotequal;
        break;
    }
    now_block->PushInstr(RegisterAssignInstr(new_reg.reg, BinaryExpr(ret,
now_val, op))); ret = new_reg;
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
    auto new_reg = Value(kI8Type, make_shared<Register>(), false);
    BinaryExpr::BinarayOp op;
    switch (*now_op_iter) {
      case AST::RelationExprNode::kGreater:
        op = IR::BinaryExpr::kGreater;
        break;
      case AST::RelationExprNode::kGreaterEqual:
        op = IR::BinaryExpr::kGreaterEqual;
        break;
      case AST::RelationExprNode::kLessEqual:
        op = IR::BinaryExpr::kLessEqual;
        break;
      case AST::RelationExprNode::kLess:
        op = IR::BinaryExpr::kLess;
        break;
    }
    now_block->PushInstr(RegisterAssignInstr(new_reg.reg, BinaryExpr(ret,
now_val, op))); ret = new_reg;
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
    auto new_reg = Value(kI32Type, make_shared<Register>(), false);
    BinaryExpr::BinarayOp op;
    switch (*now_op_iter) {
      case AST::ShiftExprNode::kLeftShift:
        op = IR::BinaryExpr::kLeftShift;
        break;
      case AST::ShiftExprNode::kRightShift:
        op = IR::BinaryExpr::kRightShift;
        break;
    }
    now_block->PushInstr(RegisterAssignInstr(new_reg.reg, BinaryExpr(ret,
now_val, op))); ret = new_reg;
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
    auto new_reg = Value(kI32Type, make_shared<Register>(), false);
    BinaryExpr::BinarayOp op;
    switch (*now_op_iter) {
      case AST::AddExprNode::kPlus:
        op = IR::BinaryExpr::kPlus;
        break;
      case AST::AddExprNode::kMinus:
        op = IR::BinaryExpr::kMinus;
        break;
    }
    now_block->PushInstr(RegisterAssignInstr(new_reg.reg, BinaryExpr(ret,
now_val, op))); ret = new_reg;
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
    auto new_reg = Value(kI32Type, make_shared<Register>(), false);
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
    now_block->PushInstr(RegisterAssignInstr(new_reg.reg, BinaryExpr(ret,
now_val, op))); ret = new_reg;
    ++now_op_iter;
  }
  return ret;
}
Value IRBuilder::Visit(shared_ptr<AST::UnaryExprNode> now) {
  Value ret(kI32Type);
  if (auto expr = AnyCastPtr<AST::PostfixExprNode>(now->expr)) {
    ret = Visit(expr);
  } else if (auto expr = AnyCastPtr<AST::NewExprNode>(now->expr)) {
    ret = Visit(expr);
  }
  for (auto op : now->prefix_unary_ops) {
    switch (op) {
      case AST::UnaryExprNode::kPlusPlus: {
        Value val = GetRightValue(ret);
        break;
      }
      case AST::UnaryExprNode::kMinusMinus: {
        Value val = GetRightValue(ret);
        break;
      }
      case AST::UnaryExprNode::kNot:
        break;
      case AST::UnaryExprNode::kTilde:
        break;
      case AST::UnaryExprNode::kMinus:
        break;
    }
  }
  return ret;
}
Value IRBuilder::Visit(shared_ptr<AST::PostfixExprNode> now) {
  // TODO
}
Value IRBuilder::Visit(shared_ptr<AST::PrimaryExprNode> now) {
  // TODO
}
Value IRBuilder::Visit(shared_ptr<AST::NewExprNode> now) {
  // TODO
} */