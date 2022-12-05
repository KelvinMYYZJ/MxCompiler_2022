#pragma once
#include <exception>
#include <string>
class MyException : std::exception {
 private:
  const std::string _ctx;

 public:
  MyException();
  MyException(const char* ctx);
  MyException(const std::string& ctx);
  ~MyException();
  const char* What() const;
};

void MyAssert(bool condition, const MyException& exception);