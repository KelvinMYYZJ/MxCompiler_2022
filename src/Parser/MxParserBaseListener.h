
// Generated from MxParser.g4 by ANTLR 4.11.1

#pragma once


#include "antlr4-runtime.h"
#include "MxParserListener.h"


/**
 * This class provides an empty implementation of MxParserListener,
 * which can be extended to create a listener which only needs to handle a subset
 * of the available methods.
 */
class  MxParserBaseListener : public MxParserListener {
public:

  virtual void enterProg(MxParser::ProgContext * /*ctx*/) override { }
  virtual void exitProg(MxParser::ProgContext * /*ctx*/) override { }

  virtual void enterDefinition(MxParser::DefinitionContext * /*ctx*/) override { }
  virtual void exitDefinition(MxParser::DefinitionContext * /*ctx*/) override { }

  virtual void enterVarDef(MxParser::VarDefContext * /*ctx*/) override { }
  virtual void exitVarDef(MxParser::VarDefContext * /*ctx*/) override { }

  virtual void enterClassDef(MxParser::ClassDefContext * /*ctx*/) override { }
  virtual void exitClassDef(MxParser::ClassDefContext * /*ctx*/) override { }

  virtual void enterClassBody(MxParser::ClassBodyContext * /*ctx*/) override { }
  virtual void exitClassBody(MxParser::ClassBodyContext * /*ctx*/) override { }

  virtual void enterFuncDef(MxParser::FuncDefContext * /*ctx*/) override { }
  virtual void exitFuncDef(MxParser::FuncDefContext * /*ctx*/) override { }

  virtual void enterArgListDef(MxParser::ArgListDefContext * /*ctx*/) override { }
  virtual void exitArgListDef(MxParser::ArgListDefContext * /*ctx*/) override { }

  virtual void enterArgList(MxParser::ArgListContext * /*ctx*/) override { }
  virtual void exitArgList(MxParser::ArgListContext * /*ctx*/) override { }

  virtual void enterConstructFuncDef(MxParser::ConstructFuncDefContext * /*ctx*/) override { }
  virtual void exitConstructFuncDef(MxParser::ConstructFuncDefContext * /*ctx*/) override { }

  virtual void enterTypeName(MxParser::TypeNameContext * /*ctx*/) override { }
  virtual void exitTypeName(MxParser::TypeNameContext * /*ctx*/) override { }

  virtual void enterBasicType(MxParser::BasicTypeContext * /*ctx*/) override { }
  virtual void exitBasicType(MxParser::BasicTypeContext * /*ctx*/) override { }

  virtual void enterFuncBody(MxParser::FuncBodyContext * /*ctx*/) override { }
  virtual void exitFuncBody(MxParser::FuncBodyContext * /*ctx*/) override { }

  virtual void enterExpression(MxParser::ExpressionContext * /*ctx*/) override { }
  virtual void exitExpression(MxParser::ExpressionContext * /*ctx*/) override { }

  virtual void enterAssignExpr(MxParser::AssignExprContext * /*ctx*/) override { }
  virtual void exitAssignExpr(MxParser::AssignExprContext * /*ctx*/) override { }

  virtual void enterOrOrExpr(MxParser::OrOrExprContext * /*ctx*/) override { }
  virtual void exitOrOrExpr(MxParser::OrOrExprContext * /*ctx*/) override { }

  virtual void enterAndAndExpr(MxParser::AndAndExprContext * /*ctx*/) override { }
  virtual void exitAndAndExpr(MxParser::AndAndExprContext * /*ctx*/) override { }

  virtual void enterOrExpr(MxParser::OrExprContext * /*ctx*/) override { }
  virtual void exitOrExpr(MxParser::OrExprContext * /*ctx*/) override { }

  virtual void enterXorExpr(MxParser::XorExprContext * /*ctx*/) override { }
  virtual void exitXorExpr(MxParser::XorExprContext * /*ctx*/) override { }

