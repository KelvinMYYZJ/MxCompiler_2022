#pragma once
#include <string>
#include <unordered_map>

#include "type.h"
using namespace std;
class ClassInfo {
 public:
  ClassInfo();
  shared_ptr<unordered_map<string, ObjectType>> member_vars;
  shared_ptr<unordered_map<string, FuncType>> member_funcs;
  void AddMemberVar(const string& identifier, const ObjectType& type);
  void AddMemberFunc(const string& identifier, const FuncType& type);
};