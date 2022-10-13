
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
      "MinusMinus", "Dot", "LeftBracket", "RightBracket", "LeftParen", "RightParen", 
      "Comma", "Semi", "LeftBrace", "RightBrace", "LineComment", "BlockComment", 
      "Space", "Tab", "Eol", "Comment", "Quotation", "Alphabet", "Digit", 
      "NonZeroDigit", "Underline", "IdentifierChars", "Identifier", "IntLiteral", 
      "Escapesequence", "Schar", "StringLiteral", "NullLiteral"
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
      "'['", "']'", "'('", "')'", "','", "';'", "'{'", "'}'", "", "", "' '", 
      "'\\t'", "'\\n'", "'//'"
    },
    std::vector<std::string>{
      "", "Void", "Bool", "Int", "String", "New", "Class", "True", "False", 
      "This", "If", "Else", "For", "While", "Break", "Continue", "Return", 
      "Plus", "Minus", "Star", "Div", "Mod", "Greater", "Less", "GreaterEqual", 
      "LessEqual", "NotEqual", "Equal", "AndAnd", "OrOr", "Not", "RightShift", 
      "LeftShift", "And", "Or", "Caret", "Tilde", "Assign", "PlusPlus", 
      "MinusMinus", "Dot", "LeftBracket", "RightBracket", "LeftParen", "RightParen", 
      "Comma", "Semi", "LeftBrace", "RightBrace", "LineComment", "BlockComment", 
      "Space", "Tab", "Eol", "Comment", "Identifier", "IntLiteral", "StringLiteral", 
      "NullLiteral"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,0,58,394,6,-1,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,
  	6,2,7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,
  	7,14,2,15,7,15,2,16,7,16,2,17,7,17,2,18,7,18,2,19,7,19,2,20,7,20,2,21,
  	7,21,2,22,7,22,2,23,7,23,2,24,7,24,2,25,7,25,2,26,7,26,2,27,7,27,2,28,
  	7,28,2,29,7,29,2,30,7,30,2,31,7,31,2,32,7,32,2,33,7,33,2,34,7,34,2,35,
  	7,35,2,36,7,36,2,37,7,37,2,38,7,38,2,39,7,39,2,40,7,40,2,41,7,41,2,42,
  	7,42,2,43,7,43,2,44,7,44,2,45,7,45,2,46,7,46,2,47,7,47,2,48,7,48,2,49,
  	7,49,2,50,7,50,2,51,7,51,2,52,7,52,2,53,7,53,2,54,7,54,2,55,7,55,2,56,
  	7,56,2,57,7,57,2,58,7,58,2,59,7,59,2,60,7,60,2,61,7,61,2,62,7,62,2,63,
  	7,63,2,64,7,64,2,65,7,65,2,66,7,66,1,0,1,0,1,0,1,0,1,0,1,1,1,1,1,1,1,
  	1,1,1,1,2,1,2,1,2,1,2,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,4,1,4,1,4,1,4,1,5,
  	1,5,1,5,1,5,1,5,1,5,1,6,1,6,1,6,1,6,1,6,1,7,1,7,1,7,1,7,1,7,1,8,1,8,1,
  	8,1,8,1,8,1,8,1,9,1,9,1,9,1,9,1,9,1,10,1,10,1,10,1,11,1,11,1,11,1,11,
  	1,11,1,12,1,12,1,12,1,12,1,13,1,13,1,13,1,13,1,13,1,13,1,14,1,14,1,14,
  	1,14,1,14,1,14,1,15,1,15,1,15,1,15,1,15,1,15,1,15,1,15,1,15,1,16,1,16,
  	1,16,1,16,1,16,1,16,1,16,1,17,1,17,1,18,1,18,1,19,1,19,1,20,1,20,1,21,
  	1,21,1,22,1,22,1,23,1,23,1,24,1,24,1,24,1,25,1,25,1,25,1,26,1,26,1,26,
  	1,27,1,27,1,27,1,28,1,28,1,28,1,29,1,29,1,29,1,30,1,30,1,31,1,31,1,31,
  	1,32,1,32,1,32,1,33,1,33,1,34,1,34,1,35,1,35,1,36,1,36,1,37,1,37,1,38,
  	1,38,1,38,1,39,1,39,1,39,1,40,1,40,1,41,1,41,1,42,1,42,1,43,1,43,1,44,
  	1,44,1,45,1,45,1,46,1,46,1,47,1,47,1,48,1,48,1,49,1,49,5,49,304,8,49,
  	10,49,12,49,307,9,49,1,49,1,49,1,50,1,50,1,50,1,50,5,50,315,8,50,10,50,
  	12,50,318,9,50,1,50,1,50,1,50,1,50,1,50,1,51,1,51,1,51,1,51,1,52,1,52,
  	1,52,1,52,1,53,1,53,1,53,1,53,1,54,1,54,1,54,1,55,1,55,1,56,1,56,1,57,
  	1,57,1,58,1,58,1,59,1,59,1,60,1,60,1,60,3,60,353,8,60,1,61,1,61,5,61,
  	357,8,61,10,61,12,61,360,9,61,1,62,1,62,1,62,5,62,365,8,62,10,62,12,62,
  	368,9,62,3,62,370,8,62,1,63,1,63,1,63,1,63,1,63,1,63,3,63,378,8,63,1,
  	64,1,64,3,64,382,8,64,1,65,1,65,5,65,386,8,65,10,65,12,65,389,9,65,1,
  	65,1,65,1,66,1,66,1,316,0,67,1,1,3,2,5,3,7,4,9,5,11,6,13,0,15,7,17,8,
  	19,9,21,10,23,11,25,12,27,13,29,14,31,15,33,16,35,17,37,18,39,19,41,20,
  	43,21,45,22,47,23,49,24,51,25,53,26,55,27,57,28,59,29,61,30,63,31,65,
  	32,67,33,69,34,71,35,73,36,75,37,77,38,79,39,81,40,83,41,85,42,87,43,
  	89,44,91,45,93,46,95,47,97,48,99,49,101,50,103,51,105,52,107,53,109,54,
  	111,0,113,0,115,0,117,0,119,0,121,0,123,55,125,56,127,0,129,0,131,57,
  	133,58,1,0,5,1,0,10,10,2,0,65,90,97,122,1,0,48,57,1,0,49,57,4,0,10,10,
  	13,13,34,34,92,92,395,0,1,1,0,0,0,0,3,1,0,0,0,0,5,1,0,0,0,0,7,1,0,0,0,
  	0,9,1,0,0,0,0,11,1,0,0,0,0,15,1,0,0,0,0,17,1,0,0,0,0,19,1,0,0,0,0,21,
  	1,0,0,0,0,23,1,0,0,0,0,25,1,0,0,0,0,27,1,0,0,0,0,29,1,0,0,0,0,31,1,0,
  	0,0,0,33,1,0,0,0,0,35,1,0,0,0,0,37,1,0,0,0,0,39,1,0,0,0,0,41,1,0,0,0,
  	0,43,1,0,0,0,0,45,1,0,0,0,0,47,1,0,0,0,0,49,1,0,0,0,0,51,1,0,0,0,0,53,
  	1,0,0,0,0,55,1,0,0,0,0,57,1,0,0,0,0,59,1,0,0,0,0,61,1,0,0,0,0,63,1,0,
  	0,0,0,65,1,0,0,0,0,67,1,0,0,0,0,69,1,0,0,0,0,71,1,0,0,0,0,73,1,0,0,0,
  	0,75,1,0,0,0,0,77,1,0,0,0,0,79,1,0,0,0,0,81,1,0,0,0,0,83,1,0,0,0,0,85,
  	1,0,0,0,0,87,1,0,0,0,0,89,1,0,0,0,0,91,1,0,0,0,0,93,1,0,0,0,0,95,1,0,
  	0,0,0,97,1,0,0,0,0,99,1,0,0,0,0,101,1,0,0,0,0,103,1,0,0,0,0,105,1,0,0,
  	0,0,107,1,0,0,0,0,109,1,0,0,0,0,123,1,0,0,0,0,125,1,0,0,0,0,131,1,0,0,
  	0,0,133,1,0,0,0,1,135,1,0,0,0,3,140,1,0,0,0,5,145,1,0,0,0,7,149,1,0,0,
  	0,9,156,1,0,0,0,11,160,1,0,0,0,13,166,1,0,0,0,15,171,1,0,0,0,17,176,1,
  	0,0,0,19,182,1,0,0,0,21,187,1,0,0,0,23,190,1,0,0,0,25,195,1,0,0,0,27,
  	199,1,0,0,0,29,205,1,0,0,0,31,211,1,0,0,0,33,220,1,0,0,0,35,227,1,0,0,
  	0,37,229,1,0,0,0,39,231,1,0,0,0,41,233,1,0,0,0,43,235,1,0,0,0,45,237,
  	1,0,0,0,47,239,1,0,0,0,49,241,1,0,0,0,51,244,1,0,0,0,53,247,1,0,0,0,55,
  	250,1,0,0,0,57,253,1,0,0,0,59,256,1,0,0,0,61,259,1,0,0,0,63,261,1,0,0,
  	0,65,264,1,0,0,0,67,267,1,0,0,0,69,269,1,0,0,0,71,271,1,0,0,0,73,273,
  	1,0,0,0,75,275,1,0,0,0,77,277,1,0,0,0,79,280,1,0,0,0,81,283,1,0,0,0,83,
  	285,1,0,0,0,85,287,1,0,0,0,87,289,1,0,0,0,89,291,1,0,0,0,91,293,1,0,0,
  	0,93,295,1,0,0,0,95,297,1,0,0,0,97,299,1,0,0,0,99,301,1,0,0,0,101,310,
  	1,0,0,0,103,324,1,0,0,0,105,328,1,0,0,0,107,332,1,0,0,0,109,336,1,0,0,
  	0,111,339,1,0,0,0,113,341,1,0,0,0,115,343,1,0,0,0,117,345,1,0,0,0,119,
  	347,1,0,0,0,121,352,1,0,0,0,123,354,1,0,0,0,125,369,1,0,0,0,127,377,1,
  	0,0,0,129,381,1,0,0,0,131,383,1,0,0,0,133,392,1,0,0,0,135,136,5,118,0,
  	0,136,137,5,111,0,0,137,138,5,105,0,0,138,139,5,100,0,0,139,2,1,0,0,0,
  	140,141,5,98,0,0,141,142,5,111,0,0,142,143,5,111,0,0,143,144,5,108,0,
  	0,144,4,1,0,0,0,145,146,5,105,0,0,146,147,5,110,0,0,147,148,5,116,0,0,
  	148,6,1,0,0,0,149,150,5,115,0,0,150,151,5,116,0,0,151,152,5,114,0,0,152,
  	153,5,105,0,0,153,154,5,110,0,0,154,155,5,103,0,0,155,8,1,0,0,0,156,157,
  	5,110,0,0,157,158,5,101,0,0,158,159,5,119,0,0,159,10,1,0,0,0,160,161,
  	5,99,0,0,161,162,5,108,0,0,162,163,5,97,0,0,163,164,5,115,0,0,164,165,
  	5,115,0,0,165,12,1,0,0,0,166,167,5,110,0,0,167,168,5,117,0,0,168,169,
  	5,108,0,0,169,170,5,108,0,0,170,14,1,0,0,0,171,172,5,116,0,0,172,173,
  	5,114,0,0,173,174,5,117,0,0,174,175,5,101,0,0,175,16,1,0,0,0,176,177,
  	5,102,0,0,177,178,5,97,0,0,178,179,5,108,0,0,179,180,5,115,0,0,180,181,
  	5,101,0,0,181,18,1,0,0,0,182,183,5,116,0,0,183,184,5,104,0,0,184,185,
  	5,105,0,0,185,186,5,115,0,0,186,20,1,0,0,0,187,188,5,105,0,0,188,189,
  	5,102,0,0,189,22,1,0,0,0,190,191,5,101,0,0,191,192,5,108,0,0,192,193,
  	5,115,0,0,193,194,5,101,0,0,194,24,1,0,0,0,195,196,5,102,0,0,196,197,
  	5,111,0,0,197,198,5,114,0,0,198,26,1,0,0,0,199,200,5,119,0,0,200,201,
  	5,104,0,0,201,202,5,105,0,0,202,203,5,108,0,0,203,204,5,101,0,0,204,28,
  	1,0,0,0,205,206,5,98,0,0,206,207,5,114,0,0,207,208,5,101,0,0,208,209,
  	5,97,0,0,209,210,5,107,0,0,210,30,1,0,0,0,211,212,5,99,0,0,212,213,5,
  	111,0,0,213,214,5,110,0,0,214,215,5,116,0,0,215,216,5,105,0,0,216,217,
  	5,110,0,0,217,218,5,117,0,0,218,219,5,101,0,0,219,32,1,0,0,0,220,221,
  	5,114,0,0,221,222,5,101,0,0,222,223,5,116,0,0,223,224,5,117,0,0,224,225,
  	5,114,0,0,225,226,5,110,0,0,226,34,1,0,0,0,227,228,5,43,0,0,228,36,1,
  	0,0,0,229,230,5,45,0,0,230,38,1,0,0,0,231,232,5,42,0,0,232,40,1,0,0,0,
  	233,234,5,47,0,0,234,42,1,0,0,0,235,236,5,37,0,0,236,44,1,0,0,0,237,238,
  	5,62,0,0,238,46,1,0,0,0,239,240,5,60,0,0,240,48,1,0,0,0,241,242,5,62,
  	0,0,242,243,5,61,0,0,243,50,1,0,0,0,244,245,5,60,0,0,245,246,5,61,0,0,
  	246,52,1,0,0,0,247,248,5,33,0,0,248,249,5,61,0,0,249,54,1,0,0,0,250,251,
  	5,61,0,0,251,252,5,61,0,0,252,56,1,0,0,0,253,254,5,38,0,0,254,255,5,38,
  	0,0,255,58,1,0,0,0,256,257,5,124,0,0,257,258,5,124,0,0,258,60,1,0,0,0,
  	259,260,5,33,0,0,260,62,1,0,0,0,261,262,5,62,0,0,262,263,5,62,0,0,263,
  	64,1,0,0,0,264,265,5,60,0,0,265,266,5,60,0,0,266,66,1,0,0,0,267,268,5,
  	38,0,0,268,68,1,0,0,0,269,270,5,124,0,0,270,70,1,0,0,0,271,272,5,94,0,
  	0,272,72,1,0,0,0,273,274,5,126,0,0,274,74,1,0,0,0,275,276,5,61,0,0,276,
  	76,1,0,0,0,277,278,5,43,0,0,278,279,5,43,0,0,279,78,1,0,0,0,280,281,5,
  	45,0,0,281,282,5,45,0,0,282,80,1,0,0,0,283,284,5,46,0,0,284,82,1,0,0,
  	0,285,286,5,91,0,0,286,84,1,0,0,0,287,288,5,93,0,0,288,86,1,0,0,0,289,
  	290,5,40,0,0,290,88,1,0,0,0,291,292,5,41,0,0,292,90,1,0,0,0,293,294,5,
  	44,0,0,294,92,1,0,0,0,295,296,5,59,0,0,296,94,1,0,0,0,297,298,5,123,0,
  	0,298,96,1,0,0,0,299,300,5,125,0,0,300,98,1,0,0,0,301,305,3,109,54,0,
  	302,304,8,0,0,0,303,302,1,0,0,0,304,307,1,0,0,0,305,303,1,0,0,0,305,306,
  	1,0,0,0,306,308,1,0,0,0,307,305,1,0,0,0,308,309,6,49,0,0,309,100,1,0,
  	0,0,310,311,5,47,0,0,311,312,5,42,0,0,312,316,1,0,0,0,313,315,9,0,0,0,
  	314,313,1,0,0,0,315,318,1,0,0,0,316,317,1,0,0,0,316,314,1,0,0,0,317,319,
  	1,0,0,0,318,316,1,0,0,0,319,320,5,42,0,0,320,321,5,47,0,0,321,322,1,0,
  	0,0,322,323,6,50,0,0,323,102,1,0,0,0,324,325,5,32,0,0,325,326,1,0,0,0,
  	326,327,6,51,0,0,327,104,1,0,0,0,328,329,5,9,0,0,329,330,1,0,0,0,330,
  	331,6,52,0,0,331,106,1,0,0,0,332,333,5,10,0,0,333,334,1,0,0,0,334,335,
  	6,53,0,0,335,108,1,0,0,0,336,337,5,47,0,0,337,338,5,47,0,0,338,110,1,
  	0,0,0,339,340,5,34,0,0,340,112,1,0,0,0,341,342,7,1,0,0,342,114,1,0,0,
  	0,343,344,7,2,0,0,344,116,1,0,0,0,345,346,7,3,0,0,346,118,1,0,0,0,347,
  	348,5,95,0,0,348,120,1,0,0,0,349,353,3,113,56,0,350,353,3,115,57,0,351,
  	353,3,119,59,0,352,349,1,0,0,0,352,350,1,0,0,0,352,351,1,0,0,0,353,122,
  	1,0,0,0,354,358,3,113,56,0,355,357,3,121,60,0,356,355,1,0,0,0,357,360,
  	1,0,0,0,358,356,1,0,0,0,358,359,1,0,0,0,359,124,1,0,0,0,360,358,1,0,0,
  	0,361,370,5,48,0,0,362,366,3,117,58,0,363,365,3,115,57,0,364,363,1,0,
  	0,0,365,368,1,0,0,0,366,364,1,0,0,0,366,367,1,0,0,0,367,370,1,0,0,0,368,
  	366,1,0,0,0,369,361,1,0,0,0,369,362,1,0,0,0,370,126,1,0,0,0,371,372,5,
  	92,0,0,372,378,5,110,0,0,373,374,5,92,0,0,374,378,5,34,0,0,375,376,5,
  	92,0,0,376,378,5,92,0,0,377,371,1,0,0,0,377,373,1,0,0,0,377,375,1,0,0,
  	0,378,128,1,0,0,0,379,382,8,4,0,0,380,382,3,127,63,0,381,379,1,0,0,0,
  	381,380,1,0,0,0,382,130,1,0,0,0,383,387,5,34,0,0,384,386,3,129,64,0,385,
  	384,1,0,0,0,386,389,1,0,0,0,387,385,1,0,0,0,387,388,1,0,0,0,388,390,1,
  	0,0,0,389,387,1,0,0,0,390,391,5,34,0,0,391,132,1,0,0,0,392,393,3,13,6,
  	0,393,134,1,0,0,0,10,0,305,316,352,358,366,369,377,381,387,1,6,0,0
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
