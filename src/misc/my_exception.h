#pragma once
#include <bits/stdc++.h>
class MyException : std::exception {
 private:
  const char* _ctx;

 public:
  MyException();
  MyException(const char* ctx);
  ~MyException();
  const char* What() const;
};