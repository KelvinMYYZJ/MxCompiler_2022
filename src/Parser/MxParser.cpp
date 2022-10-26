
// Generated from MxParser.g4 by ANTLR 4.11.1


#include "MxParserListener.h"
#include "MxParserVisitor.h"

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
      "prog", "definition", "varDef", "singleVarDef", "classDef", "classBody", 
      "funcDef", "argListDef", "argList", "constructFuncDef", "typeName", 
      "basicType", "stmtBlock", "expression", "assignExpr", "orOrExpr", 
      "andAndExpr", "orExpr", "xorExpr", "andExpr", "equalityExpr", "relationExpr", 
      "shiftExpr", "addExpr", "multiExpr", "unaryExpr", "postfixExpr", "primaryExpr", 
      "lambdaExpr", "newExpr", "newArrayExpr", "newObjExpr", "arrayIndex", 
      "equalOp", "relationOp", "shiftOp", "addOp", "multiOp", "prefixUnaryOp", 
      "suffixUnaryOp", "literal", "funcStmt", "ifStmt", "elseStmt", "whileStmt", 
      "forStmt", "memberStmt", "leftValue", "condition", "forCondition", 
      "block", "returnStmt", "breakStmt", "continueStmt", "exprStmt", "blankStmt"
    },
    std::vector<std::string>{
      "", "'void'", "'bool'", "'int'", "'string'", "'new'", "'class'", "", 
      "'true'", "'false'", "'this'", "'if'", "'else'", "'for'", "'while'", 
      "'break'", "'continue'", "'return'", "'+'", "'-'", "'*'", "'/'", "'%'", 
      "'>'", "'<'", "'>='", "'<='", "'!='", "'=='", "'&&'", "'||'", "'!'", 
      "'>>'", "'<<'", "'&'", "'|'", "'^'", "'~'", "'='", "'++'", "'--'", 
      "'.'", "'->'", "'['", "']'", "'('", "')'", "','", "';'", "'{'", "'}'", 
      "", "", "' '", "'\\t'", "'\\n'", "'//'"
    },
    std::vector<std::string>{
      "", "Void", "Bool", "Int", "String", "New", "Class", "NullLiteral", 
      "True", "False", "This", "If", "Else", "For", "While", "Break", "Continue", 
      "Return", "Plus", "Minus", "Star", "Div", "Mod", "Greater", "Less", 
      "GreaterEqual", "LessEqual", "NotEqual", "Equal", "AndAnd", "OrOr", 
      "Not", "RightShift", "LeftShift", "And", "Or", "Caret", "Tilde", "Assign", 
      "PlusPlus", "MinusMinus", "Dot", "Arrow", "LeftBracket", "RightBracket", 
      "LeftParen", "RightParen", "Comma", "Semi", "LeftBrace", "RightBrace", 
      "LineComment", "BlockComment", "Space", "Tab", "Eol", "Comment", "Identifier", 
      "IntLiteral", "StringLiteral"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,1,59,479,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,6,2,
  	7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,7,
  	14,2,15,7,15,2,16,7,16,2,17,7,17,2,18,7,18,2,19,7,19,2,20,7,20,2,21,7,
  	21,2,22,7,22,2,23,7,23,2,24,7,24,2,25,7,25,2,26,7,26,2,27,7,27,2,28,7,
  	28,2,29,7,29,2,30,7,30,2,31,7,31,2,32,7,32,2,33,7,33,2,34,7,34,2,35,7,
  	35,2,36,7,36,2,37,7,37,2,38,7,38,2,39,7,39,2,40,7,40,2,41,7,41,2,42,7,
  	42,2,43,7,43,2,44,7,44,2,45,7,45,2,46,7,46,2,47,7,47,2,48,7,48,2,49,7,
  	49,2,50,7,50,2,51,7,51,2,52,7,52,2,53,7,53,2,54,7,54,2,55,7,55,1,0,5,
  	0,114,8,0,10,0,12,0,117,9,0,1,0,1,0,1,1,1,1,1,1,3,1,124,8,1,1,2,1,2,1,
  	2,1,2,5,2,130,8,2,10,2,12,2,133,9,2,1,2,1,2,1,3,1,3,1,3,3,3,140,8,3,1,
  	4,1,4,1,4,1,4,1,4,1,5,1,5,5,5,149,8,5,10,5,12,5,152,9,5,1,5,1,5,1,6,1,
  	6,1,6,1,6,1,6,1,7,1,7,1,7,1,7,1,7,1,7,1,7,5,7,168,8,7,10,7,12,7,171,9,
  	7,3,7,173,8,7,1,7,1,7,1,8,1,8,1,8,1,8,5,8,181,8,8,10,8,12,8,184,9,8,3,
  	8,186,8,8,1,8,1,8,1,9,1,9,1,9,1,9,1,9,1,10,1,10,1,10,5,10,198,8,10,10,
  	10,12,10,201,9,10,1,11,1,11,1,12,1,12,5,12,207,8,12,10,12,12,12,210,9,
  	12,1,12,1,12,1,13,1,13,1,14,1,14,1,14,3,14,219,8,14,1,15,1,15,1,15,5,
  	15,224,8,15,10,15,12,15,227,9,15,1,16,1,16,1,16,5,16,232,8,16,10,16,12,
  	16,235,9,16,1,17,1,17,1,17,5,17,240,8,17,10,17,12,17,243,9,17,1,18,1,
  	18,1,18,5,18,248,8,18,10,18,12,18,251,9,18,1,19,1,19,1,19,5,19,256,8,
  	19,10,19,12,19,259,9,19,1,20,1,20,1,20,1,20,5,20,265,8,20,10,20,12,20,
  	268,9,20,1,21,1,21,1,21,1,21,5,21,274,8,21,10,21,12,21,277,9,21,1,22,
  	1,22,1,22,1,22,5,22,283,8,22,10,22,12,22,286,9,22,1,23,1,23,1,23,1,23,
  	5,23,292,8,23,10,23,12,23,295,9,23,1,24,1,24,1,24,1,24,5,24,301,8,24,
  	10,24,12,24,304,9,24,1,25,1,25,1,25,1,25,1,25,3,25,311,8,25,1,26,1,26,
  	1,26,1,26,1,26,1,26,1,26,1,26,1,26,1,26,1,26,1,26,5,26,325,8,26,10,26,
  	12,26,328,9,26,1,27,1,27,1,27,1,27,1,27,1,27,1,27,1,27,3,27,338,8,27,
  	1,28,1,28,3,28,342,8,28,1,28,1,28,1,28,1,28,1,28,1,29,1,29,3,29,351,8,
  	29,1,30,1,30,1,30,4,30,356,8,30,11,30,12,30,357,1,30,1,30,5,30,362,8,
  	30,10,30,12,30,365,9,30,1,31,1,31,1,31,1,31,3,31,371,8,31,1,32,1,32,1,
  	32,1,32,1,33,1,33,1,34,1,34,1,35,1,35,1,36,1,36,1,37,1,37,1,38,1,38,1,
  	39,1,39,1,40,1,40,1,41,1,41,1,41,1,41,1,41,1,41,1,41,1,41,1,41,1,41,3,
  	41,403,8,41,1,42,1,42,1,42,1,42,3,42,409,8,42,1,43,1,43,1,43,1,44,1,44,
  	1,44,1,44,1,45,1,45,1,45,1,45,1,46,1,46,1,46,3,46,425,8,46,1,47,1,47,
  	1,47,1,47,1,47,1,47,1,47,1,47,5,47,435,8,47,10,47,12,47,438,9,47,1,48,
  	1,48,1,48,1,48,1,49,1,49,3,49,446,8,49,1,49,1,49,3,49,450,8,49,1,49,1,
  	49,3,49,454,8,49,1,49,1,49,1,50,1,50,3,50,460,8,50,1,51,1,51,3,51,464,
  	8,51,1,51,1,51,1,52,1,52,1,52,1,53,1,53,1,53,1,54,1,54,1,54,1,55,1,55,
  	1,55,3,131,169,182,2,52,94,56,0,2,4,6,8,10,12,14,16,18,20,22,24,26,28,
  	30,32,34,36,38,40,42,44,46,48,50,52,54,56,58,60,62,64,66,68,70,72,74,
  	76,78,80,82,84,86,88,90,92,94,96,98,100,102,104,106,108,110,0,9,2,0,1,
  	4,57,57,1,0,27,28,1,0,23,26,1,0,32,33,1,0,18,19,1,0,20,22,4,0,19,19,31,
  	31,37,37,39,40,1,0,39,40,2,0,7,9,58,59,479,0,115,1,0,0,0,2,123,1,0,0,
  	0,4,125,1,0,0,0,6,136,1,0,0,0,8,141,1,0,0,0,10,146,1,0,0,0,12,155,1,0,
  	0,0,14,160,1,0,0,0,16,176,1,0,0,0,18,189,1,0,0,0,20,194,1,0,0,0,22,202,
  	1,0,0,0,24,204,1,0,0,0,26,213,1,0,0,0,28,215,1,0,0,0,30,220,1,0,0,0,32,
  	228,1,0,0,0,34,236,1,0,0,0,36,244,1,0,0,0,38,252,1,0,0,0,40,260,1,0,0,
  	0,42,269,1,0,0,0,44,278,1,0,0,0,46,287,1,0,0,0,48,296,1,0,0,0,50,310,
  	1,0,0,0,52,312,1,0,0,0,54,337,1,0,0,0,56,339,1,0,0,0,58,350,1,0,0,0,60,
  	352,1,0,0,0,62,366,1,0,0,0,64,372,1,0,0,0,66,376,1,0,0,0,68,378,1,0,0,
  	0,70,380,1,0,0,0,72,382,1,0,0,0,74,384,1,0,0,0,76,386,1,0,0,0,78,388,
  	1,0,0,0,80,390,1,0,0,0,82,402,1,0,0,0,84,404,1,0,0,0,86,410,1,0,0,0,88,
  	413,1,0,0,0,90,417,1,0,0,0,92,424,1,0,0,0,94,426,1,0,0,0,96,439,1,0,0,
  	0,98,443,1,0,0,0,100,459,1,0,0,0,102,461,1,0,0,0,104,467,1,0,0,0,106,
  	470,1,0,0,0,108,473,1,0,0,0,110,476,1,0,0,0,112,114,3,2,1,0,113,112,1,
  	0,0,0,114,117,1,0,0,0,115,113,1,0,0,0,115,116,1,0,0,0,116,118,1,0,0,0,
  	117,115,1,0,0,0,118,119,5,0,0,1,119,1,1,0,0,0,120,124,3,12,6,0,121,124,
  	3,4,2,0,122,124,3,8,4,0,123,120,1,0,0,0,123,121,1,0,0,0,123,122,1,0,0,
  	0,124,3,1,0,0,0,125,126,3,20,10,0,126,131,3,6,3,0,127,128,5,47,0,0,128,
  	130,3,6,3,0,129,127,1,0,0,0,130,133,1,0,0,0,131,132,1,0,0,0,131,129,1,
  	0,0,0,132,134,1,0,0,0,133,131,1,0,0,0,134,135,5,48,0,0,135,5,1,0,0,0,
  	136,139,5,57,0,0,137,138,5,38,0,0,138,140,3,26,13,0,139,137,1,0,0,0,139,
  	140,1,0,0,0,140,7,1,0,0,0,141,142,5,6,0,0,142,143,5,57,0,0,143,144,3,
  	10,5,0,144,145,5,48,0,0,145,9,1,0,0,0,146,150,5,49,0,0,147,149,3,92,46,
  	0,148,147,1,0,0,0,149,152,1,0,0,0,150,148,1,0,0,0,150,151,1,0,0,0,151,
  	153,1,0,0,0,152,150,1,0,0,0,153,154,5,50,0,0,154,11,1,0,0,0,155,156,3,
  	20,10,0,156,157,5,57,0,0,157,158,3,14,7,0,158,159,3,24,12,0,159,13,1,
  	0,0,0,160,172,5,45,0,0,161,162,3,20,10,0,162,169,5,57,0,0,163,164,5,47,
  	0,0,164,165,3,20,10,0,165,166,5,57,0,0,166,168,1,0,0,0,167,163,1,0,0,
  	0,168,171,1,0,0,0,169,170,1,0,0,0,169,167,1,0,0,0,170,173,1,0,0,0,171,
  	169,1,0,0,0,172,161,1,0,0,0,172,173,1,0,0,0,173,174,1,0,0,0,174,175,5,
  	46,0,0,175,15,1,0,0,0,176,185,5,45,0,0,177,182,3,26,13,0,178,179,5,47,
  	0,0,179,181,3,26,13,0,180,178,1,0,0,0,181,184,1,0,0,0,182,183,1,0,0,0,
  	182,180,1,0,0,0,183,186,1,0,0,0,184,182,1,0,0,0,185,177,1,0,0,0,185,186,
  	1,0,0,0,186,187,1,0,0,0,187,188,5,46,0,0,188,17,1,0,0,0,189,190,5,57,
  	0,0,190,191,5,45,0,0,191,192,5,46,0,0,192,193,3,24,12,0,193,19,1,0,0,
  	0,194,199,3,22,11,0,195,196,5,43,0,0,196,198,5,44,0,0,197,195,1,0,0,0,
  	198,201,1,0,0,0,199,197,1,0,0,0,199,200,1,0,0,0,200,21,1,0,0,0,201,199,
  	1,0,0,0,202,203,7,0,0,0,203,23,1,0,0,0,204,208,5,49,0,0,205,207,3,82,
  	41,0,206,205,1,0,0,0,207,210,1,0,0,0,208,206,1,0,0,0,208,209,1,0,0,0,
  	209,211,1,0,0,0,210,208,1,0,0,0,211,212,5,50,0,0,212,25,1,0,0,0,213,214,
  	3,28,14,0,214,27,1,0,0,0,215,218,3,30,15,0,216,217,5,38,0,0,217,219,3,
  	30,15,0,218,216,1,0,0,0,218,219,1,0,0,0,219,29,1,0,0,0,220,225,3,32,16,
  	0,221,222,5,30,0,0,222,224,3,32,16,0,223,221,1,0,0,0,224,227,1,0,0,0,
  	225,223,1,0,0,0,225,226,1,0,0,0,226,31,1,0,0,0,227,225,1,0,0,0,228,233,
  	3,34,17,0,229,230,5,29,0,0,230,232,3,34,17,0,231,229,1,0,0,0,232,235,
  	1,0,0,0,233,231,1,0,0,0,233,234,1,0,0,0,234,33,1,0,0,0,235,233,1,0,0,
  	0,236,241,3,36,18,0,237,238,5,35,0,0,238,240,3,36,18,0,239,237,1,0,0,
  	0,240,243,1,0,0,0,241,239,1,0,0,0,241,242,1,0,0,0,242,35,1,0,0,0,243,
  	241,1,0,0,0,244,249,3,38,19,0,245,246,5,36,0,0,246,248,3,38,19,0,247,
  	245,1,0,0,0,248,251,1,0,0,0,249,247,1,0,0,0,249,250,1,0,0,0,250,37,1,
  	0,0,0,251,249,1,0,0,0,252,257,3,40,20,0,253,254,5,34,0,0,254,256,3,40,
  	20,0,255,253,1,0,0,0,256,259,1,0,0,0,257,255,1,0,0,0,257,258,1,0,0,0,
  	258,39,1,0,0,0,259,257,1,0,0,0,260,266,3,42,21,0,261,262,3,66,33,0,262,
  	263,3,42,21,0,263,265,1,0,0,0,264,261,1,0,0,0,265,268,1,0,0,0,266,264,
  	1,0,0,0,266,267,1,0,0,0,267,41,1,0,0,0,268,266,1,0,0,0,269,275,3,44,22,
  	0,270,271,3,68,34,0,271,272,3,44,22,0,272,274,1,0,0,0,273,270,1,0,0,0,
  	274,277,1,0,0,0,275,273,1,0,0,0,275,276,1,0,0,0,276,43,1,0,0,0,277,275,
  	1,0,0,0,278,284,3,46,23,0,279,280,3,70,35,0,280,281,3,46,23,0,281,283,
  	1,0,0,0,282,279,1,0,0,0,283,286,1,0,0,0,284,282,1,0,0,0,284,285,1,0,0,
  	0,285,45,1,0,0,0,286,284,1,0,0,0,287,293,3,48,24,0,288,289,3,72,36,0,
  	289,290,3,48,24,0,290,292,1,0,0,0,291,288,1,0,0,0,292,295,1,0,0,0,293,
  	291,1,0,0,0,293,294,1,0,0,0,294,47,1,0,0,0,295,293,1,0,0,0,296,302,3,
  	50,25,0,297,298,3,74,37,0,298,299,3,50,25,0,299,301,1,0,0,0,300,297,1,
  	0,0,0,301,304,1,0,0,0,302,300,1,0,0,0,302,303,1,0,0,0,303,49,1,0,0,0,
  	304,302,1,0,0,0,305,311,3,52,26,0,306,307,3,76,38,0,307,308,3,50,25,0,
  	308,311,1,0,0,0,309,311,3,58,29,0,310,305,1,0,0,0,310,306,1,0,0,0,310,
  	309,1,0,0,0,311,51,1,0,0,0,312,313,6,26,-1,0,313,314,3,54,27,0,314,326,
  	1,0,0,0,315,316,10,4,0,0,316,325,3,64,32,0,317,318,10,3,0,0,318,325,3,
  	16,8,0,319,320,10,2,0,0,320,321,5,41,0,0,321,325,5,57,0,0,322,323,10,
  	1,0,0,323,325,3,78,39,0,324,315,1,0,0,0,324,317,1,0,0,0,324,319,1,0,0,
  	0,324,322,1,0,0,0,325,328,1,0,0,0,326,324,1,0,0,0,326,327,1,0,0,0,327,
  	53,1,0,0,0,328,326,1,0,0,0,329,338,3,80,40,0,330,338,5,10,0,0,331,332,
  	5,45,0,0,332,333,3,26,13,0,333,334,5,46,0,0,334,338,1,0,0,0,335,338,5,
  	57,0,0,336,338,3,56,28,0,337,329,1,0,0,0,337,330,1,0,0,0,337,331,1,0,
  	0,0,337,335,1,0,0,0,337,336,1,0,0,0,338,55,1,0,0,0,339,341,5,43,0,0,340,
  	342,5,34,0,0,341,340,1,0,0,0,341,342,1,0,0,0,342,343,1,0,0,0,343,344,
  	5,44,0,0,344,345,3,14,7,0,345,346,5,42,0,0,346,347,3,24,12,0,347,57,1,
  	0,0,0,348,351,3,60,30,0,349,351,3,62,31,0,350,348,1,0,0,0,350,349,1,0,
  	0,0,351,59,1,0,0,0,352,353,5,5,0,0,353,355,3,22,11,0,354,356,3,64,32,
  	0,355,354,1,0,0,0,356,357,1,0,0,0,357,355,1,0,0,0,357,358,1,0,0,0,358,
  	363,1,0,0,0,359,360,5,43,0,0,360,362,5,44,0,0,361,359,1,0,0,0,362,365,
  	1,0,0,0,363,361,1,0,0,0,363,364,1,0,0,0,364,61,1,0,0,0,365,363,1,0,0,
  	0,366,367,5,5,0,0,367,370,3,22,11,0,368,369,5,45,0,0,369,371,5,46,0,0,
  	370,368,1,0,0,0,370,371,1,0,0,0,371,63,1,0,0,0,372,373,5,43,0,0,373,374,
  	3,26,13,0,374,375,5,44,0,0,375,65,1,0,0,0,376,377,7,1,0,0,377,67,1,0,
  	0,0,378,379,7,2,0,0,379,69,1,0,0,0,380,381,7,3,0,0,381,71,1,0,0,0,382,
  	383,7,4,0,0,383,73,1,0,0,0,384,385,7,5,0,0,385,75,1,0,0,0,386,387,7,6,
  	0,0,387,77,1,0,0,0,388,389,7,7,0,0,389,79,1,0,0,0,390,391,7,8,0,0,391,
  	81,1,0,0,0,392,403,3,4,2,0,393,403,3,84,42,0,394,403,3,88,44,0,395,403,
  	3,90,45,0,396,403,3,102,51,0,397,403,3,104,52,0,398,403,3,106,53,0,399,
  	403,3,108,54,0,400,403,3,24,12,0,401,403,3,110,55,0,402,392,1,0,0,0,402,
  	393,1,0,0,0,402,394,1,0,0,0,402,395,1,0,0,0,402,396,1,0,0,0,402,397,1,
  	0,0,0,402,398,1,0,0,0,402,399,1,0,0,0,402,400,1,0,0,0,402,401,1,0,0,0,
  	403,83,1,0,0,0,404,405,5,11,0,0,405,406,3,96,48,0,406,408,3,100,50,0,
  	407,409,3,86,43,0,408,407,1,0,0,0,408,409,1,0,0,0,409,85,1,0,0,0,410,
  	411,5,12,0,0,411,412,3,100,50,0,412,87,1,0,0,0,413,414,5,14,0,0,414,415,
  	3,96,48,0,415,416,3,100,50,0,416,89,1,0,0,0,417,418,5,13,0,0,418,419,
  	3,98,49,0,419,420,3,100,50,0,420,91,1,0,0,0,421,425,3,4,2,0,422,425,3,
  	18,9,0,423,425,3,12,6,0,424,421,1,0,0,0,424,422,1,0,0,0,424,423,1,0,0,
  	0,425,93,1,0,0,0,426,427,6,47,-1,0,427,428,5,57,0,0,428,436,1,0,0,0,429,
  	430,10,2,0,0,430,435,3,64,32,0,431,432,10,1,0,0,432,433,5,41,0,0,433,
  	435,5,57,0,0,434,429,1,0,0,0,434,431,1,0,0,0,435,438,1,0,0,0,436,434,
  	1,0,0,0,436,437,1,0,0,0,437,95,1,0,0,0,438,436,1,0,0,0,439,440,5,45,0,
  	0,440,441,3,26,13,0,441,442,5,46,0,0,442,97,1,0,0,0,443,445,5,45,0,0,
  	444,446,3,26,13,0,445,444,1,0,0,0,445,446,1,0,0,0,446,447,1,0,0,0,447,
  	449,5,48,0,0,448,450,3,26,13,0,449,448,1,0,0,0,449,450,1,0,0,0,450,451,
  	1,0,0,0,451,453,5,48,0,0,452,454,3,26,13,0,453,452,1,0,0,0,453,454,1,
  	0,0,0,454,455,1,0,0,0,455,456,5,46,0,0,456,99,1,0,0,0,457,460,3,24,12,
  	0,458,460,3,82,41,0,459,457,1,0,0,0,459,458,1,0,0,0,460,101,1,0,0,0,461,
  	463,5,17,0,0,462,464,3,26,13,0,463,462,1,0,0,0,463,464,1,0,0,0,464,465,
  	1,0,0,0,465,466,5,48,0,0,466,103,1,0,0,0,467,468,5,15,0,0,468,469,5,48,
  	0,0,469,105,1,0,0,0,470,471,5,16,0,0,471,472,5,48,0,0,472,107,1,0,0,0,
  	473,474,3,26,13,0,474,475,5,48,0,0,475,109,1,0,0,0,476,477,5,48,0,0,477,
  	111,1,0,0,0,41,115,123,131,139,150,169,172,182,185,199,208,218,225,233,
  	241,249,257,266,275,284,293,302,310,324,326,337,341,350,357,363,370,402,
  	408,424,434,436,445,449,453,459,463
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


std::any MxParser::ProgContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MxParserVisitor*>(visitor))
    return parserVisitor->visitProg(this);
  else
    return visitor->visitChildren(this);
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
    setState(115);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 144115188075855966) != 0) {
      setState(112);
      definition();
      setState(117);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(118);
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


std::any MxParser::DefinitionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MxParserVisitor*>(visitor))
    return parserVisitor->visitDefinition(this);
  else
    return visitor->visitChildren(this);
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
    setState(123);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 1, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(120);
      funcDef();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(121);
      varDef();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(122);
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

