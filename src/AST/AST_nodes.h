#pragma once

#include "MxParser.h"
#include "class_scope.h"
#include "gscope.h"
#include "my_exception.h"
#include "type.h"
using namespace std;
namespace AST {
class ProgNode;
class VarDefNode;
class ClassDefNode;
class FuncDefNode;
class ArgListDefNode;
class ArgListNode;
class ConstructFuncDefNode;
class StmtBlockNode;
class ExpressionNode;
class AssignExprNode;
class LorExprNode;
class LandExprNode;
class OrExprNode;
class XorExprNode;
class AndExprNode;
class EqualityExprNode;
class RelationExprNode;
class ShiftExprNode;
class AddExprNode;
class MultiExprNode;
class UnaryExprNode;
class PostfixExprNode;
class PrimaryExprNode;
class LambdaExprNode;
class NewExprNode;
class ArrayIndexNode;
class LiteralNode;
class IfStmtNode;
class WhileStmtNode;
class ForStmtNode;
class ReturnStmtNode;
class BreakStmtNode;
class ContinueStmtNode;
class ExprStmtNode;
class ProgNode {
 public:
  shared_ptr<GScope> gscope;
  void BuildScope(shared_ptr<GScope> _gscope);
  list<any> definitions;  // funcDef | varDef | classDef
  ProgNode(MxParser::ProgContext *ctx);
};
class VarDefNode {
 public:
  shared_ptr<Scope> scope;
  void BuildScope(shared_ptr<Scope> _scope);
  ObjectType type;
  struct VarInitPair {
    string var_identifier;
    bool have_expr;
    shared_ptr<ExpressionNode> expr;
  };
  list<VarInitPair> var_defs;
  VarDefNode(MxParser::VarDefContext *ctx);
};
class ClassDefNode {
 public:
  shared_ptr<ClassScope> scope;
  void BuildScope();  // only visit children nodes.
  string class_identifier;
  list<any> member_stmts;  // varDef | constructFuncDef | funcDef
  ClassDefNode(MxParser::ClassDefContext *ctx);
};
class FuncDefNode {
 public:
  shared_ptr<Scope> scope;
  void BuildScope(shared_ptr<Scope> _scope);
  ObjectType type;
  string func_identifier;
  shared_ptr<ArgListDefNode> args_def;
  shared_ptr<StmtBlockNode> body;
  FuncDefNode(MxParser::FuncDefContext *ctx);
  FuncType GetFuncType();
};

class ArgListDefNode {
 public:
  shared_ptr<Scope> scope;
  void BuildScope(shared_ptr<Scope> _scope);
  list<Arg> args;
  ArgListDefNode(MxParser::ArgListDefContext *ctx);
  list<ObjectType> GetArgTypeList();
};

class ArgListNode {
 public:
  shared_ptr<Scope> scope;
  list<ObjectType> type_list;
  void BuildScope(shared_ptr<Scope> _scope);
  list<shared_ptr<ExpressionNode>> args;
  ArgListNode(MxParser::ArgListContext *ctx);
};

class ConstructFuncDefNode {
 public:
  shared_ptr<Scope> scope;
  void BuildScope(shared_ptr<Scope> _scope);
  string func_identifier;  // should be the same with class identifier.
  shared_ptr<StmtBlockNode> body;
  ConstructFuncDefNode(MxParser::ConstructFuncDefContext *ctx);
};

class StmtBlockNode {
 private:
  void AddStmtNode(MxParser::FuncStmtContext *func_stmt);

