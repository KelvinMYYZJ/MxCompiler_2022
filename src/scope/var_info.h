#pragma once

#include "my_exception.h"
#include "register.h"
#include "type.h"
using namespace std;

struct VarInfo {
  ObjectType type;
  // for a basic varible, reg points to the an i32* register and
  // for a class varible, reg points to an ptr* register and it stores the
  // pointer that this varible is pointing to now.
  shared_ptr<IR::Register> reg;
  VarInfo();
  VarInfo(ObjectType _type);
};