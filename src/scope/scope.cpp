#include "scope.h"
#include "register.h"
#include <iostream>
#include <memory>
using namespace std;

ValueType Scope::GetIdentifierType(const string &identifier) const {
  ValueType ret;
  if (parent && !in_lambda)
    ret = parent->GetIdentifierType(identifier);
  if (vars->count(identifier)) {
    ret.var_info = &(*vars)[identifier];
    ret.AddObjectType(ret.var_info->type, true);
  }
  return ret;
}

void Scope::AddVar(const string &identifier, ObjectType type) {
  if (vars->count(identifier))
    throw MyException("redefiniation of variable \"" + identifier + "\"");
  (*vars)[identifier] = type;
}
ValueType Scope::GetClassMember(const string &class_identifier,
                                const string &member_identifier) const {
  if (parent) {
    return parent->GetClassMember(class_identifier, member_identifier);
  }
  throw MyException("Unknown error");
}
void Scope::CheckClass(const string &class_identifier) const {
  if (parent)
    parent->CheckClass(class_identifier);
}
void Scope::GiveVarReg(const string &var_identifier,
                       shared_ptr<IR::Register> reg) {
  if (!reg) {
    reg = make_shared<IR::Register>(
        GetIdentifierType(var_identifier).object_type, true);
  }
  if (!vars->count(var_identifier)) {
    parent->GiveVarReg(var_identifier, reg);
    return;
  }
  if ((*vars)[var_identifier].reg)
    cerr << "!!! regive reg !!!";
  (*vars)[var_identifier].reg = reg;
}
shared_ptr<IR::Register> Scope::GetVarReg(const string &var_identifier) {
  if (vars->count(var_identifier)) {
    auto var_info = &(*vars)[var_identifier];
    return var_info->reg;
  }
  return parent->GetVarReg(var_identifier);
}
Scope::Scope(const shared_ptr<Scope> &_parent, bool _in_lambda)
    : parent(_parent), in_lambda(_in_lambda),
      vars(make_shared<linked_hashmap<string, VarInfo>>()) {}

void Scope::CheckIdentifier(const string &identifier) const {
  if (parent) {
    parent->CheckIdentifier(identifier);
  }
}