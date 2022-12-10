#pragma once
#include <list>
#include <string>

#include "MxParser.h"
using namespace std;

struct ObjectType {
 public:
  ObjectType();
  string type_identifier;
  int dim;
  ObjectType(const string &_type_identifier, const int &_dim = 0);
  ObjectType(MxParser::TypeNameContext *ctx);
  bool operator==(const ObjectType &rhs) const;
  bool operator!=(const ObjectType &rhs) const;
  bool IsBasicType() const;
};

const ObjectType kIntType = {{"int"}};
const ObjectType kStringType = {{"string"}};
const ObjectType kBoolType = {{"bool"}};
const ObjectType kNullType = {{"null"}};
const ObjectType kVoidType = {{"void"}};

struct FuncType {
 public:
  ObjectType ret_type;
  list<ObjectType> arg_type;
  ObjectType AcceptArgList(const list<ObjectType> &args);
};

struct RetType {
  // have_ret = false : no return stmt
  // have_ret = trie && type == {"void"} : only stmt : return;(no expr)
 public:
  ObjectType type;
  bool have_ret;
  RetType();
  RetType(MxParser::TypeNameContext *ctx);
  bool operator==(const RetType &rhs) const;
  bool operator!=(const RetType &rhs) const;
  void AddRet(ObjectType ret_type);
  void AddRet(RetType obj);
  bool IsVoid() const;
};

struct Arg {
 public:
  Arg();
  ObjectType type;
  string arg_identifier;
  Arg(const ObjectType &_type, const string &_arg_identifier);
};

struct Member {
 public:
  Member();
  string member_identifier;
  Member(const string &_member_identifier);
};

struct This {};
struct Null {};