std::vector<MxParser::SingleVarDefContext *> MxParser::VarDefContext::singleVarDef() {
  return getRuleContexts<MxParser::SingleVarDefContext>();
}

MxParser::SingleVarDefContext* MxParser::VarDefContext::singleVarDef(size_t i) {
  return getRuleContext<MxParser::SingleVarDefContext>(i);
}

tree::TerminalNode* MxParser::VarDefContext::Semi() {
  return getToken(MxParser::Semi, 0);
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


std::any MxParser::VarDefContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MxParserVisitor*>(visitor))
    return parserVisitor->visitVarDef(this);
  else
    return visitor->visitChildren(this);
}

MxParser::VarDefContext* MxParser::varDef() {
  VarDefContext *_localctx = _tracker.createInstance<VarDefContext>(_ctx, getState());
  enterRule(_localctx, 4, MxParser::RuleVarDef);

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
    setState(125);
    typeName();
    setState(126);
    singleVarDef();
    setState(131);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 2, _ctx);
    while (alt != 1 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1 + 1) {
        setState(127);
        match(MxParser::Comma);
        setState(128);
        singleVarDef(); 
      }
      setState(133);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 2, _ctx);
    }
    setState(134);
    match(MxParser::Semi);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SingleVarDefContext ------------------------------------------------------------------

