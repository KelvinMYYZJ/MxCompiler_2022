#pragma once
#include <bits/stdc++.h>

#include <list>
#include <memory>
#include <stack>

#include "AST_nodes.h"
#include "IR.h"
#include "gscope.h"
#include "my_exception.h"
using namespace std;
using namespace IR;
struct IRBuilder {
  GScope *gscope;
  shared_ptr<Func> global_init_func;
  shared_ptr<Func> now_func;
  shared_ptr<Block> now_block;
  shared_ptr<Register> now_this;
  AST::ClassDefNode *now_class_node;
  shared_ptr<Block> now_global_init_block;
  stack<shared_ptr<Block>> break_target;
  stack<shared_ptr<Block>> continue_target;
  IRBuffer *result;
  shared_ptr<Block> MakeBlock(bool push_now = true);
  shared_ptr<Struct> BuildStructInfo(shared_ptr<AST::ClassDefNode> now);
  shared_ptr<IRBuffer> BuildIR(shared_ptr<AST::ProgNode> now);
  void PushInitStmt(shared_ptr<AST::VarDefNode> now, shared_ptr<Func> func,
                    shared_ptr<Block> &now_init_block);
  void Visit(shared_ptr<AST::ProgNode> now);
  void Visit(shared_ptr<AST::ClassDefNode> now);
  void Visit(shared_ptr<AST::VarDefNode> now, bool is_global = false);
  void Visit(shared_ptr<AST::FuncDefNode> now);
  void Visit(shared_ptr<AST::ArgListDefNode> now);
  void Visit(shared_ptr<AST::StmtBlockNode> now);
  void Visit(shared_ptr<AST::IfStmtNode> now);
  void Visit(shared_ptr<AST::WhileStmtNode> now);
  void Visit(shared_ptr<AST::ForStmtNode> now);
  void Visit(shared_ptr<AST::ReturnStmtNode> now);
  Value Visit(shared_ptr<AST::ExpressionNode> now);
  // shared_ptr<Func> BuildMemberFunc(shared_ptr<AST::FuncDefNode>now,
  //                                  const string &class_identifier);
};
