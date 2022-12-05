#include "register.h"
using namespace std;
namespace IR {
Register::Register(const IRType& _type) : type(_type) {}
Register::Register(const ObjectType& _type, bool is_ptr) : type(_type, is_ptr) {}
}  // namespace IR