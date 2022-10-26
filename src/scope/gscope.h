#pragma once
#include "class_info.h"
#include "scope.h"
using namespace std;
class GScope : public Scope {
 public:
  shared_ptr<unordered_map<string, FuncType>> funcs;
  shared_ptr<unordered_map<string, ClassInfo>> classes;
  virtual ValueType GetIdentifierType(const string& identifier) const override;
  GScope();
  virtual ValueType GetClassMember(const string& class_identifier, const string& member_identifier) const override;
  virtual void CheckIdentifier(const string& identifier)
      const override;  // ensure the var or func identifier not used before as a class identifier.
  virtual void CheckClass(const string& class_identifier) const override;
  void AddBlankClass(const string& identifier);
  void AddFunc(const string& identifier, FuncType func_type);
};