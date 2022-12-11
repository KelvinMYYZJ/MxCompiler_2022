#include "IR_printer.h"

#include <cstdio>
#include <memory>
#include <string>

#include "IR_type.h"
#include "my_any.hpp"
#include "my_exception.h"
#include "register.h"
using namespace std;
using namespace IR;

void IRPrinter::Print(IRBuffer *IR_buffer, ostream &os) { os << ToString(IR_buffer); }
string IRPrinter::ToString(IRType IR_type) {
  string ret;
  if (IR_type.identifier == "int") {
    ret = "i32";
  } else if (IR_type.identifier == "bool") {
    ret = "i1";
  } else if (IR_type.identifier == "_char") {
    ret = "i8";
  } else if (IR_type.identifier == "void") {
    ret = "void";
  } else
    ret = "%struct." + IR_type.identifier;
  if (IR_type.size) ret = "[" + to_string(IR_type.size) + " x " + ret + "]";
  if (!IR_type.dim) return ret;
  return ret + string(IR_type.dim, '*');
  throw MyException("Unexcepted error in IR_type printing");
}
string IRPrinter::ToString(IRBuffer *IR_buffer) {
  string ret =
      "declare i8* @__Malloc_array(i32)\n"
      "declare i8* @__Malloc_int(i32)\n"
      "declare i8* @__Malloc_bool(i32)\n"
      "declare i8* @__Malloc_ptr(i32)\n"
      "declare void @print(%struct.string *)\n"
      "declare void @println(%struct.string *)\n"
      "declare void @printInt(i32)\n"
      "declare void @printlnInt(i32)\n"
      "declare %struct.string* @toString(i32)\n"
      "declare %struct.string* @getString()\n"
      "declare i32 @getInt()\n"
      "declare i32 @string.length(%struct.string*)\n"
      "declare i32 @string.parseInt(%struct.string*)\n"
      "declare i32 @string.ord(%struct.string*, i32)\n"
      "declare %struct.string* @string.substring(%struct.string*, i32, i32)\n"
      "declare i1 @_string.lt(%struct.string*, %struct.string*)\n"
      "declare i1 @_string.le(%struct.string*, %struct.string*)\n"
      "declare i1 @_string.eq(%struct.string*, %struct.string*)\n"
      "declare i1 @_string.neq(%struct.string*, %struct.string*)\n"
      "declare %struct.string* @_string_add(%struct.string*, %struct.string*)\n";
  for (auto struct_info : IR_buffer->structs) {
    ret += ToString(struct_info.second.get()) + "\n";
  }
  ret += "\n";
  for (auto var : IR_buffer->global_vars) {
    ret += ToString(var) + "\n";
  }
  ret += "\n";
  for (auto string_literals : IR_buffer->string_literals) {
    ret += ToString(string_literals.first, string_literals.second) + "\n";
  }
  ret += "\n";
  for (auto func : IR_buffer->funcs) {
    ret += ToString(func) + "\n";
  }
  return ret;
}
string IRPrinter::ToString(Struct *struct_info) {  //%struct.Type1233 = type { i32, i32 }
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
  return "@" + var.identifier + " = global " + ToString(var.type) + " " + DefaultValue(var.type);
}
string IRPrinter::DefaultValue(IRType type) {
  if (type.dim) return "null";
  if (type.identifier == "int" || type.identifier == "bool") return "0";
  return "zeroinitializer";
}

string IRPrinter::ToString(string val, shared_ptr<Register> reg) {
  GlobalRegister *greg = dynamic_cast<GlobalRegister *>((reg.get()));
  string ret = "@" + greg->global_label + " = global " + ToString(greg->type.Deref()) + " " + ToLiteral(val);
  return ret;
}

string IRPrinter::ToLiteral(string val) {
  string ret = "c\"";
  for (auto ch : val) {
    switch (ch) {
      case '\n':
        ret += "\\0A";
        break;
      case '\"':
        ret += "\\22";
        break;
      case '\\':
        ret += "\\\\";
        break;
      default:
        ret.push_back(ch);
    }
  }
  ret += "\\00\"";
  return ret;
}

