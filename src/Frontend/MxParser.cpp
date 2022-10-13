
// Generated from MxParser.g4 by ANTLR 4.11.1


#include "MxParserListener.h"

#include "MxParser.h"


using namespace antlrcpp;

using namespace antlr4;

namespace {

struct MxParserStaticData final {
  MxParserStaticData(std::vector<std::string> ruleNames,
                        std::vector<std::string> literalNames,
                        std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  MxParserStaticData(const MxParserStaticData&) = delete;
  MxParserStaticData(MxParserStaticData&&) = delete;
  MxParserStaticData& operator=(const MxParserStaticData&) = delete;
  MxParserStaticData& operator=(MxParserStaticData&&) = delete;

  std::vector<antlr4::dfa::DFA> decisionToDFA;
  antlr4::atn::PredictionContextCache sharedContextCache;
  const std::vector<std::string> ruleNames;
  const std::vector<std::string> literalNames;
  const std::vector<std::string> symbolicNames;
  const antlr4::dfa::Vocabulary vocabulary;
  antlr4::atn::SerializedATNView serializedATN;
  std::unique_ptr<antlr4::atn::ATN> atn;
};

::antlr4::internal::OnceFlag mxparserParserOnceFlag;
MxParserStaticData *mxparserParserStaticData = nullptr;

void mxparserParserInitialize() {
  assert(mxparserParserStaticData == nullptr);
  auto staticData = std::make_unique<MxParserStaticData>(
    std::vector<std::string>{
      "prog", "definition", "varDef", "classDef", "classBody", "funcDef", 
      "argListDef", "argList", "constructFuncDef", "typeName", "basicType", 
      "funcBody", "expression", "assignExpr", "orOrExpr", "andAndExpr", 
      "orExpr", "xorExpr", "andExpr", "equalityExpr", "relationExpr", "shiftExpr", 
      "addExpr", "multiExpr", "unaryExpr", "postfixExpr", "primaryExpr", 
      "newExpr", "newArrayExpr", "newObjExpr", "arrayIndex", "equalOp", 
      "relationOp", "shiftOp", "addOp", "multiOp", "prefixUnaryOp", "suffixUnaryOp", 
      "literal", "funcStmt", "ifStmt", "elseStmt", "whileStmt", "forStmt", 
      "memberStmt", "leftValue", "condition", "forCondition", "block", "multiStmtBlock", 
      "returnStmt", "breakStmt", "continueStmt", "exprStmt", "blankStmt"
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
  	4,1,58,479,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,6,2,
  	7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,7,
  	14,2,15,7,15,2,16,7,16,2,17,7,17,2,18,7,18,2,19,7,19,2,20,7,20,2,21,7,
  	21,2,22,7,22,2,23,7,23,2,24,7,24,2,25,7,25,2,26,7,26,2,27,7,27,2,28,7,
  	28,2,29,7,29,2,30,7,30,2,31,7,31,2,32,7,32,2,33,7,33,2,34,7,34,2,35,7,
  	35,2,36,7,36,2,37,7,37,2,38,7,38,2,39,7,39,2,40,7,40,2,41,7,41,2,42,7,
  	42,2,43,7,43,2,44,7,44,2,45,7,45,2,46,7,46,2,47,7,47,2,48,7,48,2,49,7,
  	49,2,50,7,50,2,51,7,51,2,52,7,52,2,53,7,53,2,54,7,54,1,0,5,0,112,8,0,
  	10,0,12,0,115,9,0,1,0,1,0,1,1,1,1,1,1,3,1,122,8,1,1,2,1,2,1,2,1,2,3,2,
  	128,8,2,1,2,1,2,1,2,1,2,3,2,134,8,2,5,2,136,8,2,10,2,12,2,139,9,2,1,2,
  	1,2,1,3,1,3,1,3,1,3,1,3,1,4,1,4,5,4,150,8,4,10,4,12,4,153,9,4,1,4,1,4,
  	1,5,1,5,1,5,1,5,1,5,1,6,1,6,1,6,1,6,1,6,1,6,1,6,5,6,169,8,6,10,6,12,6,
  	172,9,6,3,6,174,8,6,1,6,1,6,1,7,1,7,1,7,1,7,5,7,182,8,7,10,7,12,7,185,
  	9,7,3,7,187,8,7,1,7,1,7,1,8,1,8,1,8,1,8,1,8,1,9,1,9,1,9,5,9,199,8,9,10,
  	9,12,9,202,9,9,1,10,1,10,1,11,1,11,5,11,208,8,11,10,11,12,11,211,9,11,
  	1,11,1,11,1,12,1,12,1,13,1,13,1,13,3,13,220,8,13,1,14,1,14,1,14,5,14,
  	225,8,14,10,14,12,14,228,9,14,1,15,1,15,1,15,5,15,233,8,15,10,15,12,15,
  	236,9,15,1,16,1,16,1,16,5,16,241,8,16,10,16,12,16,244,9,16,1,17,1,17,
  	1,17,5,17,249,8,17,10,17,12,17,252,9,17,1,18,1,18,1,18,5,18,257,8,18,
  	10,18,12,18,260,9,18,1,19,1,19,1,19,1,19,5,19,266,8,19,10,19,12,19,269,
  	9,19,1,20,1,20,1,20,1,20,5,20,275,8,20,10,20,12,20,278,9,20,1,21,1,21,
  	1,21,1,21,5,21,284,8,21,10,21,12,21,287,9,21,1,22,1,22,1,22,1,22,5,22,
  	293,8,22,10,22,12,22,296,9,22,1,23,1,23,1,23,1,23,5,23,302,8,23,10,23,
  	12,23,305,9,23,1,24,1,24,1,24,1,24,1,24,3,24,312,8,24,1,25,1,25,1,25,
  	1,25,1,25,1,25,1,25,1,25,1,25,1,25,1,25,1,25,5,25,326,8,25,10,25,12,25,
  	329,9,25,1,26,1,26,1,26,1,26,1,26,1,26,1,26,3,26,338,8,26,1,27,1,27,3,
  	27,342,8,27,1,28,1,28,1,28,4,28,347,8,28,11,28,12,28,348,1,28,1,28,5,
  	28,353,8,28,10,28,12,28,356,9,28,1,29,1,29,1,29,1,29,3,29,362,8,29,1,
  	30,1,30,1,30,1,30,1,31,1,31,1,32,1,32,1,33,1,33,1,34,1,34,1,35,1,35,1,
  	36,1,36,1,37,1,37,1,38,1,38,1,39,1,39,1,39,1,39,1,39,1,39,1,39,1,39,1,
  	39,1,39,3,39,394,8,39,1,40,1,40,1,40,1,40,3,40,400,8,40,1,41,1,41,1,41,
  	1,42,1,42,1,42,1,42,1,43,1,43,1,43,1,43,1,44,1,44,1,44,3,44,416,8,44,
  	1,45,1,45,1,45,1,45,1,45,1,45,1,45,1,45,5,45,426,8,45,10,45,12,45,429,
  	9,45,1,46,1,46,1,46,1,46,1,47,1,47,3,47,437,8,47,1,47,1,47,3,47,441,8,
  	47,1,47,1,47,3,47,445,8,47,1,47,1,47,1,48,1,48,3,48,451,8,48,1,49,1,49,
  	5,49,455,8,49,10,49,12,49,458,9,49,1,49,1,49,1,50,1,50,3,50,464,8,50,
  	1,50,1,50,1,51,1,51,1,51,1,52,1,52,1,52,1,53,1,53,1,53,1,54,1,54,1,54,
  	4,137,170,183,456,2,50,90,55,0,2,4,6,8,10,12,14,16,18,20,22,24,26,28,
  	30,32,34,36,38,40,42,44,46,48,50,52,54,56,58,60,62,64,66,68,70,72,74,
  	76,78,80,82,84,86,88,90,92,94,96,98,100,102,104,106,108,0,9,2,0,1,4,55,
  	55,1,0,26,27,1,0,22,25,1,0,31,32,1,0,17,18,1,0,19,21,4,0,18,18,30,30,
  	36,36,38,39,1,0,38,39,2,0,7,8,56,58,480,0,113,1,0,0,0,2,121,1,0,0,0,4,
  	123,1,0,0,0,6,142,1,0,0,0,8,147,1,0,0,0,10,156,1,0,0,0,12,161,1,0,0,0,
  	14,177,1,0,0,0,16,190,1,0,0,0,18,195,1,0,0,0,20,203,1,0,0,0,22,205,1,
  	0,0,0,24,214,1,0,0,0,26,216,1,0,0,0,28,221,1,0,0,0,30,229,1,0,0,0,32,
  	237,1,0,0,0,34,245,1,0,0,0,36,253,1,0,0,0,38,261,1,0,0,0,40,270,1,0,0,
  	0,42,279,1,0,0,0,44,288,1,0,0,0,46,297,1,0,0,0,48,311,1,0,0,0,50,313,
  	1,0,0,0,52,337,1,0,0,0,54,341,1,0,0,0,56,343,1,0,0,0,58,357,1,0,0,0,60,
  	363,1,0,0,0,62,367,1,0,0,0,64,369,1,0,0,0,66,371,1,0,0,0,68,373,1,0,0,
  	0,70,375,1,0,0,0,72,377,1,0,0,0,74,379,1,0,0,0,76,381,1,0,0,0,78,393,
  	1,0,0,0,80,395,1,0,0,0,82,401,1,0,0,0,84,404,1,0,0,0,86,408,1,0,0,0,88,
  	415,1,0,0,0,90,417,1,0,0,0,92,430,1,0,0,0,94,434,1,0,0,0,96,450,1,0,0,
  	0,98,452,1,0,0,0,100,461,1,0,0,0,102,467,1,0,0,0,104,470,1,0,0,0,106,
  	473,1,0,0,0,108,476,1,0,0,0,110,112,3,2,1,0,111,110,1,0,0,0,112,115,1,
  	0,0,0,113,111,1,0,0,0,113,114,1,0,0,0,114,116,1,0,0,0,115,113,1,0,0,0,
  	116,117,5,0,0,1,117,1,1,0,0,0,118,122,3,10,5,0,119,122,3,4,2,0,120,122,
  	3,6,3,0,121,118,1,0,0,0,121,119,1,0,0,0,121,120,1,0,0,0,122,3,1,0,0,0,
  	123,124,3,18,9,0,124,127,5,55,0,0,125,126,5,37,0,0,126,128,3,24,12,0,
  	127,125,1,0,0,0,127,128,1,0,0,0,128,137,1,0,0,0,129,130,5,45,0,0,130,
  	133,5,55,0,0,131,132,5,37,0,0,132,134,3,24,12,0,133,131,1,0,0,0,133,134,
  	1,0,0,0,134,136,1,0,0,0,135,129,1,0,0,0,136,139,1,0,0,0,137,138,1,0,0,
  	0,137,135,1,0,0,0,138,140,1,0,0,0,139,137,1,0,0,0,140,141,5,46,0,0,141,
  	5,1,0,0,0,142,143,5,6,0,0,143,144,5,55,0,0,144,145,3,8,4,0,145,146,5,
  	46,0,0,146,7,1,0,0,0,147,151,5,47,0,0,148,150,3,88,44,0,149,148,1,0,0,
  	0,150,153,1,0,0,0,151,149,1,0,0,0,151,152,1,0,0,0,152,154,1,0,0,0,153,
  	151,1,0,0,0,154,155,5,48,0,0,155,9,1,0,0,0,156,157,3,18,9,0,157,158,5,
  	55,0,0,158,159,3,12,6,0,159,160,3,22,11,0,160,11,1,0,0,0,161,173,5,43,
  	0,0,162,163,3,18,9,0,163,170,5,55,0,0,164,165,5,45,0,0,165,166,3,18,9,
  	0,166,167,5,55,0,0,167,169,1,0,0,0,168,164,1,0,0,0,169,172,1,0,0,0,170,
  	171,1,0,0,0,170,168,1,0,0,0,171,174,1,0,0,0,172,170,1,0,0,0,173,162,1,
  	0,0,0,173,174,1,0,0,0,174,175,1,0,0,0,175,176,5,44,0,0,176,13,1,0,0,0,
  	177,186,5,43,0,0,178,183,3,24,12,0,179,180,5,45,0,0,180,182,3,24,12,0,
  	181,179,1,0,0,0,182,185,1,0,0,0,183,184,1,0,0,0,183,181,1,0,0,0,184,187,
  	1,0,0,0,185,183,1,0,0,0,186,178,1,0,0,0,186,187,1,0,0,0,187,188,1,0,0,
  	0,188,189,5,44,0,0,189,15,1,0,0,0,190,191,5,55,0,0,191,192,5,43,0,0,192,
  	193,5,44,0,0,193,194,3,22,11,0,194,17,1,0,0,0,195,200,3,20,10,0,196,197,
  	5,41,0,0,197,199,5,42,0,0,198,196,1,0,0,0,199,202,1,0,0,0,200,198,1,0,
  	0,0,200,201,1,0,0,0,201,19,1,0,0,0,202,200,1,0,0,0,203,204,7,0,0,0,204,
  	21,1,0,0,0,205,209,5,47,0,0,206,208,3,78,39,0,207,206,1,0,0,0,208,211,
  	1,0,0,0,209,207,1,0,0,0,209,210,1,0,0,0,210,212,1,0,0,0,211,209,1,0,0,
  	0,212,213,5,48,0,0,213,23,1,0,0,0,214,215,3,26,13,0,215,25,1,0,0,0,216,
  	219,3,28,14,0,217,218,5,37,0,0,218,220,3,28,14,0,219,217,1,0,0,0,219,
  	220,1,0,0,0,220,27,1,0,0,0,221,226,3,30,15,0,222,223,5,29,0,0,223,225,
  	3,30,15,0,224,222,1,0,0,0,225,228,1,0,0,0,226,224,1,0,0,0,226,227,1,0,
  	0,0,227,29,1,0,0,0,228,226,1,0,0,0,229,234,3,32,16,0,230,231,5,28,0,0,
  	231,233,3,32,16,0,232,230,1,0,0,0,233,236,1,0,0,0,234,232,1,0,0,0,234,
  	235,1,0,0,0,235,31,1,0,0,0,236,234,1,0,0,0,237,242,3,34,17,0,238,239,
  	5,34,0,0,239,241,3,34,17,0,240,238,1,0,0,0,241,244,1,0,0,0,242,240,1,
  	0,0,0,242,243,1,0,0,0,243,33,1,0,0,0,244,242,1,0,0,0,245,250,3,36,18,
  	0,246,247,5,35,0,0,247,249,3,36,18,0,248,246,1,0,0,0,249,252,1,0,0,0,
  	250,248,1,0,0,0,250,251,1,0,0,0,251,35,1,0,0,0,252,250,1,0,0,0,253,258,
  	3,38,19,0,254,255,5,33,0,0,255,257,3,38,19,0,256,254,1,0,0,0,257,260,
  	1,0,0,0,258,256,1,0,0,0,258,259,1,0,0,0,259,37,1,0,0,0,260,258,1,0,0,
  	0,261,267,3,40,20,0,262,263,3,62,31,0,263,264,3,40,20,0,264,266,1,0,0,
  	0,265,262,1,0,0,0,266,269,1,0,0,0,267,265,1,0,0,0,267,268,1,0,0,0,268,
  	39,1,0,0,0,269,267,1,0,0,0,270,276,3,42,21,0,271,272,3,64,32,0,272,273,
  	3,42,21,0,273,275,1,0,0,0,274,271,1,0,0,0,275,278,1,0,0,0,276,274,1,0,
  	0,0,276,277,1,0,0,0,277,41,1,0,0,0,278,276,1,0,0,0,279,285,3,44,22,0,
  	280,281,3,66,33,0,281,282,3,44,22,0,282,284,1,0,0,0,283,280,1,0,0,0,284,
  	287,1,0,0,0,285,283,1,0,0,0,285,286,1,0,0,0,286,43,1,0,0,0,287,285,1,
  	0,0,0,288,294,3,46,23,0,289,290,3,68,34,0,290,291,3,46,23,0,291,293,1,
  	0,0,0,292,289,1,0,0,0,293,296,1,0,0,0,294,292,1,0,0,0,294,295,1,0,0,0,
  	295,45,1,0,0,0,296,294,1,0,0,0,297,303,3,48,24,0,298,299,3,70,35,0,299,
  	300,3,48,24,0,300,302,1,0,0,0,301,298,1,0,0,0,302,305,1,0,0,0,303,301,
  	1,0,0,0,303,304,1,0,0,0,304,47,1,0,0,0,305,303,1,0,0,0,306,312,3,50,25,
  	0,307,308,3,72,36,0,308,309,3,48,24,0,309,312,1,0,0,0,310,312,3,54,27,
  	0,311,306,1,0,0,0,311,307,1,0,0,0,311,310,1,0,0,0,312,49,1,0,0,0,313,
  	314,6,25,-1,0,314,315,3,52,26,0,315,327,1,0,0,0,316,317,10,4,0,0,317,
  	326,3,60,30,0,318,319,10,3,0,0,319,326,3,14,7,0,320,321,10,2,0,0,321,
  	322,5,40,0,0,322,326,5,55,0,0,323,324,10,1,0,0,324,326,3,74,37,0,325,
  	316,1,0,0,0,325,318,1,0,0,0,325,320,1,0,0,0,325,323,1,0,0,0,326,329,1,
  	0,0,0,327,325,1,0,0,0,327,328,1,0,0,0,328,51,1,0,0,0,329,327,1,0,0,0,
  	330,338,3,76,38,0,331,338,5,9,0,0,332,333,5,43,0,0,333,334,3,24,12,0,
  	334,335,5,44,0,0,335,338,1,0,0,0,336,338,5,55,0,0,337,330,1,0,0,0,337,
  	331,1,0,0,0,337,332,1,0,0,0,337,336,1,0,0,0,338,53,1,0,0,0,339,342,3,
  	56,28,0,340,342,3,58,29,0,341,339,1,0,0,0,341,340,1,0,0,0,342,55,1,0,
  	0,0,343,344,5,5,0,0,344,346,3,20,10,0,345,347,3,60,30,0,346,345,1,0,0,
  	0,347,348,1,0,0,0,348,346,1,0,0,0,348,349,1,0,0,0,349,354,1,0,0,0,350,
  	351,5,41,0,0,351,353,5,42,0,0,352,350,1,0,0,0,353,356,1,0,0,0,354,352,
  	1,0,0,0,354,355,1,0,0,0,355,57,1,0,0,0,356,354,1,0,0,0,357,358,5,5,0,
  	0,358,361,3,20,10,0,359,360,5,43,0,0,360,362,5,44,0,0,361,359,1,0,0,0,
  	361,362,1,0,0,0,362,59,1,0,0,0,363,364,5,41,0,0,364,365,3,24,12,0,365,
  	366,5,42,0,0,366,61,1,0,0,0,367,368,7,1,0,0,368,63,1,0,0,0,369,370,7,
  	2,0,0,370,65,1,0,0,0,371,372,7,3,0,0,372,67,1,0,0,0,373,374,7,4,0,0,374,
  	69,1,0,0,0,375,376,7,5,0,0,376,71,1,0,0,0,377,378,7,6,0,0,378,73,1,0,
  	0,0,379,380,7,7,0,0,380,75,1,0,0,0,381,382,7,8,0,0,382,77,1,0,0,0,383,
  	394,3,4,2,0,384,394,3,80,40,0,385,394,3,84,42,0,386,394,3,86,43,0,387,
  	394,3,100,50,0,388,394,3,102,51,0,389,394,3,104,52,0,390,394,3,106,53,
  	0,391,394,3,98,49,0,392,394,3,108,54,0,393,383,1,0,0,0,393,384,1,0,0,
  	0,393,385,1,0,0,0,393,386,1,0,0,0,393,387,1,0,0,0,393,388,1,0,0,0,393,
  	389,1,0,0,0,393,390,1,0,0,0,393,391,1,0,0,0,393,392,1,0,0,0,394,79,1,
  	0,0,0,395,396,5,10,0,0,396,397,3,92,46,0,397,399,3,96,48,0,398,400,3,
  	82,41,0,399,398,1,0,0,0,399,400,1,0,0,0,400,81,1,0,0,0,401,402,5,11,0,
  	0,402,403,3,96,48,0,403,83,1,0,0,0,404,405,5,13,0,0,405,406,3,92,46,0,
  	406,407,3,96,48,0,407,85,1,0,0,0,408,409,5,12,0,0,409,410,3,94,47,0,410,
  	411,3,96,48,0,411,87,1,0,0,0,412,416,3,4,2,0,413,416,3,16,8,0,414,416,
  	3,10,5,0,415,412,1,0,0,0,415,413,1,0,0,0,415,414,1,0,0,0,416,89,1,0,0,
  	0,417,418,6,45,-1,0,418,419,5,55,0,0,419,427,1,0,0,0,420,421,10,2,0,0,
  	421,426,3,60,30,0,422,423,10,1,0,0,423,424,5,40,0,0,424,426,5,55,0,0,
  	425,420,1,0,0,0,425,422,1,0,0,0,426,429,1,0,0,0,427,425,1,0,0,0,427,428,
  	1,0,0,0,428,91,1,0,0,0,429,427,1,0,0,0,430,431,5,43,0,0,431,432,3,24,
  	12,0,432,433,5,44,0,0,433,93,1,0,0,0,434,436,5,43,0,0,435,437,3,24,12,
  	0,436,435,1,0,0,0,436,437,1,0,0,0,437,438,1,0,0,0,438,440,5,46,0,0,439,
  	441,3,24,12,0,440,439,1,0,0,0,440,441,1,0,0,0,441,442,1,0,0,0,442,444,
  	5,46,0,0,443,445,3,24,12,0,444,443,1,0,0,0,444,445,1,0,0,0,445,446,1,
  	0,0,0,446,447,5,44,0,0,447,95,1,0,0,0,448,451,3,98,49,0,449,451,3,78,
  	39,0,450,448,1,0,0,0,450,449,1,0,0,0,451,97,1,0,0,0,452,456,5,47,0,0,
  	453,455,3,78,39,0,454,453,1,0,0,0,455,458,1,0,0,0,456,457,1,0,0,0,456,
  	454,1,0,0,0,457,459,1,0,0,0,458,456,1,0,0,0,459,460,5,48,0,0,460,99,1,
  	0,0,0,461,463,5,16,0,0,462,464,3,24,12,0,463,462,1,0,0,0,463,464,1,0,
  	0,0,464,465,1,0,0,0,465,466,5,46,0,0,466,101,1,0,0,0,467,468,5,14,0,0,
  	468,469,5,46,0,0,469,103,1,0,0,0,470,471,5,15,0,0,471,472,5,46,0,0,472,
  	105,1,0,0,0,473,474,3,24,12,0,474,475,5,46,0,0,475,107,1,0,0,0,476,477,
  	5,46,0,0,477,109,1,0,0,0,42,113,121,127,133,137,151,170,173,183,186,200,
  	209,219,226,234,242,250,258,267,276,285,294,303,311,325,327,337,341,348,
  	354,361,393,399,415,425,427,436,440,444,450,456,463
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  mxparserParserStaticData = staticData.release();
}

}

MxParser::MxParser(TokenStream *input) : MxParser(input, antlr4::atn::ParserATNSimulatorOptions()) {}

MxParser::MxParser(TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options) : Parser(input) {
  MxParser::initialize();
  _interpreter = new atn::ParserATNSimulator(this, *mxparserParserStaticData->atn, mxparserParserStaticData->decisionToDFA, mxparserParserStaticData->sharedContextCache, options);
}

MxParser::~MxParser() {
  delete _interpreter;
}

const atn::ATN& MxParser::getATN() const {
  return *mxparserParserStaticData->atn;
}

std::string MxParser::getGrammarFileName() const {
  return "MxParser.g4";
}

const std::vector<std::string>& MxParser::getRuleNames() const {
  return mxparserParserStaticData->ruleNames;
}

const dfa::Vocabulary& MxParser::getVocabulary() const {
  return mxparserParserStaticData->vocabulary;
}

antlr4::atn::SerializedATNView MxParser::getSerializedATN() const {
  return mxparserParserStaticData->serializedATN;
}


//----------------- ProgContext ------------------------------------------------------------------

MxParser::ProgContext::ProgContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MxParser::ProgContext::EOF() {
  return getToken(MxParser::EOF, 0);
}

std::vector<MxParser::DefinitionContext *> MxParser::ProgContext::definition() {
  return getRuleContexts<MxParser::DefinitionContext>();
}

MxParser::DefinitionContext* MxParser::ProgContext::definition(size_t i) {
  return getRuleContext<MxParser::DefinitionContext>(i);
}


size_t MxParser::ProgContext::getRuleIndex() const {
  return MxParser::RuleProg;
}

void MxParser::ProgContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MxParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterProg(this);
}

void MxParser::ProgContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MxParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitProg(this);
}

MxParser::ProgContext* MxParser::prog() {
  ProgContext *_localctx = _tracker.createInstance<ProgContext>(_ctx, getState());
  enterRule(_localctx, 0, MxParser::RuleProg);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(113);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 36028797018964062) != 0) {
      setState(110);
      definition();
      setState(115);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(116);
    match(MxParser::EOF);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DefinitionContext ------------------------------------------------------------------

MxParser::DefinitionContext::DefinitionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

MxParser::FuncDefContext* MxParser::DefinitionContext::funcDef() {
  return getRuleContext<MxParser::FuncDefContext>(0);
}

MxParser::VarDefContext* MxParser::DefinitionContext::varDef() {
  return getRuleContext<MxParser::VarDefContext>(0);
}

MxParser::ClassDefContext* MxParser::DefinitionContext::classDef() {
  return getRuleContext<MxParser::ClassDefContext>(0);
}


size_t MxParser::DefinitionContext::getRuleIndex() const {
  return MxParser::RuleDefinition;
}

void MxParser::DefinitionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MxParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDefinition(this);
}

