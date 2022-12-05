#pragma once
#include <list>
#include <memory>
#include <string>

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
  list<IRType> member_types;
  linked_hashmap<string, int> member_idx;
  void AddMemberVar(IRType type, string var_identifier);
};

struct IRBuffer {
  shared_ptr<Func> init_func;
  linked_hashmap<string, shared_ptr<Struct>> structs;
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
  Value(IRType _type, int _value = 0);
  Value(int _value, IRType _type = kIntIRType);
  Value(shared_ptr<Register> _reg, bool _is_left = false);
  IRType GetType();
};
}  // namespace IR