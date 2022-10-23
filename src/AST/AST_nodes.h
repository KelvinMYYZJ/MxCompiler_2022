#include <bits/stdc++.h>

#include "MxParser.h"
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
class identifier;
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
class LeftValueNode;
class BlockNode;
class ReturnStmtNode;
class BreakStmtNode;
class ContinueStmtNode;
class ExprStmtNode;
class ProgNode {
 public:
  list<any> definitions;  // funcDef | varDef | classDef
  ProgNode(MxParser::ProgContext* ctx);
};
class VarDefNode {
 public:
  Type type;
  string var_identifier;
  bool have_expr;
  shared_ptr<ExpressionNode> expr;
  VarDefNode(MxParser::VarDefContext* ctx);
};
class ClassDefNode {
 public:
  string class_identifier;
  list<any> member_stmts;  // varDef | constructFuncDef | funcDef
  ClassDefNode(MxParser::ClassDefContext* ctx);
};
class FuncDefNode {
 public:
  Type type;
  string func_identifier;
  shared_ptr<ArgListDefNode> args_def;
  shared_ptr<StmtBlockNode> body;
  FuncDefNode(MxParser::FuncDefContext* ctx);
};

class ArgListDefNode {
 public:
  list<Arg> args;
  ArgListDefNode(MxParser::ArgListDefContext* ctx);
};

class ArgListNode {
 public:
  list<shared_ptr<ExpressionNode>> args;
  ArgListNode(MxParser::ArgListContext* ctx);
};

class ConstructFuncDefNode {
 public:
  string func_identifier;  // should be the same with class identifier.
  shared_ptr<StmtBlockNode> body;
  ConstructFuncDefNode(MxParser::ConstructFuncDefContext* ctx);
};