void MxParser::DefinitionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MxParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDefinition(this);
}

MxParser::DefinitionContext* MxParser::definition() {
  DefinitionContext *_localctx = _tracker.createInstance<DefinitionContext>(_ctx, getState());
  enterRule(_localctx, 2, MxParser::RuleDefinition);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(121);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 1, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(118);
      funcDef();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(119);
      varDef();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(120);
      classDef();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- VarDefContext ------------------------------------------------------------------

MxParser::VarDefContext::VarDefContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

MxParser::TypeNameContext* MxParser::VarDefContext::typeName() {
  return getRuleContext<MxParser::TypeNameContext>(0);
}

std::vector<tree::TerminalNode *> MxParser::VarDefContext::Identifier() {
  return getTokens(MxParser::Identifier);
}

tree::TerminalNode* MxParser::VarDefContext::Identifier(size_t i) {
  return getToken(MxParser::Identifier, i);
}

tree::TerminalNode* MxParser::VarDefContext::Semi() {
  return getToken(MxParser::Semi, 0);
}

std::vector<tree::TerminalNode *> MxParser::VarDefContext::Assign() {
  return getTokens(MxParser::Assign);
}

tree::TerminalNode* MxParser::VarDefContext::Assign(size_t i) {
  return getToken(MxParser::Assign, i);
}

std::vector<MxParser::ExpressionContext *> MxParser::VarDefContext::expression() {
  return getRuleContexts<MxParser::ExpressionContext>();
}

MxParser::ExpressionContext* MxParser::VarDefContext::expression(size_t i) {
  return getRuleContext<MxParser::ExpressionContext>(i);
}

std::vector<tree::TerminalNode *> MxParser::VarDefContext::Comma() {
  return getTokens(MxParser::Comma);
}

tree::TerminalNode* MxParser::VarDefContext::Comma(size_t i) {
  return getToken(MxParser::Comma, i);
}


size_t MxParser::VarDefContext::getRuleIndex() const {
  return MxParser::RuleVarDef;
}

void MxParser::VarDefContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MxParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterVarDef(this);
}

