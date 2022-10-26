
// Generated from MxLexer.g4 by ANTLR 4.11.1

#pragma once


#include "antlr4-runtime.h"




class  MxLexer : public antlr4::Lexer {
public:
  enum {
    Void = 1, Bool = 2, Int = 3, String = 4, New = 5, Class = 6, NullLiteral = 7, 
    True = 8, False = 9, This = 10, If = 11, Else = 12, For = 13, While = 14, 
    Break = 15, Continue = 16, Return = 17, Plus = 18, Minus = 19, Star = 20, 
    Div = 21, Mod = 22, Greater = 23, Less = 24, GreaterEqual = 25, LessEqual = 26, 
    NotEqual = 27, Equal = 28, AndAnd = 29, OrOr = 30, Not = 31, RightShift = 32, 
    LeftShift = 33, And = 34, Or = 35, Caret = 36, Tilde = 37, Assign = 38, 
    PlusPlus = 39, MinusMinus = 40, Dot = 41, Arrow = 42, LeftBracket = 43, 
    RightBracket = 44, LeftParen = 45, RightParen = 46, Comma = 47, Semi = 48, 
    LeftBrace = 49, RightBrace = 50, LineComment = 51, BlockComment = 52, 
    Space = 53, Tab = 54, Eol = 55, Comment = 56, Identifier = 57, IntLiteral = 58, 
    StringLiteral = 59
  };

  explicit MxLexer(antlr4::CharStream *input);

  ~MxLexer() override;


  std::string getGrammarFileName() const override;

  const std::vector<std::string>& getRuleNames() const override;

  const std::vector<std::string>& getChannelNames() const override;

  const std::vector<std::string>& getModeNames() const override;

  const antlr4::dfa::Vocabulary& getVocabulary() const override;

  antlr4::atn::SerializedATNView getSerializedATN() const override;

  const antlr4::atn::ATN& getATN() const override;

  // By default the static state used to implement the lexer is lazily initialized during the first
  // call to the constructor. You can call this function if you wish to initialize the static state
  // ahead of time.
  static void initialize();

private:

  // Individual action functions triggered by action() above.

  // Individual semantic predicate functions triggered by sempred() above.

};