  virtual void enterAndExpr(MxParser::AndExprContext * /*ctx*/) override { }
  virtual void exitAndExpr(MxParser::AndExprContext * /*ctx*/) override { }

  virtual void enterEqualityExpr(MxParser::EqualityExprContext * /*ctx*/) override { }
  virtual void exitEqualityExpr(MxParser::EqualityExprContext * /*ctx*/) override { }

  virtual void enterRelationExpr(MxParser::RelationExprContext * /*ctx*/) override { }
  virtual void exitRelationExpr(MxParser::RelationExprContext * /*ctx*/) override { }

  virtual void enterShiftExpr(MxParser::ShiftExprContext * /*ctx*/) override { }
  virtual void exitShiftExpr(MxParser::ShiftExprContext * /*ctx*/) override { }

  virtual void enterAddExpr(MxParser::AddExprContext * /*ctx*/) override { }
  virtual void exitAddExpr(MxParser::AddExprContext * /*ctx*/) override { }

  virtual void enterMultiExpr(MxParser::MultiExprContext * /*ctx*/) override { }
  virtual void exitMultiExpr(MxParser::MultiExprContext * /*ctx*/) override { }

  virtual void enterUnaryExpr(MxParser::UnaryExprContext * /*ctx*/) override { }
  virtual void exitUnaryExpr(MxParser::UnaryExprContext * /*ctx*/) override { }

  virtual void enterPostfixExpr(MxParser::PostfixExprContext * /*ctx*/) override { }
  virtual void exitPostfixExpr(MxParser::PostfixExprContext * /*ctx*/) override { }

  virtual void enterPrimaryExpr(MxParser::PrimaryExprContext * /*ctx*/) override { }
  virtual void exitPrimaryExpr(MxParser::PrimaryExprContext * /*ctx*/) override { }

  virtual void enterLambdaExpr(MxParser::LambdaExprContext * /*ctx*/) override { }
  virtual void exitLambdaExpr(MxParser::LambdaExprContext * /*ctx*/) override { }

  virtual void enterNewExpr(MxParser::NewExprContext * /*ctx*/) override { }
  virtual void exitNewExpr(MxParser::NewExprContext * /*ctx*/) override { }

  virtual void enterNewArrayExpr(MxParser::NewArrayExprContext * /*ctx*/) override { }
  virtual void exitNewArrayExpr(MxParser::NewArrayExprContext * /*ctx*/) override { }

  virtual void enterNewObjExpr(MxParser::NewObjExprContext * /*ctx*/) override { }
  virtual void exitNewObjExpr(MxParser::NewObjExprContext * /*ctx*/) override { }

  virtual void enterArrayIndex(MxParser::ArrayIndexContext * /*ctx*/) override { }
  virtual void exitArrayIndex(MxParser::ArrayIndexContext * /*ctx*/) override { }

  virtual void enterArraySize(MxParser::ArraySizeContext * /*ctx*/) override { }
  virtual void exitArraySize(MxParser::ArraySizeContext * /*ctx*/) override { }

  virtual void enterEqualOp(MxParser::EqualOpContext * /*ctx*/) override { }
  virtual void exitEqualOp(MxParser::EqualOpContext * /*ctx*/) override { }

  virtual void enterRelationOp(MxParser::RelationOpContext * /*ctx*/) override { }
  virtual void exitRelationOp(MxParser::RelationOpContext * /*ctx*/) override { }

  virtual void enterShiftOp(MxParser::ShiftOpContext * /*ctx*/) override { }
  virtual void exitShiftOp(MxParser::ShiftOpContext * /*ctx*/) override { }

  virtual void enterAddOp(MxParser::AddOpContext * /*ctx*/) override { }
  virtual void exitAddOp(MxParser::AddOpContext * /*ctx*/) override { }

  virtual void enterMultiOp(MxParser::MultiOpContext * /*ctx*/) override { }
  virtual void exitMultiOp(MxParser::MultiOpContext * /*ctx*/) override { }