void MxParser::VarDefContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MxParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitVarDef(this);
}

MxParser::VarDefContext* MxParser::varDef() {
  VarDefContext *_localctx = _tracker.createInstance<VarDefContext>(_ctx, getState());
  enterRule(_localctx, 4, MxParser::RuleVarDef);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(123);
    typeName();
    setState(124);
    match(MxParser::Identifier);
    setState(127);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == MxParser::Assign) {
      setState(125);
      match(MxParser::Assign);
      setState(126);
      expression();
    }
    setState(137);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 4, _ctx);
    while (alt != 1 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1 + 1) {
        setState(129);
        match(MxParser::Comma);
        setState(130);
        match(MxParser::Identifier);
        setState(133);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == MxParser::Assign) {
          setState(131);
          match(MxParser::Assign);
          setState(132);
          expression();
        } 
      }
      setState(139);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 4, _ctx);
    }
    setState(140);
    match(MxParser::Semi);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ClassDefContext ------------------------------------------------------------------

MxParser::ClassDefContext::ClassDefContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MxParser::ClassDefContext::Class() {
  return getToken(MxParser::Class, 0);
}

tree::TerminalNode* MxParser::ClassDefContext::Identifier() {
  return getToken(MxParser::Identifier, 0);
}

MxParser::ClassBodyContext* MxParser::ClassDefContext::classBody() {
  return getRuleContext<MxParser::ClassBodyContext>(0);
}

tree::TerminalNode* MxParser::ClassDefContext::Semi() {
  return getToken(MxParser::Semi, 0);
}


size_t MxParser::ClassDefContext::getRuleIndex() const {
  return MxParser::RuleClassDef;
}

void MxParser::ClassDefContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MxParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterClassDef(this);
}

void MxParser::ClassDefContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MxParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitClassDef(this);
}

MxParser::ClassDefContext* MxParser::classDef() {
  ClassDefContext *_localctx = _tracker.createInstance<ClassDefContext>(_ctx, getState());
  enterRule(_localctx, 6, MxParser::RuleClassDef);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(142);
    match(MxParser::Class);
    setState(143);
    match(MxParser::Identifier);
    setState(144);
    classBody();
    setState(145);
    match(MxParser::Semi);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ClassBodyContext ------------------------------------------------------------------

MxParser::ClassBodyContext::ClassBodyContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MxParser::ClassBodyContext::LeftBrace() {
  return getToken(MxParser::LeftBrace, 0);
}

tree::TerminalNode* MxParser::ClassBodyContext::RightBrace() {
  return getToken(MxParser::RightBrace, 0);
}

std::vector<MxParser::MemberStmtContext *> MxParser::ClassBodyContext::memberStmt() {
  return getRuleContexts<MxParser::MemberStmtContext>();
}

MxParser::MemberStmtContext* MxParser::ClassBodyContext::memberStmt(size_t i) {
  return getRuleContext<MxParser::MemberStmtContext>(i);
}


size_t MxParser::ClassBodyContext::getRuleIndex() const {
  return MxParser::RuleClassBody;
}

void MxParser::ClassBodyContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MxParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterClassBody(this);
}

void MxParser::ClassBodyContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MxParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitClassBody(this);
}

MxParser::ClassBodyContext* MxParser::classBody() {
  ClassBodyContext *_localctx = _tracker.createInstance<ClassBodyContext>(_ctx, getState());
  enterRule(_localctx, 8, MxParser::RuleClassBody);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(147);
    match(MxParser::LeftBrace);
    setState(151);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 36028797018963998) != 0) {
      setState(148);
      memberStmt();
      setState(153);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(154);
    match(MxParser::RightBrace);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FuncDefContext ------------------------------------------------------------------

MxParser::FuncDefContext::FuncDefContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

MxParser::TypeNameContext* MxParser::FuncDefContext::typeName() {
  return getRuleContext<MxParser::TypeNameContext>(0);
}

tree::TerminalNode* MxParser::FuncDefContext::Identifier() {
  return getToken(MxParser::Identifier, 0);
}

MxParser::ArgListDefContext* MxParser::FuncDefContext::argListDef() {
  return getRuleContext<MxParser::ArgListDefContext>(0);
}

MxParser::FuncBodyContext* MxParser::FuncDefContext::funcBody() {
  return getRuleContext<MxParser::FuncBodyContext>(0);
}


size_t MxParser::FuncDefContext::getRuleIndex() const {
  return MxParser::RuleFuncDef;
}

void MxParser::FuncDefContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MxParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFuncDef(this);
}

void MxParser::FuncDefContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MxParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFuncDef(this);
}

MxParser::FuncDefContext* MxParser::funcDef() {
  FuncDefContext *_localctx = _tracker.createInstance<FuncDefContext>(_ctx, getState());
  enterRule(_localctx, 10, MxParser::RuleFuncDef);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(156);
    typeName();
    setState(157);
    match(MxParser::Identifier);
    setState(158);
    argListDef();
    setState(159);
    funcBody();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ArgListDefContext ------------------------------------------------------------------

MxParser::ArgListDefContext::ArgListDefContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MxParser::ArgListDefContext::LeftParen() {
  return getToken(MxParser::LeftParen, 0);
}

tree::TerminalNode* MxParser::ArgListDefContext::RightParen() {
  return getToken(MxParser::RightParen, 0);
}

std::vector<MxParser::TypeNameContext *> MxParser::ArgListDefContext::typeName() {
  return getRuleContexts<MxParser::TypeNameContext>();
}

MxParser::TypeNameContext* MxParser::ArgListDefContext::typeName(size_t i) {
  return getRuleContext<MxParser::TypeNameContext>(i);
}

std::vector<tree::TerminalNode *> MxParser::ArgListDefContext::Identifier() {
  return getTokens(MxParser::Identifier);
}

tree::TerminalNode* MxParser::ArgListDefContext::Identifier(size_t i) {
  return getToken(MxParser::Identifier, i);
}

std::vector<tree::TerminalNode *> MxParser::ArgListDefContext::Comma() {
  return getTokens(MxParser::Comma);
}

tree::TerminalNode* MxParser::ArgListDefContext::Comma(size_t i) {
  return getToken(MxParser::Comma, i);
}


size_t MxParser::ArgListDefContext::getRuleIndex() const {
  return MxParser::RuleArgListDef;
}

void MxParser::ArgListDefContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MxParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterArgListDef(this);
}

void MxParser::ArgListDefContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MxParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitArgListDef(this);
}

MxParser::ArgListDefContext* MxParser::argListDef() {
  ArgListDefContext *_localctx = _tracker.createInstance<ArgListDefContext>(_ctx, getState());
  enterRule(_localctx, 12, MxParser::RuleArgListDef);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(161);
    match(MxParser::LeftParen);
    setState(173);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 36028797018963998) != 0) {
      setState(162);
      typeName();
      setState(163);
      match(MxParser::Identifier);
      setState(170);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 6, _ctx);
      while (alt != 1 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1 + 1) {
          setState(164);
          match(MxParser::Comma);
          setState(165);
          typeName();
          setState(166);
          match(MxParser::Identifier); 
        }
        setState(172);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 6, _ctx);
      }
    }
    setState(175);
    match(MxParser::RightParen);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ArgListContext ------------------------------------------------------------------

MxParser::ArgListContext::ArgListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MxParser::ArgListContext::LeftParen() {
  return getToken(MxParser::LeftParen, 0);
}

tree::TerminalNode* MxParser::ArgListContext::RightParen() {
  return getToken(MxParser::RightParen, 0);
}

std::vector<MxParser::ExpressionContext *> MxParser::ArgListContext::expression() {
  return getRuleContexts<MxParser::ExpressionContext>();
}

MxParser::ExpressionContext* MxParser::ArgListContext::expression(size_t i) {
  return getRuleContext<MxParser::ExpressionContext>(i);
}

std::vector<tree::TerminalNode *> MxParser::ArgListContext::Comma() {
  return getTokens(MxParser::Comma);
}

tree::TerminalNode* MxParser::ArgListContext::Comma(size_t i) {
  return getToken(MxParser::Comma, i);
}


size_t MxParser::ArgListContext::getRuleIndex() const {
  return MxParser::RuleArgList;
}

void MxParser::ArgListContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MxParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterArgList(this);
}

void MxParser::ArgListContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MxParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitArgList(this);
}

MxParser::ArgListContext* MxParser::argList() {
  ArgListContext *_localctx = _tracker.createInstance<ArgListContext>(_ctx, getState());
  enterRule(_localctx, 14, MxParser::RuleArgList);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(177);
    match(MxParser::LeftParen);
    setState(186);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 540441645804684192) != 0) {
      setState(178);
      expression();
      setState(183);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 8, _ctx);
      while (alt != 1 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1 + 1) {
          setState(179);
          match(MxParser::Comma);
          setState(180);
          expression(); 
        }
        setState(185);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 8, _ctx);
      }
    }
    setState(188);
    match(MxParser::RightParen);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ConstructFuncDefContext ------------------------------------------------------------------

MxParser::ConstructFuncDefContext::ConstructFuncDefContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MxParser::ConstructFuncDefContext::Identifier() {
  return getToken(MxParser::Identifier, 0);
}

tree::TerminalNode* MxParser::ConstructFuncDefContext::LeftParen() {
  return getToken(MxParser::LeftParen, 0);
}

tree::TerminalNode* MxParser::ConstructFuncDefContext::RightParen() {
  return getToken(MxParser::RightParen, 0);
}

MxParser::FuncBodyContext* MxParser::ConstructFuncDefContext::funcBody() {
  return getRuleContext<MxParser::FuncBodyContext>(0);
}


size_t MxParser::ConstructFuncDefContext::getRuleIndex() const {
  return MxParser::RuleConstructFuncDef;
}

void MxParser::ConstructFuncDefContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MxParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterConstructFuncDef(this);
}

void MxParser::ConstructFuncDefContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MxParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitConstructFuncDef(this);
}

