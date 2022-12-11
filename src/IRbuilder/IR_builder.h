#pragma once
#include <list>
#include <memory>
#include <stack>

#include "AST_nodes.h"
#include "IR.h"
#include "gscope.h"
#include "my_exception.h"
#include "type.h"
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
  void PushInitStmt(shared_ptr<AST::VarDefNode> now, shared_ptr<Func> func, shared_ptr<Block> &now_init_block);
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
  void Visit(shared_ptr<AST::BreakStmtNode> now);
  void Visit(shared_ptr<AST::ContinueStmtNode> now);
  Value GetRightValue(Value val);
  Value NowThis();
  void BuildArrayStruct(ObjectType type);
  Value InitArray(ObjectType type, list<Value>::const_iterator cend_iter, list<Value>::const_iterator iter);
  Value Visit(shared_ptr<AST::ExpressionNode> now);
  Value Visit(shared_ptr<AST::AssignExprNode> now);
  Value Visit(shared_ptr<AST::LorExprNode> now);
  Value Visit(shared_ptr<AST::LandExprNode> now);
  Value Visit(shared_ptr<AST::OrExprNode> now);
  Value Visit(shared_ptr<AST::XorExprNode> now);
  Value Visit(shared_ptr<AST::AndExprNode> now);
  Value Visit(shared_ptr<AST::EqualityExprNode> now);
  Value Visit(shared_ptr<AST::RelationExprNode> now);
  Value Visit(shared_ptr<AST::ShiftExprNode> now);
  Value Visit(shared_ptr<AST::AddExprNode> now);
  Value Visit(shared_ptr<AST::MultiExprNode> now);
  Value Visit(shared_ptr<AST::UnaryExprNode> now);
  Value Visit(shared_ptr<AST::PostfixExprNode> now);
  Value Visit(shared_ptr<AST::PrimaryExprNode> now);
  Value Visit(shared_ptr<AST::NewExprNode> now);
  Value Visit(shared_ptr<AST::LiteralNode> now);
  list<Value> Visit(shared_ptr<AST::ArgListNode> now);
  // obj_ptr must be right value
  Value VisitMemberVarible(Value obj_ptr, const string &class_identifier, const string &member_identifier);
  // shared_ptr<Func> BuildMemberFunc(shared_ptr<AST::FuncDefNode>now,
  //                                  const string &class_identifier);
};
