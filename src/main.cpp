#include <bits/stdc++.h>

#include "MxLexer.h"
#include "MxParser.h"
#include "antlr4-runtime.h"
#ifndef ONLINE_JUDGE
#ifndef BUG
#define DEBUG
#endif
#endif
using namespace std;
using namespace antlr4;

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
    // tree::ParseTree* tree = parser.file_input();
    // EvalVisitor visitor;
    // visitor.visit(tree);
  } catch (const char* exp) {
    std::cout << "error!!" << std::endl << exp << std::endl;
  }
  return 0;
}