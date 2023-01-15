#include "asm_printer.h"

#include <string>

#include "builtin.h"
#include "instr.h"
#include "my_any.hpp"
#include "my_exception.h"
#include "register.h"
using std::ostream, std::string;
void AsmPrinter::Print(IR::IRBuffer *ir_buffer, std::ostream &os) { os << ToString(ir_buffer); }

int AsmPrinter::SizeOf(Register *reg) { return SizeOf(reg->type); }

int AsmPrinter::SizeOf(IRType type) {
  if (type == kBoolIRType) return 1;
  if (type == kVoidIRType) return 0;
  if (type == kIntIRType) return 4;
  if (!type.dim) {
    MyAssert(struct_info_list.count(type.identifier), "size of un collected struct : " + type.identifier);
    return struct_info_list[type.identifier].total_size;
  }
  return 4;
}

string AsmPrinter::ToString(IR::IRBuffer *ir_buffer) {
  struct_info_list.clear();
  for (const auto &now_struct : ir_buffer->structs) {
    MyAssert(!struct_info_list.count(now_struct.first), "multiple definition of struct " + now_struct.first);
    auto &struct_info = struct_info_list[now_struct.first];
    auto &memebr_offset = struct_info.member_offset;
    int &now_offset = struct_info.total_size;
    for (const auto &now_member_type : now_struct.second->member_types) {
      memebr_offset.push_back(now_offset);
      now_offset += SizeOf(now_member_type);
    }
  }
  string ret = kBuiltinASM;
  ret +=
      "\n"
      "\n"
      "\t.text\n"
      "\t.align 2\n"
      "\n";
  for (auto func : ir_buffer->funcs) {
    ret += ToString(func.get());
  }
  ret += "\n";
  ret += "\t.section .rodata\n";
  for (auto string_literal : ir_buffer->string_literals) {
    ret += ToStringLiteral(string_literal.second.get(), string_literal.first);
  }
  ret += "\n";
  ret += "\t.section .data\n";
  for (auto global_var : ir_buffer->global_vars) {
    ret += ToGlobalSymbol(global_var.identifier);
  }
  return ret;
}

string AsmPrinter::ToString(Func *func) {
  now_func_name = func->identifier;
  string ret = "\t.globl " + func->identifier + "\n";
  ret += func->identifier + ":\n";
  // Collect the virtual registers in this function
  now_func_reg_offset.clear();
  reg_alloca_result.clear();
  bitcast_relations.clear();
  int tmp_stack_size = 0;
  auto collect_reg_into_stack = [&](Register *reg) -> void {
    MyAssert(reg->label == now_func_reg_offset.size(), "unexcepted label in collecting! ");
    tmp_stack_size += SizeOf(reg);
    now_func_reg_offset.push_back(-tmp_stack_size);
  };
  for (auto func_arg : func->args) {
    collect_reg_into_stack(func_arg.reg.get());
  }

  // space for ret
  tmp_stack_size += SizeOf(func->ret_type);
  now_func_ret_offset = -tmp_stack_size;

  // space for ra
  tmp_stack_size += 4;
  now_func_ra_offset = -tmp_stack_size;

  for (const auto &block : func->blocks) {
    for (const auto &instr : block->instrs) {
      if (AnyIs<RegisterAssignInstr>(instr)) {
        auto real_instr = AnyCast<RegisterAssignInstr>(instr);
        if (AnyIs<FuncCallExpr>(real_instr.right_value) &&
            AnyCast<FuncCallExpr>(real_instr.right_value).ret_type == kVoidIRType)
          continue;
        if (AnyIs<BitcastExpr>(real_instr.right_value)) {
          auto bit_cast_expr = AnyCast<BitcastExpr>(real_instr.right_value);
          if (auto greg = dynamic_cast<GlobalRegister *>(bit_cast_expr.val.reg.get())) {
            bitcast_relations[real_instr.left_reg->label] = greg;

          } else
            real_instr.left_reg->label = bit_cast_expr.val.reg->label;
          now_func_reg_offset.push_back(0x7fffffff);
          continue;
        }
        if (AnyIs<AllocaExpr>(real_instr.right_value)) {
          auto type = AnyCast<AllocaExpr>(real_instr.right_value).type;
          tmp_stack_size += SizeOf(type);
          MyAssert(!reg_alloca_result.count(real_instr.left_reg->label), "multiple alloca");
          reg_alloca_result[real_instr.left_reg->label] = -tmp_stack_size;
        }
        collect_reg_into_stack(real_instr.left_reg.get());
      }
    }
  }

  // now the total stack size is sure
  now_func_stack_size = tmp_stack_size;
  // modify the offset (should calculate from the top)
  now_func_ret_offset += now_func_stack_size;
  now_func_ra_offset += now_func_stack_size;
  for (auto &reg_offset : now_func_reg_offset) {
    reg_offset += now_func_stack_size;
  }
  for (auto &alloca_result_pair : reg_alloca_result) {
    alloca_result_pair.second += now_func_stack_size;
  }

  // DEBUG
  int ttt = 0;
  for (auto &reg_pos : now_func_reg_offset) {
    ret += "# %" + to_string(ttt) + " : " + to_string(reg_pos) + "(sp)\n";
    ttt++;
  }
  // collect phi info
  block_phi_requests.clear();
  for (const auto &block : func->blocks) {
    auto instr = block->instrs.front();
    if (AnyIs<RegisterAssignInstr>(instr)) {
      auto real_instr = AnyCast<RegisterAssignInstr>(instr);
      if (AnyIs<PhiExpr>(real_instr.right_value)) {
        auto phi_expr = AnyCast<PhiExpr>(real_instr.right_value);
        for (const auto &phi_case : phi_expr.case_list) {
          PhiRequestInfo tmp_phi_request;
          tmp_phi_request.tar_reg = real_instr.left_reg;
          tmp_phi_request.val = phi_case.val;
          int now_block_idx = phi_case.pre_block->label;
          block_phi_requests[now_block_idx].push_back(tmp_phi_request);
        }
      }
    }
  }

  // some necessary work
  ret += "\taddi sp,sp," + to_string(-tmp_stack_size) + "\n";
  ret += "\tsw ra," + to_string(now_func_ra_offset) + "(sp)\n";
  for (auto block : func->blocks) {
    ret += ToString(block.get());
  }
  ret += "\n";
  now_func_name = "";
  return ret;
}

