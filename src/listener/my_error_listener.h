#include "antlr4-runtime.h"
#include "my_exception.h"
using namespace antlr4;
using namespace std;

class MxErrorListener : public BaseErrorListener {
  void syntaxError(Recognizer *recognizer, Token *offendingSymbol, size_t line, size_t charPositionInLine,
                   const std::string &msg, std::exception_ptr e) override;
};