#pragma once
#include "scope.h"
using namespace std;

ValueType Scope::GetIdentifierType(const string& identifier) const {
  ValueType ret;
  if (parent && !in_lambda) ret = parent->GetIdentifierType(identifier);
  if (vars->count(identifier)) {
    ret.AddObjectType((*vars)[identifier], true);
  }
  return ret;
}

void Scope::AddVar(const string& identifier, ObjectType type) {
  if (vars->count(identifier)) throw MyException("redefiniation of variable \"" + identifier + "\"");
  (*vars)[identifier] = type;
}
ValueType Scope::GetClassMember(const string& class_identifier, const string& member_identifier) const {
  if (parent) {
    return parent->GetClassMember(class_identifier, class_identifier);
  }
  throw MyException("Unknown error");
}
Scope::Scope(const shared_ptr<Scope>& _parent, bool _in_lambda)
    : parent(_parent), in_lambda(_in_lambda), vars(make_shared<unordered_map<string, ObjectType>>()) {}

void Scope::CheckIdentifier(const string& identifier) const {
  if (parent) {
    parent->CheckIdentifier(identifier);
  }
}