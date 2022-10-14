#pragma once
#include "my_exception.h"

MyException::MyException() : MyException("Unknown error") {}
MyException::MyException(const char* ctx) : _ctx(ctx) {}
const char* MyException::What() const { return _ctx; }
MyException::~MyException() = default;