MxParser::SingleVarDefContext::SingleVarDefContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MxParser::SingleVarDefContext::Identifier() {
  return getToken(MxParser::Identifier, 0);
}

tree::TerminalNode* MxParser::SingleVarDefContext::Assign() {
  return getToken(MxParser::Assign, 0);
}

MxParser::ExpressionContext* MxParser::SingleVarDefContext::expression() {
  return getRuleContext<MxParser::ExpressionContext>(0);
}


size_t MxParser::SingleVarDefContext::getRuleIndex() const {
  return MxParser::RuleSingleVarDef;
}

void MxParser::SingleVarDefContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MxParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSingleVarDef(this);
}

void MxParser::SingleVarDefContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MxParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSingleVarDef(this);
}


std::any MxParser::SingleVarDefContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MxParserVisitor*>(visitor))
    return parserVisitor->visitSingleVarDef(this);
  else
    return visitor->visitChildren(this);
}

MxParser::SingleVarDefContext* MxParser::singleVarDef() {
  SingleVarDefContext *_localctx = _tracker.createInstance<SingleVarDefContext>(_ctx, getState());
  enterRule(_localctx, 6, MxParser::RuleSingleVarDef);
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
    setState(136);
    match(MxParser::Identifier);
    setState(139);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == MxParser::Assign) {
      setState(137);
      match(MxParser::Assign);
      setState(138);
      expression();
    }
   
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


