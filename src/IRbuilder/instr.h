#pragma once

#include <any>
#include <memory>

#include "IR.h"
#include "my_exception.h"
#include "register.h"
using namespace std;
namespace IR {

struct StoreInstr {
  Value ptr;
  Value value;
  StoreInstr(Value _ptr, Value _value);
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
  shared_ptr<Register> ptr;
  LoadExpr(shared_ptr<Register> reg);
};

struct AllocaExpr {
  IRType type;
  Value size;
  AllocaExpr(IRType _type, Value _size = 1);
};

struct FuncCall {};

struct BinaryExpr {
  Value lhs, rhs;
  enum BinarayOp {
    kLor,
    kLand,
    kOr,
    kXor,
    kAnd,
    kEqual,
    kNotequal,
    kLess,
    kLessEqual,
    kGreater,
    kGreaterEqual,
    kLeftShift,
    kRightShift,
    kPlus,
    kMinus,
    kStar,
    kDiv,
    kMod
  };
  BinarayOp op;
  BinaryExpr(Value _lhs, Value _rhs, BinarayOp _op);
};
} // namespace IR