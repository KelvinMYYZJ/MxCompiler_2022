#include "class_info.h"

#include "linked_hashmap.hpp"
#include "my_exception.h"
using namespace std;

ClassInfo::ClassInfo()
    : member_vars(make_shared<linked_hashmap<string, ObjectType>>()),
      member_funcs(make_shared<linked_hashmap<string, FuncType>>()) {}
void ClassInfo::AddMemberVar(const string &identifier, const ObjectType &type) {
  if (member_vars->count(identifier)) {
    throw MyException("redefinition of member var : \"" + identifier + "\"");
  }
  (*member_vars)[identifier] = type;
}
void ClassInfo::AddMemberFunc(const string &identifier, const FuncType &type) {
  if (member_funcs->count(identifier)) {
    throw MyException("redefinition of member func : \"" + identifier + "\"");
  }
  (*member_funcs)[identifier] = type;
}