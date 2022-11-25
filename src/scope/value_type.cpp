#include "value_type.h"

#include "my_exception.h"

using namespace std;

ValueType::ValueType() : have_func_type(false), have_object_type(false) {}

void ValueType::AddObjectType(const ObjectType &_object_type,
                              bool is_leftvalue) {
  object_type = _object_type;
  object_leftvalue = is_leftvalue;
  have_object_type = true;
}

void ValueType::SetObjectType(const ObjectType &_object_type,
                              bool is_leftvalue) {
  AddObjectType(_object_type, is_leftvalue);
  have_func_type = false;
}
void ValueType::AddFuncType(const FuncType &_func_type) {
  func_type = _func_type;
  have_func_type = true;
}
void ValueType::SetFuncType(const FuncType &_func_type) {
  AddFuncType(_func_type);
  have_object_type = false;
}

ObjectType ValueType::GetObjectType() {
  MyAssert(have_object_type, "doesn't have object type");
  return object_type;
}
FuncType ValueType::GetFuncType() {
  MyAssert(have_func_type, "doesn't have function type");
  return func_type;
}