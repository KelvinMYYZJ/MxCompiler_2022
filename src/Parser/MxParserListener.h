
// Generated from MxParser.g4 by ANTLR 4.11.1

#pragma once


#include "antlr4-runtime.h"
#include "MxParser.h"


/**
 * This interface defines an abstract listener for a parse tree produced by MxParser.
 */
class  MxParserListener : public antlr4::tree::ParseTreeListener {
public:

  virtual void enterProg(MxParser::ProgContext *ctx) = 0;
  virtual void exitProg(MxParser::ProgContext *ctx) = 0;

  virtual void enterDefinition(MxParser::DefinitionContext *ctx) = 0;
  virtual void exitDefinition(MxParser::DefinitionContext *ctx) = 0;

  virtual void enterVarDef(MxParser::VarDefContext *ctx) = 0;
  virtual void exitVarDef(MxParser::VarDefContext *ctx) = 0;

  virtual void enterClassDef(MxParser::ClassDefContext *ctx) = 0;
  virtual void exitClassDef(MxParser::ClassDefContext *ctx) = 0;

  virtual void enterClassBody(MxParser::ClassBodyContext *ctx) = 0;
  virtual void exitClassBody(MxParser::ClassBodyContext *ctx) = 0;

  virtual void enterFuncDef(MxParser::FuncDefContext *ctx) = 0;
  virtual void exitFuncDef(MxParser::FuncDefContext *ctx) = 0;

  virtual void enterArgListDef(MxParser::ArgListDefContext *ctx) = 0;
  virtual void exitArgListDef(MxParser::ArgListDefContext *ctx) = 0;

  virtual void enterArgList(MxParser::ArgListContext *ctx) = 0;
  virtual void exitArgList(MxParser::ArgListContext *ctx) = 0;

  virtual void enterConstructFuncDef(MxParser::ConstructFuncDefContext *ctx) = 0;
  virtual void exitConstructFuncDef(MxParser::ConstructFuncDefContext *ctx) = 0;

  virtual void enterTypeName(MxParser::TypeNameContext *ctx) = 0;
  virtual void exitTypeName(MxParser::TypeNameContext *ctx) = 0;

  virtual void enterBasicType(MxParser::BasicTypeContext *ctx) = 0;
  virtual void exitBasicType(MxParser::BasicTypeContext *ctx) = 0;

  virtual void enterFuncBody(MxParser::FuncBodyContext *ctx) = 0;
  virtual void exitFuncBody(MxParser::FuncBodyContext *ctx) = 0;

  virtual void enterExpression(MxParser::ExpressionContext *ctx) = 0;
  virtual void exitExpression(MxParser::ExpressionContext *ctx) = 0;

  virtual void enterAssignExpr(MxParser::AssignExprContext *ctx) = 0;
  virtual void exitAssignExpr(MxParser::AssignExprContext *ctx) = 0;

  virtual void enterOrOrExpr(MxParser::OrOrExprContext *ctx) = 0;
  virtual void exitOrOrExpr(MxParser::OrOrExprContext *ctx) = 0;

  virtual void enterAndAndExpr(MxParser::AndAndExprContext *ctx) = 0;
  virtual void exitAndAndExpr(MxParser::AndAndExprContext *ctx) = 0;

  virtual void enterOrExpr(MxParser::OrExprContext *ctx) = 0;
  virtual void exitOrExpr(MxParser::OrExprContext *ctx) = 0;

  virtual void enterXorExpr(MxParser::XorExprContext *ctx) = 0;
  virtual void exitXorExpr(MxParser::XorExprContext *ctx) = 0;

  virtual void enterAndExpr(MxParser::AndExprContext *ctx) = 0;
  virtual void exitAndExpr(MxParser::AndExprContext *ctx) = 0;

  virtual void enterEqualityExpr(MxParser::EqualityExprContext *ctx) = 0;
  virtual void exitEqualityExpr(MxParser::EqualityExprContext *ctx) = 0;

  virtual void enterRelationExpr(MxParser::RelationExprContext *ctx) = 0;
  virtual void exitRelationExpr(MxParser::RelationExprContext *ctx) = 0;

  virtual void enterShiftExpr(MxParser::ShiftExprContext *ctx) = 0;
  virtual void exitShiftExpr(MxParser::ShiftExprContext *ctx) = 0;

  virtual void enterAddExpr(MxParser::AddExprContext *ctx) = 0;
  virtual void exitAddExpr(MxParser::AddExprContext *ctx) = 0;

  virtual void enterMultiExpr(MxParser::MultiExprContext *ctx) = 0;
  virtual void exitMultiExpr(MxParser::MultiExprContext *ctx) = 0;

  virtual void enterUnaryExpr(MxParser::UnaryExprContext *ctx) = 0;
  virtual void exitUnaryExpr(MxParser::UnaryExprContext *ctx) = 0;

  virtual void enterPostfixExpr(MxParser::PostfixExprContext *ctx) = 0;
  virtual void exitPostfixExpr(MxParser::PostfixExprContext *ctx) = 0;

  virtual void enterPrimaryExpr(MxParser::PrimaryExprContext *ctx) = 0;
  virtual void exitPrimaryExpr(MxParser::PrimaryExprContext *ctx) = 0;

  virtual void enterLambdaExpr(MxParser::LambdaExprContext *ctx) = 0;
  virtual void exitLambdaExpr(MxParser::LambdaExprContext *ctx) = 0;