std::any MxParser::ClassDefContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MxParserVisitor*>(visitor))
    return parserVisitor->visitClassDef(this);
  else
    return visitor->visitChildren(this);
}

MxParser::ClassDefContext* MxParser::classDef() {
  ClassDefContext *_localctx = _tracker.createInstance<ClassDefContext>(_ctx, getState());
  enterRule(_localctx, 8, MxParser::RuleClassDef);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(141);
    match(MxParser::Class);
    setState(142);
    match(MxParser::Identifier);
    setState(143);
    classBody();
    setState(144);
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


std::any MxParser::ClassBodyContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MxParserVisitor*>(visitor))
    return parserVisitor->visitClassBody(this);
  else
    return visitor->visitChildren(this);
}

MxParser::ClassBodyContext* MxParser::classBody() {
  ClassBodyContext *_localctx = _tracker.createInstance<ClassBodyContext>(_ctx, getState());
  enterRule(_localctx, 10, MxParser::RuleClassBody);
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
    setState(146);
    match(MxParser::LeftBrace);
    setState(150);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 144115188075855902) != 0) {
      setState(147);
      memberStmt();
      setState(152);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(153);
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

MxParser::StmtBlockContext* MxParser::FuncDefContext::stmtBlock() {
  return getRuleContext<MxParser::StmtBlockContext>(0);
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


std::any MxParser::FuncDefContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MxParserVisitor*>(visitor))
    return parserVisitor->visitFuncDef(this);
  else
    return visitor->visitChildren(this);
}

MxParser::FuncDefContext* MxParser::funcDef() {
  FuncDefContext *_localctx = _tracker.createInstance<FuncDefContext>(_ctx, getState());
  enterRule(_localctx, 12, MxParser::RuleFuncDef);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(155);
    typeName();
    setState(156);
    match(MxParser::Identifier);
    setState(157);
    argListDef();
    setState(158);
    stmtBlock();
   
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


std::any MxParser::ArgListDefContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MxParserVisitor*>(visitor))
    return parserVisitor->visitArgListDef(this);
  else
    return visitor->visitChildren(this);
}

MxParser::ArgListDefContext* MxParser::argListDef() {
  ArgListDefContext *_localctx = _tracker.createInstance<ArgListDefContext>(_ctx, getState());
  enterRule(_localctx, 14, MxParser::RuleArgListDef);
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
    setState(160);
    match(MxParser::LeftParen);
    setState(172);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 144115188075855902) != 0) {
      setState(161);
      typeName();
      setState(162);
      match(MxParser::Identifier);
      setState(169);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 5, _ctx);
      while (alt != 1 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1 + 1) {
          setState(163);
          match(MxParser::Comma);
          setState(164);
          typeName();
          setState(165);
          match(MxParser::Identifier); 
        }
        setState(171);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 5, _ctx);
      }
    }
    setState(174);
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


std::any MxParser::ArgListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MxParserVisitor*>(visitor))
    return parserVisitor->visitArgList(this);
  else
    return visitor->visitChildren(this);
}

MxParser::ArgListContext* MxParser::argList() {
  ArgListContext *_localctx = _tracker.createInstance<ArgListContext>(_ctx, getState());
  enterRule(_localctx, 16, MxParser::RuleArgList);
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
    setState(176);
    match(MxParser::LeftParen);
    setState(185);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 1008852085850507168) != 0) {
      setState(177);
      expression();
      setState(182);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 7, _ctx);
      while (alt != 1 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1 + 1) {
          setState(178);
          match(MxParser::Comma);
          setState(179);
          expression(); 
        }
        setState(184);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 7, _ctx);
      }
    }
    setState(187);
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

MxParser::StmtBlockContext* MxParser::ConstructFuncDefContext::stmtBlock() {
  return getRuleContext<MxParser::StmtBlockContext>(0);
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


std::any MxParser::ConstructFuncDefContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MxParserVisitor*>(visitor))
    return parserVisitor->visitConstructFuncDef(this);
  else
    return visitor->visitChildren(this);
}

MxParser::ConstructFuncDefContext* MxParser::constructFuncDef() {
  ConstructFuncDefContext *_localctx = _tracker.createInstance<ConstructFuncDefContext>(_ctx, getState());
  enterRule(_localctx, 18, MxParser::RuleConstructFuncDef);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(189);
    match(MxParser::Identifier);
    setState(190);
    match(MxParser::LeftParen);
    setState(191);
    match(MxParser::RightParen);
    setState(192);
    stmtBlock();
   
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


std::any MxParser::TypeNameContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MxParserVisitor*>(visitor))
    return parserVisitor->visitTypeName(this);
  else
    return visitor->visitChildren(this);
}

