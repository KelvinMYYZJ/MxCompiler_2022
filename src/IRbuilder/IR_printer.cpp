#include "IR_printer.h"

#include <bits/stdc++.h>
#include <cstdio>
#include <memory>
#include <string>

#include "my_any.hpp"
#include "my_exception.h"
#include "register.h"
using namespace std;
using namespace IR;

void IRPrinter::Print(IRBuffer *IR_buffer, ostream &os) {
  os << ToString(IR_buffer);
}
string IRPrinter::ToString(IRType IR_type) {
  switch (IR_type.kind) {
  case IRType::kInt:
    return "i32";
  case IRType::kChar:
    return "i8";
  case IRType::kPtr:
    return "ptr";
  }
  throw MyException("Unexcepted error in IR_type printing");
}
string IRPrinter::ToString(IRBuffer *IR_buffer) {
  string ret;
  for (auto struct_info : IR_buffer->structs) {
    ret += ToString(struct_info.get()) + "\n";
  }
  ret += "\n";
  for (auto var : IR_buffer->global_vars) {
    ret += ToString(var) + "\n";
  }
  ret += "\n";
  for (auto func : IR_buffer->funcs) {
    ret += ToString(func) + "\n\n";
  }
  return ret;
}
string IRPrinter::ToString(
    Struct *struct_info) { //%struct.Type1233 = type { i32, i32 }
  string ret;
  ret += "%struct." + struct_info->struct_identifier + " = type {";
  for (auto member_type : struct_info->member_types) {
    ret += " " + ToString(member_type) + ",";
  }
  ret.pop_back();
  ret += " }";
  return ret;
}

string IRPrinter::ToString(GlobalVarDef var) {
  return "@" + var.identifier + " = global " + ToString(var.type) + " " +
         DefaultValue(var.type);
}
string IRPrinter::DefaultValue(IRType type) {
  switch (type.kind) {
  case IRType::kInt:
  case IRType::kChar:
    return "0";
  case IRType::kPtr:
    return "null";
  }
  throw MyException("Unexcepted error in IR_type printing");
}

void IRPrinter::Label(shared_ptr<Register> reg) {
  if (!dynamic_cast<GlobalRegister *>(reg.get()))
    reg->label = now_block_idx++;
}

void IRPrinter::Label(shared_ptr<Block> block) { block->label = now_reg_idx++; }

string IRPrinter::ToString(shared_ptr<Func> func) {
  string ret;
  now_reg_idx = 0;
  now_block_idx = 0;
  ret += "define " + ToString(func->ret_type) + " @" + func->identifier + "(";
  for (auto func_arg : func->args) {
    ret += ToString(func_arg.type);
    Label(func_arg.reg);
    ret += " " + ToString(func_arg.reg) + ", ";
  }
  if (func->args.size()) {
    ret.pop_back();
    ret.pop_back();
  }
  ret += ") {\n";

  for (auto block : func->blocks) {
    Label(block);
  }
  for (auto block : func->blocks) {
    ret += ToString(block) + "\n";
  }
  ret += "}";
  return ret;
}

string IRPrinter::ToString(shared_ptr<Register> reg) {
  if (auto g_reg = dynamic_cast<GlobalRegister *>(reg.get())) {
    return "@" + g_reg->global_label;
  }
  return "%" + to_string(reg->label);
}

string IRPrinter::ToString(shared_ptr<Block> block) {
  string ret;
  ret += "block" + to_string(block->label) + ":\n";
  for (auto instr : block->instrs) {
    if (AnyIs<StoreInstr>(instr)) {
      ret += ToString(AnyCast<StoreInstr>(instr)) + "\n";
    } else if (AnyIs<BrInstr>(instr)) {
      ret += ToString(AnyCast<BrInstr>(instr)) + "\n";
    } else if (AnyIs<ConditionBrInstr>(instr)) {
      ret += ToString(AnyCast<ConditionBrInstr>(instr)) + "\n";
    } else if (AnyIs<RegisterAssignInstr>(instr)) {
      // ret += ToString(AnyCast<RegisterAssignInstr>(instr)) + "\n";
    } else if (AnyIs<ReturnInstr>(instr)) {
      ret += ToString(AnyCast<ReturnInstr>(instr)) + "\n";
    }
  }
  return ret;
}
string IRPrinter::ToLabel(shared_ptr<Block> block) {
  return "label %block" + to_string(block->label);
}
string IRPrinter::ToString(Value value) {
  if (value.reg)
    return ToString(value.type) + " %" + to_string(value.reg->label);
  return ToString(value.type) + " " + to_string(value.value);
}
string IRPrinter::ToString(StoreInstr instr) {
  return "store " + ToString(instr.value) + ", " + ToString(instr.ptr);
}
string IRPrinter::ToString(BrInstr instr) {
  return "br " + ToLabel(instr.target_block);
}
string IRPrinter::ToString(ConditionBrInstr instr) {
  return "br " + ToString(instr.condition) + ", " +
         ToLabel(instr.true_target_block) + ", " +
         ToLabel(instr.false_target_block);
}
// string IRPrinter::ToString(RegisterAssignInstr instr) { return; }
string IRPrinter::ToString(ReturnInstr instr) {
  if (instr.have_value) {
    return "ret " + ToString(instr.value);
  }
  return "ret void";
}