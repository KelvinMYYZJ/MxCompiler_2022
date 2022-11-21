#include "IR.h"

#include <bits/stdc++.h>
using namespace std;
namespace IR {
Register::Register(int _idx) : idx(_idx) {}

BinaryExpression::BinaryExpression(shared_ptr<Register> _lhs, shared_ptr<Register> _rhs, BinarayOp _op)
    : lhs(_lhs), rhs(_rhs), op(_op) {}
}  // namespace IR