#include <bits/stdc++.h>
#include <string>

#include "my_exception.h"
#include "type.h"
using namespace std;
struct IRType {
  enum TypeKind { kInt, kChar, kPtr, kStruct, kVoid };
  TypeKind kind;
  string identifier;
  IRType(TypeKind _kind = kInt);
  IRType(const string &_identifier);
  IRType(const ObjectType &obj_type);
};

const IRType kI32Type{IRType::TypeKind::kInt};
const IRType kI8Type{IRType::TypeKind::kChar};
const IRType kPtrType{IRType::TypeKind::kPtr};
const IRType kIRVoidType{IRType::TypeKind::kPtr};