#pragma once
#include <any>
#include <memory>
using namespace std;

template <class T>
T AnyCast(any obj) {
  if (obj.type() == typeid(T)) {
    return any_cast<T>(obj);
  }
  return T();
}

template <class T>
bool AnyIs(any obj) {
  return obj.type() == typeid(T);
}

template <class T>
shared_ptr<T> AnyCastPtr(any obj) {
  return AnyCast<shared_ptr<T>>(obj);
}