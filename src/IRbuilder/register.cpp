#include "register.h"

#include "IR_type.h"
using namespace std;
namespace IR {
Register::Register(const IRType &_type) : type(_type), label(-1) {}
Register::Register(const ObjectType &_type, bool is_ptr) : type(_type, is_ptr), label(-1) {}

GlobalRegister::GlobalRegister(const string &identifier, const ObjectType &_type, bool is_ptr)
    : global_label(identifier), Register(_type, is_ptr) {}

GlobalRegister::GlobalRegister(const string &identifier, const IRType &_type)
    : global_label(identifier), Register(_type) {}

}  // namespace IR