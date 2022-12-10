#pragma once

#include <any>
#include <memory>

#include "IR.h"
#include "IR_type.h"
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
  ConditionBrInstr(Value _condition_reg, shared_ptr<IR::Block> _true_target_block,
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

struct FuncCallExpr {
  list<Value> arg_list;
  string identifier;
  IRType ret_type;
  FuncCallExpr(const list<Value> &_arg_list, string _identifier, IRType _ret_type);
};

struct PhiExpr {
  struct Case {
    shared_ptr<IR::Block> pre_block;
    Value val;
  };
  list<Case> case_list;
  IRType type;
  PhiExpr(IRType _type);
  void PushCase(Case obj);
};

struct BinaryExpr {
  Value lhs, rhs;
  IRType type;
  enum BinarayOp {
    // kLor,
    // kLand,
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
  BinaryExpr(Value _lhs, Value _rhs, BinarayOp _op, IRType _type);
};

struct GetElementPtrExpr {
  IRType type;
  Value ptr;
  Value offset;
  Value member_idx;
  bool have_member_idx;
  GetElementPtrExpr(Value _ptr, Value _offset, Value _member_idx, bool _have_member_idx = true);
};

struct BitcastExpr {
  Value val;
  IRType type;
  BitcastExpr(Value _val, IRType _type);
};
}  // namespace IR