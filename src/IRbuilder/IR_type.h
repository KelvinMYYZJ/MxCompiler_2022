#pragma once
#include <string>

#include "my_exception.h"
#include "type.h"
using namespace std;
struct IRType {
  string identifier;
  int dim;
  int size;
  // is_ptr means the type that point to an obj_type
  IRType(const ObjectType &obj_type = ObjectType(), bool is_ptr = false);
  IRType(const IRType &other);
  IRType Deref() const;
  IRType Ref() const;
  bool operator==(const IRType &rhs) const;
};

const IRType kIntIRType{kIntType};
const IRType kCharIRType{{"_char"}, false};
const IRType kCharPtrIRType{{"_char", 1}, false};
const IRType kBoolIRType{kBoolType};
const IRType kVoidIRType{kVoidType};
const IRType kStringIRType{kStringType};