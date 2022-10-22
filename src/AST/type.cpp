#pragma once
#include "type.h"

#include <bits/stdc++.h>
using namespace std;

Type::Type(const std::string& _type_identifier, const int& _dim) : type_identifier(_type_identifier), dim(_dim) {}

Arg::Arg(const Type& _type, const string& _arg_identifier) : type(_type), arg_identifier(_arg_identifier) {}

Member::Member(const string& _member_identifier) : member_identifier(_member_identifier) {}