MxParser::ConstructFuncDefContext* MxParser::constructFuncDef() {
  ConstructFuncDefContext *_localctx = _tracker.createInstance<ConstructFuncDefContext>(_ctx, getState());
  enterRule(_localctx, 16, MxParser::RuleConstructFuncDef);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(190);
    match(MxParser::Identifier);
    setState(191);
    match(MxParser::LeftParen);
    setState(192);
    match(MxParser::RightParen);
    setState(193);
    funcBody();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TypeNameContext ------------------------------------------------------------------

MxParser::TypeNameContext::TypeNameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

MxParser::BasicTypeContext* MxParser::TypeNameContext::basicType() {
  return getRuleContext<MxParser::BasicTypeContext>(0);
}

std::vector<tree::TerminalNode *> MxParser::TypeNameContext::LeftBracket() {
  return getTokens(MxParser::LeftBracket);
}

tree::TerminalNode* MxParser::TypeNameContext::LeftBracket(size_t i) {
  return getToken(MxParser::LeftBracket, i);
}

std::vector<tree::TerminalNode *> MxParser::TypeNameContext::RightBracket() {
  return getTokens(MxParser::RightBracket);
}

tree::TerminalNode* MxParser::TypeNameContext::RightBracket(size_t i) {
  return getToken(MxParser::RightBracket, i);
}


size_t MxParser::TypeNameContext::getRuleIndex() const {
  return MxParser::RuleTypeName;
}

void MxParser::TypeNameContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MxParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTypeName(this);
}

void MxParser::TypeNameContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MxParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTypeName(this);
}

MxParser::TypeNameContext* MxParser::typeName() {
  TypeNameContext *_localctx = _tracker.createInstance<TypeNameContext>(_ctx, getState());
  enterRule(_localctx, 18, MxParser::RuleTypeName);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(195);
    basicType();
    setState(200);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == MxParser::LeftBracket) {
      setState(196);
      match(MxParser::LeftBracket);
      setState(197);
      match(MxParser::RightBracket);
      setState(202);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BasicTypeContext ------------------------------------------------------------------

MxParser::BasicTypeContext::BasicTypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MxParser::BasicTypeContext::Int() {
  return getToken(MxParser::Int, 0);
}

tree::TerminalNode* MxParser::BasicTypeContext::Bool() {
  return getToken(MxParser::Bool, 0);
}

tree::TerminalNode* MxParser::BasicTypeContext::String() {
  return getToken(MxParser::String, 0);
}

tree::TerminalNode* MxParser::BasicTypeContext::Void() {
  return getToken(MxParser::Void, 0);
}

tree::TerminalNode* MxParser::BasicTypeContext::Identifier() {
  return getToken(MxParser::Identifier, 0);
}


size_t MxParser::BasicTypeContext::getRuleIndex() const {
  return MxParser::RuleBasicType;
}

void MxParser::BasicTypeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MxParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBasicType(this);
}

void MxParser::BasicTypeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MxParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBasicType(this);
}

MxParser::BasicTypeContext* MxParser::basicType() {
  BasicTypeContext *_localctx = _tracker.createInstance<BasicTypeContext>(_ctx, getState());
  enterRule(_localctx, 20, MxParser::RuleBasicType);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(203);
    _la = _input->LA(1);
    if (!(((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 36028797018963998) != 0)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FuncBodyContext ------------------------------------------------------------------

MxParser::FuncBodyContext::FuncBodyContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MxParser::FuncBodyContext::LeftBrace() {
  return getToken(MxParser::LeftBrace, 0);
}

tree::TerminalNode* MxParser::FuncBodyContext::RightBrace() {
  return getToken(MxParser::RightBrace, 0);
}

std::vector<MxParser::FuncStmtContext *> MxParser::FuncBodyContext::funcStmt() {
  return getRuleContexts<MxParser::FuncStmtContext>();
}

MxParser::FuncStmtContext* MxParser::FuncBodyContext::funcStmt(size_t i) {
  return getRuleContext<MxParser::FuncStmtContext>(i);
}


size_t MxParser::FuncBodyContext::getRuleIndex() const {
  return MxParser::RuleFuncBody;
}

void MxParser::FuncBodyContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MxParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFuncBody(this);
}

void MxParser::FuncBodyContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MxParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFuncBody(this);
}

MxParser::FuncBodyContext* MxParser::funcBody() {
  FuncBodyContext *_localctx = _tracker.createInstance<FuncBodyContext>(_ctx, getState());
  enterRule(_localctx, 22, MxParser::RuleFuncBody);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(205);
    match(MxParser::LeftBrace);
    setState(209);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 540652752037345214) != 0) {
      setState(206);
      funcStmt();
      setState(211);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(212);
    match(MxParser::RightBrace);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExpressionContext ------------------------------------------------------------------

MxParser::ExpressionContext::ExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

MxParser::AssignExprContext* MxParser::ExpressionContext::assignExpr() {
  return getRuleContext<MxParser::AssignExprContext>(0);
}


size_t MxParser::ExpressionContext::getRuleIndex() const {
  return MxParser::RuleExpression;
}

void MxParser::ExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MxParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExpression(this);
}

void MxParser::ExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MxParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExpression(this);
}

MxParser::ExpressionContext* MxParser::expression() {
  ExpressionContext *_localctx = _tracker.createInstance<ExpressionContext>(_ctx, getState());
  enterRule(_localctx, 24, MxParser::RuleExpression);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(214);
    assignExpr();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AssignExprContext ------------------------------------------------------------------

MxParser::AssignExprContext::AssignExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<MxParser::OrOrExprContext *> MxParser::AssignExprContext::orOrExpr() {
  return getRuleContexts<MxParser::OrOrExprContext>();
}

MxParser::OrOrExprContext* MxParser::AssignExprContext::orOrExpr(size_t i) {
  return getRuleContext<MxParser::OrOrExprContext>(i);
}

tree::TerminalNode* MxParser::AssignExprContext::Assign() {
  return getToken(MxParser::Assign, 0);
}


size_t MxParser::AssignExprContext::getRuleIndex() const {
  return MxParser::RuleAssignExpr;
}

void MxParser::AssignExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MxParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAssignExpr(this);
}

void MxParser::AssignExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MxParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAssignExpr(this);
}

MxParser::AssignExprContext* MxParser::assignExpr() {
  AssignExprContext *_localctx = _tracker.createInstance<AssignExprContext>(_ctx, getState());
  enterRule(_localctx, 26, MxParser::RuleAssignExpr);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(216);
    orOrExpr();
    setState(219);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == MxParser::Assign) {
      setState(217);
      match(MxParser::Assign);
      setState(218);
      orOrExpr();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- OrOrExprContext ------------------------------------------------------------------

MxParser::OrOrExprContext::OrOrExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<MxParser::AndAndExprContext *> MxParser::OrOrExprContext::andAndExpr() {
  return getRuleContexts<MxParser::AndAndExprContext>();
}

MxParser::AndAndExprContext* MxParser::OrOrExprContext::andAndExpr(size_t i) {
  return getRuleContext<MxParser::AndAndExprContext>(i);
}

std::vector<tree::TerminalNode *> MxParser::OrOrExprContext::OrOr() {
  return getTokens(MxParser::OrOr);
}

tree::TerminalNode* MxParser::OrOrExprContext::OrOr(size_t i) {
  return getToken(MxParser::OrOr, i);
}


size_t MxParser::OrOrExprContext::getRuleIndex() const {
  return MxParser::RuleOrOrExpr;
}

void MxParser::OrOrExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MxParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterOrOrExpr(this);
}

void MxParser::OrOrExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MxParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitOrOrExpr(this);
}

MxParser::OrOrExprContext* MxParser::orOrExpr() {
  OrOrExprContext *_localctx = _tracker.createInstance<OrOrExprContext>(_ctx, getState());
  enterRule(_localctx, 28, MxParser::RuleOrOrExpr);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(221);
    andAndExpr();
    setState(226);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == MxParser::OrOr) {
      setState(222);
      match(MxParser::OrOr);
      setState(223);
      andAndExpr();
      setState(228);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AndAndExprContext ------------------------------------------------------------------

MxParser::AndAndExprContext::AndAndExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<MxParser::OrExprContext *> MxParser::AndAndExprContext::orExpr() {
  return getRuleContexts<MxParser::OrExprContext>();
}

MxParser::OrExprContext* MxParser::AndAndExprContext::orExpr(size_t i) {
  return getRuleContext<MxParser::OrExprContext>(i);
}

std::vector<tree::TerminalNode *> MxParser::AndAndExprContext::AndAnd() {
  return getTokens(MxParser::AndAnd);
}

tree::TerminalNode* MxParser::AndAndExprContext::AndAnd(size_t i) {
  return getToken(MxParser::AndAnd, i);
}


size_t MxParser::AndAndExprContext::getRuleIndex() const {
  return MxParser::RuleAndAndExpr;
}

void MxParser::AndAndExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MxParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAndAndExpr(this);
}

void MxParser::AndAndExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MxParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAndAndExpr(this);
}

MxParser::AndAndExprContext* MxParser::andAndExpr() {
  AndAndExprContext *_localctx = _tracker.createInstance<AndAndExprContext>(_ctx, getState());
  enterRule(_localctx, 30, MxParser::RuleAndAndExpr);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(229);
    orExpr();
    setState(234);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == MxParser::AndAnd) {
      setState(230);
      match(MxParser::AndAnd);
      setState(231);
      orExpr();
      setState(236);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- OrExprContext ------------------------------------------------------------------

MxParser::OrExprContext::OrExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<MxParser::XorExprContext *> MxParser::OrExprContext::xorExpr() {
  return getRuleContexts<MxParser::XorExprContext>();
}

MxParser::XorExprContext* MxParser::OrExprContext::xorExpr(size_t i) {
  return getRuleContext<MxParser::XorExprContext>(i);
}

std::vector<tree::TerminalNode *> MxParser::OrExprContext::Or() {
  return getTokens(MxParser::Or);
}

tree::TerminalNode* MxParser::OrExprContext::Or(size_t i) {
  return getToken(MxParser::Or, i);
}


size_t MxParser::OrExprContext::getRuleIndex() const {
  return MxParser::RuleOrExpr;
}

void MxParser::OrExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MxParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterOrExpr(this);
}

void MxParser::OrExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MxParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitOrExpr(this);
}

MxParser::OrExprContext* MxParser::orExpr() {
  OrExprContext *_localctx = _tracker.createInstance<OrExprContext>(_ctx, getState());
  enterRule(_localctx, 32, MxParser::RuleOrExpr);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(237);
    xorExpr();
    setState(242);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == MxParser::Or) {
      setState(238);
      match(MxParser::Or);
      setState(239);
      xorExpr();
      setState(244);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- XorExprContext ------------------------------------------------------------------

MxParser::XorExprContext::XorExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<MxParser::AndExprContext *> MxParser::XorExprContext::andExpr() {
  return getRuleContexts<MxParser::AndExprContext>();
}

MxParser::AndExprContext* MxParser::XorExprContext::andExpr(size_t i) {
  return getRuleContext<MxParser::AndExprContext>(i);
}

std::vector<tree::TerminalNode *> MxParser::XorExprContext::Caret() {
  return getTokens(MxParser::Caret);
}

tree::TerminalNode* MxParser::XorExprContext::Caret(size_t i) {
  return getToken(MxParser::Caret, i);
}


size_t MxParser::XorExprContext::getRuleIndex() const {
  return MxParser::RuleXorExpr;
}

void MxParser::XorExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MxParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterXorExpr(this);
}

void MxParser::XorExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MxParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitXorExpr(this);
}

MxParser::XorExprContext* MxParser::xorExpr() {
  XorExprContext *_localctx = _tracker.createInstance<XorExprContext>(_ctx, getState());
  enterRule(_localctx, 34, MxParser::RuleXorExpr);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(245);
    andExpr();
    setState(250);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == MxParser::Caret) {
      setState(246);
      match(MxParser::Caret);
      setState(247);
      andExpr();
      setState(252);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AndExprContext ------------------------------------------------------------------

MxParser::AndExprContext::AndExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<MxParser::EqualityExprContext *> MxParser::AndExprContext::equalityExpr() {
  return getRuleContexts<MxParser::EqualityExprContext>();
}

MxParser::EqualityExprContext* MxParser::AndExprContext::equalityExpr(size_t i) {
  return getRuleContext<MxParser::EqualityExprContext>(i);
}

std::vector<tree::TerminalNode *> MxParser::AndExprContext::And() {
  return getTokens(MxParser::And);
}

tree::TerminalNode* MxParser::AndExprContext::And(size_t i) {
  return getToken(MxParser::And, i);
}


size_t MxParser::AndExprContext::getRuleIndex() const {
  return MxParser::RuleAndExpr;
}

void MxParser::AndExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MxParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAndExpr(this);
}

void MxParser::AndExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MxParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAndExpr(this);
}

