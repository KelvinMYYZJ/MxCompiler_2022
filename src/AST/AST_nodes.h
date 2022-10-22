#include <bits/stdc++.h>

#include "type.h"
using namespace std;
class ProgNode;
class VarDefNode;
class ClassDefNode;
class FuncDefNode;
class ConstructFuncDefNode;
class FuncBodyNode;
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
class EqualOpNode;
class RelationOpNode;
class ShiftOpNode;
class AddOpNode;
class MultiOpNode;
class PrefixUnaryOpNode;
class SuffixUnaryOpNode;
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
};
class VarDefNode {
 public:
  Type type;
  string var_identifier;
  bool have_expr;
  shared_ptr<ExpressionNode> expr;
};
class ClassDefNode {
 public:
  string class_identifier;
  list<any> member_stmts;  // varDef | constructFuncDef | funcDef
};
class FuncDefNode {
 public:
  Type type;
  string func_identifier;
  list<Arg> arglist;
  shared_ptr<FuncBodyNode> body;
};
class ConstructFuncDefNode {
 public:
  string func_identifier;  // should be the same with class identifier.
  shared_ptr<FuncBodyNode> body;
};

class FuncBodyNode {
 public:
  list<any> stmts;  // varDef | ifStmt | whileStmt | forStmt | returnStmt | breakStmt | continueStmt | exprStmt |
                    // multiStmtBlock
};
class ExpressionNode {
 public:
  shared_ptr<AssignExprNode> assign_expr;
};
class AssignExprNode {
 public:
  shared_ptr<LorExprNode> left_expr;
  shared_ptr<LorExprNode> lor_expr;
};
class LorExprNode {
 public:
  list<shared_ptr<LandExprNode>> land_exprs;
};
class LandExprNode {
 public:
  list<shared_ptr<OrExprNode>> or_exprs;
};
class OrExprNode {
 public:
  list<shared_ptr<XorExprNode>> xor_exprs;
};
class XorExprNode {
 public:
  list<shared_ptr<AndExprNode>> and_exprs;
};
class AndExprNode {
 public:
  list<shared_ptr<EqualityExprNode>> equal_exprs;
};
class EqualityExprNode {
 public:
  enum EqualOp { kEqual, kNotEqual };
  list<shared_ptr<RelationExprNode>> relation_exprs;
  list<EqualOp> equal_ops;
};
class RelationExprNode {
 public:
  enum RelationOp { kLess, kGreater, kLessEqual, kGreaterEqual };
  list<shared_ptr<ShiftExprNode>> shift_exprs;
  list<RelationOp> relations_ops;
};
class ShiftExprNode {
 public:
  enum ShiftOp { kLeftShift, kRightShift };
  list<shared_ptr<AddExprNode>> add_exprs;
  list<ShiftOp> shift_ops;
};
class AddExprNode {
 public:
  enum AddOp { kPlus, kMinus };
  list<shared_ptr<MultiExprNode>> multi_exprs;
  list<AddOp> add_ops;
};
class MultiExprNode {
 public:
  enum MultiOp { kStar, kDiv, kMod };
  list<shared_ptr<UnaryExprNode>> unary_exprs;
  list<MultiOp> multi_ops;
};
class UnaryExprNode {
 public:
  enum PrefixUnaryOp { kPlusPlus, kMinusMinus, kNot, kTilde, kMinus };
  any expr;  // postfixExpr | newExpr
  list<PrefixUnaryOp> prefix_unary_ops;
};
class PostfixExprNode {
 public:
  enum SuffixUnaryOp { kPlusPlus, kMinusMinus };
  shared_ptr<PrimaryExprNode> primary_expr;
  list<any> suffix_ops;  // suffixUnaryOp | Member | argList | arrayIndex ,inner op at front
};
class PrimaryExprNode {
 public:
  any expr;  // literal | This	| expression | Identifier | lambdaExpr;
};
class LambdaExprNode {
 public:
  bool ref;
  list<Arg> arglist;
  shared_ptr<FuncBodyNode> body;
};
class NewExprNode {
 public:
  Type type;
};
class ArrayIndexNode {
 public:
  shared_ptr<ExpressionNode> idx_expr;
};
class LiteralNode {
 public:
  Type type;
  any value;
};
class IfStmtNode {
 public:
  shared_ptr<ExpressionNode> condition_expr;
  shared_ptr<BlockNode> block;
  bool have_else;
  shared_ptr<BlockNode> else_block;
};
class WhileStmtNode {
 public:
  shared_ptr<ExpressionNode> condition_expr;
  shared_ptr<BlockNode> block;
};
class ForStmtNode {
 public:
  shared_ptr<ExpressionNode> init_expr;
  shared_ptr<ExpressionNode> condition_expr;
  shared_ptr<ExpressionNode> step_expr;
  shared_ptr<BlockNode> block;
};
class LeftValueNode {
 public:
};  //?
class BlockNode {
 public:
  list<any> stmts;  // varDef| ifStmt| whileStmt| forStmt| returnStmt| breakStmt| continueStmt| exprStmt|
                    // multiStmtBlock| blankStmt;
};
class ReturnStmtNode {
 public:
  shared_ptr<ExpressionNode> ret_expr;
};
class BreakStmtNode {
 public:
};
class ContinueStmtNode {
 public:
};
class ExprStmtNode {
 public:
  shared_ptr<ExpressionNode> expr;
};