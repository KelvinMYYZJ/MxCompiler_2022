#include <bits/stdc++.h>

#include "MxLexer.h"
#include "MxParser.h"
#include "MxParserBaseListener.h"
#include "antlr4-runtime.h"
#include "my_exception.h"
#ifndef ONLINE_JUDGE
#ifndef BUG
#define DEBUG
#endif
#endif
using namespace std;
using namespace antlr4;
class MyListener : public MxParserBaseListener {
 public:
  void enterProg(MxParser::ProgContext *ctx) override { cout << "enterProg" << endl; }
  void exitProg(MxParser::ProgContext *ctx) override { cout << "exitProg" << endl; }
  void enterDefinition(MxParser::DefinitionContext *ctx) override { cout << "enterDefinition" << endl; }
  void exitDefinition(MxParser::DefinitionContext *ctx) override { cout << "exitDefinition" << endl; }
  virtual void visitErrorNode(antlr4::tree::ErrorNode *node) override { throw MyException("not vaild program"); }
};
signed main() {
#ifndef ONLINE_JUDGE
  freopen("!input.txt", "r", stdin);
// freopen("!output.txt","w",stdout);
#endif
  try {
    ANTLRInputStream input(std::cin);
    MxLexer lexer(&input);
    CommonTokenStream tokens(&lexer);
    tokens.fill();
    MxParser parser(&tokens);
    tree::ParseTree *tree = parser.prog();
    MyListener my_listener;
    tree::ParseTreeWalker::DEFAULT.walk(&my_listener, tree);
  } catch (const MyException &exp) {
    std::cerr << "error!!" << std::endl << exp.What() << std::endl;
    return 1;
  }
  return 0;
}