MxParser::TypeNameContext* MxParser::typeName() {
  TypeNameContext *_localctx = _tracker.createInstance<TypeNameContext>(_ctx, getState());
  enterRule(_localctx, 20, MxParser::RuleTypeName);
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
    setState(194);
    basicType();
    setState(199);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == MxParser::LeftBracket) {
      setState(195);
      match(MxParser::LeftBracket);
      setState(196);
      match(MxParser::RightBracket);
      setState(201);
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


std::any MxParser::BasicTypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MxParserVisitor*>(visitor))
    return parserVisitor->visitBasicType(this);
  else
    return visitor->visitChildren(this);
}

MxParser::BasicTypeContext* MxParser::basicType() {
  BasicTypeContext *_localctx = _tracker.createInstance<BasicTypeContext>(_ctx, getState());
  enterRule(_localctx, 22, MxParser::RuleBasicType);
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
    setState(202);
    _la = _input->LA(1);
    if (!(((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 144115188075855902) != 0)) {
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

//----------------- StmtBlockContext ------------------------------------------------------------------

MxParser::StmtBlockContext::StmtBlockContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MxParser::StmtBlockContext::LeftBrace() {
  return getToken(MxParser::LeftBrace, 0);
}

tree::TerminalNode* MxParser::StmtBlockContext::RightBrace() {
  return getToken(MxParser::RightBrace, 0);
}

std::vector<MxParser::FuncStmtContext *> MxParser::StmtBlockContext::funcStmt() {
  return getRuleContexts<MxParser::FuncStmtContext>();
}

MxParser::FuncStmtContext* MxParser::StmtBlockContext::funcStmt(size_t i) {
  return getRuleContext<MxParser::FuncStmtContext>(i);
}


size_t MxParser::StmtBlockContext::getRuleIndex() const {
  return MxParser::RuleStmtBlock;
}

void MxParser::StmtBlockContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MxParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStmtBlock(this);
}

void MxParser::StmtBlockContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MxParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStmtBlock(this);
}


std::any MxParser::StmtBlockContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MxParserVisitor*>(visitor))
    return parserVisitor->visitStmtBlock(this);
  else
    return visitor->visitChildren(this);
}

MxParser::StmtBlockContext* MxParser::stmtBlock() {
  StmtBlockContext *_localctx = _tracker.createInstance<StmtBlockContext>(_ctx, getState());
  enterRule(_localctx, 24, MxParser::RuleStmtBlock);
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
    setState(204);
    match(MxParser::LeftBrace);
    setState(208);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 1009696510780895166) != 0) {
      setState(205);
      funcStmt();
      setState(210);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(211);
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


std::any MxParser::ExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MxParserVisitor*>(visitor))
    return parserVisitor->visitExpression(this);
  else
    return visitor->visitChildren(this);
}

MxParser::ExpressionContext* MxParser::expression() {
  ExpressionContext *_localctx = _tracker.createInstance<ExpressionContext>(_ctx, getState());
  enterRule(_localctx, 26, MxParser::RuleExpression);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(213);
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


std::any MxParser::AssignExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MxParserVisitor*>(visitor))
    return parserVisitor->visitAssignExpr(this);
  else
    return visitor->visitChildren(this);
}

MxParser::AssignExprContext* MxParser::assignExpr() {
  AssignExprContext *_localctx = _tracker.createInstance<AssignExprContext>(_ctx, getState());
  enterRule(_localctx, 28, MxParser::RuleAssignExpr);
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
    setState(215);
    orOrExpr();
    setState(218);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == MxParser::Assign) {
      setState(216);
      match(MxParser::Assign);
      setState(217);
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


std::any MxParser::OrOrExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MxParserVisitor*>(visitor))
    return parserVisitor->visitOrOrExpr(this);
  else
    return visitor->visitChildren(this);
}

MxParser::OrOrExprContext* MxParser::orOrExpr() {
  OrOrExprContext *_localctx = _tracker.createInstance<OrOrExprContext>(_ctx, getState());
  enterRule(_localctx, 30, MxParser::RuleOrOrExpr);
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
    setState(220);
    andAndExpr();
    setState(225);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == MxParser::OrOr) {
      setState(221);
      match(MxParser::OrOr);
      setState(222);
      andAndExpr();
      setState(227);
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


std::any MxParser::AndAndExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MxParserVisitor*>(visitor))
    return parserVisitor->visitAndAndExpr(this);
  else
    return visitor->visitChildren(this);
}

MxParser::AndAndExprContext* MxParser::andAndExpr() {
  AndAndExprContext *_localctx = _tracker.createInstance<AndAndExprContext>(_ctx, getState());
  enterRule(_localctx, 32, MxParser::RuleAndAndExpr);
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
    setState(228);
    orExpr();
    setState(233);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == MxParser::AndAnd) {
      setState(229);
      match(MxParser::AndAnd);
      setState(230);
      orExpr();
      setState(235);
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


std::any MxParser::OrExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MxParserVisitor*>(visitor))
    return parserVisitor->visitOrExpr(this);
  else
    return visitor->visitChildren(this);
}

MxParser::OrExprContext* MxParser::orExpr() {
  OrExprContext *_localctx = _tracker.createInstance<OrExprContext>(_ctx, getState());
  enterRule(_localctx, 34, MxParser::RuleOrExpr);
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
    setState(236);
    xorExpr();
    setState(241);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == MxParser::Or) {
      setState(237);
      match(MxParser::Or);
      setState(238);
      xorExpr();
      setState(243);
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


std::any MxParser::XorExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MxParserVisitor*>(visitor))
    return parserVisitor->visitXorExpr(this);
  else
    return visitor->visitChildren(this);
}

MxParser::XorExprContext* MxParser::xorExpr() {
  XorExprContext *_localctx = _tracker.createInstance<XorExprContext>(_ctx, getState());
  enterRule(_localctx, 36, MxParser::RuleXorExpr);
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
    setState(244);
    andExpr();
    setState(249);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == MxParser::Caret) {
      setState(245);
      match(MxParser::Caret);
      setState(246);
      andExpr();
      setState(251);
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


std::any MxParser::AndExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MxParserVisitor*>(visitor))
    return parserVisitor->visitAndExpr(this);
  else
    return visitor->visitChildren(this);
}

MxParser::AndExprContext* MxParser::andExpr() {
  AndExprContext *_localctx = _tracker.createInstance<AndExprContext>(_ctx, getState());
  enterRule(_localctx, 38, MxParser::RuleAndExpr);
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
    setState(252);
    equalityExpr();
    setState(257);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == MxParser::And) {
      setState(253);
      match(MxParser::And);
      setState(254);
      equalityExpr();
      setState(259);
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


std::any MxParser::EqualityExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MxParserVisitor*>(visitor))
    return parserVisitor->visitEqualityExpr(this);
  else
    return visitor->visitChildren(this);
}

MxParser::EqualityExprContext* MxParser::equalityExpr() {
  EqualityExprContext *_localctx = _tracker.createInstance<EqualityExprContext>(_ctx, getState());
  enterRule(_localctx, 40, MxParser::RuleEqualityExpr);
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
    setState(260);
    relationExpr();
    setState(266);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == MxParser::NotEqual

    || _la == MxParser::Equal) {
      setState(261);
      equalOp();
      setState(262);
      relationExpr();
      setState(268);
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


std::any MxParser::RelationExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MxParserVisitor*>(visitor))
    return parserVisitor->visitRelationExpr(this);
  else
    return visitor->visitChildren(this);
}

MxParser::RelationExprContext* MxParser::relationExpr() {
  RelationExprContext *_localctx = _tracker.createInstance<RelationExprContext>(_ctx, getState());
  enterRule(_localctx, 42, MxParser::RuleRelationExpr);
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
    setState(269);
    shiftExpr();
    setState(275);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 125829120) != 0) {
      setState(270);
      relationOp();
      setState(271);
      shiftExpr();
      setState(277);
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


std::any MxParser::ShiftExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MxParserVisitor*>(visitor))
    return parserVisitor->visitShiftExpr(this);
  else
    return visitor->visitChildren(this);
}

