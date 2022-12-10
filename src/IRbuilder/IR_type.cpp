#include "IR_type.h"

#include <string>

#include "type.h"
using namespace std;
IRType::IRType(const ObjectType &obj_type, bool is_ptr) : identifier(obj_type.type_identifier), dim(0), size(0) {
  if (identifier == "void") {
    dim = 0;
    return;
  }
  if (is_ptr) dim = 1;
  if (obj_type.dim && obj_type.type_identifier != "_char") {
    // is array object
    identifier = "_array_" + to_string(obj_type.dim) + "_" + identifier;
    ++dim;
    return;
  }
  if (!obj_type.IsBasicType() || obj_type.type_identifier == "string") {
    ++dim;
  }
}

IRType::IRType(const IRType &other) = default;

IRType IRType::Deref() const {
  IRType ret = *this;
  MyAssert(ret.dim, MyException("derefing a value"));
  --ret.dim;
  return ret;
}

IRType IRType::Ref() const {
  IRType ret = *this;
  ++ret.dim;
  return ret;
}

bool IRType::operator==(const IRType &rhs) const { return identifier == rhs.identifier && dim == rhs.dim; }
