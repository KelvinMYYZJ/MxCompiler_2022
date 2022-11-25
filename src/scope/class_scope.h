#pragma once
#include "class_info.h"
#include "scope.h"
using namespace std;
class ClassScope : public Scope {
public:
  shared_ptr<linked_hashmap<string, FuncType>> member_funcs;
  virtual ValueType GetIdentifierType(const string &identifier) const override;
  ClassScope(shared_ptr<Scope> _scope);
  // virtual void CheckIdentifier(
  //     const string& identifier) const override;  // ensure the var or func
  //     identifier not used before as a class identifier.
  virtual void AddVar(const string &identifier, ObjectType type) override;
  void AddMemberFunc(const string &identifier, FuncType func_type);
  void AddMemberVar(const string &identifier, ObjectType func_type);
};