  virtual void enterNewExpr(MxParser::NewExprContext *ctx) = 0;
  virtual void exitNewExpr(MxParser::NewExprContext *ctx) = 0;

  virtual void enterNewArrayExpr(MxParser::NewArrayExprContext *ctx) = 0;
  virtual void exitNewArrayExpr(MxParser::NewArrayExprContext *ctx) = 0;

  virtual void enterNewObjExpr(MxParser::NewObjExprContext *ctx) = 0;
  virtual void exitNewObjExpr(MxParser::NewObjExprContext *ctx) = 0;

  virtual void enterArrayIndex(MxParser::ArrayIndexContext *ctx) = 0;
  virtual void exitArrayIndex(MxParser::ArrayIndexContext *ctx) = 0;

  virtual void enterArraySize(MxParser::ArraySizeContext *ctx) = 0;
  virtual void exitArraySize(MxParser::ArraySizeContext *ctx) = 0;

  virtual void enterEqualOp(MxParser::EqualOpContext *ctx) = 0;
  virtual void exitEqualOp(MxParser::EqualOpContext *ctx) = 0;

  virtual void enterRelationOp(MxParser::RelationOpContext *ctx) = 0;
  virtual void exitRelationOp(MxParser::RelationOpContext *ctx) = 0;

  virtual void enterShiftOp(MxParser::ShiftOpContext *ctx) = 0;
  virtual void exitShiftOp(MxParser::ShiftOpContext *ctx) = 0;

  virtual void enterAddOp(MxParser::AddOpContext *ctx) = 0;
  virtual void exitAddOp(MxParser::AddOpContext *ctx) = 0;

  virtual void enterMultiOp(MxParser::MultiOpContext *ctx) = 0;
  virtual void exitMultiOp(MxParser::MultiOpContext *ctx) = 0;

  virtual void enterPrefixUnaryOp(MxParser::PrefixUnaryOpContext *ctx) = 0;
  virtual void exitPrefixUnaryOp(MxParser::PrefixUnaryOpContext *ctx) = 0;

  virtual void enterSuffixUnaryOp(MxParser::SuffixUnaryOpContext *ctx) = 0;
  virtual void exitSuffixUnaryOp(MxParser::SuffixUnaryOpContext *ctx) = 0;

  virtual void enterLiteral(MxParser::LiteralContext *ctx) = 0;
  virtual void exitLiteral(MxParser::LiteralContext *ctx) = 0;

  virtual void enterFuncStmt(MxParser::FuncStmtContext *ctx) = 0;
  virtual void exitFuncStmt(MxParser::FuncStmtContext *ctx) = 0;

  virtual void enterIfStmt(MxParser::IfStmtContext *ctx) = 0;
  virtual void exitIfStmt(MxParser::IfStmtContext *ctx) = 0;

  virtual void enterElseStmt(MxParser::ElseStmtContext *ctx) = 0;
  virtual void exitElseStmt(MxParser::ElseStmtContext *ctx) = 0;

  virtual void enterWhileStmt(MxParser::WhileStmtContext *ctx) = 0;
  virtual void exitWhileStmt(MxParser::WhileStmtContext *ctx) = 0;

  virtual void enterForStmt(MxParser::ForStmtContext *ctx) = 0;
  virtual void exitForStmt(MxParser::ForStmtContext *ctx) = 0;

  virtual void enterMemberStmt(MxParser::MemberStmtContext *ctx) = 0;
  virtual void exitMemberStmt(MxParser::MemberStmtContext *ctx) = 0;

  virtual void enterLeftValue(MxParser::LeftValueContext *ctx) = 0;
  virtual void exitLeftValue(MxParser::LeftValueContext *ctx) = 0;

  virtual void enterCondition(MxParser::ConditionContext *ctx) = 0;
  virtual void exitCondition(MxParser::ConditionContext *ctx) = 0;

  virtual void enterForCondition(MxParser::ForConditionContext *ctx) = 0;
  virtual void exitForCondition(MxParser::ForConditionContext *ctx) = 0;

  virtual void enterBlock(MxParser::BlockContext *ctx) = 0;
  virtual void exitBlock(MxParser::BlockContext *ctx) = 0;

  virtual void enterMultiStmtBlock(MxParser::MultiStmtBlockContext *ctx) = 0;
  virtual void exitMultiStmtBlock(MxParser::MultiStmtBlockContext *ctx) = 0;

  virtual void enterReturnStmt(MxParser::ReturnStmtContext *ctx) = 0;
  virtual void exitReturnStmt(MxParser::ReturnStmtContext *ctx) = 0;

  virtual void enterBreakStmt(MxParser::BreakStmtContext *ctx) = 0;
  virtual void exitBreakStmt(MxParser::BreakStmtContext *ctx) = 0;

  virtual void enterContinueStmt(MxParser::ContinueStmtContext *ctx) = 0;
  virtual void exitContinueStmt(MxParser::ContinueStmtContext *ctx) = 0;

  virtual void enterExprStmt(MxParser::ExprStmtContext *ctx) = 0;
  virtual void exitExprStmt(MxParser::ExprStmtContext *ctx) = 0;

  virtual void enterBlankStmt(MxParser::BlankStmtContext *ctx) = 0;
  virtual void exitBlankStmt(MxParser::BlankStmtContext *ctx) = 0;


};

