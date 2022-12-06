#pragma once
#include <memory>

#include "linked_hashmap.hpp"
#include "my_exception.h"
#include "type.h"
#include "value_type.h"
#include "var_info.h"
using namespace std;

class Scope {
public:
  bool in_lambda;
  shared_ptr<Scope> parent;
  shared_ptr<linked_hashmap<string, VarInfo>> vars;
  virtual ValueType GetIdentifierType(const string &identifier) const;
  virtual void CheckIdentifier(
      const string &identifier) const; // ensure the var or func identifier not
                                       // used before as a class identifier.
  virtual void AddVar(const string &identifier, ObjectType type);
  virtual ValueType GetClassMember(const string &class_identifier,
                                   const string &member_identifier) const;
  virtual void CheckClass(const string &class_identifier) const;
  virtual void GiveVarReg(const string &var_identifier,
                          shared_ptr<IR::Register> reg);
  virtual void GiveVarReg(const string &var_identifier);
  virtual shared_ptr<IR::Register> GetVarReg(const string &var_identifier);
  Scope(const shared_ptr<Scope> &_parent, bool _in_lambda = false);
};