void IRPrinter::Label(shared_ptr<Register> reg) {
  if (!dynamic_cast<GlobalRegister *>(reg.get())) reg->label = now_block_idx++;
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
  ret += "block" + to_string(block->label) + ": ;" + block->comment + "\n";
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
string IRPrinter::ToLabel(shared_ptr<Block> block, bool show_type) {
  if (!show_type) {
    return "%block" + to_string(block->label);
  }
  return "label %block" + to_string(block->label);
}
string IRPrinter::ToString(Value value, bool show_type) {
  // if (!show_type) {
  //   if (value.reg)
  //     return ToString(value.reg);
  //   return to_string(value.value);
  // }
  // if (value.reg)
  //   return ToString(value.type) + " " + ToString(value.reg);
  // return ToString(value.type) + " " + to_string(value.value);
  string val;
  string type = ToString(value.type);
  if (value.reg) {
    val = ToString(value.reg);
  } else if ((value.type.dim && value.value == 0) || value.is_null) {
    val = "null";
  } else {
    val = to_string(value.value);
  }
  if (show_type) return type + " " + val;
  return val;
}
string IRPrinter::ToString(StoreInstr instr) { return "store " + ToString(instr.value) + ", " + ToString(instr.ptr); }
string IRPrinter::ToString(BrInstr instr) { return "br " + ToLabel(instr.target_block); }
string IRPrinter::ToString(ConditionBrInstr instr) {
  return "br " + ToString(instr.condition) + ", " + ToLabel(instr.true_target_block) + ", " +
         ToLabel(instr.false_target_block);
}
string IRPrinter::ToString(RegisterAssignInstr instr) {
  if (AnyIs<FuncCallExpr>(instr.right_value) && AnyCast<FuncCallExpr>(instr.right_value).ret_type == kVoidIRType) {
    return ToString(AnyCast<FuncCallExpr>(instr.right_value));
  }
  Label(instr.left_reg);
  string ret = ToString(instr.left_reg) + " = ";
  if (AnyIs<AllocaExpr>(instr.right_value)) {
    ret += ToString(AnyCast<AllocaExpr>(instr.right_value));
  } else if (AnyIs<LoadExpr>(instr.right_value)) {
    ret += ToString(AnyCast<LoadExpr>(instr.right_value));
  } else if (AnyIs<BinaryExpr>(instr.right_value)) {
    ret += ToString(AnyCast<BinaryExpr>(instr.right_value));
  } else if (AnyIs<FuncCallExpr>(instr.right_value)) {
    ret += ToString(AnyCast<FuncCallExpr>(instr.right_value));
  } else if (AnyIs<PhiExpr>(instr.right_value)) {
    ret += ToString(AnyCast<PhiExpr>(instr.right_value));
  } else if (AnyIs<GetElementPtrExpr>(instr.right_value)) {
    ret += ToString(AnyCast<GetElementPtrExpr>(instr.right_value));
  } else if (AnyIs<BitcastExpr>(instr.right_value)) {
    ret += ToString(AnyCast<BitcastExpr>(instr.right_value));
  }
  return ret;
}
string IRPrinter::ToString(BinaryExpr instr) {
  string ret;
  switch (instr.op) {
    // case IR::BinaryExpr::kLor:
    //   ret = "";
    //   break;
    // case IR::BinaryExpr::kLand:
    //   ret = "";
    //   break;
    case IR::BinaryExpr::kOr:
      ret = "or";
      break;
    case IR::BinaryExpr::kXor:
      ret = "xor";
      break;
    case IR::BinaryExpr::kAnd:
      ret = "and";
      break;
    case IR::BinaryExpr::kEqual:
      ret = "icmp eq";
      break;
    case IR::BinaryExpr::kNotequal:
      ret = "icmp ne";
      break;
    case IR::BinaryExpr::kLess:
      ret = "icmp slt";
      break;
    case IR::BinaryExpr::kLessEqual:
      ret = "icmp sle";
      break;
    case IR::BinaryExpr::kGreater:
      ret = "icmp sgt";
      break;
    case IR::BinaryExpr::kGreaterEqual:
      ret = "icmp sge";
      break;
    case IR::BinaryExpr::kLeftShift:
      ret = "shl";
      break;
    case IR::BinaryExpr::kRightShift:
      ret = "ashr";
      break;
    case IR::BinaryExpr::kPlus:
      ret = "add";
      break;
    case IR::BinaryExpr::kMinus:
      ret = "sub";
      break;
    case IR::BinaryExpr::kStar:
      ret = "mul";
      break;
    case IR::BinaryExpr::kDiv:
      ret = "sdiv";
      break;
    case IR::BinaryExpr::kMod:
      ret = "srem";
      break;
  }
  ret += " ";
  ret += ToString(instr.lhs);
  ret += ", ";
  ret += ToString(instr.rhs, false);
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
  string type_str = ToString(expr.type);
  if (expr.size.reg) {
    ret += "[" + ToString(expr.size) + " x " + type_str + "]";
  } else {
    if (expr.size.value == 1) {
      ret += type_str;
    } else {
      ret += "[" + to_string(expr.size.value) + " x " + type_str + "]";
    }
  }
  return ret;
}
string IRPrinter::ToString(LoadExpr expr) {
  string ret = "load " + ToString(expr.result_type) + ", " + ToString(Value(expr.ptr));
  return ret;
}
string IRPrinter::ToString(FuncCallExpr expr) {
  string ret = "call " + ToString(expr.ret_type) + " @" + (expr.identifier) + "(";
  for (auto arg : expr.arg_list) {
    ret += ToString(arg) + ", ";
  }
  if (expr.arg_list.size()) {
    ret.pop_back();
    ret.pop_back();
  }
  ret += ")";
  return ret;
}
string IRPrinter::ToString(PhiExpr expr) {
  string ret = "phi " + ToString(expr.type) + " ";
  for (auto now_case : expr.case_list) {
    ret += "[ " + ToString(now_case.val, false) + ", " + ToLabel(now_case.pre_block, false) + " ], ";
  }
  ret.pop_back();
  ret.pop_back();
  return ret;
}

string IRPrinter::ToString(GetElementPtrExpr expr) {
  string ret = "getelementptr inbounds " + ToString(expr.type);
  ret += ", " + ToString(expr.ptr);
  ret += ", " + ToString(expr.offset);
  if (expr.have_member_idx) ret += ", " + ToString(expr.member_idx);
  return ret;
}

string IRPrinter::ToString(BitcastExpr expr) {
  string ret = "bitcast " + ToString(expr.val) + " to " + ToString(expr.type);
  return ret;
}
