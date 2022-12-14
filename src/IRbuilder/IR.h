#pragma once
#include <list>
#include <memory>
#include <string>
#include <vector>

#include "IR_type.h"
#include "linked_hashmap.hpp"
#include "my_exception.h"
#include "register.h"
using namespace std;
namespace IR {

struct GlobalVarDef {
  string identifier;
  IRType type;
};

struct Block {
  list<any> instrs;
  int label;
  string comment;
  bool closed = false;
  void PushInstr(any instr);
};

struct FuncArg {
  shared_ptr<Register> reg;
  FuncArg(IRType type);
};

struct Func {
  string identifier;
  IRType ret_type;
  list<FuncArg> args;
  list<shared_ptr<Block>> blocks;
  Func();
};
struct Struct {
  string struct_identifier;
  vector<IRType> member_types;
  linked_hashmap<string, int> member_idx;
  // number of Byte of the struct
  int size;
  void AddMemberVar(IRType type, string var_identifier);
};

struct IRBuffer {
  shared_ptr<Func> init_func;
  linked_hashmap<string, shared_ptr<Struct>> structs;
  linked_hashmap<string, shared_ptr<Register>> string_literals;
  list<GlobalVarDef> global_vars;
  list<shared_ptr<Func>> funcs;
};
struct Value {
  shared_ptr<Register> reg;
  IRType type;
  int value;
  // actually is_ptr_to_something.
  // when is_left is true, the type means the type of value it is pointing to
  // so actually it's type must be ptr.
  bool is_left;
  bool is_null;
  struct IRFuncInfo {
    string identifier;
    bool is_member;
    IRType ret_type;
  } func;
  Value(IRType _type);
  Value(int _value, IRType _type = kIntIRType);
  Value(bool _value, IRType _type = kBoolIRType);
  Value(shared_ptr<Register> _reg, bool _is_left = false);
  IRType GetType();
};
}  // namespace IR