#include "IR_type.h"
#include "type.h"
using namespace std;
IRType::IRType(TypeKind _kind) : kind(_kind) {}
IRType::IRType(const string &_identifier)
    : identifier(_identifier), kind(kStruct) {}
IRType::IRType(const ObjectType &obj_type) : IRType(kPtrType) {
  if (obj_type == kIntType)
    kind = kInt;
  if (obj_type == kBoolType)
    kind = kChar;
}