#include "AST_nodes.h"
using namespace std;
namespace AST {
FuncType FuncDefNode::GetFuncType() {
  FuncType ret;
  ret.ret_type = type;
  ret.arg_type = args_def->GetArgTypeList();
  return ret;
}

list<ObjectType> ArgListDefNode::GetArgTypeList() {
  list<ObjectType> ret;
  for (auto arg : args) {
    ret.push_back(arg.type);
  }
  return ret;
}
}  // namespace AST