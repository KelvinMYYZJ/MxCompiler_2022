#pragma once
#include <memory>

#include "AST_nodes.h"
#include "IR.h"
#include "instr.h"
#include "my_exception.h"
using namespace std;
using namespace IR;
struct IRPrinter {
  int now_reg_idx;
  int now_block_idx;
  void Print(IRBuffer *IR_buffer, ostream &os);
  void Label(shared_ptr<Register> reg);
  void Label(shared_ptr<Block> block);
  // void LabelAll(shared_ptr<Block> block);
  string ToString(IRType IR_type);
  string ToString(IRBuffer *IR_buffer);
  string ToString(Struct *struct_info);
  string ToString(GlobalVarDef var);
  string ToString(shared_ptr<Func> func);
  string ToString(shared_ptr<Register> reg);
  string ToString(shared_ptr<Block> block);
  string ToLabel(shared_ptr<Block> block, bool show_type = true);
  string ToString(Value value, bool show_type = true);
  string ToString(StoreInstr instr);
  string ToString(BrInstr instr);
  string ToString(ConditionBrInstr instr);
  string ToString(RegisterAssignInstr instr);
  string ToString(ReturnInstr instr);
  string DefaultValue(IRType type);
  string ToString(AllocaExpr expr);
  string ToString(LoadExpr expr);
  string ToString(BinaryExpr expr);
  string ToString(FuncCallExpr expr);
  string ToString(PhiExpr expr);
  string ToString(GetElementPtrExpr expr);
};
