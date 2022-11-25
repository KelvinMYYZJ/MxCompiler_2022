#pragma once
#include <bits/stdc++.h>

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
  IRType type;
  FuncArg(IRType _type);
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
  list<shared_ptr<Struct>> structs;
  list<GlobalVarDef> global_vars;
  list<shared_ptr<Func>> funcs;
};
struct Value {
  shared_ptr<Register> reg;
  IRType type;
  int value;
  Value(IRType _type, int _value = 0);
  Value(IRType _type, shared_ptr<Register> _reg);
};
} // namespace IR