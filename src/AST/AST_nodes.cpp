#pragma once
#include "AST_nodes.h"
using namespace std;
namespace AST {

ProgNode::ProgNode(MxParser::ProgContext* ctx) {
  for (auto definition : ctx->definition()) {
    if (auto nxt_node = definition->classDef()) {
      definitions.push_back(make_shared<ClassDefNode>(nxt_node));
    } else if (auto nxt_node = definition->varDef()) {
      definitions.push_back(make_shared<VarDefNode>(nxt_node));
    } else if (auto nxt_node = definition->funcDef()) {
      definitions.push_back(make_shared<FuncDefNode>(nxt_node));
    } else
      throw MyException("Unknown error in AST building");
  }
}
VarDefNode::VarDefNode(MxParser::VarDefContext* ctx) {
  //?
}
ClassDefNode::ClassDefNode(MxParser::ClassDefContext* ctx) {
  class_identifier = ctx->Identifier()->getText();
  for (auto now_stmt : ctx->classBody()->memberStmt()) {
    if (auto nxt_node = now_stmt->constructFuncDef()) {
      member_stmts.push_back(make_shared<ConstructFuncDefNode>(nxt_node));
    } else if (auto nxt_node = now_stmt->varDef()) {
      member_stmts.push_back(make_shared<VarDefNode>(nxt_node));
    } else if (auto nxt_node = now_stmt->funcDef()) {
      member_stmts.push_back(make_shared<FuncDefNode>(nxt_node));
    } else
      throw MyException("Unknown error in AST building");
  }
}
FuncDefNode::FuncDefNode(MxParser::FuncDefContext* ctx) {
  type = ctx->typeName();
  func_identifier = ctx->Identifier()->getText();
  args_def = make_shared<ArgListDefNode>(ctx->argListDef());
  body = make_shared<StmtBlockNode>(ctx->stmtBlock());
}
ArgListDefNode::ArgListDefNode(MxParser::ArgListDefContext* ctx) {
  const auto& type_names = ctx->typeName();
  const auto& arg_identifiers = ctx->Identifier();
  auto arg_n = type_names.size();
  for (int idx = 0; idx < arg_n; ++idx) {
    args.push_back(Arg(type_names[idx], arg_identifiers[idx]->getText()));
  }
}
ArgListNode::ArgListNode(MxParser::ArgListContext* ctx) {
  for (auto now_expr : ctx->expression()) {
    args.push_back(make_shared<ExpressionNode>(now_expr));
  }
}
ConstructFuncDefNode::ConstructFuncDefNode(MxParser::ConstructFuncDefContext* ctx) {
  func_identifier = ctx->Identifier()->getText();
  body = make_shared<StmtBlockNode>(ctx->stmtBlock());
}
StmtBlockNode::StmtBlockNode(MxParser::StmtBlockContext* ctx) {
  for (auto now_stmt : ctx->funcStmt()) {
    if (auto nxt_node = now_stmt->varDef()) {
      stmts.push_back(make_shared<VarDefNode>(nxt_node));
    } else if (auto nxt_node = now_stmt->ifStmt()) {
      stmts.push_back(make_shared<IfStmtNode>(nxt_node));
    } else if (auto nxt_node = now_stmt->whileStmt()) {
      stmts.push_back(make_shared<WhileStmtNode>(nxt_node));
    } else if (auto nxt_node = now_stmt->forStmt()) {
      stmts.push_back(make_shared<ForStmtNode>(nxt_node));
    } else if (auto nxt_node = now_stmt->returnStmt()) {
      stmts.push_back(make_shared<ReturnStmtNode>(nxt_node));
    } else if (auto nxt_node = now_stmt->breakStmt()) {
      stmts.push_back(make_shared<BreakStmtNode>(nxt_node));
    } else if (auto nxt_node = now_stmt->continueStmt()) {
      stmts.push_back(make_shared<ContinueStmtNode>(nxt_node));
    } else if (auto nxt_node = now_stmt->exprStmt()) {
      stmts.push_back(make_shared<ExprStmtNode>(nxt_node));
    } else if (auto nxt_node = now_stmt->stmtBlock()) {
      stmts.push_back(make_shared<StmtBlockNode>(nxt_node));
    } else if (auto nxt_node = now_stmt->blankStmt()) {
      continue;
    } else
      throw MyException("Unknown error in AST building");
  }
}
ExpressionNode::ExpressionNode(MxParser::ExpressionContext* ctx) {
  assign_expr = make_shared<AssignExprNode>(ctx->assignExpr());
}
AssignExprNode::AssignExprNode(MxParser::AssignExprContext* ctx) {
  if (ctx->Assign()) {  // really an assign expression
    have_left_expr = true;
    left_expr = make_shared<LorExprNode>(ctx->orOrExpr(0));
    lor_expr = make_shared<LorExprNode>(ctx->orOrExpr(1));
  } else {
    have_left_expr = false;
    lor_expr = make_shared<LorExprNode>(ctx->orOrExpr(0));
  }
}
LorExprNode::LorExprNode(MxParser::OrOrExprContext* ctx) {
  for (auto now_land_expr : ctx->andAndExpr()) {
    land_exprs.push_back(make_shared<LandExprNode>(now_land_expr));
  }
}
LandExprNode::LandExprNode(MxParser::AndAndExprContext* ctx) {
  for (auto now_or_expr : ctx->orExpr()) {
    or_exprs.push_back(make_shared<OrExprNode>(now_or_expr));
  }
}
OrExprNode::OrExprNode(MxParser::OrExprContext* ctx) {
  for (auto now_xor_expr : ctx->xorExpr()) {
    xor_exprs.push_back(make_shared<XorExprNode>(now_xor_expr));
  }
}
XorExprNode::XorExprNode(MxParser::XorExprContext* ctx) {
  for (auto now_and_expr : ctx->andExpr()) {
    and_exprs.push_back(make_shared<AndExprNode>(now_and_expr));
  }
}
AndExprNode::AndExprNode(MxParser::AndExprContext* ctx) {
  for (auto now_equality_expr : ctx->equalityExpr()) {
    equal_exprs.push_back(make_shared<EqualityExprNode>(now_equality_expr));
  }
}
EqualityExprNode::EqualityExprNode(MxParser::EqualityExprContext* ctx) {
  for (auto now_relation_expr : ctx->relationExpr()) {
    relation_exprs.push_back(make_shared<RelationExprNode>(now_relation_expr));
  }
  for (auto now_equal_op : ctx->equalOp()) {
    if (now_equal_op->Equal()) {
      equal_ops.push_back(kEqual);
    } else if (now_equal_op->NotEqual()) {
      equal_ops.push_back(kNotEqual);
    } else
      throw MyException("Unknown error in AST building");
  }
}
RelationExprNode::RelationExprNode(MxParser::RelationExprContext* ctx) {
  for (auto now_shift_expr : ctx->shiftExpr()) {
    shift_exprs.push_back(make_shared<ShiftExprNode>(now_shift_expr));
  }
  for (auto now_relation_op : ctx->relationOp()) {
    if (now_relation_op->Less()) {
      relations_ops.push_back(kLess);
    } else if (now_relation_op->Greater()) {
      relations_ops.push_back(kGreater);
    } else if (now_relation_op->LessEqual()) {
      relations_ops.push_back(kLessEqual);
    } else if (now_relation_op->GreaterEqual()) {
      relations_ops.push_back(kGreaterEqual);
    } else
      throw MyException("Unknown error in AST building");
  }
}
ShiftExprNode::ShiftExprNode(MxParser::ShiftExprContext* ctx) {
  for (auto now_add_expr : ctx->addExpr()) {
    add_exprs.push_back(make_shared<AddExprNode>(now_add_expr));
  }
  for (auto now_shift_op : ctx->shiftOp()) {
    if (now_shift_op->LeftShift()) {
      shift_ops.push_back(kLeftShift);
    } else if (now_shift_op->RightShift()) {
      shift_ops.push_back(kRightShift);
    } else
      throw MyException("Unknown error in AST building");
  }
}
AddExprNode::AddExprNode(MxParser::AddExprContext* ctx) {
  for (auto now_multi_expr : ctx->multiExpr()) {
    multi_exprs.push_back(make_shared<MultiExprNode>(now_multi_expr));
  }
  for (auto now_shift_op : ctx->addOp()) {
    if (now_shift_op->Plus()) {
      add_ops.push_back(kPlus);
    } else if (now_shift_op->Minus()) {
      add_ops.push_back(kMinus);
    } else
      throw MyException("Unknown error in AST building");
  }
}
MultiExprNode::MultiExprNode(MxParser::MultiExprContext* ctx) {
  for (auto now_unary_expr : ctx->unaryExpr()) {
    unary_exprs.push_back(make_shared<UnaryExprNode>(now_unary_expr));
  }
  for (auto now_multi_op : ctx->multiOp()) {
    if (now_multi_op->Star()) {
      multi_ops.push_back(kStar);
    } else if (now_multi_op->Div()) {
      multi_ops.push_back(kDiv);
    } else if (now_multi_op->Mod()) {
      multi_ops.push_back(kMod);
    } else
      throw MyException("Unknown error in AST building");
  }
}
UnaryExprNode::UnaryExprNode(MxParser::UnaryExprContext* ctx) {
  auto now_expr = ctx;
  while (now_expr->unaryExpr()) {
    if (!now_expr->prefixUnaryOp()) throw MyException("Unknown error in AST building");
    auto now_prefix_op = now_expr->prefixUnaryOp();
    if (now_prefix_op->PlusPlus()) {
      prefix_unary_ops.push_back(kPlusPlus);
    } else if (now_prefix_op->MinusMinus()) {
      prefix_unary_ops.push_back(kMinusMinus);
    } else if (now_prefix_op->Not()) {
      prefix_unary_ops.push_back(kNot);
    } else if (now_prefix_op->Tilde()) {
      prefix_unary_ops.push_back(kTilde);
    } else if (now_prefix_op->Minus()) {
      prefix_unary_ops.push_back(kMinus);
    } else
      throw MyException("Unknown error in AST building");
    now_expr = now_expr->unaryExpr();
  }
  // now, now_expr is a postfixExpr or newExpr
  if (auto next_node = now_expr->postfixExpr()) {
    expr = make_shared<PostfixExprNode>(next_node);
  } else if (auto next_node = now_expr->newExpr()) {
    expr = make_shared<NewExprNode>(next_node);
  } else
    throw MyException("Unknown error in AST building");
}
PostfixExprNode::PostfixExprNode(MxParser::PostfixExprContext* ctx) {
  auto now_expr = ctx;
  while (now_expr->postfixExpr()) {
    if (auto now_suffix_op = now_expr->arrayIndex()) {
      suffix_ops.push_back(make_shared<ArrayIndexNode>(now_suffix_op));
    } else if (auto now_suffix_op = now_expr->argList()) {
      suffix_ops.push_back(make_shared<ArgListNode>(now_suffix_op));
    } else if (auto now_suffix_op = now_expr->Identifier()) {
      suffix_ops.push_back(Member(now_suffix_op->getText()));
    } else if (auto now_suffix_op = now_expr->suffixUnaryOp()) {
      if (now_suffix_op->PlusPlus()) {
        suffix_ops.push_back(kPlusPlus);
      } else if (now_suffix_op->MinusMinus()) {
        suffix_ops.push_back(kMinusMinus);
      } else
        throw MyException("Unknown error in AST building");
    } else
      throw MyException("Unknown error in AST building");
    now_expr = now_expr->postfixExpr();
  }
  // now, now_expr is a primaryExpr
  if (auto next_node = now_expr->primaryExpr()) {
    primary_expr = make_shared<PrimaryExprNode>(next_node);
  } else
    throw MyException("Unknown error in AST building");
}
PrimaryExprNode::PrimaryExprNode(MxParser::PrimaryExprContext* ctx) {
  if (auto nxt_node = ctx->literal()) {
  } else if (auto nxt_node = ctx->This()) {
    expr = This();
  } else if (auto nxt_node = ctx->expression()) {
    expr = make_shared<ExpressionNode>(nxt_node);
  } else if (auto nxt_node = ctx->Identifier()) {
    expr = nxt_node->getText();
  } else if (auto nxt_node = ctx->lambdaExpr()) {
    expr = make_shared<LambdaExprNode>(nxt_node);
  } else
    throw MyException("Unknown error in AST building");
}
LambdaExprNode::LambdaExprNode(MxParser::LambdaExprContext* ctx) {
  ref = ctx->And();
  args_def = make_shared<ArgListDefNode>(ctx->argListDef());
  body = make_shared<StmtBlockNode>(ctx->stmtBlock());
}
NewExprNode::NewExprNode(MxParser::NewExprContext* ctx) {
  if (auto now_node = ctx->newObjExpr()) {
    type = Type(now_node->basicType()->getText(), 0);
  } else if (auto now_node = ctx->newArrayExpr()) {
    type = Type();  // todo
  } else
    throw MyException("Unknown error in AST building");
}
ArrayIndexNode::ArrayIndexNode(MxParser::ArrayIndexContext* ctx) {
  idx_expr = make_shared<ExpressionNode>(ctx->expression());
}
LiteralNode::LiteralNode(MxParser::LiteralContext* ctx) {
  if (auto now_literal = ctx->IntLiteral()) {
    value = stoi(now_literal->getText());
  } else if (auto now_literal = ctx->True()) {
    type = Type("bool", 0);
    value = true;
  } else if (auto now_literal = ctx->False()) {
    type = Type("bool", 0);
    value = false;
  } else if (auto now_literal = ctx->NullLiteral()) {
    type = Type("null", 0);
  } else if (auto now_literal = ctx->StringLiteral()) {
    type = Type("string", 0);
    value = string(now_literal->getText().c_str() + 1);
    any_cast<string>(value).pop_back();
  }
}
IfStmtNode::IfStmtNode(MxParser::IfStmtContext* ctx) {
  condition_expr = make_shared<ExpressionNode>(ctx->condition()->expression());
  block = make_shared<BlockNode>(ctx->block());
  if (auto now_else_stmt = ctx->elseStmt()) {
    have_else = true;
    else_block = make_shared<BlockNode>(ctx->elseStmt()->block());
  } else
    have_else = false;
}
WhileStmtNode::WhileStmtNode(MxParser::WhileStmtContext* ctx) {
  condition_expr = make_shared<ExpressionNode>(ctx->condition()->expression());
  block = make_shared<BlockNode>(ctx->block());
}
ForStmtNode::ForStmtNode(MxParser::ForStmtContext* ctx) {
  if (auto now_init_expr = ctx->forCondition()->expression(0)) {
    have_init_expr = true;
    init_expr = make_shared<ExpressionNode>(now_init_expr);
  } else
    have_init_expr = false;
  if (auto now_condition_expr = ctx->forCondition()->expression(1)) {
    have_condition_expr = true;
    condition_expr = make_shared<ExpressionNode>(now_condition_expr);
  } else
    have_condition_expr = false;
  if (auto now_step_expr = ctx->forCondition()->expression(0)) {
    have_step_expr = true;
    step_expr = make_shared<ExpressionNode>(now_step_expr);
  } else
    have_step_expr = false;
  block = make_shared<BlockNode>(ctx->block());
}
BlockNode::BlockNode(MxParser::BlockContext* ctx) {
  auto stmt_parser = [&](MxParser::FuncStmtContext* stmt) -> void {
    if (auto now_stmt = stmt->varDef()) {
      stmts.push_back(make_shared<VarDefNode>(now_stmt));
    } else if (auto now_stmt = stmt->ifStmt()) {
      stmts.push_back(make_shared<IfStmtNode>(now_stmt));
    } else if (auto now_stmt = stmt->whileStmt()) {
      stmts.push_back(make_shared<WhileStmtNode>(now_stmt));
    } else if (auto now_stmt = stmt->forStmt()) {
      stmts.push_back(make_shared<ForStmtNode>(now_stmt));
    } else if (auto now_stmt = stmt->returnStmt()) {
      stmts.push_back(make_shared<ReturnStmtNode>(now_stmt));
    } else if (auto now_stmt = stmt->breakStmt()) {
      stmts.push_back(make_shared<BreakStmtNode>(now_stmt));
    } else if (auto now_stmt = stmt->continueStmt()) {
      stmts.push_back(make_shared<ContinueStmtNode>(now_stmt));
    } else if (auto now_stmt = stmt->exprStmt()) {
      stmts.push_back(make_shared<ExprStmtNode>(now_stmt));
    } else if (auto now_stmt = stmt->stmtBlock()) {
      stmts.push_back(make_shared<StmtBlockNode>(now_stmt));
    } else if (auto now_stmt = stmt->blankStmt()) {
      return;
    } else
      throw MyException("Unknown error in AST building");
  };
  if (auto now_block = ctx->stmtBlock()) {
    for (auto now_stmt : now_block->funcStmt()) {
      stmt_parser(now_stmt);
    }
  } else if (auto now_block = ctx->funcStmt()) {
    stmt_parser(now_block);
  }
}
ReturnStmtNode::ReturnStmtNode(MxParser::ReturnStmtContext* ctx) {
  ret_expr = make_shared<ExpressionNode>(ctx->expression());
}
BreakStmtNode::BreakStmtNode(MxParser::BreakStmtContext* ctx) {}
ContinueStmtNode::ContinueStmtNode(MxParser::ContinueStmtContext* ctx) {}
ExprStmtNode::ExprStmtNode(MxParser::ExprStmtContext* ctx) { expr = make_shared<ExpressionNode>(ctx->expression()); }
}  // namespace AST
