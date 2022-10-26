#pragma once
#include <memory>

#include "my_exception.h"
#include "type.h"
#include "value_type.h"
using namespace std;

class Scope {
 public:
  bool in_lambda;
  shared_ptr<Scope> parent;
  shared_ptr<unordered_map<string, ObjectType>> vars;
  virtual ValueType GetIdentifierType(const string& identifier) const;
  virtual void CheckIdentifier(
      const string& identifier) const;  // ensure the var or func identifier not used before as a class identifier.
  virtual void AddVar(const string& identifier, ObjectType type);
  virtual ValueType GetClassMember(const string& class_identifier, const string& member_identifier)const;
  Scope(const shared_ptr<Scope>& _parent, bool _in_lambda = false);
};