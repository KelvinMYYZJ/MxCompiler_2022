
// Generated from MxLexer.g4 by ANTLR 4.11.1

#pragma once


#include "antlr4-runtime.h"




class  MxLexer : public antlr4::Lexer {
public:
  enum {
    Void = 1, Bool = 2, Int = 3, String = 4, New = 5, Class = 6, True = 7, 
    False = 8, This = 9, If = 10, Else = 11, For = 12, While = 13, Break = 14, 
    Continue = 15, Return = 16, Plus = 17, Minus = 18, Star = 19, Div = 20, 
    Mod = 21, Greater = 22, Less = 23, GreaterEqual = 24, LessEqual = 25, 
    NotEqual = 26, Equal = 27, AndAnd = 28, OrOr = 29, Not = 30, RightShift = 31, 
    LeftShift = 32, And = 33, Or = 34, Caret = 35, Tilde = 36, Assign = 37, 
    PlusPlus = 38, MinusMinus = 39, Dot = 40, Arrow = 41, LeftBracket = 42, 
    RightBracket = 43, LeftParen = 44, RightParen = 45, Comma = 46, Semi = 47, 
    LeftBrace = 48, RightBrace = 49, LineComment = 50, BlockComment = 51, 
    Space = 52, Tab = 53, Eol = 54, Comment = 55, Identifier = 56, IntLiteral = 57, 
    StringLiteral = 58, NullLiteral = 59
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

