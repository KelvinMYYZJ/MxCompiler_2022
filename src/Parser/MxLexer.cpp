
// Generated from MxLexer.g4 by ANTLR 4.11.1


#include "MxLexer.h"


using namespace antlr4;



using namespace antlr4;

namespace {

struct MxLexerStaticData final {
  MxLexerStaticData(std::vector<std::string> ruleNames,
                          std::vector<std::string> channelNames,
                          std::vector<std::string> modeNames,
                          std::vector<std::string> literalNames,
                          std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), channelNames(std::move(channelNames)),
        modeNames(std::move(modeNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  MxLexerStaticData(const MxLexerStaticData&) = delete;
  MxLexerStaticData(MxLexerStaticData&&) = delete;
  MxLexerStaticData& operator=(const MxLexerStaticData&) = delete;
  MxLexerStaticData& operator=(MxLexerStaticData&&) = delete;

  std::vector<antlr4::dfa::DFA> decisionToDFA;
  antlr4::atn::PredictionContextCache sharedContextCache;
  const std::vector<std::string> ruleNames;
  const std::vector<std::string> channelNames;
  const std::vector<std::string> modeNames;
  const std::vector<std::string> literalNames;
  const std::vector<std::string> symbolicNames;
  const antlr4::dfa::Vocabulary vocabulary;
  antlr4::atn::SerializedATNView serializedATN;
  std::unique_ptr<antlr4::atn::ATN> atn;
};

::antlr4::internal::OnceFlag mxlexerLexerOnceFlag;
MxLexerStaticData *mxlexerLexerStaticData = nullptr;

void mxlexerLexerInitialize() {
  assert(mxlexerLexerStaticData == nullptr);
  auto staticData = std::make_unique<MxLexerStaticData>(
    std::vector<std::string>{
      "Void", "Bool", "Int", "String", "New", "Class", "Null", "True", "False", 
      "This", "If", "Else", "For", "While", "Break", "Continue", "Return", 
      "Plus", "Minus", "Star", "Div", "Mod", "Greater", "Less", "GreaterEqual", 
      "LessEqual", "NotEqual", "Equal", "AndAnd", "OrOr", "Not", "RightShift", 
      "LeftShift", "And", "Or", "Caret", "Tilde", "Assign", "PlusPlus", 
      "MinusMinus", "Dot", "Arrow", "LeftBracket", "RightBracket", "LeftParen", 
      "RightParen", "Comma", "Semi", "LeftBrace", "RightBrace", "LineComment", 
      "BlockComment", "Space", "Tab", "Eol", "Comment", "Quotation", "Alphabet", 
      "Digit", "NonZeroDigit", "Underline", "IdentifierChars", "Identifier", 
      "IntLiteral", "Escapesequence", "Schar", "StringLiteral", "NullLiteral"
    },
    std::vector<std::string>{
      "DEFAULT_TOKEN_CHANNEL", "HIDDEN"
    },
    std::vector<std::string>{
      "DEFAULT_MODE"
    },
    std::vector<std::string>{
      "", "'void'", "'bool'", "'int'", "'string'", "'new'", "'class'", "'true'", 
      "'false'", "'this'", "'if'", "'else'", "'for'", "'while'", "'break'", 
      "'continue'", "'return'", "'+'", "'-'", "'*'", "'/'", "'%'", "'>'", 
      "'<'", "'>='", "'<='", "'!='", "'=='", "'&&'", "'||'", "'!'", "'>>'", 
      "'<<'", "'&'", "'|'", "'^'", "'~'", "'='", "'++'", "'--'", "'.'", 
      "'->'", "'['", "']'", "'('", "')'", "','", "';'", "'{'", "'}'", "", 
      "", "' '", "'\\t'", "'\\n'", "'//'"
    },
    std::vector<std::string>{
      "", "Void", "Bool", "Int", "String", "New", "Class", "True", "False", 
      "This", "If", "Else", "For", "While", "Break", "Continue", "Return", 
      "Plus", "Minus", "Star", "Div", "Mod", "Greater", "Less", "GreaterEqual", 
      "LessEqual", "NotEqual", "Equal", "AndAnd", "OrOr", "Not", "RightShift", 
      "LeftShift", "And", "Or", "Caret", "Tilde", "Assign", "PlusPlus", 
      "MinusMinus", "Dot", "Arrow", "LeftBracket", "RightBracket", "LeftParen", 
      "RightParen", "Comma", "Semi", "LeftBrace", "RightBrace", "LineComment", 
      "BlockComment", "Space", "Tab", "Eol", "Comment", "Identifier", "IntLiteral", 
      "StringLiteral", "NullLiteral"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,0,59,399,6,-1,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,
  	6,2,7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,
  	7,14,2,15,7,15,2,16,7,16,2,17,7,17,2,18,7,18,2,19,7,19,2,20,7,20,2,21,
  	7,21,2,22,7,22,2,23,7,23,2,24,7,24,2,25,7,25,2,26,7,26,2,27,7,27,2,28,
  	7,28,2,29,7,29,2,30,7,30,2,31,7,31,2,32,7,32,2,33,7,33,2,34,7,34,2,35,
  	7,35,2,36,7,36,2,37,7,37,2,38,7,38,2,39,7,39,2,40,7,40,2,41,7,41,2,42,
  	7,42,2,43,7,43,2,44,7,44,2,45,7,45,2,46,7,46,2,47,7,47,2,48,7,48,2,49,
  	7,49,2,50,7,50,2,51,7,51,2,52,7,52,2,53,7,53,2,54,7,54,2,55,7,55,2,56,
  	7,56,2,57,7,57,2,58,7,58,2,59,7,59,2,60,7,60,2,61,7,61,2,62,7,62,2,63,
  	7,63,2,64,7,64,2,65,7,65,2,66,7,66,2,67,7,67,1,0,1,0,1,0,1,0,1,0,1,1,
  	1,1,1,1,1,1,1,1,1,2,1,2,1,2,1,2,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,4,1,4,1,
  	4,1,4,1,5,1,5,1,5,1,5,1,5,1,5,1,6,1,6,1,6,1,6,1,6,1,7,1,7,1,7,1,7,1,7,
  	1,8,1,8,1,8,1,8,1,8,1,8,1,9,1,9,1,9,1,9,1,9,1,10,1,10,1,10,1,11,1,11,
  	1,11,1,11,1,11,1,12,1,12,1,12,1,12,1,13,1,13,1,13,1,13,1,13,1,13,1,14,
  	1,14,1,14,1,14,1,14,1,14,1,15,1,15,1,15,1,15,1,15,1,15,1,15,1,15,1,15,
  	1,16,1,16,1,16,1,16,1,16,1,16,1,16,1,17,1,17,1,18,1,18,1,19,1,19,1,20,
  	1,20,1,21,1,21,1,22,1,22,1,23,1,23,1,24,1,24,1,24,1,25,1,25,1,25,1,26,
  	1,26,1,26,1,27,1,27,1,27,1,28,1,28,1,28,1,29,1,29,1,29,1,30,1,30,1,31,
  	1,31,1,31,1,32,1,32,1,32,1,33,1,33,1,34,1,34,1,35,1,35,1,36,1,36,1,37,
  	1,37,1,38,1,38,1,38,1,39,1,39,1,39,1,40,1,40,1,41,1,41,1,41,1,42,1,42,
  	1,43,1,43,1,44,1,44,1,45,1,45,1,46,1,46,1,47,1,47,1,48,1,48,1,49,1,49,
  	1,50,1,50,5,50,309,8,50,10,50,12,50,312,9,50,1,50,1,50,1,51,1,51,1,51,
  	1,51,5,51,320,8,51,10,51,12,51,323,9,51,1,51,1,51,1,51,1,51,1,51,1,52,
  	1,52,1,52,1,52,1,53,1,53,1,53,1,53,1,54,1,54,1,54,1,54,1,55,1,55,1,55,
  	1,56,1,56,1,57,1,57,1,58,1,58,1,59,1,59,1,60,1,60,1,61,1,61,1,61,3,61,
  	358,8,61,1,62,1,62,5,62,362,8,62,10,62,12,62,365,9,62,1,63,1,63,1,63,
  	5,63,370,8,63,10,63,12,63,373,9,63,3,63,375,8,63,1,64,1,64,1,64,1,64,
  	1,64,1,64,3,64,383,8,64,1,65,1,65,3,65,387,8,65,1,66,1,66,5,66,391,8,
  	66,10,66,12,66,394,9,66,1,66,1,66,1,67,1,67,1,321,0,68,1,1,3,2,5,3,7,
  	4,9,5,11,6,13,0,15,7,17,8,19,9,21,10,23,11,25,12,27,13,29,14,31,15,33,
  	16,35,17,37,18,39,19,41,20,43,21,45,22,47,23,49,24,51,25,53,26,55,27,
  	57,28,59,29,61,30,63,31,65,32,67,33,69,34,71,35,73,36,75,37,77,38,79,
  	39,81,40,83,41,85,42,87,43,89,44,91,45,93,46,95,47,97,48,99,49,101,50,
  	103,51,105,52,107,53,109,54,111,55,113,0,115,0,117,0,119,0,121,0,123,
  	0,125,56,127,57,129,0,131,0,133,58,135,59,1,0,5,1,0,10,10,2,0,65,90,97,
  	122,1,0,48,57,1,0,49,57,4,0,10,10,13,13,34,34,92,92,400,0,1,1,0,0,0,0,
  	3,1,0,0,0,0,5,1,0,0,0,0,7,1,0,0,0,0,9,1,0,0,0,0,11,1,0,0,0,0,15,1,0,0,
  	0,0,17,1,0,0,0,0,19,1,0,0,0,0,21,1,0,0,0,0,23,1,0,0,0,0,25,1,0,0,0,0,
  	27,1,0,0,0,0,29,1,0,0,0,0,31,1,0,0,0,0,33,1,0,0,0,0,35,1,0,0,0,0,37,1,
  	0,0,0,0,39,1,0,0,0,0,41,1,0,0,0,0,43,1,0,0,0,0,45,1,0,0,0,0,47,1,0,0,
  	0,0,49,1,0,0,0,0,51,1,0,0,0,0,53,1,0,0,0,0,55,1,0,0,0,0,57,1,0,0,0,0,
  	59,1,0,0,0,0,61,1,0,0,0,0,63,1,0,0,0,0,65,1,0,0,0,0,67,1,0,0,0,0,69,1,
  	0,0,0,0,71,1,0,0,0,0,73,1,0,0,0,0,75,1,0,0,0,0,77,1,0,0,0,0,79,1,0,0,
  	0,0,81,1,0,0,0,0,83,1,0,0,0,0,85,1,0,0,0,0,87,1,0,0,0,0,89,1,0,0,0,0,
  	91,1,0,0,0,0,93,1,0,0,0,0,95,1,0,0,0,0,97,1,0,0,0,0,99,1,0,0,0,0,101,
  	1,0,0,0,0,103,1,0,0,0,0,105,1,0,0,0,0,107,1,0,0,0,0,109,1,0,0,0,0,111,
  	1,0,0,0,0,125,1,0,0,0,0,127,1,0,0,0,0,133,1,0,0,0,0,135,1,0,0,0,1,137,
  	1,0,0,0,3,142,1,0,0,0,5,147,1,0,0,0,7,151,1,0,0,0,9,158,1,0,0,0,11,162,
  	1,0,0,0,13,168,1,0,0,0,15,173,1,0,0,0,17,178,1,0,0,0,19,184,1,0,0,0,21,
  	189,1,0,0,0,23,192,1,0,0,0,25,197,1,0,0,0,27,201,1,0,0,0,29,207,1,0,0,
  	0,31,213,1,0,0,0,33,222,1,0,0,0,35,229,1,0,0,0,37,231,1,0,0,0,39,233,
  	1,0,0,0,41,235,1,0,0,0,43,237,1,0,0,0,45,239,1,0,0,0,47,241,1,0,0,0,49,
  	243,1,0,0,0,51,246,1,0,0,0,53,249,1,0,0,0,55,252,1,0,0,0,57,255,1,0,0,
  	0,59,258,1,0,0,0,61,261,1,0,0,0,63,263,1,0,0,0,65,266,1,0,0,0,67,269,
  	1,0,0,0,69,271,1,0,0,0,71,273,1,0,0,0,73,275,1,0,0,0,75,277,1,0,0,0,77,
  	279,1,0,0,0,79,282,1,0,0,0,81,285,1,0,0,0,83,287,1,0,0,0,85,290,1,0,0,
  	0,87,292,1,0,0,0,89,294,1,0,0,0,91,296,1,0,0,0,93,298,1,0,0,0,95,300,
  	1,0,0,0,97,302,1,0,0,0,99,304,1,0,0,0,101,306,1,0,0,0,103,315,1,0,0,0,
  	105,329,1,0,0,0,107,333,1,0,0,0,109,337,1,0,0,0,111,341,1,0,0,0,113,344,
  	1,0,0,0,115,346,1,0,0,0,117,348,1,0,0,0,119,350,1,0,0,0,121,352,1,0,0,
  	0,123,357,1,0,0,0,125,359,1,0,0,0,127,374,1,0,0,0,129,382,1,0,0,0,131,
  	386,1,0,0,0,133,388,1,0,0,0,135,397,1,0,0,0,137,138,5,118,0,0,138,139,
  	5,111,0,0,139,140,5,105,0,0,140,141,5,100,0,0,141,2,1,0,0,0,142,143,5,
  	98,0,0,143,144,5,111,0,0,144,145,5,111,0,0,145,146,5,108,0,0,146,4,1,
  	0,0,0,147,148,5,105,0,0,148,149,5,110,0,0,149,150,5,116,0,0,150,6,1,0,
  	0,0,151,152,5,115,0,0,152,153,5,116,0,0,153,154,5,114,0,0,154,155,5,105,
  	0,0,155,156,5,110,0,0,156,157,5,103,0,0,157,8,1,0,0,0,158,159,5,110,0,
  	0,159,160,5,101,0,0,160,161,5,119,0,0,161,10,1,0,0,0,162,163,5,99,0,0,
  	163,164,5,108,0,0,164,165,5,97,0,0,165,166,5,115,0,0,166,167,5,115,0,
  	0,167,12,1,0,0,0,168,169,5,110,0,0,169,170,5,117,0,0,170,171,5,108,0,
  	0,171,172,5,108,0,0,172,14,1,0,0,0,173,174,5,116,0,0,174,175,5,114,0,
  	0,175,176,5,117,0,0,176,177,5,101,0,0,177,16,1,0,0,0,178,179,5,102,0,
  	0,179,180,5,97,0,0,180,181,5,108,0,0,181,182,5,115,0,0,182,183,5,101,
  	0,0,183,18,1,0,0,0,184,185,5,116,0,0,185,186,5,104,0,0,186,187,5,105,
  	0,0,187,188,5,115,0,0,188,20,1,0,0,0,189,190,5,105,0,0,190,191,5,102,
  	0,0,191,22,1,0,0,0,192,193,5,101,0,0,193,194,5,108,0,0,194,195,5,115,
  	0,0,195,196,5,101,0,0,196,24,1,0,0,0,197,198,5,102,0,0,198,199,5,111,
  	0,0,199,200,5,114,0,0,200,26,1,0,0,0,201,202,5,119,0,0,202,203,5,104,
  	0,0,203,204,5,105,0,0,204,205,5,108,0,0,205,206,5,101,0,0,206,28,1,0,
  	0,0,207,208,5,98,0,0,208,209,5,114,0,0,209,210,5,101,0,0,210,211,5,97,
  	0,0,211,212,5,107,0,0,212,30,1,0,0,0,213,214,5,99,0,0,214,215,5,111,0,
  	0,215,216,5,110,0,0,216,217,5,116,0,0,217,218,5,105,0,0,218,219,5,110,
  	0,0,219,220,5,117,0,0,220,221,5,101,0,0,221,32,1,0,0,0,222,223,5,114,
  	0,0,223,224,5,101,0,0,224,225,5,116,0,0,225,226,5,117,0,0,226,227,5,114,
  	0,0,227,228,5,110,0,0,228,34,1,0,0,0,229,230,5,43,0,0,230,36,1,0,0,0,
  	231,232,5,45,0,0,232,38,1,0,0,0,233,234,5,42,0,0,234,40,1,0,0,0,235,236,
  	5,47,0,0,236,42,1,0,0,0,237,238,5,37,0,0,238,44,1,0,0,0,239,240,5,62,
  	0,0,240,46,1,0,0,0,241,242,5,60,0,0,242,48,1,0,0,0,243,244,5,62,0,0,244,
  	245,5,61,0,0,245,50,1,0,0,0,246,247,5,60,0,0,247,248,5,61,0,0,248,52,
  	1,0,0,0,249,250,5,33,0,0,250,251,5,61,0,0,251,54,1,0,0,0,252,253,5,61,
  	0,0,253,254,5,61,0,0,254,56,1,0,0,0,255,256,5,38,0,0,256,257,5,38,0,0,
  	257,58,1,0,0,0,258,259,5,124,0,0,259,260,5,124,0,0,260,60,1,0,0,0,261,
  	262,5,33,0,0,262,62,1,0,0,0,263,264,5,62,0,0,264,265,5,62,0,0,265,64,
  	1,0,0,0,266,267,5,60,0,0,267,268,5,60,0,0,268,66,1,0,0,0,269,270,5,38,
  	0,0,270,68,1,0,0,0,271,272,5,124,0,0,272,70,1,0,0,0,273,274,5,94,0,0,
  	274,72,1,0,0,0,275,276,5,126,0,0,276,74,1,0,0,0,277,278,5,61,0,0,278,
  	76,1,0,0,0,279,280,5,43,0,0,280,281,5,43,0,0,281,78,1,0,0,0,282,283,5,
  	45,0,0,283,284,5,45,0,0,284,80,1,0,0,0,285,286,5,46,0,0,286,82,1,0,0,
  	0,287,288,5,45,0,0,288,289,5,62,0,0,289,84,1,0,0,0,290,291,5,91,0,0,291,
  	86,1,0,0,0,292,293,5,93,0,0,293,88,1,0,0,0,294,295,5,40,0,0,295,90,1,
  	0,0,0,296,297,5,41,0,0,297,92,1,0,0,0,298,299,5,44,0,0,299,94,1,0,0,0,
  	300,301,5,59,0,0,301,96,1,0,0,0,302,303,5,123,0,0,303,98,1,0,0,0,304,
  	305,5,125,0,0,305,100,1,0,0,0,306,310,3,111,55,0,307,309,8,0,0,0,308,
  	307,1,0,0,0,309,312,1,0,0,0,310,308,1,0,0,0,310,311,1,0,0,0,311,313,1,
  	0,0,0,312,310,1,0,0,0,313,314,6,50,0,0,314,102,1,0,0,0,315,316,5,47,0,
  	0,316,317,5,42,0,0,317,321,1,0,0,0,318,320,9,0,0,0,319,318,1,0,0,0,320,
  	323,1,0,0,0,321,322,1,0,0,0,321,319,1,0,0,0,322,324,1,0,0,0,323,321,1,
  	0,0,0,324,325,5,42,0,0,325,326,5,47,0,0,326,327,1,0,0,0,327,328,6,51,
  	0,0,328,104,1,0,0,0,329,330,5,32,0,0,330,331,1,0,0,0,331,332,6,52,0,0,
  	332,106,1,0,0,0,333,334,5,9,0,0,334,335,1,0,0,0,335,336,6,53,0,0,336,
  	108,1,0,0,0,337,338,5,10,0,0,338,339,1,0,0,0,339,340,6,54,0,0,340,110,
  	1,0,0,0,341,342,5,47,0,0,342,343,5,47,0,0,343,112,1,0,0,0,344,345,5,34,
  	0,0,345,114,1,0,0,0,346,347,7,1,0,0,347,116,1,0,0,0,348,349,7,2,0,0,349,
  	118,1,0,0,0,350,351,7,3,0,0,351,120,1,0,0,0,352,353,5,95,0,0,353,122,
  	1,0,0,0,354,358,3,115,57,0,355,358,3,117,58,0,356,358,3,121,60,0,357,
  	354,1,0,0,0,357,355,1,0,0,0,357,356,1,0,0,0,358,124,1,0,0,0,359,363,3,
  	115,57,0,360,362,3,123,61,0,361,360,1,0,0,0,362,365,1,0,0,0,363,361,1,
  	0,0,0,363,364,1,0,0,0,364,126,1,0,0,0,365,363,1,0,0,0,366,375,5,48,0,
  	0,367,371,3,119,59,0,368,370,3,117,58,0,369,368,1,0,0,0,370,373,1,0,0,
  	0,371,369,1,0,0,0,371,372,1,0,0,0,372,375,1,0,0,0,373,371,1,0,0,0,374,
  	366,1,0,0,0,374,367,1,0,0,0,375,128,1,0,0,0,376,377,5,92,0,0,377,383,
  	5,110,0,0,378,379,5,92,0,0,379,383,5,34,0,0,380,381,5,92,0,0,381,383,
  	5,92,0,0,382,376,1,0,0,0,382,378,1,0,0,0,382,380,1,0,0,0,383,130,1,0,
  	0,0,384,387,8,4,0,0,385,387,3,129,64,0,386,384,1,0,0,0,386,385,1,0,0,
  	0,387,132,1,0,0,0,388,392,5,34,0,0,389,391,3,131,65,0,390,389,1,0,0,0,
  	391,394,1,0,0,0,392,390,1,0,0,0,392,393,1,0,0,0,393,395,1,0,0,0,394,392,
  	1,0,0,0,395,396,5,34,0,0,396,134,1,0,0,0,397,398,3,13,6,0,398,136,1,0,
  	0,0,10,0,310,321,357,363,371,374,382,386,392,1,6,0,0
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  mxlexerLexerStaticData = staticData.release();
}

}

MxLexer::MxLexer(CharStream *input) : Lexer(input) {
  MxLexer::initialize();
  _interpreter = new atn::LexerATNSimulator(this, *mxlexerLexerStaticData->atn, mxlexerLexerStaticData->decisionToDFA, mxlexerLexerStaticData->sharedContextCache);
}

MxLexer::~MxLexer() {
  delete _interpreter;
}

std::string MxLexer::getGrammarFileName() const {
  return "MxLexer.g4";
}

const std::vector<std::string>& MxLexer::getRuleNames() const {
  return mxlexerLexerStaticData->ruleNames;
}

const std::vector<std::string>& MxLexer::getChannelNames() const {
  return mxlexerLexerStaticData->channelNames;
}

const std::vector<std::string>& MxLexer::getModeNames() const {
  return mxlexerLexerStaticData->modeNames;
}

const dfa::Vocabulary& MxLexer::getVocabulary() const {
  return mxlexerLexerStaticData->vocabulary;
}

antlr4::atn::SerializedATNView MxLexer::getSerializedATN() const {
  return mxlexerLexerStaticData->serializedATN;
}

const atn::ATN& MxLexer::getATN() const {
  return *mxlexerLexerStaticData->atn;
}




void MxLexer::initialize() {
  ::antlr4::internal::call_once(mxlexerLexerOnceFlag, mxlexerLexerInitialize);
}