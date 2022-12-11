#include "gscope.h"

#include "my_exception.h"
using namespace std;

GScope::GScope()
    : Scope(shared_ptr<Scope>(), false),
      funcs(make_shared<linked_hashmap<string, FuncType>>()),
      classes(make_shared<linked_hashmap<string, ClassInfo>>()) {
  (*funcs)["print"] = {{"void"}, list<ObjectType>{{"string"}}};
  (*funcs)["println"] = {{"void"}, list<ObjectType>{{"string"}}};
  (*funcs)["printInt"] = {{"void"}, list<ObjectType>{{"int"}}};
  (*funcs)["printlnInt"] = {{"void"}, list<ObjectType>{{"int"}}};
  (*funcs)["getString"] = {{"string"}, list<ObjectType>{}};
  (*funcs)["getInt"] = {{"int"}, list<ObjectType>{}};
  (*funcs)["toString"] = {{"string"}, list<ObjectType>{{"int"}}};
}

ValueType GScope::GetIdentifierType(const string &identifier) const {
  ValueType ret = Scope::GetIdentifierType(identifier);
  if (funcs->count(identifier)) {
    ret.AddFuncType((*funcs)[identifier]);
  }
  return ret;
}
ValueType GScope::GetClassMember(const string &class_identifier, const string &member_identifier) const {
  ValueType ret;
  if (class_identifier == "string") {
    if (member_identifier == "length") {
      ret.AddFuncType({kIntType});
    } else if (member_identifier == "substring") {
      ret.AddFuncType({kStringType, {kIntType, kIntType}});
    } else if (member_identifier == "parseInt") {
      ret.AddFuncType({kIntType});
    } else if (member_identifier == "ord") {
      ret.AddFuncType({kIntType, {kIntType}});
    } else
      throw MyException("wrong member in string : \"" + member_identifier + "\"");
    return ret;
  }
  if (classes->count(class_identifier)) {
    const auto &class_info = (*classes)[class_identifier];
    if (class_info.member_funcs->count(member_identifier)) {
      ret.AddFuncType((*class_info.member_funcs)[member_identifier]);
    }
    if (class_info.member_vars->count(member_identifier)) {
      ret.AddObjectType((*class_info.member_vars)[member_identifier], true);
    }
    // MyAssert(ret.have_func_type || ret.have_object_type,
    //          "Undefined member : \"" + member_identifier + "\"");
    return ret;
  } else
    throw MyException("Undefined class : \"" + class_identifier + "\"");
}
void GScope::CheckIdentifier(const string &identifier) const {
  if (classes->count(identifier)) throw MyException("identifier \"" + identifier + "\" used as a class identifier.");
}
void GScope::CheckClass(const string &class_identifier) const {
  if (class_identifier == "int" || class_identifier == "string" || class_identifier == "bool" ||
      class_identifier == "void")
    return;
  MyAssert(classes->count(class_identifier), "undefined type \"" + class_identifier + "\"");
}

void GScope::AddFunc(const string &identifier, FuncType func_type) {
  MyAssert(!classes->count(identifier), "Func use a class identifier : \"" + identifier + "\"");
  if (funcs->count(identifier)) {
    throw MyException("redefiniation of function :\"" + identifier + "\"");
  }
  (*funcs)[identifier] = func_type;
  if (identifier == "main") {
    if (func_type.ret_type != ObjectType("int", 0) || func_type.arg_type.size())
      throw MyException("wrong main function definition");
  }
}

void GScope::AddBlankClass(const string &identifier) {
  if (classes->count(identifier)) {
    throw MyException("redefiniation of class :\"" + identifier + "\"");
  }
  (*classes)[identifier] = ClassInfo();
}