MxParser::ShiftExprContext* MxParser::shiftExpr() {
  ShiftExprContext *_localctx = _tracker.createInstance<ShiftExprContext>(_ctx, getState());
  enterRule(_localctx, 44, MxParser::RuleShiftExpr);
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
    setState(278);
    addExpr();
    setState(284);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == MxParser::RightShift

    || _la == MxParser::LeftShift) {
      setState(279);
      shiftOp();
      setState(280);
      addExpr();
      setState(286);
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


std::any MxParser::AddExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MxParserVisitor*>(visitor))
    return parserVisitor->visitAddExpr(this);
  else
    return visitor->visitChildren(this);
}

MxParser::AddExprContext* MxParser::addExpr() {
  AddExprContext *_localctx = _tracker.createInstance<AddExprContext>(_ctx, getState());
  enterRule(_localctx, 46, MxParser::RuleAddExpr);
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
    setState(287);
    multiExpr();
    setState(293);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == MxParser::Plus

    || _la == MxParser::Minus) {
      setState(288);
      addOp();
      setState(289);
      multiExpr();
      setState(295);
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


std::any MxParser::MultiExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MxParserVisitor*>(visitor))
    return parserVisitor->visitMultiExpr(this);
  else
    return visitor->visitChildren(this);
}

MxParser::MultiExprContext* MxParser::multiExpr() {
  MultiExprContext *_localctx = _tracker.createInstance<MultiExprContext>(_ctx, getState());
  enterRule(_localctx, 48, MxParser::RuleMultiExpr);
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
    setState(296);
    unaryExpr();
    setState(302);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 7340032) != 0) {
      setState(297);
      multiOp();
      setState(298);
      unaryExpr();
      setState(304);
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


std::any MxParser::UnaryExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MxParserVisitor*>(visitor))
    return parserVisitor->visitUnaryExpr(this);
  else
    return visitor->visitChildren(this);
}

MxParser::UnaryExprContext* MxParser::unaryExpr() {
  UnaryExprContext *_localctx = _tracker.createInstance<UnaryExprContext>(_ctx, getState());
  enterRule(_localctx, 50, MxParser::RuleUnaryExpr);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(310);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case MxParser::NullLiteral:
      case MxParser::True:
      case MxParser::False:
      case MxParser::This:
      case MxParser::LeftBracket:
      case MxParser::LeftParen:
      case MxParser::Identifier:
      case MxParser::IntLiteral:
      case MxParser::StringLiteral: {
        enterOuterAlt(_localctx, 1);
        setState(305);
        postfixExpr(0);
        break;
      }

      case MxParser::Minus:
      case MxParser::Not:
      case MxParser::Tilde:
      case MxParser::PlusPlus:
      case MxParser::MinusMinus: {
        enterOuterAlt(_localctx, 2);
        setState(306);
        prefixUnaryOp();
        setState(307);
        unaryExpr();
        break;
      }

      case MxParser::New: {
        enterOuterAlt(_localctx, 3);
        setState(309);
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


std::any MxParser::PostfixExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MxParserVisitor*>(visitor))
    return parserVisitor->visitPostfixExpr(this);
  else
    return visitor->visitChildren(this);
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
  size_t startState = 52;
  enterRecursionRule(_localctx, 52, MxParser::RulePostfixExpr, precedence);

    

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
    setState(313);
    primaryExpr();
    _ctx->stop = _input->LT(-1);
    setState(326);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 24, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(324);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 23, _ctx)) {
        case 1: {
          _localctx = _tracker.createInstance<PostfixExprContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RulePostfixExpr);
          setState(315);

          if (!(precpred(_ctx, 4))) throw FailedPredicateException(this, "precpred(_ctx, 4)");
          setState(316);
          arrayIndex();
          break;
        }

        case 2: {
          _localctx = _tracker.createInstance<PostfixExprContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RulePostfixExpr);
          setState(317);

          if (!(precpred(_ctx, 3))) throw FailedPredicateException(this, "precpred(_ctx, 3)");
          setState(318);
          argList();
          break;
        }

        case 3: {
          _localctx = _tracker.createInstance<PostfixExprContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RulePostfixExpr);
          setState(319);

          if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
          setState(320);
          match(MxParser::Dot);
          setState(321);
          match(MxParser::Identifier);
          break;
        }

        case 4: {
          _localctx = _tracker.createInstance<PostfixExprContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RulePostfixExpr);
          setState(322);

          if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
          setState(323);
          suffixUnaryOp();
          break;
        }

        default:
          break;
        } 
      }
      setState(328);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 24, _ctx);
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

MxParser::LambdaExprContext* MxParser::PrimaryExprContext::lambdaExpr() {
  return getRuleContext<MxParser::LambdaExprContext>(0);
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


std::any MxParser::PrimaryExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MxParserVisitor*>(visitor))
    return parserVisitor->visitPrimaryExpr(this);
  else
    return visitor->visitChildren(this);
}

MxParser::PrimaryExprContext* MxParser::primaryExpr() {
  PrimaryExprContext *_localctx = _tracker.createInstance<PrimaryExprContext>(_ctx, getState());
  enterRule(_localctx, 54, MxParser::RulePrimaryExpr);

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
      case MxParser::NullLiteral:
      case MxParser::True:
      case MxParser::False:
      case MxParser::IntLiteral:
      case MxParser::StringLiteral: {
        enterOuterAlt(_localctx, 1);
        setState(329);
        literal();
        break;
      }

      case MxParser::This: {
        enterOuterAlt(_localctx, 2);
        setState(330);
        match(MxParser::This);
        break;
      }

      case MxParser::LeftParen: {
        enterOuterAlt(_localctx, 3);
        setState(331);
        match(MxParser::LeftParen);
        setState(332);
        expression();
        setState(333);
        match(MxParser::RightParen);
        break;
      }

      case MxParser::Identifier: {
        enterOuterAlt(_localctx, 4);
        setState(335);
        match(MxParser::Identifier);
        break;
      }

      case MxParser::LeftBracket: {
        enterOuterAlt(_localctx, 5);
        setState(336);
        lambdaExpr();
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

//----------------- LambdaExprContext ------------------------------------------------------------------

MxParser::LambdaExprContext::LambdaExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MxParser::LambdaExprContext::LeftBracket() {
  return getToken(MxParser::LeftBracket, 0);
}

tree::TerminalNode* MxParser::LambdaExprContext::RightBracket() {
  return getToken(MxParser::RightBracket, 0);
}

MxParser::ArgListDefContext* MxParser::LambdaExprContext::argListDef() {
  return getRuleContext<MxParser::ArgListDefContext>(0);
}

tree::TerminalNode* MxParser::LambdaExprContext::Arrow() {
  return getToken(MxParser::Arrow, 0);
}

MxParser::StmtBlockContext* MxParser::LambdaExprContext::stmtBlock() {
  return getRuleContext<MxParser::StmtBlockContext>(0);
}

tree::TerminalNode* MxParser::LambdaExprContext::And() {
  return getToken(MxParser::And, 0);
}


size_t MxParser::LambdaExprContext::getRuleIndex() const {
  return MxParser::RuleLambdaExpr;
}

void MxParser::LambdaExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MxParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLambdaExpr(this);
}

void MxParser::LambdaExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MxParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLambdaExpr(this);
}


std::any MxParser::LambdaExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MxParserVisitor*>(visitor))
    return parserVisitor->visitLambdaExpr(this);
  else
    return visitor->visitChildren(this);
}

MxParser::LambdaExprContext* MxParser::lambdaExpr() {
  LambdaExprContext *_localctx = _tracker.createInstance<LambdaExprContext>(_ctx, getState());
  enterRule(_localctx, 56, MxParser::RuleLambdaExpr);
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
    setState(339);
    match(MxParser::LeftBracket);
    setState(341);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == MxParser::And) {
      setState(340);
      match(MxParser::And);
    }
    setState(343);
    match(MxParser::RightBracket);
    setState(344);
    argListDef();
    setState(345);
    match(MxParser::Arrow);
    setState(346);
    stmtBlock();
   
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


std::any MxParser::NewExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MxParserVisitor*>(visitor))
    return parserVisitor->visitNewExpr(this);
  else
    return visitor->visitChildren(this);
}