string AsmPrinter::ToLabel(Block *block) { return "." + now_func_name + ".block" + to_string(block->label); }

string AsmPrinter::ToString(Block *block) {
  now_block_label = block->label;
  string ret = "";
  ret += ToLabel(block) + ":\n";
  for (auto any_instr : block->instrs) {
    if (AnyIs<StoreInstr>(any_instr)) {
      ret += ToString(AnyCast<StoreInstr>(any_instr));
    } else if (AnyIs<BrInstr>(any_instr)) {
      ret += ToString(AnyCast<BrInstr>(any_instr));
    } else if (AnyIs<ConditionBrInstr>(any_instr)) {
      ret += ToString(AnyCast<ConditionBrInstr>(any_instr));
    } else if (AnyIs<RegisterAssignInstr>(any_instr)) {
      ret += ToString(AnyCast<RegisterAssignInstr>(any_instr));
    } else if (AnyIs<ReturnInstr>(any_instr)) {
      ret += ToString(AnyCast<ReturnInstr>(any_instr));
    }
    ret += "\n";
  }
  return ret;
}

string AsmPrinter::ToLiteral(string val) {
  string ret = "\"";
  for (auto ch : val) {
    switch (ch) {
      case '\n':
        ret += "\\n";
        break;
      case '\"':
        ret += "\\\"";
        break;
      case '\\':
        ret += "\\\\";
        break;
      default:
        ret.push_back(ch);
    }
  }
  ret += "\"";
  return ret;
}

string AsmPrinter::ToStringLiteral(Register *reg, string val) {
  GlobalRegister *greg = dynamic_cast<GlobalRegister *>(reg);
  string ret = greg->global_label + ":\n";
  ret += "\t.string " + ToLiteral(val) + "\n ";
  return ret;
}

string AsmPrinter::ToGlobalSymbol(string var_identifier) { return var_identifier + ":\n" + "\t.word 0\n"; }
string AsmPrinter::LoadValue(Value val, string tar_reg_name) {
  if (val.reg) {
    return LoadReg(val.reg.get(), tar_reg_name);
  }
  return "\tli " + tar_reg_name + "," + to_string(val.value) + "\n";
}