 public:
  RetType ret_type;
  shared_ptr<Scope> scope;
  void BuildScope(shared_ptr<Scope> _scope, bool create_inner_scope = true);
  bool in_loop;     // can accept break and continue;
  list<any> stmts;  // varDef | ifStmt | whileStmt | forStmt | returnStmt |
                    // breakStmt | continueStmt | exprStmt |
  // multiStmtBlock
  StmtBlockNode(MxParser::StmtBlockContext *ctx, bool _in_loop = false);
  StmtBlockNode(MxParser::BlockContext *ctx, bool _in_loop = false);
};
class ExpressionNode {
 public:
  ValueType value_type;
  shared_ptr<Scope> scope;
  void BuildScope(shared_ptr<Scope> _scope);
  shared_ptr<AssignExprNode> assign_expr;
  ExpressionNode(MxParser::ExpressionContext *ctx);
};
class AssignExprNode {
 public:
  ValueType value_type;
  shared_ptr<Scope> scope;
  void BuildScope(shared_ptr<Scope> _scope);
  bool have_left_expr;
  shared_ptr<LorExprNode> left_expr;
  shared_ptr<LorExprNode> lor_expr;
  AssignExprNode(MxParser::AssignExprContext *ctx);
};
class LorExprNode {
 public:
  ValueType value_type;
  shared_ptr<Scope> scope;
  void BuildScope(shared_ptr<Scope> _scope);
  list<shared_ptr<LandExprNode>> land_exprs;
  LorExprNode(MxParser::OrOrExprContext *ctx);
};
class LandExprNode {
 public:
  ValueType value_type;
  shared_ptr<Scope> scope;
  void BuildScope(shared_ptr<Scope> _scope);
  list<shared_ptr<OrExprNode>> or_exprs;
  LandExprNode(MxParser::AndAndExprContext *ctx);
};
class OrExprNode {
 public:
  ValueType value_type;
  shared_ptr<Scope> scope;
  void BuildScope(shared_ptr<Scope> _scope);
  list<shared_ptr<XorExprNode>> xor_exprs;
  OrExprNode(MxParser::OrExprContext *ctx);
};
class XorExprNode {
 public:
  ValueType value_type;
  shared_ptr<Scope> scope;
  void BuildScope(shared_ptr<Scope> _scope);
  list<shared_ptr<AndExprNode>> and_exprs;
  XorExprNode(MxParser::XorExprContext *ctx);
};
class AndExprNode {
 public:
  ValueType value_type;
  shared_ptr<Scope> scope;
  void BuildScope(shared_ptr<Scope> _scope);
  list<shared_ptr<EqualityExprNode>> equal_exprs;
  AndExprNode(MxParser::AndExprContext *ctx);
};
class EqualityExprNode {
 public:
  ValueType value_type;
  shared_ptr<Scope> scope;
  void BuildScope(shared_ptr<Scope> _scope);
  enum EqualOp { kEqual, kNotEqual };
  list<shared_ptr<RelationExprNode>> relation_exprs;
  list<EqualOp> equal_ops;
  EqualityExprNode(MxParser::EqualityExprContext *ctx);
};
class RelationExprNode {
 public:
  ValueType value_type;
  shared_ptr<Scope> scope;
  void BuildScope(shared_ptr<Scope> _scope);
  enum RelationOp { kLess, kGreater, kLessEqual, kGreaterEqual };
  list<shared_ptr<ShiftExprNode>> shift_exprs;
  list<RelationOp> relations_ops;
  RelationExprNode(MxParser::RelationExprContext *ctx);
};
class ShiftExprNode {
 public:
  ValueType value_type;
  shared_ptr<Scope> scope;
  void BuildScope(shared_ptr<Scope> _scope);
  enum ShiftOp { kLeftShift, kRightShift };
  list<shared_ptr<AddExprNode>> add_exprs;
  list<ShiftOp> shift_ops;
  ShiftExprNode(MxParser::ShiftExprContext *ctx);
};
class AddExprNode {
 public:
  ValueType value_type;
  shared_ptr<Scope> scope;
  void BuildScope(shared_ptr<Scope> _scope);
  enum AddOp { kPlus, kMinus };
  list<shared_ptr<MultiExprNode>> multi_exprs;
  list<AddOp> add_ops;
  AddExprNode(MxParser::AddExprContext *ctx);
};
class MultiExprNode {
 public:
  ValueType value_type;
  shared_ptr<Scope> scope;
  void BuildScope(shared_ptr<Scope> _scope);
  enum MultiOp { kStar, kDiv, kMod };
  list<shared_ptr<UnaryExprNode>> unary_exprs;
  list<MultiOp> multi_ops;
  MultiExprNode(MxParser::MultiExprContext *ctx);
};
class UnaryExprNode {
 public:
  ValueType value_type;
  shared_ptr<Scope> scope;
  void BuildScope(shared_ptr<Scope> _scope);
  enum PrefixUnaryOp { kPlusPlus, kMinusMinus, kNot, kTilde, kMinus };
  any expr;  // postfixExpr | newExpr
  list<PrefixUnaryOp> prefix_unary_ops;
  UnaryExprNode(MxParser::UnaryExprContext *ctx);
};
class PostfixExprNode {
 public:
  ValueType value_type;
  shared_ptr<Scope> scope;
  void BuildScope(shared_ptr<Scope> _scope);
  enum SuffixUnaryOp { kPlusPlus, kMinusMinus };
  shared_ptr<PrimaryExprNode> primary_expr;
  list<any> suffix_ops;  // suffixUnaryOp | Member | argList | arrayIndex ,inner
                         // op at front
  PostfixExprNode(MxParser::PostfixExprContext *ctx);
};
class PrimaryExprNode {
 public:
  ValueType value_type;
  shared_ptr<Scope> scope;
  void BuildScope(shared_ptr<Scope> _scope);
  any expr;  // literal | This	| expression | Identifier | lambdaExpr;
  PrimaryExprNode(MxParser::PrimaryExprContext *ctx);
};
class LambdaExprNode {
 public:
  ValueType value_type;
  shared_ptr<Scope> scope;
  void BuildScope(shared_ptr<Scope> _scope);
  bool ref;
  shared_ptr<ArgListDefNode> args_def;
  shared_ptr<StmtBlockNode> body;
  LambdaExprNode(MxParser::LambdaExprContext *ctx);
};
class NewExprNode {
 public:
  ValueType value_type;
  shared_ptr<Scope> scope;
  bool is_array;
  list<shared_ptr<ArrayIndexNode>> array_idxs;
  void BuildScope(shared_ptr<Scope> _scope);
  ObjectType type;
  NewExprNode(MxParser::NewExprContext *ctx);
};
class ArrayIndexNode {
 public:
  shared_ptr<Scope> scope;
  void BuildScope(shared_ptr<Scope> _scope);
  shared_ptr<ExpressionNode> idx_expr;
  ArrayIndexNode(MxParser::ArrayIndexContext *ctx);
};
class LiteralNode {
 public:
  ObjectType type;
  any value;
  LiteralNode(MxParser::LiteralContext *ctx);
};
class IfStmtNode {
 public:
  shared_ptr<Scope> scope;
  RetType ret_type;
  void BuildScope(shared_ptr<Scope> _scope);
  shared_ptr<ExpressionNode> condition_expr;
  shared_ptr<StmtBlockNode> block;
  bool have_else;
  shared_ptr<StmtBlockNode> else_block;
  bool in_loop;
  IfStmtNode(MxParser::IfStmtContext *ctxm, bool _in_loop = false);
};
class WhileStmtNode {
 public:
  shared_ptr<Scope> scope;
  RetType ret_type;
  void BuildScope(shared_ptr<Scope> _scope);
  shared_ptr<ExpressionNode> condition_expr;
  shared_ptr<StmtBlockNode> block;
  WhileStmtNode(MxParser::WhileStmtContext *ctx);
};
class ForStmtNode {
 public:
  shared_ptr<Scope> scope;
  RetType ret_type;
  void BuildScope(shared_ptr<Scope> _scope);
  bool have_init_expr;
  shared_ptr<ExpressionNode> init_expr;
  bool have_condition_expr;
  shared_ptr<ExpressionNode> condition_expr;
  bool have_step_expr;
  shared_ptr<ExpressionNode> step_expr;
  shared_ptr<StmtBlockNode> block;
  ForStmtNode(MxParser::ForStmtContext *ctx);
};
class ReturnStmtNode {
 public:
  shared_ptr<Scope> scope;
  RetType ret_type;
  void BuildScope(shared_ptr<Scope> _scope);
  bool have_ret_expr;
  shared_ptr<ExpressionNode> ret_expr;
  ReturnStmtNode(MxParser::ReturnStmtContext *ctx);
};
class BreakStmtNode {
 public:
  // shared_ptr<Scope> scope;
  // void BuildScope(shared_ptr<Scope> _scope);
  BreakStmtNode(MxParser::BreakStmtContext *ctx);
};
class ContinueStmtNode {
 public:
  // shared_ptr<Scope> scope;
  // void BuildScope(shared_ptr<Scope> _scope);
  ContinueStmtNode(MxParser::ContinueStmtContext *ctx);
};
class ExprStmtNode {
 public:
  shared_ptr<Scope> scope;
  void BuildScope(shared_ptr<Scope> _scope);
  shared_ptr<ExpressionNode> expr;
  ExprStmtNode(MxParser::ExprStmtContext *ctx);
};
}  // namespace AST