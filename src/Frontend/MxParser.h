
// Generated from MxParser.g4 by ANTLR 4.11.1

#pragma once


#include "antlr4-runtime.h"




class  MxParser : public antlr4::Parser {
public:
  enum {
    Void = 1, Bool = 2, Int = 3, String = 4, New = 5, Class = 6, True = 7, 
    False = 8, This = 9, If = 10, Else = 11, For = 12, While = 13, Break = 14, 
    Continue = 15, Return = 16, Plus = 17, Minus = 18, Star = 19, Div = 20, 
    Mod = 21, Greater = 22, Less = 23, GreaterEqual = 24, LessEqual = 25, 
    NotEqual = 26, Equal = 27, AndAnd = 28, OrOr = 29, Not = 30, RightShift = 31, 
    LeftShift = 32, And = 33, Or = 34, Caret = 35, Tilde = 36, Assign = 37, 
    PlusPlus = 38, MinusMinus = 39, Dot = 40, LeftBracket = 41, RightBracket = 42, 
    LeftParen = 43, RightParen = 44, Comma = 45, Semi = 46, LeftBrace = 47, 
    RightBrace = 48, LineComment = 49, BlockComment = 50, Space = 51, Tab = 52, 
    Eol = 53, Comment = 54, Identifier = 55, IntLiteral = 56, StringLiteral = 57, 
    NullLiteral = 58
  };

  enum {
    RuleProg = 0, RuleDefinition = 1, RuleVarDef = 2, RuleClassDef = 3, 
    RuleClassBody = 4, RuleFuncDef = 5, RuleArgListDef = 6, RuleArgList = 7, 
    RuleConstructFuncDef = 8, RuleTypeName = 9, RuleBasicType = 10, RuleFuncBody = 11, 
    RuleExpression = 12, RuleAssignExpr = 13, RuleOrOrExpr = 14, RuleAndAndExpr = 15, 
    RuleOrExpr = 16, RuleXorExpr = 17, RuleAndExpr = 18, RuleEqualityExpr = 19, 
    RuleRelationExpr = 20, RuleShiftExpr = 21, RuleAddExpr = 22, RuleMultiExpr = 23, 
    RuleUnaryExpr = 24, RulePostfixExpr = 25, RulePrimaryExpr = 26, RuleNewExpr = 27, 
    RuleNewArrayExpr = 28, RuleNewObjExpr = 29, RuleArrayIndex = 30, RuleEqualOp = 31, 
    RuleRelationOp = 32, RuleShiftOp = 33, RuleAddOp = 34, RuleMultiOp = 35, 
    RulePrefixUnaryOp = 36, RuleSuffixUnaryOp = 37, RuleLiteral = 38, RuleFuncStmt = 39, 
    RuleIfStmt = 40, RuleElseStmt = 41, RuleWhileStmt = 42, RuleForStmt = 43, 
    RuleMemberStmt = 44, RuleLeftValue = 45, RuleCondition = 46, RuleForCondition = 47, 
    RuleBlock = 48, RuleMultiStmtBlock = 49, RuleReturnStmt = 50, RuleBreakStmt = 51, 
    RuleContinueStmt = 52, RuleExprStmt = 53, RuleBlankStmt = 54
  };

  explicit MxParser(antlr4::TokenStream *input);

  MxParser(antlr4::TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options);

  ~MxParser() override;

  std::string getGrammarFileName() const override;

  const antlr4::atn::ATN& getATN() const override;

  const std::vector<std::string>& getRuleNames() const override;

  const antlr4::dfa::Vocabulary& getVocabulary() const override;

  antlr4::atn::SerializedATNView getSerializedATN() const override;


  class ProgContext;
  class DefinitionContext;
  class VarDefContext;
  class ClassDefContext;
  class ClassBodyContext;
  class FuncDefContext;
  class ArgListDefContext;
  class ArgListContext;
  class ConstructFuncDefContext;
  class TypeNameContext;
  class BasicTypeContext;
  class FuncBodyContext;
  class ExpressionContext;
  class AssignExprContext;
  class OrOrExprContext;
  class AndAndExprContext;
  class OrExprContext;
  class XorExprContext;
  class AndExprContext;
  class EqualityExprContext;
  class RelationExprContext;
  class ShiftExprContext;
  class AddExprContext;
  class MultiExprContext;
  class UnaryExprContext;
  class PostfixExprContext;
  class PrimaryExprContext;
  class NewExprContext;
  class NewArrayExprContext;
  class NewObjExprContext;
  class ArrayIndexContext;
  class EqualOpContext;
  class RelationOpContext;
  class ShiftOpContext;
  class AddOpContext;
  class MultiOpContext;
  class PrefixUnaryOpContext;
  class SuffixUnaryOpContext;
  class LiteralContext;
  class FuncStmtContext;
  class IfStmtContext;
  class ElseStmtContext;
  class WhileStmtContext;
  class ForStmtContext;
  class MemberStmtContext;
  class LeftValueContext;
  class ConditionContext;
  class ForConditionContext;
  class BlockContext;
  class MultiStmtBlockContext;
  class ReturnStmtContext;
  class BreakStmtContext;
  class ContinueStmtContext;
  class ExprStmtContext;
  class BlankStmtContext; 