string AsmPrinter::LoadReg(Register *reg, string tar_reg_name) {
  if (auto greg = dynamic_cast<GlobalRegister *>(reg)) {
    return "\tlui " + tar_reg_name + ",%hi(" + greg->global_label + ")\n" + "\taddi " + tar_reg_name + "," +
           tar_reg_name + ",%lo(" + greg->global_label + ")\n";
  }
  if (bitcast_relations.count(reg->label)) return LoadReg(bitcast_relations[reg->label], tar_reg_name);
  // TODO? : load struct
  return LoadStack(GetRegOffset(reg), reg->type, tar_reg_name);
  // if (SizeOf(reg) == 1) return "\tlbu " + tar_reg_name + "," + to_string(GetRegOffset(reg)) + "(sp)\n";
  // return "\tlw " + tar_reg_name + "," + to_string(GetRegOffset(reg)) + "(sp)\n";
}

string AsmPrinter::LoadStack(int offset, IRType load_type, string tar_reg_name) {
  return LoadMem(offset, "sp", load_type, tar_reg_name);
}

string AsmPrinter::LoadMem(int imm, string addr_reg_name, IRType load_type, string tar_reg_name) {
  if (SizeOf(load_type) == 1) return "\tlbu " + tar_reg_name + "," + to_string(imm) + "(" + addr_reg_name + ")\n";
  return "\tlw " + tar_reg_name + "," + to_string(imm) + "(" + addr_reg_name + ")\n";
}

string AsmPrinter::StoreValueInRegIntoReg(Register *tar_reg, string val_reg_name) {
  string ret;
  if (auto greg = dynamic_cast<GlobalRegister *>(tar_reg)) {
    // Treat global reg
  }
  ret += StoreValueIntoStack(GetRegOffset(tar_reg), tar_reg->type, val_reg_name);
  return ret;
}

string AsmPrinter::StoreValueIntoStack(int offset, IRType store_type, string val_reg_name) {
  string ret;
  if (SizeOf(store_type) == 1)
    ret += "\tsb " + val_reg_name + "," + to_string(offset) + "(sp)\n";
  else
    ret += "\tsw " + val_reg_name + "," + to_string(offset) + "(sp)\n";
  return ret;
}

string AsmPrinter::StoreValueIntoReg(Register *tar_reg, Value val) {
  string ret;
  ret += LoadValue(val, "t1");
  ret += StoreValueInRegIntoReg(tar_reg, "t1");
  return ret;
}

int AsmPrinter::GetRegOffset(Register *reg) { return now_func_reg_offset[reg->label]; }
string AsmPrinter::ToString(StoreInstr instr) {
  string ret;
  ret += LoadValue(instr.value, "t1");
  ret += LoadValue(instr.ptr, "t0");
  if (SizeOf(instr.value.type) == 1)
    ret += "\tsb t1,0(t0)\n";
  else
    ret += "\tsw t1,0(t0)\n";
  return ret;
}

string AsmPrinter::TreatPhiRequest() {
  string ret = "";
  if (block_phi_requests.count(now_block_label) && block_phi_requests[now_block_label].size()) {
    // deal the phi requests
    for (const auto &phi_request : block_phi_requests[now_block_label]) {
      ret += StoreValueIntoReg(phi_request.tar_reg.get(), phi_request.val);
    }
  }
  return ret;
}

string AsmPrinter::ToString(BrInstr instr) {
  string ret = TreatPhiRequest();
  ret += "\tj " + ToLabel(instr.target_block.get()) + "\n";
  return ret;
}

string AsmPrinter::ToString(ConditionBrInstr instr) {
  string ret = TreatPhiRequest();
  ret += LoadValue(instr.condition, "t0");
  ret += "\tbnez t0," + ToLabel(instr.true_target_block.get()) + "\n";
  ret += "\tj " + ToLabel(instr.false_target_block.get()) + "\n";
  return ret;
}

