#pragma once
#include "class_scope.h"
using namespace std;

ClassScope::ClassScope(shared_ptr<Scope> _scope)
    : Scope(_scope, false), member_funcs(make_shared<unordered_map<string, FuncType>>()) {}

ValueType ClassScope::GetIdentifierType(const string& identifier) const {
  ValueType ret = Scope::GetIdentifierType(identifier);
  if (member_funcs->count(identifier)) {
    ret.AddFuncType((*member_funcs)[identifier]);
  }
  return ret;
}

void ClassScope::AddMemberFunc(const string& identifier, FuncType func_type) {
  if (member_funcs->count(identifier)) {
    throw MyException("redefiniation of function :\"" + identifier + "\"");
  }
  (*member_funcs)[identifier] = func_type;
}

void ClassScope::AddMemberVar(const string& identifier, ObjectType func_type) {
  if (vars->count(identifier)) {
    throw MyException("redefiniation of member var :\"" + identifier + "\"");
  }
  (*vars)[identifier] = func_type;
}

void ClassScope::AddVar(const string& identifier, ObjectType type) {}