  class  ProgContext : public antlr4::ParserRuleContext {
  public:
    ProgContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *EOF();
    std::vector<DefinitionContext *> definition();
    DefinitionContext* definition(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  ProgContext* prog();

  class  DefinitionContext : public antlr4::ParserRuleContext {
  public:
    DefinitionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    FuncDefContext *funcDef();
    VarDefContext *varDef();
    ClassDefContext *classDef();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  DefinitionContext* definition();

  class  VarDefContext : public antlr4::ParserRuleContext {
  public:
    VarDefContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    TypeNameContext *typeName();
    std::vector<antlr4::tree::TerminalNode *> Identifier();
    antlr4::tree::TerminalNode* Identifier(size_t i);
    antlr4::tree::TerminalNode *Semi();
    std::vector<antlr4::tree::TerminalNode *> Assign();
    antlr4::tree::TerminalNode* Assign(size_t i);
    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);
    std::vector<antlr4::tree::TerminalNode *> Comma();
    antlr4::tree::TerminalNode* Comma(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  VarDefContext* varDef();

  class  ClassDefContext : public antlr4::ParserRuleContext {
  public:
    ClassDefContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *Class();
    antlr4::tree::TerminalNode *Identifier();
    ClassBodyContext *classBody();
    antlr4::tree::TerminalNode *Semi();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  ClassDefContext* classDef();

  class  ClassBodyContext : public antlr4::ParserRuleContext {
  public:
    ClassBodyContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LeftBrace();
    antlr4::tree::TerminalNode *RightBrace();
    std::vector<MemberStmtContext *> memberStmt();
    MemberStmtContext* memberStmt(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  ClassBodyContext* classBody();

  class  FuncDefContext : public antlr4::ParserRuleContext {
  public:
    FuncDefContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    TypeNameContext *typeName();
    antlr4::tree::TerminalNode *Identifier();
    ArgListDefContext *argListDef();
    FuncBodyContext *funcBody();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  FuncDefContext* funcDef();

  class  ArgListDefContext : public antlr4::ParserRuleContext {
  public:
    ArgListDefContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LeftParen();
    antlr4::tree::TerminalNode *RightParen();
    std::vector<TypeNameContext *> typeName();
    TypeNameContext* typeName(size_t i);
    std::vector<antlr4::tree::TerminalNode *> Identifier();
    antlr4::tree::TerminalNode* Identifier(size_t i);
    std::vector<antlr4::tree::TerminalNode *> Comma();
    antlr4::tree::TerminalNode* Comma(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  ArgListDefContext* argListDef();

  class  ArgListContext : public antlr4::ParserRuleContext {
  public:
    ArgListContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LeftParen();
    antlr4::tree::TerminalNode *RightParen();
    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);
    std::vector<antlr4::tree::TerminalNode *> Comma();
    antlr4::tree::TerminalNode* Comma(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  ArgListContext* argList();

  class  ConstructFuncDefContext : public antlr4::ParserRuleContext {
  public:
    ConstructFuncDefContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *Identifier();
    antlr4::tree::TerminalNode *LeftParen();
    antlr4::tree::TerminalNode *RightParen();
    FuncBodyContext *funcBody();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  ConstructFuncDefContext* constructFuncDef();

  class  TypeNameContext : public antlr4::ParserRuleContext {
  public:
    TypeNameContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    BasicTypeContext *basicType();
    std::vector<antlr4::tree::TerminalNode *> LeftBracket();
    antlr4::tree::TerminalNode* LeftBracket(size_t i);
    std::vector<antlr4::tree::TerminalNode *> RightBracket();
    antlr4::tree::TerminalNode* RightBracket(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  TypeNameContext* typeName();

  class  BasicTypeContext : public antlr4::ParserRuleContext {
  public:
    BasicTypeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *Int();
    antlr4::tree::TerminalNode *Bool();
    antlr4::tree::TerminalNode *String();
    antlr4::tree::TerminalNode *Void();
    antlr4::tree::TerminalNode *Identifier();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  BasicTypeContext* basicType();

  class  FuncBodyContext : public antlr4::ParserRuleContext {
  public:
    FuncBodyContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LeftBrace();
    antlr4::tree::TerminalNode *RightBrace();
    std::vector<FuncStmtContext *> funcStmt();
    FuncStmtContext* funcStmt(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  FuncBodyContext* funcBody();

  class  ExpressionContext : public antlr4::ParserRuleContext {
  public:
    ExpressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    AssignExprContext *assignExpr();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  ExpressionContext* expression();

  class  AssignExprContext : public antlr4::ParserRuleContext {
  public:
    AssignExprContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<OrOrExprContext *> orOrExpr();
    OrOrExprContext* orOrExpr(size_t i);
    antlr4::tree::TerminalNode *Assign();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  AssignExprContext* assignExpr();

  class  OrOrExprContext : public antlr4::ParserRuleContext {
  public:
    OrOrExprContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<AndAndExprContext *> andAndExpr();
    AndAndExprContext* andAndExpr(size_t i);
    std::vector<antlr4::tree::TerminalNode *> OrOr();
    antlr4::tree::TerminalNode* OrOr(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  OrOrExprContext* orOrExpr();

  class  AndAndExprContext : public antlr4::ParserRuleContext {
  public:
    AndAndExprContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<OrExprContext *> orExpr();
    OrExprContext* orExpr(size_t i);
    std::vector<antlr4::tree::TerminalNode *> AndAnd();
    antlr4::tree::TerminalNode* AndAnd(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  AndAndExprContext* andAndExpr();

  class  OrExprContext : public antlr4::ParserRuleContext {
  public:
    OrExprContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<XorExprContext *> xorExpr();
    XorExprContext* xorExpr(size_t i);
    std::vector<antlr4::tree::TerminalNode *> Or();
    antlr4::tree::TerminalNode* Or(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  OrExprContext* orExpr();

  class  XorExprContext : public antlr4::ParserRuleContext {
  public:
    XorExprContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<AndExprContext *> andExpr();
    AndExprContext* andExpr(size_t i);
    std::vector<antlr4::tree::TerminalNode *> Caret();
    antlr4::tree::TerminalNode* Caret(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  XorExprContext* xorExpr();

  class  AndExprContext : public antlr4::ParserRuleContext {
  public:
    AndExprContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<EqualityExprContext *> equalityExpr();
    EqualityExprContext* equalityExpr(size_t i);
    std::vector<antlr4::tree::TerminalNode *> And();
    antlr4::tree::TerminalNode* And(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  AndExprContext* andExpr();

  class  EqualityExprContext : public antlr4::ParserRuleContext {
  public:
    EqualityExprContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<RelationExprContext *> relationExpr();
    RelationExprContext* relationExpr(size_t i);
    std::vector<EqualOpContext *> equalOp();
    EqualOpContext* equalOp(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  EqualityExprContext* equalityExpr();

  class  RelationExprContext : public antlr4::ParserRuleContext {
  public:
    RelationExprContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<ShiftExprContext *> shiftExpr();
    ShiftExprContext* shiftExpr(size_t i);
    std::vector<RelationOpContext *> relationOp();
    RelationOpContext* relationOp(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  RelationExprContext* relationExpr();

  class  ShiftExprContext : public antlr4::ParserRuleContext {
  public:
    ShiftExprContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<AddExprContext *> addExpr();
    AddExprContext* addExpr(size_t i);
    std::vector<ShiftOpContext *> shiftOp();
    ShiftOpContext* shiftOp(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  ShiftExprContext* shiftExpr();

  class  AddExprContext : public antlr4::ParserRuleContext {
  public:
    AddExprContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<MultiExprContext *> multiExpr();
    MultiExprContext* multiExpr(size_t i);
    std::vector<AddOpContext *> addOp();
    AddOpContext* addOp(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  AddExprContext* addExpr();

  class  MultiExprContext : public antlr4::ParserRuleContext {
  public:
    MultiExprContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<UnaryExprContext *> unaryExpr();
    UnaryExprContext* unaryExpr(size_t i);
    std::vector<MultiOpContext *> multiOp();
    MultiOpContext* multiOp(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  MultiExprContext* multiExpr();

  class  UnaryExprContext : public antlr4::ParserRuleContext {
  public:
    UnaryExprContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    PostfixExprContext *postfixExpr();
    PrefixUnaryOpContext *prefixUnaryOp();
    UnaryExprContext *unaryExpr();
    NewExprContext *newExpr();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  UnaryExprContext* unaryExpr();

  class  PostfixExprContext : public antlr4::ParserRuleContext {
  public:
    PostfixExprContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    PrimaryExprContext *primaryExpr();
    PostfixExprContext *postfixExpr();
    ArrayIndexContext *arrayIndex();
    ArgListContext *argList();
    antlr4::tree::TerminalNode *Dot();
    antlr4::tree::TerminalNode *Identifier();
    SuffixUnaryOpContext *suffixUnaryOp();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  PostfixExprContext* postfixExpr();
  PostfixExprContext* postfixExpr(int precedence);
  class  PrimaryExprContext : public antlr4::ParserRuleContext {
  public:
    PrimaryExprContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    LiteralContext *literal();
    antlr4::tree::TerminalNode *This();
    antlr4::tree::TerminalNode *LeftParen();
    ExpressionContext *expression();
    antlr4::tree::TerminalNode *RightParen();
    antlr4::tree::TerminalNode *Identifier();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  PrimaryExprContext* primaryExpr();

  class  NewExprContext : public antlr4::ParserRuleContext {
  public:
    NewExprContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    NewArrayExprContext *newArrayExpr();
    NewObjExprContext *newObjExpr();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  NewExprContext* newExpr();

  class  NewArrayExprContext : public antlr4::ParserRuleContext {
  public:
    NewArrayExprContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *New();
    BasicTypeContext *basicType();
    std::vector<ArrayIndexContext *> arrayIndex();
    ArrayIndexContext* arrayIndex(size_t i);
    std::vector<antlr4::tree::TerminalNode *> LeftBracket();
    antlr4::tree::TerminalNode* LeftBracket(size_t i);
    std::vector<antlr4::tree::TerminalNode *> RightBracket();
    antlr4::tree::TerminalNode* RightBracket(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  NewArrayExprContext* newArrayExpr();

  class  NewObjExprContext : public antlr4::ParserRuleContext {
  public:
    NewObjExprContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *New();
    BasicTypeContext *basicType();
    antlr4::tree::TerminalNode *LeftParen();
    antlr4::tree::TerminalNode *RightParen();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  NewObjExprContext* newObjExpr();

  class  ArrayIndexContext : public antlr4::ParserRuleContext {
  public:
    ArrayIndexContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LeftBracket();
    ExpressionContext *expression();
    antlr4::tree::TerminalNode *RightBracket();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  ArrayIndexContext* arrayIndex();

  class  EqualOpContext : public antlr4::ParserRuleContext {
  public:
    EqualOpContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *Equal();
    antlr4::tree::TerminalNode *NotEqual();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  EqualOpContext* equalOp();

  class  RelationOpContext : public antlr4::ParserRuleContext {
  public:
    RelationOpContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *Less();
    antlr4::tree::TerminalNode *Greater();
    antlr4::tree::TerminalNode *LessEqual();
    antlr4::tree::TerminalNode *GreaterEqual();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  RelationOpContext* relationOp();

  class  ShiftOpContext : public antlr4::ParserRuleContext {
  public:
    ShiftOpContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LeftShift();
    antlr4::tree::TerminalNode *RightShift();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  ShiftOpContext* shiftOp();

  class  AddOpContext : public antlr4::ParserRuleContext {
  public:
    AddOpContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *Plus();
    antlr4::tree::TerminalNode *Minus();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  AddOpContext* addOp();

  class  MultiOpContext : public antlr4::ParserRuleContext {
  public:
    MultiOpContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *Star();
    antlr4::tree::TerminalNode *Div();
    antlr4::tree::TerminalNode *Mod();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  MultiOpContext* multiOp();

  class  PrefixUnaryOpContext : public antlr4::ParserRuleContext {
  public:
    PrefixUnaryOpContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *PlusPlus();
    antlr4::tree::TerminalNode *MinusMinus();
    antlr4::tree::TerminalNode *Not();
    antlr4::tree::TerminalNode *Tilde();
    antlr4::tree::TerminalNode *Minus();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  PrefixUnaryOpContext* prefixUnaryOp();

  class  SuffixUnaryOpContext : public antlr4::ParserRuleContext {
  public:
    SuffixUnaryOpContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *PlusPlus();
    antlr4::tree::TerminalNode *MinusMinus();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  SuffixUnaryOpContext* suffixUnaryOp();

  class  LiteralContext : public antlr4::ParserRuleContext {
  public:
    LiteralContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *IntLiteral();
    antlr4::tree::TerminalNode *True();
    antlr4::tree::TerminalNode *False();
    antlr4::tree::TerminalNode *NullLiteral();
    antlr4::tree::TerminalNode *StringLiteral();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  LiteralContext* literal();

  class  FuncStmtContext : public antlr4::ParserRuleContext {
  public:
    FuncStmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    VarDefContext *varDef();
    IfStmtContext *ifStmt();
    WhileStmtContext *whileStmt();
    ForStmtContext *forStmt();
    ReturnStmtContext *returnStmt();
    BreakStmtContext *breakStmt();
    ContinueStmtContext *continueStmt();
    ExprStmtContext *exprStmt();
    MultiStmtBlockContext *multiStmtBlock();
    BlankStmtContext *blankStmt();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  FuncStmtContext* funcStmt();

  class  IfStmtContext : public antlr4::ParserRuleContext {
  public:
    IfStmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *If();
    ConditionContext *condition();
    BlockContext *block();
    ElseStmtContext *elseStmt();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  IfStmtContext* ifStmt();

  class  ElseStmtContext : public antlr4::ParserRuleContext {
  public:
    ElseStmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *Else();
    BlockContext *block();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  ElseStmtContext* elseStmt();

  class  WhileStmtContext : public antlr4::ParserRuleContext {
  public:
    WhileStmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *While();
    ConditionContext *condition();
    BlockContext *block();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  WhileStmtContext* whileStmt();

  class  ForStmtContext : public antlr4::ParserRuleContext {
  public:
    ForStmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *For();
    ForConditionContext *forCondition();
    BlockContext *block();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  ForStmtContext* forStmt();

  class  MemberStmtContext : public antlr4::ParserRuleContext {
  public:
    MemberStmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    VarDefContext *varDef();
    ConstructFuncDefContext *constructFuncDef();
    FuncDefContext *funcDef();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  MemberStmtContext* memberStmt();

  class  LeftValueContext : public antlr4::ParserRuleContext {
  public:
    LeftValueContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *Identifier();
    LeftValueContext *leftValue();
    ArrayIndexContext *arrayIndex();
    antlr4::tree::TerminalNode *Dot();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  LeftValueContext* leftValue();
  LeftValueContext* leftValue(int precedence);
  class  ConditionContext : public antlr4::ParserRuleContext {
  public:
    ConditionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LeftParen();
    ExpressionContext *expression();
    antlr4::tree::TerminalNode *RightParen();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  ConditionContext* condition();

  class  ForConditionContext : public antlr4::ParserRuleContext {
  public:
    ForConditionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LeftParen();
    std::vector<antlr4::tree::TerminalNode *> Semi();
    antlr4::tree::TerminalNode* Semi(size_t i);
    antlr4::tree::TerminalNode *RightParen();
    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  ForConditionContext* forCondition();

  class  BlockContext : public antlr4::ParserRuleContext {
  public:
    BlockContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    MultiStmtBlockContext *multiStmtBlock();
    FuncStmtContext *funcStmt();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  BlockContext* block();

  class  MultiStmtBlockContext : public antlr4::ParserRuleContext {
  public:
    MultiStmtBlockContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LeftBrace();
    antlr4::tree::TerminalNode *RightBrace();
    std::vector<FuncStmtContext *> funcStmt();
    FuncStmtContext* funcStmt(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  MultiStmtBlockContext* multiStmtBlock();

  class  ReturnStmtContext : public antlr4::ParserRuleContext {
  public:
    ReturnStmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *Return();
    antlr4::tree::TerminalNode *Semi();
    ExpressionContext *expression();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  ReturnStmtContext* returnStmt();

  class  BreakStmtContext : public antlr4::ParserRuleContext {
  public:
    BreakStmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *Break();
    antlr4::tree::TerminalNode *Semi();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  BreakStmtContext* breakStmt();

  class  ContinueStmtContext : public antlr4::ParserRuleContext {
  public:
    ContinueStmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *Continue();
    antlr4::tree::TerminalNode *Semi();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  ContinueStmtContext* continueStmt();

  class  ExprStmtContext : public antlr4::ParserRuleContext {
  public:
    ExprStmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ExpressionContext *expression();
    antlr4::tree::TerminalNode *Semi();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  ExprStmtContext* exprStmt();

  class  BlankStmtContext : public antlr4::ParserRuleContext {
  public:
    BlankStmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *Semi();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  BlankStmtContext* blankStmt();


  bool sempred(antlr4::RuleContext *_localctx, size_t ruleIndex, size_t predicateIndex) override;

  bool postfixExprSempred(PostfixExprContext *_localctx, size_t predicateIndex);
  bool leftValueSempred(LeftValueContext *_localctx, size_t predicateIndex);

  // By default the static state used to implement the parser is lazily initialized during the first
  // call to the constructor. You can call this function if you wish to initialize the static state
  // ahead of time.
  static void initialize();

private:
};

