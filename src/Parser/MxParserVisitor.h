
// Generated from MxParser.g4 by ANTLR 4.11.1

#pragma once


#include "antlr4-runtime.h"
#include "MxParser.h"



/**
 * This class defines an abstract visitor for a parse tree
 * produced by MxParser.
 */
class  MxParserVisitor : public antlr4::tree::AbstractParseTreeVisitor {
public:

  /**
   * Visit parse trees produced by MxParser.
   */
    virtual std::any visitProg(MxParser::ProgContext *context) = 0;

    virtual std::any visitDefinition(MxParser::DefinitionContext *context) = 0;

    virtual std::any visitVarDef(MxParser::VarDefContext *context) = 0;

    virtual std::any visitClassDef(MxParser::ClassDefContext *context) = 0;

    virtual std::any visitClassBody(MxParser::ClassBodyContext *context) = 0;

    virtual std::any visitFuncDef(MxParser::FuncDefContext *context) = 0;

    virtual std::any visitArgListDef(MxParser::ArgListDefContext *context) = 0;

    virtual std::any visitArgList(MxParser::ArgListContext *context) = 0;

    virtual std::any visitConstructFuncDef(MxParser::ConstructFuncDefContext *context) = 0;

    virtual std::any visitTypeName(MxParser::TypeNameContext *context) = 0;

    virtual std::any visitBasicType(MxParser::BasicTypeContext *context) = 0;

    virtual std::any visitFuncBody(MxParser::FuncBodyContext *context) = 0;

    virtual std::any visitExpression(MxParser::ExpressionContext *context) = 0;

    virtual std::any visitAssignExpr(MxParser::AssignExprContext *context) = 0;

    virtual std::any visitOrOrExpr(MxParser::OrOrExprContext *context) = 0;

    virtual std::any visitAndAndExpr(MxParser::AndAndExprContext *context) = 0;

    virtual std::any visitOrExpr(MxParser::OrExprContext *context) = 0;

    virtual std::any visitXorExpr(MxParser::XorExprContext *context) = 0;

    virtual std::any visitAndExpr(MxParser::AndExprContext *context) = 0;

    virtual std::any visitEqualityExpr(MxParser::EqualityExprContext *context) = 0;

    virtual std::any visitRelationExpr(MxParser::RelationExprContext *context) = 0;

    virtual std::any visitShiftExpr(MxParser::ShiftExprContext *context) = 0;

    virtual std::any visitAddExpr(MxParser::AddExprContext *context) = 0;

    virtual std::any visitMultiExpr(MxParser::MultiExprContext *context) = 0;

    virtual std::any visitUnaryExpr(MxParser::UnaryExprContext *context) = 0;

    virtual std::any visitPostfixExpr(MxParser::PostfixExprContext *context) = 0;

    virtual std::any visitPrimaryExpr(MxParser::PrimaryExprContext *context) = 0;

    virtual std::any visitLambdaExpr(MxParser::LambdaExprContext *context) = 0;

    virtual std::any visitNewExpr(MxParser::NewExprContext *context) = 0;

    virtual std::any visitNewArrayExpr(MxParser::NewArrayExprContext *context) = 0;

    virtual std::any visitNewObjExpr(MxParser::NewObjExprContext *context) = 0;

    virtual std::any visitArrayIndex(MxParser::ArrayIndexContext *context) = 0;

    virtual std::any visitEqualOp(MxParser::EqualOpContext *context) = 0;

    virtual std::any visitRelationOp(MxParser::RelationOpContext *context) = 0;

    virtual std::any visitShiftOp(MxParser::ShiftOpContext *context) = 0;

    virtual std::any visitAddOp(MxParser::AddOpContext *context) = 0;

    virtual std::any visitMultiOp(MxParser::MultiOpContext *context) = 0;

    virtual std::any visitPrefixUnaryOp(MxParser::PrefixUnaryOpContext *context) = 0;

    virtual std::any visitSuffixUnaryOp(MxParser::SuffixUnaryOpContext *context) = 0;

    virtual std::any visitLiteral(MxParser::LiteralContext *context) = 0;

    virtual std::any visitFuncStmt(MxParser::FuncStmtContext *context) = 0;

    virtual std::any visitIfStmt(MxParser::IfStmtContext *context) = 0;

    virtual std::any visitElseStmt(MxParser::ElseStmtContext *context) = 0;

    virtual std::any visitWhileStmt(MxParser::WhileStmtContext *context) = 0;

    virtual std::any visitForStmt(MxParser::ForStmtContext *context) = 0;

    virtual std::any visitMemberStmt(MxParser::MemberStmtContext *context) = 0;

    virtual std::any visitLeftValue(MxParser::LeftValueContext *context) = 0;

    virtual std::any visitCondition(MxParser::ConditionContext *context) = 0;

    virtual std::any visitForCondition(MxParser::ForConditionContext *context) = 0;

    virtual std::any visitBlock(MxParser::BlockContext *context) = 0;

    virtual std::any visitMultiStmtBlock(MxParser::MultiStmtBlockContext *context) = 0;

    virtual std::any visitReturnStmt(MxParser::ReturnStmtContext *context) = 0;

    virtual std::any visitBreakStmt(MxParser::BreakStmtContext *context) = 0;

    virtual std::any visitContinueStmt(MxParser::ContinueStmtContext *context) = 0;

    virtual std::any visitExprStmt(MxParser::ExprStmtContext *context) = 0;

    virtual std::any visitBlankStmt(MxParser::BlankStmtContext *context) = 0;


};