MxParser::AndExprContext* MxParser::andExpr() {
  AndExprContext *_localctx = _tracker.createInstance<AndExprContext>(_ctx, getState());
  enterRule(_localctx, 36, MxParser::RuleAndExpr);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(253);
    equalityExpr();
    setState(258);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == MxParser::And) {
      setState(254);
      match(MxParser::And);
      setState(255);
      equalityExpr();
      setState(260);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- EqualityExprContext ------------------------------------------------------------------

MxParser::EqualityExprContext::EqualityExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<MxParser::RelationExprContext *> MxParser::EqualityExprContext::relationExpr() {
  return getRuleContexts<MxParser::RelationExprContext>();
}

MxParser::RelationExprContext* MxParser::EqualityExprContext::relationExpr(size_t i) {
  return getRuleContext<MxParser::RelationExprContext>(i);
}

std::vector<MxParser::EqualOpContext *> MxParser::EqualityExprContext::equalOp() {
  return getRuleContexts<MxParser::EqualOpContext>();
}

MxParser::EqualOpContext* MxParser::EqualityExprContext::equalOp(size_t i) {
  return getRuleContext<MxParser::EqualOpContext>(i);
}


size_t MxParser::EqualityExprContext::getRuleIndex() const {
  return MxParser::RuleEqualityExpr;
}

void MxParser::EqualityExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MxParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterEqualityExpr(this);
}

void MxParser::EqualityExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MxParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitEqualityExpr(this);
}

MxParser::EqualityExprContext* MxParser::equalityExpr() {
  EqualityExprContext *_localctx = _tracker.createInstance<EqualityExprContext>(_ctx, getState());
  enterRule(_localctx, 38, MxParser::RuleEqualityExpr);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(261);
    relationExpr();
    setState(267);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == MxParser::NotEqual

    || _la == MxParser::Equal) {
      setState(262);
      equalOp();
      setState(263);
      relationExpr();
      setState(269);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- RelationExprContext ------------------------------------------------------------------

MxParser::RelationExprContext::RelationExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<MxParser::ShiftExprContext *> MxParser::RelationExprContext::shiftExpr() {
  return getRuleContexts<MxParser::ShiftExprContext>();
}

MxParser::ShiftExprContext* MxParser::RelationExprContext::shiftExpr(size_t i) {
  return getRuleContext<MxParser::ShiftExprContext>(i);
}

std::vector<MxParser::RelationOpContext *> MxParser::RelationExprContext::relationOp() {
  return getRuleContexts<MxParser::RelationOpContext>();
}

MxParser::RelationOpContext* MxParser::RelationExprContext::relationOp(size_t i) {
  return getRuleContext<MxParser::RelationOpContext>(i);
}


size_t MxParser::RelationExprContext::getRuleIndex() const {
  return MxParser::RuleRelationExpr;
}

void MxParser::RelationExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MxParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterRelationExpr(this);
}

void MxParser::RelationExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MxParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitRelationExpr(this);
}

MxParser::RelationExprContext* MxParser::relationExpr() {
  RelationExprContext *_localctx = _tracker.createInstance<RelationExprContext>(_ctx, getState());
  enterRule(_localctx, 40, MxParser::RuleRelationExpr);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(270);
    shiftExpr();
    setState(276);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 62914560) != 0) {
      setState(271);
      relationOp();
      setState(272);
      shiftExpr();
      setState(278);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ShiftExprContext ------------------------------------------------------------------

MxParser::ShiftExprContext::ShiftExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<MxParser::AddExprContext *> MxParser::ShiftExprContext::addExpr() {
  return getRuleContexts<MxParser::AddExprContext>();
}

MxParser::AddExprContext* MxParser::ShiftExprContext::addExpr(size_t i) {
  return getRuleContext<MxParser::AddExprContext>(i);
}

std::vector<MxParser::ShiftOpContext *> MxParser::ShiftExprContext::shiftOp() {
  return getRuleContexts<MxParser::ShiftOpContext>();
}

MxParser::ShiftOpContext* MxParser::ShiftExprContext::shiftOp(size_t i) {
  return getRuleContext<MxParser::ShiftOpContext>(i);
}


size_t MxParser::ShiftExprContext::getRuleIndex() const {
  return MxParser::RuleShiftExpr;
}

void MxParser::ShiftExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MxParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterShiftExpr(this);
}

void MxParser::ShiftExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MxParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitShiftExpr(this);
}

MxParser::ShiftExprContext* MxParser::shiftExpr() {
  ShiftExprContext *_localctx = _tracker.createInstance<ShiftExprContext>(_ctx, getState());
  enterRule(_localctx, 42, MxParser::RuleShiftExpr);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(279);
    addExpr();
    setState(285);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == MxParser::RightShift

    || _la == MxParser::LeftShift) {
      setState(280);
      shiftOp();
      setState(281);
      addExpr();
      setState(287);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AddExprContext ------------------------------------------------------------------

MxParser::AddExprContext::AddExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<MxParser::MultiExprContext *> MxParser::AddExprContext::multiExpr() {
  return getRuleContexts<MxParser::MultiExprContext>();
}

MxParser::MultiExprContext* MxParser::AddExprContext::multiExpr(size_t i) {
  return getRuleContext<MxParser::MultiExprContext>(i);
}

std::vector<MxParser::AddOpContext *> MxParser::AddExprContext::addOp() {
  return getRuleContexts<MxParser::AddOpContext>();
}

MxParser::AddOpContext* MxParser::AddExprContext::addOp(size_t i) {
  return getRuleContext<MxParser::AddOpContext>(i);
}


size_t MxParser::AddExprContext::getRuleIndex() const {
  return MxParser::RuleAddExpr;
}

void MxParser::AddExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MxParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAddExpr(this);
}

void MxParser::AddExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MxParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAddExpr(this);
}

MxParser::AddExprContext* MxParser::addExpr() {
  AddExprContext *_localctx = _tracker.createInstance<AddExprContext>(_ctx, getState());
  enterRule(_localctx, 44, MxParser::RuleAddExpr);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(288);
    multiExpr();
    setState(294);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == MxParser::Plus

    || _la == MxParser::Minus) {
      setState(289);
      addOp();
      setState(290);
      multiExpr();
      setState(296);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- MultiExprContext ------------------------------------------------------------------

MxParser::MultiExprContext::MultiExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<MxParser::UnaryExprContext *> MxParser::MultiExprContext::unaryExpr() {
  return getRuleContexts<MxParser::UnaryExprContext>();
}

MxParser::UnaryExprContext* MxParser::MultiExprContext::unaryExpr(size_t i) {
  return getRuleContext<MxParser::UnaryExprContext>(i);
}

std::vector<MxParser::MultiOpContext *> MxParser::MultiExprContext::multiOp() {
  return getRuleContexts<MxParser::MultiOpContext>();
}

MxParser::MultiOpContext* MxParser::MultiExprContext::multiOp(size_t i) {
  return getRuleContext<MxParser::MultiOpContext>(i);
}


size_t MxParser::MultiExprContext::getRuleIndex() const {
  return MxParser::RuleMultiExpr;
}

void MxParser::MultiExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MxParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMultiExpr(this);
}

void MxParser::MultiExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MxParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMultiExpr(this);
}

MxParser::MultiExprContext* MxParser::multiExpr() {
  MultiExprContext *_localctx = _tracker.createInstance<MultiExprContext>(_ctx, getState());
  enterRule(_localctx, 46, MxParser::RuleMultiExpr);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(297);
    unaryExpr();
    setState(303);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 3670016) != 0) {
      setState(298);
      multiOp();
      setState(299);
      unaryExpr();
      setState(305);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- UnaryExprContext ------------------------------------------------------------------

MxParser::UnaryExprContext::UnaryExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

MxParser::PostfixExprContext* MxParser::UnaryExprContext::postfixExpr() {
  return getRuleContext<MxParser::PostfixExprContext>(0);
}

MxParser::PrefixUnaryOpContext* MxParser::UnaryExprContext::prefixUnaryOp() {
  return getRuleContext<MxParser::PrefixUnaryOpContext>(0);
}

MxParser::UnaryExprContext* MxParser::UnaryExprContext::unaryExpr() {
  return getRuleContext<MxParser::UnaryExprContext>(0);
}

MxParser::NewExprContext* MxParser::UnaryExprContext::newExpr() {
  return getRuleContext<MxParser::NewExprContext>(0);
}


size_t MxParser::UnaryExprContext::getRuleIndex() const {
  return MxParser::RuleUnaryExpr;
}

void MxParser::UnaryExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MxParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterUnaryExpr(this);
}

void MxParser::UnaryExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MxParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitUnaryExpr(this);
}

MxParser::UnaryExprContext* MxParser::unaryExpr() {
  UnaryExprContext *_localctx = _tracker.createInstance<UnaryExprContext>(_ctx, getState());
  enterRule(_localctx, 48, MxParser::RuleUnaryExpr);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(311);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case MxParser::True:
      case MxParser::False:
      case MxParser::This:
      case MxParser::LeftParen:
      case MxParser::Identifier:
      case MxParser::IntLiteral:
      case MxParser::StringLiteral:
      case MxParser::NullLiteral: {
        enterOuterAlt(_localctx, 1);
        setState(306);
        postfixExpr(0);
        break;
      }

      case MxParser::Minus:
      case MxParser::Not:
      case MxParser::Tilde:
      case MxParser::PlusPlus:
      case MxParser::MinusMinus: {
        enterOuterAlt(_localctx, 2);
        setState(307);
        prefixUnaryOp();
        setState(308);
        unaryExpr();
        break;
      }

      case MxParser::New: {
        enterOuterAlt(_localctx, 3);
        setState(310);
        newExpr();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- PostfixExprContext ------------------------------------------------------------------

MxParser::PostfixExprContext::PostfixExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

MxParser::PrimaryExprContext* MxParser::PostfixExprContext::primaryExpr() {
  return getRuleContext<MxParser::PrimaryExprContext>(0);
}

MxParser::PostfixExprContext* MxParser::PostfixExprContext::postfixExpr() {
  return getRuleContext<MxParser::PostfixExprContext>(0);
}

MxParser::ArrayIndexContext* MxParser::PostfixExprContext::arrayIndex() {
  return getRuleContext<MxParser::ArrayIndexContext>(0);
}

MxParser::ArgListContext* MxParser::PostfixExprContext::argList() {
  return getRuleContext<MxParser::ArgListContext>(0);
}

tree::TerminalNode* MxParser::PostfixExprContext::Dot() {
  return getToken(MxParser::Dot, 0);
}

tree::TerminalNode* MxParser::PostfixExprContext::Identifier() {
  return getToken(MxParser::Identifier, 0);
}

MxParser::SuffixUnaryOpContext* MxParser::PostfixExprContext::suffixUnaryOp() {
  return getRuleContext<MxParser::SuffixUnaryOpContext>(0);
}


size_t MxParser::PostfixExprContext::getRuleIndex() const {
  return MxParser::RulePostfixExpr;
}

void MxParser::PostfixExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MxParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPostfixExpr(this);
}

void MxParser::PostfixExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MxParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPostfixExpr(this);
}


MxParser::PostfixExprContext* MxParser::postfixExpr() {
   return postfixExpr(0);
}

MxParser::PostfixExprContext* MxParser::postfixExpr(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  MxParser::PostfixExprContext *_localctx = _tracker.createInstance<PostfixExprContext>(_ctx, parentState);
  MxParser::PostfixExprContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 50;
  enterRecursionRule(_localctx, 50, MxParser::RulePostfixExpr, precedence);

    

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(314);
    primaryExpr();
    _ctx->stop = _input->LT(-1);
    setState(327);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 25, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(325);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 24, _ctx)) {
        case 1: {
          _localctx = _tracker.createInstance<PostfixExprContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RulePostfixExpr);
          setState(316);

          if (!(precpred(_ctx, 4))) throw FailedPredicateException(this, "precpred(_ctx, 4)");
          setState(317);
          arrayIndex();
          break;
        }

        case 2: {
          _localctx = _tracker.createInstance<PostfixExprContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RulePostfixExpr);
          setState(318);

          if (!(precpred(_ctx, 3))) throw FailedPredicateException(this, "precpred(_ctx, 3)");
          setState(319);
          argList();
          break;
        }

        case 3: {
          _localctx = _tracker.createInstance<PostfixExprContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RulePostfixExpr);
          setState(320);

          if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
          setState(321);
          match(MxParser::Dot);
          setState(322);
          match(MxParser::Identifier);
          break;
        }

        case 4: {
          _localctx = _tracker.createInstance<PostfixExprContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RulePostfixExpr);
          setState(323);

          if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
          setState(324);
          suffixUnaryOp();
          break;
        }

        default:
          break;
        } 
      }
      setState(329);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 25, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- PrimaryExprContext ------------------------------------------------------------------

MxParser::PrimaryExprContext::PrimaryExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

