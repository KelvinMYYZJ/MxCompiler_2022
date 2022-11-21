#pragma once
#include <bits/stdc++.h>

#include "my_exception.h"
using namespace std;
namespace IR {
struct Register {
  int idx;
  Register(int _idx);
};

struct BinaryExpression {
  shared_ptr<Register> lhs, rhs;
  enum BinarayOp {};
  BinarayOp op;
  BinaryExpression(shared_ptr<Register> _lhs, shared_ptr<Register> _rhs, BinarayOp _op);
};

// struct IRBuffer {
//   list<GlobalVar> global_vars;
//   list<GlobalFunc> global_funcs;
// };
}  // namespace IR