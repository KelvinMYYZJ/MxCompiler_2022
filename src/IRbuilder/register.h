#pragma once
#include <bits/stdc++.h>
using namespace std;
namespace IR {
struct Register {
  int label;
  Register();
  virtual void useless_func() {}
};
struct GlobalRegister : public Register {
  string global_label;
};
} // namespace IR