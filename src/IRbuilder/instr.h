#pragma once
#include <bits/stdc++.h>

#include <any>
#include <memory>

#include "IR.h"
#include "my_exception.h"
#include "register.h"
using namespace std;
namespace IR {

struct StoreInstr {
  shared_ptr<IR::Register> ptr;
  Value value;
  StoreInstr(shared_ptr<IR::Register> _ptr, Value _value);
};
struct BrInstr {
  shared_ptr<IR::Block> target_block;
  BrInstr(shared_ptr<IR::Block> _target_block);
};
struct ConditionBrInstr {
  Value condition;
  shared_ptr<IR::Block> true_target_block;
  shared_ptr<IR::Block> false_target_block;
  ConditionBrInstr(Value _condition_reg,
                   shared_ptr<IR::Block> _true_target_block,
                   shared_ptr<IR::Block> _false_target_block);
};

struct RegisterAssignInstr {
  shared_ptr<IR::Register> left_reg;
  any right_value;
  RegisterAssignInstr(shared_ptr<IR::Register> _left_reg, any _right_value);
};

struct ReturnInstr {
  bool have_value;
  Value value;
  ReturnInstr();
  ReturnInstr(Value _value);
};

struct LoadExpr {
  IRType result_type;
  Register ptr;
  LoadExpr(IRType _result_type, Register _ptr);
};
struct FuncCall {};

struct BinaryExpr {
  shared_ptr<Register> lhs, rhs;
  enum BinarayOp {};
  BinarayOp op;
  BinaryExpr(shared_ptr<Register> _lhs, shared_ptr<Register> _rhs,
             BinarayOp _op);
};
} // namespace IR