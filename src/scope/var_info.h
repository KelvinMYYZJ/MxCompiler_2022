#pragma once
#include <bits/stdc++.h>

#include "IR.h"
#include "my_exception.h"
#include "type.h"
using namespace std;

struct VarInfo {
  ObjectType type;
  IR::Register *reg;
  VarInfo(ObjectType _type);
};