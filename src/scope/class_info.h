#pragma once
#include "linked_hashmap.hpp"
#include <string>

#include "type.h"
using namespace std;
class ClassInfo {
public:
  ClassInfo();
  shared_ptr<linked_hashmap<string, ObjectType>> member_vars;
  shared_ptr<linked_hashmap<string, FuncType>> member_funcs;
  void AddMemberVar(const string &identifier, const ObjectType &type);
  void AddMemberFunc(const string &identifier, const FuncType &type);
};