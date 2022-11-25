#include "IR.h"
#include "instr.h"
#include "my_any.hpp"
#include "register.h"

#include <bits/stdc++.h>
#include <memory>
using namespace std;
namespace IR {
FuncArg::FuncArg(IRType _type) : reg(make_shared<Register>()), type(_type) {}

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

Value::Value(IRType _type, int _value) : type(_type), value(_value) {}
Value::Value(IRType _type, shared_ptr<Register> _reg)
    : type(_type), reg(_reg) {}
} // namespace IR