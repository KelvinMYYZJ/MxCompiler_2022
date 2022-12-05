#include "IR_type.h"

#include "type.h"
using namespace std;
IRType::IRType(const ObjectType &obj_type, bool is_ptr)
    : identifier(obj_type.type_identifier), dim(obj_type.dim) {
  if (identifier == "void") {
    dim = 0;
    return;
  }
  if (is_ptr)
    ++dim;
  if (!obj_type.IsBasicType() || obj_type.type_identifier == "string") {
    ++dim;
  }
}

IRType::IRType(const IRType &other) = default;

IRType IRType::Deref() const {
  IRType ret = *this;
  MyAssert(ret.dim, MyException("derefing a value"));
  ret.dim--;
  return ret;
}

bool IRType::operator==(const IRType &rhs) const {
  return identifier == rhs.identifier && dim == rhs.dim;
}
