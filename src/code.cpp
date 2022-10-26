#include <bits/stdc++.h>

#include "AST_nodes.h"
#include "MxLexer.h"
#include "MxParser.h"
#include "MxParserBaseListener.h"
#include "antlr4-runtime.h"
#include "gscope.h"
#include "my_error_listener.h"
#include "my_exception.h"
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
    ANTLRInputStream input(cin);
    MxLexer lexer(&input);
    lexer.removeErrorListeners();
    MxErrorListener error_listener;
    lexer.addErrorListener(&error_listener);
    CommonTokenStream tokens(&lexer);
    tokens.fill();
    MxParser parser(&tokens);
    parser.removeErrorListeners();
    parser.addErrorListener(&error_listener);
    auto *parse_tree_root = parser.prog();
    AST::ProgNode ast_root(parse_tree_root);
    ast_root.BuildScope(make_shared<GScope>());
  } catch (const MyException &exp) {
    cerr << "error!!" << endl << exp.What() << endl;
    return 1;
  }
  return 0;
}