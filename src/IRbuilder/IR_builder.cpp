#include "IR_builder.h"

#include <bits/stdc++.h>

#include <cstdlib>
#include <memory>

#include "AST_nodes.h"
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
    now->scope->GiveVarReg(var_identifier, make_shared<Register>());
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
  global_init_func->ret_type = kIRVoidType;
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
  init_func->ret_type = kIRVoidType;
  shared_ptr<Block> now_init_block = init_func->blocks.back();
  // collect member func
  for (auto member_stmt : now->member_stmts) {
    if (auto member_func_def = AnyCastPtr<AST::FuncDefNode>(member_stmt)) {
      Visit(member_func_def);
    } else {
      auto member_var_def = AnyCastPtr<AST::VarDefNode>(member_stmt);
      PushInitStmt(member_var_def, init_func, now_init_block);
    }
  }
  now_init_block->PushInstr(ReturnInstr());
  now_class_node = nullptr;
}

void IRBuilder::Visit(shared_ptr<AST::FuncDefNode> now) {
  auto func = make_shared<Func>();
  result->funcs.push_back(func);
  now_func = func;
  now_block = func->blocks.back();
  string func_identifier = now->func_identifier;
  if (now_class_node) {
    func_identifier = now_class_node->class_identifier + "_" + func_identifier;
    func->args.push_back(FuncArg(kPtrType));
    now_this = func->args.front().reg;
  }
  func->identifier = func_identifier;
  Visit(now->args_def);
  Visit(now->body);
  if (!now_block->closed) {
    if (func->ret_type.kind == IRType::kVoid)
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
    now_func->args.push_back(FuncArg(arg_def.type));
    now->scope->GiveVarReg(arg_def.arg_identifier);
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

Value IRBuilder::Visit(shared_ptr<AST::ExpressionNode> now) {
  return Value(now->value_type.object_type, make_shared<Register>());
}