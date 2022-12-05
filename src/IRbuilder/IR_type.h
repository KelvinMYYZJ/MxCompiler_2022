#pragma once
#include <string>

#include "my_exception.h"
#include "type.h"
using namespace std;
struct IRType {
  string identifier;
  int dim;
  // is_ptr means the type that point to an obj_type
  IRType(const ObjectType &obj_type = ObjectType(), bool is_ptr = false);
  IRType(const IRType& other);
  IRType Deref() const;
  bool operator==(const IRType &rhs) const;
};

const IRType kIntIRType{kIntType};
// const IRTypee kCharIRType{IRTypee::TypeKind::kChar};
const IRType kBoolIRType{kBoolType};
const IRType kVoidIRType{kVoidType};