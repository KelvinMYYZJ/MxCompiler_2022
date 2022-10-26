#pragma once
#include "type.h"

#include <bits/stdc++.h>

#include "my_exception.h"
using namespace std;

ObjectType::ObjectType() = default;
ObjectType::ObjectType(const std::string& _type_identifier, const int& _dim)
    : type_identifier(_type_identifier), dim(_dim) {}

ObjectType::ObjectType(MxParser::TypeNameContext* ctx)
    : type_identifier(ctx->basicType()->getText()), dim(ctx->LeftBracket().size()) {}

bool ObjectType::operator==(const ObjectType& rhs) const {
  return (type_identifier == "null" && rhs.IsBasicType()) || (rhs.type_identifier == "null" && IsBasicType()) ||
         type_identifier == rhs.type_identifier && dim == rhs.dim;
}
bool ObjectType::operator!=(const ObjectType& rhs) const { return !(*this == rhs); }

bool ObjectType::IsBasicType() const {
  return !dim && (type_identifier == "int" || type_identifier == "bool" || type_identifier == "string");
}

ObjectType FuncType::AcceptArgList(const list<ObjectType>& args) {
  if (args.size() != arg_type.size()) throw("wrong arg list : wrong arg num");
  auto iter = args.begin();
  for (auto def_type : arg_type) {
    Assert(def_type == *iter, "wrong arg type");
    ++iter;
  }
  return ret_type;
}

RetType::RetType() : have_ret(false) {}

RetType::RetType(MxParser::TypeNameContext* ctx) : have_ret(false) {
  if (!ctx->basicType()->Void()) {
    AddRet(ObjectType(ctx));
  }
}

void RetType::AddRet(ObjectType ret_type) {
  if (!have_ret) {
    have_ret = true;
    type = ret_type;
  } else if (ret_type != type)
    throw MyException("different ret type in same func");
}

void RetType::AddRet(RetType obj) {
  if (obj.have_ret) AddRet(obj.type);
}

bool RetType::operator==(const RetType& rhs) const {
  if (have_ret != rhs.have_ret) return false;
  if (!have_ret && rhs.have_ret) return true;
  return type == rhs.type;
}
bool RetType::operator!=(const RetType& rhs) const { return !(*this == rhs); }
Arg::Arg() = default;
Arg::Arg(const ObjectType& _type, const string& _arg_identifier) : type(_type), arg_identifier(_arg_identifier) {}

Member::Member() = default;
Member::Member(const string& _member_identifier) : member_identifier(_member_identifier) {}