MxParser::LiteralContext* MxParser::PrimaryExprContext::literal() {
  return getRuleContext<MxParser::LiteralContext>(0);
}

tree::TerminalNode* MxParser::PrimaryExprContext::This() {
  return getToken(MxParser::This, 0);
}

tree::TerminalNode* MxParser::PrimaryExprContext::LeftParen() {
  return getToken(MxParser::LeftParen, 0);
}

MxParser::ExpressionContext* MxParser::PrimaryExprContext::expression() {
  return getRuleContext<MxParser::ExpressionContext>(0);
}

tree::TerminalNode* MxParser::PrimaryExprContext::RightParen() {
  return getToken(MxParser::RightParen, 0);
}

tree::TerminalNode* MxParser::PrimaryExprContext::Identifier() {
  return getToken(MxParser::Identifier, 0);
}


size_t MxParser::PrimaryExprContext::getRuleIndex() const {
  return MxParser::RulePrimaryExpr;
}

void MxParser::PrimaryExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MxParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPrimaryExpr(this);
}

void MxParser::PrimaryExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MxParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPrimaryExpr(this);
}

MxParser::PrimaryExprContext* MxParser::primaryExpr() {
  PrimaryExprContext *_localctx = _tracker.createInstance<PrimaryExprContext>(_ctx, getState());
  enterRule(_localctx, 52, MxParser::RulePrimaryExpr);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(337);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case MxParser::True:
      case MxParser::False:
      case MxParser::IntLiteral:
      case MxParser::StringLiteral:
      case MxParser::NullLiteral: {
        enterOuterAlt(_localctx, 1);
        setState(330);
        literal();
        break;
      }

      case MxParser::This: {
        enterOuterAlt(_localctx, 2);
        setState(331);
        match(MxParser::This);
        break;
      }

      case MxParser::LeftParen: {
        enterOuterAlt(_localctx, 3);
        setState(332);
        match(MxParser::LeftParen);
        setState(333);
        expression();
        setState(334);
        match(MxParser::RightParen);
        break;
      }

      case MxParser::Identifier: {
        enterOuterAlt(_localctx, 4);
        setState(336);
        match(MxParser::Identifier);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- NewExprContext ------------------------------------------------------------------

MxParser::NewExprContext::NewExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

MxParser::NewArrayExprContext* MxParser::NewExprContext::newArrayExpr() {
  return getRuleContext<MxParser::NewArrayExprContext>(0);
}

MxParser::NewObjExprContext* MxParser::NewExprContext::newObjExpr() {
  return getRuleContext<MxParser::NewObjExprContext>(0);
}


size_t MxParser::NewExprContext::getRuleIndex() const {
  return MxParser::RuleNewExpr;
}

void MxParser::NewExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MxParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterNewExpr(this);
}

void MxParser::NewExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MxParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitNewExpr(this);
}

MxParser::NewExprContext* MxParser::newExpr() {
  NewExprContext *_localctx = _tracker.createInstance<NewExprContext>(_ctx, getState());
  enterRule(_localctx, 54, MxParser::RuleNewExpr);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(341);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 27, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(339);
      newArrayExpr();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(340);
      newObjExpr();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- NewArrayExprContext ------------------------------------------------------------------

MxParser::NewArrayExprContext::NewArrayExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MxParser::NewArrayExprContext::New() {
  return getToken(MxParser::New, 0);
}

MxParser::BasicTypeContext* MxParser::NewArrayExprContext::basicType() {
  return getRuleContext<MxParser::BasicTypeContext>(0);
}

std::vector<MxParser::ArrayIndexContext *> MxParser::NewArrayExprContext::arrayIndex() {
  return getRuleContexts<MxParser::ArrayIndexContext>();
}

MxParser::ArrayIndexContext* MxParser::NewArrayExprContext::arrayIndex(size_t i) {
  return getRuleContext<MxParser::ArrayIndexContext>(i);
}

std::vector<tree::TerminalNode *> MxParser::NewArrayExprContext::LeftBracket() {
  return getTokens(MxParser::LeftBracket);
}

tree::TerminalNode* MxParser::NewArrayExprContext::LeftBracket(size_t i) {
  return getToken(MxParser::LeftBracket, i);
}

std::vector<tree::TerminalNode *> MxParser::NewArrayExprContext::RightBracket() {
  return getTokens(MxParser::RightBracket);
}

tree::TerminalNode* MxParser::NewArrayExprContext::RightBracket(size_t i) {
  return getToken(MxParser::RightBracket, i);
}


size_t MxParser::NewArrayExprContext::getRuleIndex() const {
  return MxParser::RuleNewArrayExpr;
}

void MxParser::NewArrayExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MxParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterNewArrayExpr(this);
}

void MxParser::NewArrayExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MxParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitNewArrayExpr(this);
}

MxParser::NewArrayExprContext* MxParser::newArrayExpr() {
  NewArrayExprContext *_localctx = _tracker.createInstance<NewArrayExprContext>(_ctx, getState());
  enterRule(_localctx, 56, MxParser::RuleNewArrayExpr);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(343);
    match(MxParser::New);
    setState(344);
    basicType();

    setState(346); 
    _errHandler->sync(this);
    alt = 1;
    do {
      switch (alt) {
        case 1: {
              setState(345);
              arrayIndex();
              break;
            }

      default:
        throw NoViableAltException(this);
      }
      setState(348); 
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 28, _ctx);
    } while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER);
    setState(354);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == MxParser::LeftBracket) {
      setState(350);
      match(MxParser::LeftBracket);
      setState(351);
      match(MxParser::RightBracket);
      setState(356);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- NewObjExprContext ------------------------------------------------------------------

MxParser::NewObjExprContext::NewObjExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MxParser::NewObjExprContext::New() {
  return getToken(MxParser::New, 0);
}

MxParser::BasicTypeContext* MxParser::NewObjExprContext::basicType() {
  return getRuleContext<MxParser::BasicTypeContext>(0);
}

tree::TerminalNode* MxParser::NewObjExprContext::LeftParen() {
  return getToken(MxParser::LeftParen, 0);
}

tree::TerminalNode* MxParser::NewObjExprContext::RightParen() {
  return getToken(MxParser::RightParen, 0);
}


size_t MxParser::NewObjExprContext::getRuleIndex() const {
  return MxParser::RuleNewObjExpr;
}

void MxParser::NewObjExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MxParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterNewObjExpr(this);
}

void MxParser::NewObjExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MxParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitNewObjExpr(this);
}

MxParser::NewObjExprContext* MxParser::newObjExpr() {
  NewObjExprContext *_localctx = _tracker.createInstance<NewObjExprContext>(_ctx, getState());
  enterRule(_localctx, 58, MxParser::RuleNewObjExpr);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(357);
    match(MxParser::New);
    setState(358);
    basicType();
    setState(361);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == MxParser::LeftParen) {
      setState(359);
      match(MxParser::LeftParen);
      setState(360);
      match(MxParser::RightParen);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ArrayIndexContext ------------------------------------------------------------------

MxParser::ArrayIndexContext::ArrayIndexContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MxParser::ArrayIndexContext::LeftBracket() {
  return getToken(MxParser::LeftBracket, 0);
}

MxParser::ExpressionContext* MxParser::ArrayIndexContext::expression() {
  return getRuleContext<MxParser::ExpressionContext>(0);
}

tree::TerminalNode* MxParser::ArrayIndexContext::RightBracket() {
  return getToken(MxParser::RightBracket, 0);
}


size_t MxParser::ArrayIndexContext::getRuleIndex() const {
  return MxParser::RuleArrayIndex;
}

void MxParser::ArrayIndexContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MxParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterArrayIndex(this);
}

void MxParser::ArrayIndexContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MxParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitArrayIndex(this);
}

MxParser::ArrayIndexContext* MxParser::arrayIndex() {
  ArrayIndexContext *_localctx = _tracker.createInstance<ArrayIndexContext>(_ctx, getState());
  enterRule(_localctx, 60, MxParser::RuleArrayIndex);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(363);
    match(MxParser::LeftBracket);
    setState(364);
    expression();
    setState(365);
    match(MxParser::RightBracket);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- EqualOpContext ------------------------------------------------------------------

MxParser::EqualOpContext::EqualOpContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MxParser::EqualOpContext::Equal() {
  return getToken(MxParser::Equal, 0);
}

tree::TerminalNode* MxParser::EqualOpContext::NotEqual() {
  return getToken(MxParser::NotEqual, 0);
}


size_t MxParser::EqualOpContext::getRuleIndex() const {
  return MxParser::RuleEqualOp;
}

void MxParser::EqualOpContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MxParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterEqualOp(this);
}

void MxParser::EqualOpContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MxParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitEqualOp(this);
}

MxParser::EqualOpContext* MxParser::equalOp() {
  EqualOpContext *_localctx = _tracker.createInstance<EqualOpContext>(_ctx, getState());
  enterRule(_localctx, 62, MxParser::RuleEqualOp);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(367);
    _la = _input->LA(1);
    if (!(_la == MxParser::NotEqual

    || _la == MxParser::Equal)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- RelationOpContext ------------------------------------------------------------------

MxParser::RelationOpContext::RelationOpContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MxParser::RelationOpContext::Less() {
  return getToken(MxParser::Less, 0);
}

tree::TerminalNode* MxParser::RelationOpContext::Greater() {
  return getToken(MxParser::Greater, 0);
}

tree::TerminalNode* MxParser::RelationOpContext::LessEqual() {
  return getToken(MxParser::LessEqual, 0);
}

tree::TerminalNode* MxParser::RelationOpContext::GreaterEqual() {
  return getToken(MxParser::GreaterEqual, 0);
}


size_t MxParser::RelationOpContext::getRuleIndex() const {
  return MxParser::RuleRelationOp;
}

void MxParser::RelationOpContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MxParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterRelationOp(this);
}

void MxParser::RelationOpContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MxParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitRelationOp(this);
}

