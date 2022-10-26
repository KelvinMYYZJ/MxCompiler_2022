#pragma once
#include <bits/stdc++.h>

#include "type.h"
using namespace std;

class ValueType {
 public:
  ObjectType object_type;
  bool have_object_type;
  bool object_leftvalue;
  FuncType func_type;
  bool have_func_type;
  void AddObjectType(const ObjectType& _object_type, bool is_leftvalue);
  void SetObjectType(const ObjectType& _object_type, bool is_leftvalue);
  void AddFuncType(const FuncType& _func_type);
  void SetFuncType(const FuncType& _func_type);
  ObjectType GetObjectType();
  FuncType GetFuncType();
};