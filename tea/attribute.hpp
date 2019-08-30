#pragma once

#include <iostream>
#include <list>
#include <mutex>
#include <functional>

namespace tea
{

template<typename T>
class Attribute
{
private:
  std::mutex mtx;
  T value;
  std::list<std::function<void(const T& value)>> callbacks;

public:
  Attribute<T>& operator= (const T& value) { 
    std::lock_guard<std::mutex> lock(mtx);
    this->value = value; 
    for (auto &f : callbacks) {
      f(value);
    }
    return *this;
  }

  void observe(std::function<void(const T& value)> function) {
    this->callbacks.push_back(function);
  }

  void unobserve(std::function<void(const T& value)> function) {
    this->callbacks.erase(function);
  }
};

} // namespace tea
