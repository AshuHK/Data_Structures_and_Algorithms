#include <iostream>
#include <vector>

#ifndef STACK_HPP
#define STACK_HPP

template <typename Type>
class Stack {
 private:
  std::vector<Type> data;
  size_t size = 0;

 public:
  Stack() = default;
  ~Stack() { std::cout << "The stack has been destroyed" << std::endl; }

  size_t get_size() { return size; }

  void push(Type item) {
    data.push_back(item);
    size++;
  }

  Type pop() {
    Type old = data[size - 1];
    data.pop_back();
    size--;
    return old;
  }
};

#endif
