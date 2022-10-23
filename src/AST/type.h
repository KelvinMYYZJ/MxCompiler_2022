#pragma once
#include <bits/stdc++.h>

#include "MxParser.h"
using namespace std;

struct Type {
 public:
  Type();
  string type_identifier;
  int dim;
  Type(const string& _type_identifier, const int& _dim = 0);
  Type(MxParser::TypeNameContext* ctx);
};

struct Arg {
 public:
  Arg();
  Type type;
  string arg_identifier;
  Arg(const Type& _type, const string& _arg_identifier);
};

struct Member {
 public:
  Member();
  string member_identifier;
  Member(const string& _member_identifier);
};

struct This {};