string AsmPrinter::ToString(RegisterAssignInstr instr) {
  string ret;
  if (AnyIs<PhiExpr>(instr.right_value)) return ret;
  // store the result of expr into t1
  if (AnyIs<AllocaExpr>(instr.right_value)) {
    ret += "\taddi t1,sp," + to_string(reg_alloca_result[instr.left_reg->label]) + "\n";
  } else if (AnyIs<LoadExpr>(instr.right_value)) {
    auto load_expr = AnyCast<LoadExpr>(instr.right_value);
    ret += LoadValue(load_expr.ptr, "t0");
    ret += LoadMem(0, "t0", instr.left_reg->type, "t1");
  } else if (AnyIs<BinaryExpr>(instr.right_value)) {
    auto bin_expr = AnyCast<BinaryExpr>(instr.right_value);
    // TODO(OPT) : if both side is const value then skip the calclation step
    ret += LoadValue(bin_expr.lhs, "t0");
    ret += LoadValue(bin_expr.rhs, "t1");
    string op;
    bool finish_flag = false;
    switch (bin_expr.op) {
      case IR::BinaryExpr::kOr:
        op = "or";
        break;
      case IR::BinaryExpr::kXor:
        op = "xor";
        break;
      case IR::BinaryExpr::kAnd:
        op = "and";
        break;
      case IR::BinaryExpr::kEqual:
        ret += "\txor t1,t0,t1\n";
        ret += "\tseqz t1,t1\n";
        finish_flag = true;
        break;
      case IR::BinaryExpr::kNotequal:
        ret += "\txor t1,t0,t1\n";
        ret += "\tsnez t1,t1\n";
        finish_flag = true;
        break;
      case IR::BinaryExpr::kLess:
        op = "slt";
        break;
      case IR::BinaryExpr::kLessEqual:
        ret += "\tslt t1,t1,t0\n";
        ret += "\txori t1,t1,1\n";
        finish_flag = true;
        break;
      case IR::BinaryExpr::kGreater:
        ret += "\tslt t1,t1,t0\n";
        finish_flag = true;
        break;
      case IR::BinaryExpr::kGreaterEqual:
        ret += "\tslt t1,t0,t1\n";
        ret += "\txori t1,t1,1\n";
        finish_flag = true;
        break;
      case IR::BinaryExpr::kLeftShift:
        op = "sll";
        break;
      case IR::BinaryExpr::kRightShift:
        op = "srl";
        break;
      case IR::BinaryExpr::kPlus:
        op = "add";
        break;
      case IR::BinaryExpr::kMinus:
        op = "sub";
        break;
      case IR::BinaryExpr::kStar:
        op = "mul";
        break;
      case IR::BinaryExpr::kDiv:
        op = "div";
        break;
      case IR::BinaryExpr::kMod:
        op = "rem";
        break;
    }
    if (!finish_flag) {
      ret += "\t" + op + " t1,t0,t1\n";
    }
  } else if (AnyIs<FuncCallExpr>(instr.right_value)) {
    auto func_call_expr = AnyCast<FuncCallExpr>(instr.right_value);
    // Push arguments into stack
    int now_offset = 0;
    for (auto arg : func_call_expr.arg_list) {
      now_offset -= SizeOf(arg.type);
      ret += LoadValue(arg, "t1");
      ret += StoreValueIntoStack(now_offset, arg.type, "t1");
    }
    ret += "\tcall " + func_call_expr.identifier + "\n";
    if (func_call_expr.ret_type == kVoidIRType) {
      return ret;
    }
    ret += "\tmv t1,a0\n";
  } else if (AnyIs<GetElementPtrExpr>(instr.right_value)) {
    auto get_element_ptr_expr = AnyCast<GetElementPtrExpr>(instr.right_value);
    // first store offset into t2
    if (!get_element_ptr_expr.have_member_idx) {
      // array type
      int single_offset = SizeOf(get_element_ptr_expr.type);
      ret += LoadValue(get_element_ptr_expr.offset, "t1");
      ret += "\tli t2," + to_string(single_offset) + "\n";
      ret += "\tmul t2,t1,t2\n";
      // ret += "\tadd t2,t1,t2\n";
      ret += LoadValue(get_element_ptr_expr.ptr, "t1");
      ret += "\tadd t1,t1,t2\n";
    } else {
      // member type
      ret += LoadValue(get_element_ptr_expr.ptr, "t1");
      int offset =
          struct_info_list[get_element_ptr_expr.type.identifier].member_offset[get_element_ptr_expr.member_idx.value];
      ret += "\taddi t1,t1," + to_string(offset) + "\n";
    }
  } else if (AnyIs<BitcastExpr>(instr.right_value)) {
    return "\tnop\n";
  }
  ret += StoreValueInRegIntoReg(instr.left_reg.get(), "t1");
  return ret;
}

string AsmPrinter::ToString(ReturnInstr instr) {
  string ret;
  if (instr.have_value) {
    ret += LoadValue(instr.value, "a0");
  }
  ret += "\tlw ra," + to_string(now_func_ra_offset) + "(sp)\n";
  ret += "\taddi sp,sp," + to_string(now_func_stack_size) + "\n";
  // actually unnecessary
  // if (SizeOf(instr.value.type) == 1)
  //   ret += "\tsb a0,-1(sp)\n";
  // else
  //   ret += "\tsw a0,-4(sp)\n";
  ret += "\tret\n";
  return ret;
}