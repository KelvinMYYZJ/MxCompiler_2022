#pragma once
#include <list>
#include <memory>
#include <ostream>
#include <string>
#include <vector>

#include "IR.h"
#include "instr.h"
#include "linked_hashmap.hpp"
#include "register.h"
using std::ostream, std::string;
using namespace IR;
class AsmPrinter {
 public:
  void Print(IRBuffer* ir_buffer, std::ostream& os);

 private:
  vector<int> now_func_reg_offset;
  int now_func_ra_offset;
  int now_func_ret_offset;
  linked_hashmap<int, int> reg_alloca_result;
  struct StructInfo {
    vector<int> member_offset;
    int total_size;
  };
  linked_hashmap<string, StructInfo> struct_info_list;
  struct PhiRequestInfo {
    shared_ptr<Register> tar_reg;
    Value val = 0;
  };
  linked_hashmap<int, list<PhiRequestInfo>> block_phi_requests;
  linked_hashmap<int, GlobalRegister*> bitcast_relations;
  // linked_hashmap<int, >
  string now_func_name;
  int now_func_stack_size;
  int now_block_label;
  int SizeOf(Register* reg);  // return how many bytes a reg will take
  int SizeOf(IRType type);    // return how many bytes a type will take
  string ToString(IRBuffer* ir_buffer);
  string ToString(Func* func);
  string ToLabel(Block* block);
  string ToString(Block* block);
  string ToLiteral(string val);
  string ToStringLiteral(Register* reg, string val);
  string ToGlobalSymbol(string var_identifier);
  string LoadValue(Value val, string tar_reg_name);
  string LoadReg(Register* reg, string tar_reg_name);
  string LoadStack(int offset, IRType load_type, string tar_reg_name);
  string LoadMem(int imm, string addr_reg_name, IRType load_type, string tar_reg_name);
  string StoreValueInRegIntoReg(Register* tar_reg, string val_reg_name);
  string StoreValueIntoStack(int offset, IRType store_type, string val_reg_name);
  string StoreValueIntoReg(Register* tar_reg, Value val);
  int GetRegOffset(Register* reg);
  string ToString(StoreInstr instr);
  string TreatPhiRequest();
  string ToString(BrInstr instr);
  string ToString(ConditionBrInstr instr);
  string ToString(RegisterAssignInstr instr);
  string ToString(ReturnInstr instr);
  // string ToString(Struct* struct_info);
  // string ToString(GlobalVarDef var);
  // string ToString(string val, shared_ptr<Register> reg);
  // string ToString(shared_ptr<Register> reg);
  // string ToString(Value value, bool show_type = true);
  // string DefaultValue(IRType type);
  // string ToString(AllocaExpr expr);
  // string ToString(LoadExpr expr);
  // string ToString(BinaryExpr expr);
  // string ToString(FuncCallExpr expr);
  // string ToString(PhiExpr expr);
  // string ToString(GetElementPtrExpr expr);
  // string ToString(BitcastExpr expr);
};