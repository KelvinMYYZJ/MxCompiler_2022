#include "my_exception.h"

MyException::MyException() : MyException("Unknown error") {}
MyException::MyException(const char* ctx) : _ctx(ctx) {}
MyException::MyException(const std::string& ctx) : _ctx(ctx) {}
const char* MyException::What() const { return _ctx.c_str(); }
MyException::~MyException() = default;
void MyAssert(bool condition, const MyException& exception) {
  if (!condition) throw exception;
}
