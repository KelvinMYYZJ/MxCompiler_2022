#include "instr.h"

#include "IR_type.h"
namespace IR {

StoreInstr::StoreInstr(Value _ptr, Value _value) : ptr(_ptr), value(_value) {}

BrInstr::BrInstr(shared_ptr<IR::Block> _target_block) : target_block(_target_block) {}

ConditionBrInstr::ConditionBrInstr(Value _condition_reg, shared_ptr<IR::Block> _true_target_block,
                                   shared_ptr<IR::Block> _false_target_block)
    : condition(_condition_reg), true_target_block(_true_target_block), false_target_block(_false_target_block) {}

RegisterAssignInstr::RegisterAssignInstr(shared_ptr<IR::Register> _left_reg, any _right_value)
    : left_reg(_left_reg), right_value(_right_value) {}

ReturnInstr::ReturnInstr() : have_value(false), value(0) {}
ReturnInstr::ReturnInstr(Value _value) : value(_value), have_value(true) {}

AllocaExpr::AllocaExpr(IRType _type, Value _size) : type(_type), size(_size) {}
FuncCallExpr::FuncCallExpr(const list<Value> &_arg_list, string _identifier, IRType _ret_type)
    : arg_list(_arg_list), identifier(_identifier), ret_type(_ret_type) {}

LoadExpr::LoadExpr(shared_ptr<Register> reg)
    : result_type(reg->type.Deref()),
      ptr(reg) {}  // Fake here, actually should be Value instead of shared_ptr<Register>.

BinaryExpr::BinaryExpr(Value _lhs, Value _rhs, BinarayOp _op, IRType _type)
    : lhs(_lhs), rhs(_rhs), op(_op), type(_type) {}

PhiExpr::PhiExpr(IRType _type) : type(_type) {}
void PhiExpr::PushCase(Case obj) { case_list.push_back(obj); }

GetElementPtrExpr::GetElementPtrExpr(Value _ptr, Value _offset, Value _member_idx, bool _have_member_idx)
    : ptr(_ptr), offset(_offset), member_idx(_member_idx), type(_ptr.type.Deref()), have_member_idx(_have_member_idx) {}
BitcastExpr::BitcastExpr(Value _val, IRType _type) : val(_val), type(_type) {}
}  // namespace IR