MxParser::RelationOpContext* MxParser::relationOp() {
  RelationOpContext *_localctx = _tracker.createInstance<RelationOpContext>(_ctx, getState());
  enterRule(_localctx, 64, MxParser::RuleRelationOp);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(369);
    _la = _input->LA(1);
    if (!(((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 62914560) != 0)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ShiftOpContext ------------------------------------------------------------------

MxParser::ShiftOpContext::ShiftOpContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MxParser::ShiftOpContext::LeftShift() {
  return getToken(MxParser::LeftShift, 0);
}

tree::TerminalNode* MxParser::ShiftOpContext::RightShift() {
  return getToken(MxParser::RightShift, 0);
}


size_t MxParser::ShiftOpContext::getRuleIndex() const {
  return MxParser::RuleShiftOp;
}

void MxParser::ShiftOpContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MxParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterShiftOp(this);
}

void MxParser::ShiftOpContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MxParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitShiftOp(this);
}

MxParser::ShiftOpContext* MxParser::shiftOp() {
  ShiftOpContext *_localctx = _tracker.createInstance<ShiftOpContext>(_ctx, getState());
  enterRule(_localctx, 66, MxParser::RuleShiftOp);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(371);
    _la = _input->LA(1);
    if (!(_la == MxParser::RightShift

    || _la == MxParser::LeftShift)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AddOpContext ------------------------------------------------------------------

MxParser::AddOpContext::AddOpContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MxParser::AddOpContext::Plus() {
  return getToken(MxParser::Plus, 0);
}

tree::TerminalNode* MxParser::AddOpContext::Minus() {
  return getToken(MxParser::Minus, 0);
}


size_t MxParser::AddOpContext::getRuleIndex() const {
  return MxParser::RuleAddOp;
}

void MxParser::AddOpContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MxParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAddOp(this);
}

void MxParser::AddOpContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MxParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAddOp(this);
}

MxParser::AddOpContext* MxParser::addOp() {
  AddOpContext *_localctx = _tracker.createInstance<AddOpContext>(_ctx, getState());
  enterRule(_localctx, 68, MxParser::RuleAddOp);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(373);
    _la = _input->LA(1);
    if (!(_la == MxParser::Plus

    || _la == MxParser::Minus)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- MultiOpContext ------------------------------------------------------------------

MxParser::MultiOpContext::MultiOpContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MxParser::MultiOpContext::Star() {
  return getToken(MxParser::Star, 0);
}

tree::TerminalNode* MxParser::MultiOpContext::Div() {
  return getToken(MxParser::Div, 0);
}

tree::TerminalNode* MxParser::MultiOpContext::Mod() {
  return getToken(MxParser::Mod, 0);
}


size_t MxParser::MultiOpContext::getRuleIndex() const {
  return MxParser::RuleMultiOp;
}

void MxParser::MultiOpContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MxParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMultiOp(this);
}

void MxParser::MultiOpContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MxParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMultiOp(this);
}

MxParser::MultiOpContext* MxParser::multiOp() {
  MultiOpContext *_localctx = _tracker.createInstance<MultiOpContext>(_ctx, getState());
  enterRule(_localctx, 70, MxParser::RuleMultiOp);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(375);
    _la = _input->LA(1);
    if (!(((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 3670016) != 0)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- PrefixUnaryOpContext ------------------------------------------------------------------

MxParser::PrefixUnaryOpContext::PrefixUnaryOpContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MxParser::PrefixUnaryOpContext::PlusPlus() {
  return getToken(MxParser::PlusPlus, 0);
}

tree::TerminalNode* MxParser::PrefixUnaryOpContext::MinusMinus() {
  return getToken(MxParser::MinusMinus, 0);
}

tree::TerminalNode* MxParser::PrefixUnaryOpContext::Not() {
  return getToken(MxParser::Not, 0);
}

tree::TerminalNode* MxParser::PrefixUnaryOpContext::Tilde() {
  return getToken(MxParser::Tilde, 0);
}

tree::TerminalNode* MxParser::PrefixUnaryOpContext::Minus() {
  return getToken(MxParser::Minus, 0);
}


size_t MxParser::PrefixUnaryOpContext::getRuleIndex() const {
  return MxParser::RulePrefixUnaryOp;
}

void MxParser::PrefixUnaryOpContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MxParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPrefixUnaryOp(this);
}

void MxParser::PrefixUnaryOpContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MxParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPrefixUnaryOp(this);
}

MxParser::PrefixUnaryOpContext* MxParser::prefixUnaryOp() {
  PrefixUnaryOpContext *_localctx = _tracker.createInstance<PrefixUnaryOpContext>(_ctx, getState());
  enterRule(_localctx, 72, MxParser::RulePrefixUnaryOp);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(377);
    _la = _input->LA(1);
    if (!(((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 894427201536) != 0)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SuffixUnaryOpContext ------------------------------------------------------------------

MxParser::SuffixUnaryOpContext::SuffixUnaryOpContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MxParser::SuffixUnaryOpContext::PlusPlus() {
  return getToken(MxParser::PlusPlus, 0);
}

tree::TerminalNode* MxParser::SuffixUnaryOpContext::MinusMinus() {
  return getToken(MxParser::MinusMinus, 0);
}


size_t MxParser::SuffixUnaryOpContext::getRuleIndex() const {
  return MxParser::RuleSuffixUnaryOp;
}

void MxParser::SuffixUnaryOpContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MxParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSuffixUnaryOp(this);
}

void MxParser::SuffixUnaryOpContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MxParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSuffixUnaryOp(this);
}

MxParser::SuffixUnaryOpContext* MxParser::suffixUnaryOp() {
  SuffixUnaryOpContext *_localctx = _tracker.createInstance<SuffixUnaryOpContext>(_ctx, getState());
  enterRule(_localctx, 74, MxParser::RuleSuffixUnaryOp);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(379);
    _la = _input->LA(1);
    if (!(_la == MxParser::PlusPlus

    || _la == MxParser::MinusMinus)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- LiteralContext ------------------------------------------------------------------

MxParser::LiteralContext::LiteralContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MxParser::LiteralContext::IntLiteral() {
  return getToken(MxParser::IntLiteral, 0);
}

tree::TerminalNode* MxParser::LiteralContext::True() {
  return getToken(MxParser::True, 0);
}

tree::TerminalNode* MxParser::LiteralContext::False() {
  return getToken(MxParser::False, 0);
}

tree::TerminalNode* MxParser::LiteralContext::NullLiteral() {
  return getToken(MxParser::NullLiteral, 0);
}

tree::TerminalNode* MxParser::LiteralContext::StringLiteral() {
  return getToken(MxParser::StringLiteral, 0);
}


size_t MxParser::LiteralContext::getRuleIndex() const {
  return MxParser::RuleLiteral;
}

void MxParser::LiteralContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MxParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLiteral(this);
}

void MxParser::LiteralContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MxParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLiteral(this);
}

MxParser::LiteralContext* MxParser::literal() {
  LiteralContext *_localctx = _tracker.createInstance<LiteralContext>(_ctx, getState());
  enterRule(_localctx, 76, MxParser::RuleLiteral);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(381);
    _la = _input->LA(1);
    if (!(((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 504403158265495936) != 0)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FuncStmtContext ------------------------------------------------------------------

MxParser::FuncStmtContext::FuncStmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

MxParser::VarDefContext* MxParser::FuncStmtContext::varDef() {
  return getRuleContext<MxParser::VarDefContext>(0);
}

MxParser::IfStmtContext* MxParser::FuncStmtContext::ifStmt() {
  return getRuleContext<MxParser::IfStmtContext>(0);
}

MxParser::WhileStmtContext* MxParser::FuncStmtContext::whileStmt() {
  return getRuleContext<MxParser::WhileStmtContext>(0);
}

MxParser::ForStmtContext* MxParser::FuncStmtContext::forStmt() {
  return getRuleContext<MxParser::ForStmtContext>(0);
}

MxParser::ReturnStmtContext* MxParser::FuncStmtContext::returnStmt() {
  return getRuleContext<MxParser::ReturnStmtContext>(0);
}

MxParser::BreakStmtContext* MxParser::FuncStmtContext::breakStmt() {
  return getRuleContext<MxParser::BreakStmtContext>(0);
}

MxParser::ContinueStmtContext* MxParser::FuncStmtContext::continueStmt() {
  return getRuleContext<MxParser::ContinueStmtContext>(0);
}

MxParser::ExprStmtContext* MxParser::FuncStmtContext::exprStmt() {
  return getRuleContext<MxParser::ExprStmtContext>(0);
}

MxParser::MultiStmtBlockContext* MxParser::FuncStmtContext::multiStmtBlock() {
  return getRuleContext<MxParser::MultiStmtBlockContext>(0);
}

MxParser::BlankStmtContext* MxParser::FuncStmtContext::blankStmt() {
  return getRuleContext<MxParser::BlankStmtContext>(0);
}


size_t MxParser::FuncStmtContext::getRuleIndex() const {
  return MxParser::RuleFuncStmt;
}

void MxParser::FuncStmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MxParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFuncStmt(this);
}

void MxParser::FuncStmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MxParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFuncStmt(this);
}

MxParser::FuncStmtContext* MxParser::funcStmt() {
  FuncStmtContext *_localctx = _tracker.createInstance<FuncStmtContext>(_ctx, getState());
  enterRule(_localctx, 78, MxParser::RuleFuncStmt);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(393);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 31, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(383);
      varDef();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(384);
      ifStmt();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(385);
      whileStmt();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(386);
      forStmt();
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(387);
      returnStmt();
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(388);
      breakStmt();
      break;
    }

    case 7: {
      enterOuterAlt(_localctx, 7);
      setState(389);
      continueStmt();
      break;
    }

    case 8: {
      enterOuterAlt(_localctx, 8);
      setState(390);
      exprStmt();
      break;
    }

    case 9: {
      enterOuterAlt(_localctx, 9);
      setState(391);
      multiStmtBlock();
      break;
    }

    case 10: {
      enterOuterAlt(_localctx, 10);
      setState(392);
      blankStmt();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- IfStmtContext ------------------------------------------------------------------

MxParser::IfStmtContext::IfStmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MxParser::IfStmtContext::If() {
  return getToken(MxParser::If, 0);
}

MxParser::ConditionContext* MxParser::IfStmtContext::condition() {
  return getRuleContext<MxParser::ConditionContext>(0);
}

MxParser::BlockContext* MxParser::IfStmtContext::block() {
  return getRuleContext<MxParser::BlockContext>(0);
}

MxParser::ElseStmtContext* MxParser::IfStmtContext::elseStmt() {
  return getRuleContext<MxParser::ElseStmtContext>(0);
}


size_t MxParser::IfStmtContext::getRuleIndex() const {
  return MxParser::RuleIfStmt;
}

void MxParser::IfStmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MxParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIfStmt(this);
}

void MxParser::IfStmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MxParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIfStmt(this);
}

MxParser::IfStmtContext* MxParser::ifStmt() {
  IfStmtContext *_localctx = _tracker.createInstance<IfStmtContext>(_ctx, getState());
  enterRule(_localctx, 80, MxParser::RuleIfStmt);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(395);
    match(MxParser::If);
    setState(396);
    condition();
    setState(397);
    block();
    setState(399);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 32, _ctx)) {
    case 1: {
      setState(398);
      elseStmt();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ElseStmtContext ------------------------------------------------------------------

MxParser::ElseStmtContext::ElseStmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MxParser::ElseStmtContext::Else() {
  return getToken(MxParser::Else, 0);
}

MxParser::BlockContext* MxParser::ElseStmtContext::block() {
  return getRuleContext<MxParser::BlockContext>(0);
}


size_t MxParser::ElseStmtContext::getRuleIndex() const {
  return MxParser::RuleElseStmt;
}

void MxParser::ElseStmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MxParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterElseStmt(this);
}

void MxParser::ElseStmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MxParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitElseStmt(this);
}

MxParser::ElseStmtContext* MxParser::elseStmt() {
  ElseStmtContext *_localctx = _tracker.createInstance<ElseStmtContext>(_ctx, getState());
  enterRule(_localctx, 82, MxParser::RuleElseStmt);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(401);
    match(MxParser::Else);
    setState(402);
    block();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- WhileStmtContext ------------------------------------------------------------------

MxParser::WhileStmtContext::WhileStmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MxParser::WhileStmtContext::While() {
  return getToken(MxParser::While, 0);
}

MxParser::ConditionContext* MxParser::WhileStmtContext::condition() {
  return getRuleContext<MxParser::ConditionContext>(0);
}

MxParser::BlockContext* MxParser::WhileStmtContext::block() {
  return getRuleContext<MxParser::BlockContext>(0);
}


size_t MxParser::WhileStmtContext::getRuleIndex() const {
  return MxParser::RuleWhileStmt;
}

void MxParser::WhileStmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MxParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterWhileStmt(this);
}

void MxParser::WhileStmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MxParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitWhileStmt(this);
}

MxParser::WhileStmtContext* MxParser::whileStmt() {
  WhileStmtContext *_localctx = _tracker.createInstance<WhileStmtContext>(_ctx, getState());
  enterRule(_localctx, 84, MxParser::RuleWhileStmt);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(404);
    match(MxParser::While);
    setState(405);
    condition();
    setState(406);
    block();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ForStmtContext ------------------------------------------------------------------

MxParser::ForStmtContext::ForStmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MxParser::ForStmtContext::For() {
  return getToken(MxParser::For, 0);
}

MxParser::ForConditionContext* MxParser::ForStmtContext::forCondition() {
  return getRuleContext<MxParser::ForConditionContext>(0);
}

MxParser::BlockContext* MxParser::ForStmtContext::block() {
  return getRuleContext<MxParser::BlockContext>(0);
}


size_t MxParser::ForStmtContext::getRuleIndex() const {
  return MxParser::RuleForStmt;
}

void MxParser::ForStmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MxParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterForStmt(this);
}

void MxParser::ForStmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MxParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitForStmt(this);
}

MxParser::ForStmtContext* MxParser::forStmt() {
  ForStmtContext *_localctx = _tracker.createInstance<ForStmtContext>(_ctx, getState());
  enterRule(_localctx, 86, MxParser::RuleForStmt);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(408);
    match(MxParser::For);
    setState(409);
    forCondition();
    setState(410);
    block();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- MemberStmtContext ------------------------------------------------------------------

MxParser::MemberStmtContext::MemberStmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

MxParser::VarDefContext* MxParser::MemberStmtContext::varDef() {
  return getRuleContext<MxParser::VarDefContext>(0);
}

MxParser::ConstructFuncDefContext* MxParser::MemberStmtContext::constructFuncDef() {
  return getRuleContext<MxParser::ConstructFuncDefContext>(0);
}

MxParser::FuncDefContext* MxParser::MemberStmtContext::funcDef() {
  return getRuleContext<MxParser::FuncDefContext>(0);
}


size_t MxParser::MemberStmtContext::getRuleIndex() const {
  return MxParser::RuleMemberStmt;
}

void MxParser::MemberStmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MxParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMemberStmt(this);
}

void MxParser::MemberStmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MxParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMemberStmt(this);
}

