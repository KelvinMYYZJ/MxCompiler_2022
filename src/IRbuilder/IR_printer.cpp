#include "IR_printer.h"

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
  string ret;
  if (IR_type.identifier == "int") {
    ret = "i32";
  } else if (IR_type.identifier == "bool") {
    ret = "i1";
  } else if (IR_type.identifier == "void") {
    ret = "void";
  } else
    ret = "%struct." + IR_type.identifier;
  if (!IR_type.dim)
    return ret;
  return ret + string(IR_type.dim, '*');
  throw MyException("Unexcepted error in IR_type printing");
}
string IRPrinter::ToString(IRBuffer *IR_buffer) {
  string ret;
  for (auto struct_info : IR_buffer->structs) {
    ret += ToString(struct_info.second.get()) + "\n";
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
  if (type.dim)
    return "null";
  if (type.identifier == "int" || type.identifier == "bool")
    return "0";
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
    ret += ToString(func_arg.reg->type);
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
      ret += ToString(AnyCast<RegisterAssignInstr>(instr)) + "\n";
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
    return ToString(value.type) + " " + ToString(value.reg);
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
string IRPrinter::ToString(RegisterAssignInstr instr) {
  Label(instr.left_reg);
  string ret = ToString(instr.left_reg) + " = ";
  if (AnyIs<AllocaExpr>(instr.right_value)) {
    ret += ToString(AnyCast<AllocaExpr>(instr.right_value));
  }
  return ret;
}
string IRPrinter::ToString(ReturnInstr instr) {
  if (instr.have_value) {
    return "ret " + ToString(instr.value);
  }
  return "ret void";
}

string IRPrinter::ToString(AllocaExpr expr) {
  string ret = "alloca ";
  if (expr.size.reg) {
    ret += "[" + ToString(expr.size) + " x " + expr.type.identifier + "]";
  } else {
    if (expr.size.value == 1) {
      ret += expr.type.identifier;
    } else {
      ret +=
          "[" + to_string(expr.size.value) + " x " + expr.type.identifier + "]";
    }
  }
  return ret;
}