#pragma once
#include <string>

#include "IR_type.h"
using namespace std;
namespace IR {
struct Register {
  int label;
  IRType type;
  Register(const IRType &_type);
  Register(const ObjectType &_type, bool is_ptr = false);
  virtual void useless_func() {}
};
struct GlobalRegister : public Register {
  string global_label;
  GlobalRegister(const string &identifier, const ObjectType &_type, bool is_ptr);
  GlobalRegister(const string &identifier, const IRType &_type);
};
}  // namespace IR