  virtual void enterPrefixUnaryOp(MxParser::PrefixUnaryOpContext * /*ctx*/) override { }
  virtual void exitPrefixUnaryOp(MxParser::PrefixUnaryOpContext * /*ctx*/) override { }

  virtual void enterSuffixUnaryOp(MxParser::SuffixUnaryOpContext * /*ctx*/) override { }
  virtual void exitSuffixUnaryOp(MxParser::SuffixUnaryOpContext * /*ctx*/) override { }

  virtual void enterLiteral(MxParser::LiteralContext * /*ctx*/) override { }
  virtual void exitLiteral(MxParser::LiteralContext * /*ctx*/) override { }

  virtual void enterFuncStmt(MxParser::FuncStmtContext * /*ctx*/) override { }
  virtual void exitFuncStmt(MxParser::FuncStmtContext * /*ctx*/) override { }

  virtual void enterIfStmt(MxParser::IfStmtContext * /*ctx*/) override { }
  virtual void exitIfStmt(MxParser::IfStmtContext * /*ctx*/) override { }

  virtual void enterElseStmt(MxParser::ElseStmtContext * /*ctx*/) override { }
  virtual void exitElseStmt(MxParser::ElseStmtContext * /*ctx*/) override { }

  virtual void enterWhileStmt(MxParser::WhileStmtContext * /*ctx*/) override { }
  virtual void exitWhileStmt(MxParser::WhileStmtContext * /*ctx*/) override { }

  virtual void enterForStmt(MxParser::ForStmtContext * /*ctx*/) override { }
  virtual void exitForStmt(MxParser::ForStmtContext * /*ctx*/) override { }

  virtual void enterMemberStmt(MxParser::MemberStmtContext * /*ctx*/) override { }
  virtual void exitMemberStmt(MxParser::MemberStmtContext * /*ctx*/) override { }

  virtual void enterLeftValue(MxParser::LeftValueContext * /*ctx*/) override { }
  virtual void exitLeftValue(MxParser::LeftValueContext * /*ctx*/) override { }

  virtual void enterCondition(MxParser::ConditionContext * /*ctx*/) override { }
  virtual void exitCondition(MxParser::ConditionContext * /*ctx*/) override { }

  virtual void enterForCondition(MxParser::ForConditionContext * /*ctx*/) override { }
  virtual void exitForCondition(MxParser::ForConditionContext * /*ctx*/) override { }

  virtual void enterBlock(MxParser::BlockContext * /*ctx*/) override { }
  virtual void exitBlock(MxParser::BlockContext * /*ctx*/) override { }

  virtual void enterMultiStmtBlock(MxParser::MultiStmtBlockContext * /*ctx*/) override { }
  virtual void exitMultiStmtBlock(MxParser::MultiStmtBlockContext * /*ctx*/) override { }

  virtual void enterReturnStmt(MxParser::ReturnStmtContext * /*ctx*/) override { }
  virtual void exitReturnStmt(MxParser::ReturnStmtContext * /*ctx*/) override { }

  virtual void enterBreakStmt(MxParser::BreakStmtContext * /*ctx*/) override { }
  virtual void exitBreakStmt(MxParser::BreakStmtContext * /*ctx*/) override { }

  virtual void enterContinueStmt(MxParser::ContinueStmtContext * /*ctx*/) override { }
  virtual void exitContinueStmt(MxParser::ContinueStmtContext * /*ctx*/) override { }

  virtual void enterExprStmt(MxParser::ExprStmtContext * /*ctx*/) override { }
  virtual void exitExprStmt(MxParser::ExprStmtContext * /*ctx*/) override { }

  virtual void enterBlankStmt(MxParser::BlankStmtContext * /*ctx*/) override { }
  virtual void exitBlankStmt(MxParser::BlankStmtContext * /*ctx*/) override { }


  virtual void enterEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void exitEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void visitTerminal(antlr4::tree::TerminalNode * /*node*/) override { }
  virtual void visitErrorNode(antlr4::tree::ErrorNode * /*node*/) override { }

};

