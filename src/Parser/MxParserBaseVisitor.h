
// Generated from MxParser.g4 by ANTLR 4.11.1

#pragma once


#include "antlr4-runtime.h"
#include "MxParserVisitor.h"


/**
 * This class provides an empty implementation of MxParserVisitor, which can be
 * extended to create a visitor which only needs to handle a subset of the available methods.
 */
class  MxParserBaseVisitor : public MxParserVisitor {
public:

  virtual std::any visitProg(MxParser::ProgContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDefinition(MxParser::DefinitionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitVarDef(MxParser::VarDefContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSingleVarDef(MxParser::SingleVarDefContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitClassDef(MxParser::ClassDefContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitClassBody(MxParser::ClassBodyContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFuncDef(MxParser::FuncDefContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitArgListDef(MxParser::ArgListDefContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitArgList(MxParser::ArgListContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitConstructFuncDef(MxParser::ConstructFuncDefContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTypeName(MxParser::TypeNameContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitBasicType(MxParser::BasicTypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitStmtBlock(MxParser::StmtBlockContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitExpression(MxParser::ExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAssignExpr(MxParser::AssignExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitOrOrExpr(MxParser::OrOrExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAndAndExpr(MxParser::AndAndExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitOrExpr(MxParser::OrExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitXorExpr(MxParser::XorExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAndExpr(MxParser::AndExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitEqualityExpr(MxParser::EqualityExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitRelationExpr(MxParser::RelationExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitShiftExpr(MxParser::ShiftExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAddExpr(MxParser::AddExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitMultiExpr(MxParser::MultiExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitUnaryExpr(MxParser::UnaryExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitPostfixExpr(MxParser::PostfixExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitPrimaryExpr(MxParser::PrimaryExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitLambdaExpr(MxParser::LambdaExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitNewExpr(MxParser::NewExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitNewArrayExpr(MxParser::NewArrayExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitNewObjExpr(MxParser::NewObjExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitArrayIndex(MxParser::ArrayIndexContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitArraySize(MxParser::ArraySizeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitEqualOp(MxParser::EqualOpContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitRelationOp(MxParser::RelationOpContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitShiftOp(MxParser::ShiftOpContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAddOp(MxParser::AddOpContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitMultiOp(MxParser::MultiOpContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitPrefixUnaryOp(MxParser::PrefixUnaryOpContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSuffixUnaryOp(MxParser::SuffixUnaryOpContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitLiteral(MxParser::LiteralContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFuncStmt(MxParser::FuncStmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitIfStmt(MxParser::IfStmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitElseStmt(MxParser::ElseStmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitWhileStmt(MxParser::WhileStmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitForStmt(MxParser::ForStmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitMemberStmt(MxParser::MemberStmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitLeftValue(MxParser::LeftValueContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitCondition(MxParser::ConditionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitForCondition(MxParser::ForConditionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitBlock(MxParser::BlockContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitReturnStmt(MxParser::ReturnStmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitBreakStmt(MxParser::BreakStmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitContinueStmt(MxParser::ContinueStmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitExprStmt(MxParser::ExprStmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitBlankStmt(MxParser::BlankStmtContext *ctx) override {
    return visitChildren(ctx);
  }


};

