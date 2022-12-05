#pragma once
#include <string>

#include "IR_type.h"
using namespace std;
namespace IR {
struct Register {
  int label;
  IRType type;
  Register(const IRType& _type);
  Register(const ObjectType& _type, bool is_ptr = false);
  virtual void useless_func() {}
};
struct GlobalRegister : public Register {
  string global_label;
};
}  // namespace IR