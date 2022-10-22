#pragma once
#include <bits/stdc++.h>
using namespace std;

struct Type {
 public:
  string type_identifier;
  int dim;
  Type(const string& _type_identifier, const int& _dim = 0);
};

struct Arg {
 public:
  Type type;
  string arg_identifier;
  Arg(const Type& _type, const string& _arg_identifier);
};

struct Member {
 public:
  string member_identifier;
  Member(const string& _member_identifier);
};