MxParser::MemberStmtContext* MxParser::memberStmt() {
  MemberStmtContext *_localctx = _tracker.createInstance<MemberStmtContext>(_ctx, getState());
  enterRule(_localctx, 88, MxParser::RuleMemberStmt);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(415);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 33, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(412);
      varDef();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(413);
      constructFuncDef();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(414);
      funcDef();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- LeftValueContext ------------------------------------------------------------------

MxParser::LeftValueContext::LeftValueContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MxParser::LeftValueContext::Identifier() {
  return getToken(MxParser::Identifier, 0);
}

MxParser::LeftValueContext* MxParser::LeftValueContext::leftValue() {
  return getRuleContext<MxParser::LeftValueContext>(0);
}

MxParser::ArrayIndexContext* MxParser::LeftValueContext::arrayIndex() {
  return getRuleContext<MxParser::ArrayIndexContext>(0);
}

tree::TerminalNode* MxParser::LeftValueContext::Dot() {
  return getToken(MxParser::Dot, 0);
}


size_t MxParser::LeftValueContext::getRuleIndex() const {
  return MxParser::RuleLeftValue;
}

void MxParser::LeftValueContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MxParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLeftValue(this);
}

void MxParser::LeftValueContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MxParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLeftValue(this);
}


MxParser::LeftValueContext* MxParser::leftValue() {
   return leftValue(0);
}

MxParser::LeftValueContext* MxParser::leftValue(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  MxParser::LeftValueContext *_localctx = _tracker.createInstance<LeftValueContext>(_ctx, parentState);
  MxParser::LeftValueContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 90;
  enterRecursionRule(_localctx, 90, MxParser::RuleLeftValue, precedence);

    

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(418);
    match(MxParser::Identifier);
    _ctx->stop = _input->LT(-1);
    setState(427);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 35, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(425);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 34, _ctx)) {
        case 1: {
          _localctx = _tracker.createInstance<LeftValueContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleLeftValue);
          setState(420);

          if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
          setState(421);
          arrayIndex();
          break;
        }

        case 2: {
          _localctx = _tracker.createInstance<LeftValueContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleLeftValue);
          setState(422);

          if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
          setState(423);
          match(MxParser::Dot);
          setState(424);
          match(MxParser::Identifier);
          break;
        }

        default:
          break;
        } 
      }
      setState(429);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 35, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- ConditionContext ------------------------------------------------------------------

MxParser::ConditionContext::ConditionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MxParser::ConditionContext::LeftParen() {
  return getToken(MxParser::LeftParen, 0);
}

MxParser::ExpressionContext* MxParser::ConditionContext::expression() {
  return getRuleContext<MxParser::ExpressionContext>(0);
}

tree::TerminalNode* MxParser::ConditionContext::RightParen() {
  return getToken(MxParser::RightParen, 0);
}


size_t MxParser::ConditionContext::getRuleIndex() const {
  return MxParser::RuleCondition;
}

void MxParser::ConditionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MxParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCondition(this);
}

void MxParser::ConditionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MxParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCondition(this);
}

MxParser::ConditionContext* MxParser::condition() {
  ConditionContext *_localctx = _tracker.createInstance<ConditionContext>(_ctx, getState());
  enterRule(_localctx, 92, MxParser::RuleCondition);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(430);
    match(MxParser::LeftParen);
    setState(431);
    expression();
    setState(432);
    match(MxParser::RightParen);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ForConditionContext ------------------------------------------------------------------

MxParser::ForConditionContext::ForConditionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MxParser::ForConditionContext::LeftParen() {
  return getToken(MxParser::LeftParen, 0);
}

std::vector<tree::TerminalNode *> MxParser::ForConditionContext::Semi() {
  return getTokens(MxParser::Semi);
}

tree::TerminalNode* MxParser::ForConditionContext::Semi(size_t i) {
  return getToken(MxParser::Semi, i);
}

tree::TerminalNode* MxParser::ForConditionContext::RightParen() {
  return getToken(MxParser::RightParen, 0);
}

std::vector<MxParser::ExpressionContext *> MxParser::ForConditionContext::expression() {
  return getRuleContexts<MxParser::ExpressionContext>();
}

MxParser::ExpressionContext* MxParser::ForConditionContext::expression(size_t i) {
  return getRuleContext<MxParser::ExpressionContext>(i);
}


size_t MxParser::ForConditionContext::getRuleIndex() const {
  return MxParser::RuleForCondition;
}

void MxParser::ForConditionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MxParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterForCondition(this);
}

void MxParser::ForConditionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MxParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitForCondition(this);
}

MxParser::ForConditionContext* MxParser::forCondition() {
  ForConditionContext *_localctx = _tracker.createInstance<ForConditionContext>(_ctx, getState());
  enterRule(_localctx, 94, MxParser::RuleForCondition);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(434);
    match(MxParser::LeftParen);
    setState(436);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 540441645804684192) != 0) {
      setState(435);
      expression();
    }
    setState(438);
    match(MxParser::Semi);
    setState(440);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 540441645804684192) != 0) {
      setState(439);
      expression();
    }
    setState(442);
    match(MxParser::Semi);
    setState(444);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 540441645804684192) != 0) {
      setState(443);
      expression();
    }
    setState(446);
    match(MxParser::RightParen);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BlockContext ------------------------------------------------------------------

MxParser::BlockContext::BlockContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

MxParser::MultiStmtBlockContext* MxParser::BlockContext::multiStmtBlock() {
  return getRuleContext<MxParser::MultiStmtBlockContext>(0);
}

MxParser::FuncStmtContext* MxParser::BlockContext::funcStmt() {
  return getRuleContext<MxParser::FuncStmtContext>(0);
}


size_t MxParser::BlockContext::getRuleIndex() const {
  return MxParser::RuleBlock;
}

void MxParser::BlockContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MxParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBlock(this);
}

void MxParser::BlockContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MxParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBlock(this);
}

MxParser::BlockContext* MxParser::block() {
  BlockContext *_localctx = _tracker.createInstance<BlockContext>(_ctx, getState());
  enterRule(_localctx, 96, MxParser::RuleBlock);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(450);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 39, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(448);
      multiStmtBlock();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(449);
      funcStmt();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- MultiStmtBlockContext ------------------------------------------------------------------

MxParser::MultiStmtBlockContext::MultiStmtBlockContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MxParser::MultiStmtBlockContext::LeftBrace() {
  return getToken(MxParser::LeftBrace, 0);
}

tree::TerminalNode* MxParser::MultiStmtBlockContext::RightBrace() {
  return getToken(MxParser::RightBrace, 0);
}

std::vector<MxParser::FuncStmtContext *> MxParser::MultiStmtBlockContext::funcStmt() {
  return getRuleContexts<MxParser::FuncStmtContext>();
}

MxParser::FuncStmtContext* MxParser::MultiStmtBlockContext::funcStmt(size_t i) {
  return getRuleContext<MxParser::FuncStmtContext>(i);
}


size_t MxParser::MultiStmtBlockContext::getRuleIndex() const {
  return MxParser::RuleMultiStmtBlock;
}

void MxParser::MultiStmtBlockContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MxParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMultiStmtBlock(this);
}

void MxParser::MultiStmtBlockContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MxParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMultiStmtBlock(this);
}

MxParser::MultiStmtBlockContext* MxParser::multiStmtBlock() {
  MultiStmtBlockContext *_localctx = _tracker.createInstance<MultiStmtBlockContext>(_ctx, getState());
  enterRule(_localctx, 98, MxParser::RuleMultiStmtBlock);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(452);
    match(MxParser::LeftBrace);
    setState(456);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 40, _ctx);
    while (alt != 1 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1 + 1) {
        setState(453);
        funcStmt(); 
      }
      setState(458);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 40, _ctx);
    }
    setState(459);
    match(MxParser::RightBrace);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ReturnStmtContext ------------------------------------------------------------------

MxParser::ReturnStmtContext::ReturnStmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MxParser::ReturnStmtContext::Return() {
  return getToken(MxParser::Return, 0);
}

tree::TerminalNode* MxParser::ReturnStmtContext::Semi() {
  return getToken(MxParser::Semi, 0);
}

MxParser::ExpressionContext* MxParser::ReturnStmtContext::expression() {
  return getRuleContext<MxParser::ExpressionContext>(0);
}


size_t MxParser::ReturnStmtContext::getRuleIndex() const {
  return MxParser::RuleReturnStmt;
}

void MxParser::ReturnStmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MxParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterReturnStmt(this);
}

void MxParser::ReturnStmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MxParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitReturnStmt(this);
}

MxParser::ReturnStmtContext* MxParser::returnStmt() {
  ReturnStmtContext *_localctx = _tracker.createInstance<ReturnStmtContext>(_ctx, getState());
  enterRule(_localctx, 100, MxParser::RuleReturnStmt);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(461);
    match(MxParser::Return);
    setState(463);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 540441645804684192) != 0) {
      setState(462);
      expression();
    }
    setState(465);
    match(MxParser::Semi);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BreakStmtContext ------------------------------------------------------------------

MxParser::BreakStmtContext::BreakStmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MxParser::BreakStmtContext::Break() {
  return getToken(MxParser::Break, 0);
}

tree::TerminalNode* MxParser::BreakStmtContext::Semi() {
  return getToken(MxParser::Semi, 0);
}


size_t MxParser::BreakStmtContext::getRuleIndex() const {
  return MxParser::RuleBreakStmt;
}

void MxParser::BreakStmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MxParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBreakStmt(this);
}

void MxParser::BreakStmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MxParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBreakStmt(this);
}

MxParser::BreakStmtContext* MxParser::breakStmt() {
  BreakStmtContext *_localctx = _tracker.createInstance<BreakStmtContext>(_ctx, getState());
  enterRule(_localctx, 102, MxParser::RuleBreakStmt);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(467);
    match(MxParser::Break);
    setState(468);
    match(MxParser::Semi);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ContinueStmtContext ------------------------------------------------------------------

MxParser::ContinueStmtContext::ContinueStmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MxParser::ContinueStmtContext::Continue() {
  return getToken(MxParser::Continue, 0);
}

tree::TerminalNode* MxParser::ContinueStmtContext::Semi() {
  return getToken(MxParser::Semi, 0);
}


size_t MxParser::ContinueStmtContext::getRuleIndex() const {
  return MxParser::RuleContinueStmt;
}

void MxParser::ContinueStmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MxParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterContinueStmt(this);
}

void MxParser::ContinueStmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MxParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitContinueStmt(this);
}

MxParser::ContinueStmtContext* MxParser::continueStmt() {
  ContinueStmtContext *_localctx = _tracker.createInstance<ContinueStmtContext>(_ctx, getState());
  enterRule(_localctx, 104, MxParser::RuleContinueStmt);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(470);
    match(MxParser::Continue);
    setState(471);
    match(MxParser::Semi);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExprStmtContext ------------------------------------------------------------------

MxParser::ExprStmtContext::ExprStmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

MxParser::ExpressionContext* MxParser::ExprStmtContext::expression() {
  return getRuleContext<MxParser::ExpressionContext>(0);
}

tree::TerminalNode* MxParser::ExprStmtContext::Semi() {
  return getToken(MxParser::Semi, 0);
}


size_t MxParser::ExprStmtContext::getRuleIndex() const {
  return MxParser::RuleExprStmt;
}

void MxParser::ExprStmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MxParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExprStmt(this);
}

void MxParser::ExprStmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MxParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExprStmt(this);
}

MxParser::ExprStmtContext* MxParser::exprStmt() {
  ExprStmtContext *_localctx = _tracker.createInstance<ExprStmtContext>(_ctx, getState());
  enterRule(_localctx, 106, MxParser::RuleExprStmt);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(473);
    expression();
    setState(474);
    match(MxParser::Semi);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BlankStmtContext ------------------------------------------------------------------

MxParser::BlankStmtContext::BlankStmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MxParser::BlankStmtContext::Semi() {
  return getToken(MxParser::Semi, 0);
}


size_t MxParser::BlankStmtContext::getRuleIndex() const {
  return MxParser::RuleBlankStmt;
}

void MxParser::BlankStmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MxParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBlankStmt(this);
}

void MxParser::BlankStmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MxParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBlankStmt(this);
}

MxParser::BlankStmtContext* MxParser::blankStmt() {
  BlankStmtContext *_localctx = _tracker.createInstance<BlankStmtContext>(_ctx, getState());
  enterRule(_localctx, 108, MxParser::RuleBlankStmt);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(476);
    match(MxParser::Semi);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

bool MxParser::sempred(RuleContext *context, size_t ruleIndex, size_t predicateIndex) {
  switch (ruleIndex) {
    case 25: return postfixExprSempred(antlrcpp::downCast<PostfixExprContext *>(context), predicateIndex);
    case 45: return leftValueSempred(antlrcpp::downCast<LeftValueContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool MxParser::postfixExprSempred(PostfixExprContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 4);
    case 1: return precpred(_ctx, 3);
    case 2: return precpred(_ctx, 2);
    case 3: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool MxParser::leftValueSempred(LeftValueContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 4: return precpred(_ctx, 2);
    case 5: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

void MxParser::initialize() {
  ::antlr4::internal::call_once(mxparserParserOnceFlag, mxparserParserInitialize);
}
