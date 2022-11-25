#pragma once
#include <any>
#include <memory>
using namespace std;

template <class T> T AnyCast(any obj) { return any_cast<T>(obj); }

template <class T> bool AnyIs(any obj) { return obj.type() == typeid(T); }

template <class T> shared_ptr<T> AnyCastPtr(any obj) {
  if (!AnyIs<shared_ptr<T>>(obj))
    return nullptr;
  return AnyCast<shared_ptr<T>>(obj);
}