#include "IR.h"

#include <memory>

#include "instr.h"
#include "my_any.hpp"
#include "register.h"
using namespace std;
namespace IR {
FuncArg::FuncArg(IRType type) : reg(make_shared<Register>(type)) {}

void Struct::AddMemberVar(IRType type, string var_identifier) {
  int now_idx = member_types.size();
  member_idx[var_identifier] = now_idx;
  member_types.push_back(type);
}

void Block::PushInstr(any instr) {
  instrs.push_back(instr);
  if (AnyIs<ReturnInstr>(instr) || AnyIs<BrInstr>(instr))
    closed = true;
}

Func::Func() { blocks.push_back(make_shared<Block>()); }

Value::Value(IRType _type) : type(_type), reg(make_shared<Register>(_type)) {}
Value::Value(int _value, IRType _type)
    : type(_type), value(_value), is_left(false) {}
Value::Value(bool _value, IRType _type)
    : type(_type), value(_value), is_left(false) {}
Value::Value(shared_ptr<Register> _reg, bool _is_left)
    : type(_reg->type), reg(_reg), is_left(_is_left) {}
IRType Value::GetType() { return type; }
} // namespace IR