MxParser::NewExprContext* MxParser::newExpr() {
  NewExprContext *_localctx = _tracker.createInstance<NewExprContext>(_ctx, getState());
  enterRule(_localctx, 58, MxParser::RuleNewExpr);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(350);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 27, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(348);
      newArrayExpr();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(349);
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


std::any MxParser::NewArrayExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MxParserVisitor*>(visitor))
    return parserVisitor->visitNewArrayExpr(this);
  else
    return visitor->visitChildren(this);
}

MxParser::NewArrayExprContext* MxParser::newArrayExpr() {
  NewArrayExprContext *_localctx = _tracker.createInstance<NewArrayExprContext>(_ctx, getState());
  enterRule(_localctx, 60, MxParser::RuleNewArrayExpr);
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
    setState(352);
    match(MxParser::New);
    setState(353);
    basicType();

    setState(355); 
    _errHandler->sync(this);
    alt = 1;
    do {
      switch (alt) {
        case 1: {
              setState(354);
              arrayIndex();
              break;
            }

      default:
        throw NoViableAltException(this);
      }
      setState(357); 
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 28, _ctx);
    } while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER);
    setState(363);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == MxParser::LeftBracket) {
      setState(359);
      match(MxParser::LeftBracket);
      setState(360);
      match(MxParser::RightBracket);
      setState(365);
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


std::any MxParser::NewObjExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MxParserVisitor*>(visitor))
    return parserVisitor->visitNewObjExpr(this);
  else
    return visitor->visitChildren(this);
}

MxParser::NewObjExprContext* MxParser::newObjExpr() {
  NewObjExprContext *_localctx = _tracker.createInstance<NewObjExprContext>(_ctx, getState());
  enterRule(_localctx, 62, MxParser::RuleNewObjExpr);
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
    setState(366);
    match(MxParser::New);
    setState(367);
    basicType();
    setState(370);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == MxParser::LeftParen) {
      setState(368);
      match(MxParser::LeftParen);
      setState(369);
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


std::any MxParser::ArrayIndexContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MxParserVisitor*>(visitor))
    return parserVisitor->visitArrayIndex(this);
  else
    return visitor->visitChildren(this);
}

MxParser::ArrayIndexContext* MxParser::arrayIndex() {
  ArrayIndexContext *_localctx = _tracker.createInstance<ArrayIndexContext>(_ctx, getState());
  enterRule(_localctx, 64, MxParser::RuleArrayIndex);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(372);
    match(MxParser::LeftBracket);
    setState(373);
    expression();
    setState(374);
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


std::any MxParser::EqualOpContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MxParserVisitor*>(visitor))
    return parserVisitor->visitEqualOp(this);
  else
    return visitor->visitChildren(this);
}

MxParser::EqualOpContext* MxParser::equalOp() {
  EqualOpContext *_localctx = _tracker.createInstance<EqualOpContext>(_ctx, getState());
  enterRule(_localctx, 66, MxParser::RuleEqualOp);
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
    setState(376);
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


std::any MxParser::RelationOpContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MxParserVisitor*>(visitor))
    return parserVisitor->visitRelationOp(this);
  else
    return visitor->visitChildren(this);
}

MxParser::RelationOpContext* MxParser::relationOp() {
  RelationOpContext *_localctx = _tracker.createInstance<RelationOpContext>(_ctx, getState());
  enterRule(_localctx, 68, MxParser::RuleRelationOp);
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
    setState(378);
    _la = _input->LA(1);
    if (!(((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 125829120) != 0)) {
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


std::any MxParser::ShiftOpContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MxParserVisitor*>(visitor))
    return parserVisitor->visitShiftOp(this);
  else
    return visitor->visitChildren(this);
}

MxParser::ShiftOpContext* MxParser::shiftOp() {
  ShiftOpContext *_localctx = _tracker.createInstance<ShiftOpContext>(_ctx, getState());
  enterRule(_localctx, 70, MxParser::RuleShiftOp);
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
    setState(380);
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


std::any MxParser::AddOpContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MxParserVisitor*>(visitor))
    return parserVisitor->visitAddOp(this);
  else
    return visitor->visitChildren(this);
}

MxParser::AddOpContext* MxParser::addOp() {
  AddOpContext *_localctx = _tracker.createInstance<AddOpContext>(_ctx, getState());
  enterRule(_localctx, 72, MxParser::RuleAddOp);
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
    setState(382);
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


std::any MxParser::MultiOpContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MxParserVisitor*>(visitor))
    return parserVisitor->visitMultiOp(this);
  else
    return visitor->visitChildren(this);
}

MxParser::MultiOpContext* MxParser::multiOp() {
  MultiOpContext *_localctx = _tracker.createInstance<MultiOpContext>(_ctx, getState());
  enterRule(_localctx, 74, MxParser::RuleMultiOp);
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
    setState(384);
    _la = _input->LA(1);
    if (!(((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 7340032) != 0)) {
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


std::any MxParser::PrefixUnaryOpContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MxParserVisitor*>(visitor))
    return parserVisitor->visitPrefixUnaryOp(this);
  else
    return visitor->visitChildren(this);
}

MxParser::PrefixUnaryOpContext* MxParser::prefixUnaryOp() {
  PrefixUnaryOpContext *_localctx = _tracker.createInstance<PrefixUnaryOpContext>(_ctx, getState());
  enterRule(_localctx, 76, MxParser::RulePrefixUnaryOp);
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
    setState(386);
    _la = _input->LA(1);
    if (!(((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 1788854403072) != 0)) {
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


std::any MxParser::SuffixUnaryOpContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MxParserVisitor*>(visitor))
    return parserVisitor->visitSuffixUnaryOp(this);
  else
    return visitor->visitChildren(this);
}

MxParser::SuffixUnaryOpContext* MxParser::suffixUnaryOp() {
  SuffixUnaryOpContext *_localctx = _tracker.createInstance<SuffixUnaryOpContext>(_ctx, getState());
  enterRule(_localctx, 78, MxParser::RuleSuffixUnaryOp);
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
    setState(388);
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


std::any MxParser::LiteralContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MxParserVisitor*>(visitor))
    return parserVisitor->visitLiteral(this);
  else
    return visitor->visitChildren(this);
}

MxParser::LiteralContext* MxParser::literal() {
  LiteralContext *_localctx = _tracker.createInstance<LiteralContext>(_ctx, getState());
  enterRule(_localctx, 80, MxParser::RuleLiteral);
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
    setState(390);
    _la = _input->LA(1);
    if (!(((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 864691128455136128) != 0)) {
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

MxParser::StmtBlockContext* MxParser::FuncStmtContext::stmtBlock() {
  return getRuleContext<MxParser::StmtBlockContext>(0);
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


std::any MxParser::FuncStmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MxParserVisitor*>(visitor))
    return parserVisitor->visitFuncStmt(this);
  else
    return visitor->visitChildren(this);
}

MxParser::FuncStmtContext* MxParser::funcStmt() {
  FuncStmtContext *_localctx = _tracker.createInstance<FuncStmtContext>(_ctx, getState());
  enterRule(_localctx, 82, MxParser::RuleFuncStmt);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(402);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 31, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(392);
      varDef();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(393);
      ifStmt();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(394);
      whileStmt();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(395);
      forStmt();
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(396);
      returnStmt();
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(397);
      breakStmt();
      break;
    }

    case 7: {
      enterOuterAlt(_localctx, 7);
      setState(398);
      continueStmt();
      break;
    }

    case 8: {
      enterOuterAlt(_localctx, 8);
      setState(399);
      exprStmt();
      break;
    }

    case 9: {
      enterOuterAlt(_localctx, 9);
      setState(400);
      stmtBlock();
      break;
    }

    case 10: {
      enterOuterAlt(_localctx, 10);
      setState(401);
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


std::any MxParser::IfStmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MxParserVisitor*>(visitor))
    return parserVisitor->visitIfStmt(this);
  else
    return visitor->visitChildren(this);
}

MxParser::IfStmtContext* MxParser::ifStmt() {
  IfStmtContext *_localctx = _tracker.createInstance<IfStmtContext>(_ctx, getState());
  enterRule(_localctx, 84, MxParser::RuleIfStmt);

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
    match(MxParser::If);
    setState(405);
    condition();
    setState(406);
    block();
    setState(408);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 32, _ctx)) {
    case 1: {
      setState(407);
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


std::any MxParser::ElseStmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MxParserVisitor*>(visitor))
    return parserVisitor->visitElseStmt(this);
  else
    return visitor->visitChildren(this);
}

MxParser::ElseStmtContext* MxParser::elseStmt() {
  ElseStmtContext *_localctx = _tracker.createInstance<ElseStmtContext>(_ctx, getState());
  enterRule(_localctx, 86, MxParser::RuleElseStmt);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(410);
    match(MxParser::Else);
    setState(411);
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


std::any MxParser::WhileStmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MxParserVisitor*>(visitor))
    return parserVisitor->visitWhileStmt(this);
  else
    return visitor->visitChildren(this);
}