class StmtBlockNode {
 public:
  list<any> stmts;  // varDef | ifStmt | whileStmt | forStmt | returnStmt | breakStmt | continueStmt | exprStmt |
  // multiStmtBlock
  StmtBlockNode(MxParser::StmtBlockContext* ctx);
};
class ExpressionNode {
 public:
  shared_ptr<AssignExprNode> assign_expr;
  ExpressionNode(MxParser::ExpressionContext* ctx);
};
class AssignExprNode {
 public:
  bool have_left_expr;
  shared_ptr<LorExprNode> left_expr;
  shared_ptr<LorExprNode> lor_expr;
  AssignExprNode(MxParser::AssignExprContext* ctx);
};
class LorExprNode {
 public:
  list<shared_ptr<LandExprNode>> land_exprs;
  LorExprNode(MxParser::OrOrExprContext* ctx);
};
class LandExprNode {
 public:
  list<shared_ptr<OrExprNode>> or_exprs;
  LandExprNode(MxParser::AndAndExprContext* ctx);
};
class OrExprNode {
 public:
  list<shared_ptr<XorExprNode>> xor_exprs;
  OrExprNode(MxParser::OrExprContext* ctx);
};
class XorExprNode {
 public:
  list<shared_ptr<AndExprNode>> and_exprs;
  XorExprNode(MxParser::XorExprContext* ctx);
};
class AndExprNode {
 public:
  list<shared_ptr<EqualityExprNode>> equal_exprs;
  AndExprNode(MxParser::AndExprContext* ctx);
};
class EqualityExprNode {
 public:
  enum EqualOp { kEqual, kNotEqual };
  list<shared_ptr<RelationExprNode>> relation_exprs;
  list<EqualOp> equal_ops;
  EqualityExprNode(MxParser::EqualityExprContext* ctx);
};
class RelationExprNode {
 public:
  enum RelationOp { kLess, kGreater, kLessEqual, kGreaterEqual };
  list<shared_ptr<ShiftExprNode>> shift_exprs;
  list<RelationOp> relations_ops;
  RelationExprNode(MxParser::RelationExprContext* ctx);
};
class ShiftExprNode {
 public:
  enum ShiftOp { kLeftShift, kRightShift };
  list<shared_ptr<AddExprNode>> add_exprs;
  list<ShiftOp> shift_ops;
  ShiftExprNode(MxParser::ShiftExprContext* ctx);
};
class AddExprNode {
 public:
  enum AddOp { kPlus, kMinus };
  list<shared_ptr<MultiExprNode>> multi_exprs;
  list<AddOp> add_ops;
  AddExprNode(MxParser::AddExprContext* ctx);
};
class MultiExprNode {
 public:
  enum MultiOp { kStar, kDiv, kMod };
  list<shared_ptr<UnaryExprNode>> unary_exprs;
  list<MultiOp> multi_ops;
  MultiExprNode(MxParser::MultiExprContext* ctx);
};
class UnaryExprNode {
 public:
  enum PrefixUnaryOp { kPlusPlus, kMinusMinus, kNot, kTilde, kMinus };
  any expr;  // postfixExpr | newExpr
  list<PrefixUnaryOp> prefix_unary_ops;
  UnaryExprNode(MxParser::UnaryExprContext* ctx);
};
class PostfixExprNode {
 public:
  enum SuffixUnaryOp { kPlusPlus, kMinusMinus };
  shared_ptr<PrimaryExprNode> primary_expr;
  list<any> suffix_ops;  // suffixUnaryOp | Member | argList | arrayIndex ,inner op at front
  PostfixExprNode(MxParser::PostfixExprContext* ctx);
};
class PrimaryExprNode {
 public:
  any expr;  // literal | This	| expression | Identifier | lambdaExpr;
  PrimaryExprNode(MxParser::PrimaryExprContext* ctx);
};
class LambdaExprNode {
 public:
  bool ref;
  shared_ptr<ArgListDefNode> args_def;
  shared_ptr<StmtBlockNode> body;
  LambdaExprNode(MxParser::LambdaExprContext* ctx);
};
class NewExprNode {
 public:
  Type type;
  NewExprNode(MxParser::NewExprContext* ctx);
};
class ArrayIndexNode {
 public:
  shared_ptr<ExpressionNode> idx_expr;
  ArrayIndexNode(MxParser::ArrayIndexContext* ctx);
};
class LiteralNode {
 public:
  Type type;
  any value;
  LiteralNode(MxParser::LiteralContext* ctx);
};
class IfStmtNode {
 public:
  shared_ptr<ExpressionNode> condition_expr;
  shared_ptr<BlockNode> block;
  bool have_else;
  shared_ptr<BlockNode> else_block;
  IfStmtNode(MxParser::IfStmtContext* ctx);
};
class WhileStmtNode {
 public:
  shared_ptr<ExpressionNode> condition_expr;
  shared_ptr<BlockNode> block;
  WhileStmtNode(MxParser::WhileStmtContext* ctx);
};
class ForStmtNode {
 public:
  bool have_init_expr;
  shared_ptr<ExpressionNode> init_expr;
  bool have_condition_expr;
  shared_ptr<ExpressionNode> condition_expr;
  bool have_step_expr;
  shared_ptr<ExpressionNode> step_expr;
  shared_ptr<BlockNode> block;
  ForStmtNode(MxParser::ForStmtContext* ctx);
};
class BlockNode {
 public:
  list<any> stmts;  // varDef| ifStmt| whileStmt| forStmt| returnStmt| breakStmt| continueStmt| exprStmt|
  // multiStmtBlock| blankStmt;
  BlockNode(MxParser::BlockContext* ctx);
};
class ReturnStmtNode {
 public:
  shared_ptr<ExpressionNode> ret_expr;
  ReturnStmtNode(MxParser::ReturnStmtContext* ctx);
};
class BreakStmtNode {
 public:
  BreakStmtNode(MxParser::BreakStmtContext* ctx);
};
class ContinueStmtNode {
 public:
  ContinueStmtNode(MxParser::ContinueStmtContext* ctx);
};
class ExprStmtNode {
 public:
  shared_ptr<ExpressionNode> expr;
  ExprStmtNode(MxParser::ExprStmtContext* ctx);
};
}  // namespace AST