MxParser::WhileStmtContext* MxParser::whileStmt() {
  WhileStmtContext *_localctx = _tracker.createInstance<WhileStmtContext>(_ctx, getState());
  enterRule(_localctx, 88, MxParser::RuleWhileStmt);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(413);
    match(MxParser::While);
    setState(414);
    condition();
    setState(415);
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


std::any MxParser::ForStmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MxParserVisitor*>(visitor))
    return parserVisitor->visitForStmt(this);
  else
    return visitor->visitChildren(this);
}

MxParser::ForStmtContext* MxParser::forStmt() {
  ForStmtContext *_localctx = _tracker.createInstance<ForStmtContext>(_ctx, getState());
  enterRule(_localctx, 90, MxParser::RuleForStmt);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(417);
    match(MxParser::For);
    setState(418);
    forCondition();
    setState(419);
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


std::any MxParser::MemberStmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MxParserVisitor*>(visitor))
    return parserVisitor->visitMemberStmt(this);
  else
    return visitor->visitChildren(this);
}

MxParser::MemberStmtContext* MxParser::memberStmt() {
  MemberStmtContext *_localctx = _tracker.createInstance<MemberStmtContext>(_ctx, getState());
  enterRule(_localctx, 92, MxParser::RuleMemberStmt);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(424);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 33, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(421);
      varDef();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(422);
      constructFuncDef();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(423);
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


std::any MxParser::LeftValueContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MxParserVisitor*>(visitor))
    return parserVisitor->visitLeftValue(this);
  else
    return visitor->visitChildren(this);
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
  size_t startState = 94;
  enterRecursionRule(_localctx, 94, MxParser::RuleLeftValue, precedence);

    

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
    setState(427);
    match(MxParser::Identifier);
    _ctx->stop = _input->LT(-1);
    setState(436);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 35, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(434);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 34, _ctx)) {
        case 1: {
          _localctx = _tracker.createInstance<LeftValueContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleLeftValue);
          setState(429);

          if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
          setState(430);
          arrayIndex();
          break;
        }

        case 2: {
          _localctx = _tracker.createInstance<LeftValueContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleLeftValue);
          setState(431);

          if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
          setState(432);
          match(MxParser::Dot);
          setState(433);
          match(MxParser::Identifier);
          break;
        }

        default:
          break;
        } 
      }
      setState(438);
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


std::any MxParser::ConditionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MxParserVisitor*>(visitor))
    return parserVisitor->visitCondition(this);
  else
    return visitor->visitChildren(this);
}

MxParser::ConditionContext* MxParser::condition() {
  ConditionContext *_localctx = _tracker.createInstance<ConditionContext>(_ctx, getState());
  enterRule(_localctx, 96, MxParser::RuleCondition);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(439);
    match(MxParser::LeftParen);
    setState(440);
    expression();
    setState(441);
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


std::any MxParser::ForConditionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MxParserVisitor*>(visitor))
    return parserVisitor->visitForCondition(this);
  else
    return visitor->visitChildren(this);
}

MxParser::ForConditionContext* MxParser::forCondition() {
  ForConditionContext *_localctx = _tracker.createInstance<ForConditionContext>(_ctx, getState());
  enterRule(_localctx, 98, MxParser::RuleForCondition);
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
    setState(443);
    match(MxParser::LeftParen);
    setState(445);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 1008852085850507168) != 0) {
      setState(444);
      antlrcpp::downCast<ForConditionContext *>(_localctx)->init_expr = expression();
    }
    setState(447);
    match(MxParser::Semi);
    setState(449);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 1008852085850507168) != 0) {
      setState(448);
      antlrcpp::downCast<ForConditionContext *>(_localctx)->condition_expr = expression();
    }
    setState(451);
    match(MxParser::Semi);
    setState(453);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 1008852085850507168) != 0) {
      setState(452);
      antlrcpp::downCast<ForConditionContext *>(_localctx)->step_expr = expression();
    }
    setState(455);
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

MxParser::StmtBlockContext* MxParser::BlockContext::stmtBlock() {
  return getRuleContext<MxParser::StmtBlockContext>(0);
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


std::any MxParser::BlockContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MxParserVisitor*>(visitor))
    return parserVisitor->visitBlock(this);
  else
    return visitor->visitChildren(this);
}

MxParser::BlockContext* MxParser::block() {
  BlockContext *_localctx = _tracker.createInstance<BlockContext>(_ctx, getState());
  enterRule(_localctx, 100, MxParser::RuleBlock);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(459);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 39, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(457);
      stmtBlock();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(458);
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


std::any MxParser::ReturnStmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MxParserVisitor*>(visitor))
    return parserVisitor->visitReturnStmt(this);
  else
    return visitor->visitChildren(this);
}

MxParser::ReturnStmtContext* MxParser::returnStmt() {
  ReturnStmtContext *_localctx = _tracker.createInstance<ReturnStmtContext>(_ctx, getState());
  enterRule(_localctx, 102, MxParser::RuleReturnStmt);
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
      ((1ULL << _la) & 1008852085850507168) != 0) {
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


std::any MxParser::BreakStmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MxParserVisitor*>(visitor))
    return parserVisitor->visitBreakStmt(this);
  else
    return visitor->visitChildren(this);
}

MxParser::BreakStmtContext* MxParser::breakStmt() {
  BreakStmtContext *_localctx = _tracker.createInstance<BreakStmtContext>(_ctx, getState());
  enterRule(_localctx, 104, MxParser::RuleBreakStmt);

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


std::any MxParser::ContinueStmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MxParserVisitor*>(visitor))
    return parserVisitor->visitContinueStmt(this);
  else
    return visitor->visitChildren(this);
}

MxParser::ContinueStmtContext* MxParser::continueStmt() {
  ContinueStmtContext *_localctx = _tracker.createInstance<ContinueStmtContext>(_ctx, getState());
  enterRule(_localctx, 106, MxParser::RuleContinueStmt);

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


std::any MxParser::ExprStmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MxParserVisitor*>(visitor))
    return parserVisitor->visitExprStmt(this);
  else
    return visitor->visitChildren(this);
}

MxParser::ExprStmtContext* MxParser::exprStmt() {
  ExprStmtContext *_localctx = _tracker.createInstance<ExprStmtContext>(_ctx, getState());
  enterRule(_localctx, 108, MxParser::RuleExprStmt);

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


std::any MxParser::BlankStmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MxParserVisitor*>(visitor))
    return parserVisitor->visitBlankStmt(this);
  else
    return visitor->visitChildren(this);
}

MxParser::BlankStmtContext* MxParser::blankStmt() {
  BlankStmtContext *_localctx = _tracker.createInstance<BlankStmtContext>(_ctx, getState());
  enterRule(_localctx, 110, MxParser::RuleBlankStmt);

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
    case 26: return postfixExprSempred(antlrcpp::downCast<PostfixExprContext *>(context), predicateIndex);
    case 47: return leftValueSempred(antlrcpp::downCast<LeftValueContext *>(context), predicateIndex);

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
