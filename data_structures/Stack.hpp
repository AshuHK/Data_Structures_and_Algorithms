#include <iostream>
#include <vector>

#ifndef STACK_HPP
#define STACK_HPP

template <typename Type>
class Stack {
 private:
  std::vector<Type> data;
  size_t size;

 public:
  Stack() = default;
  ~Stack();
};

template <typename Type>
Stack<Type>::~Stack() {
  std::cout << "The stack has been destroyed" << std::endl;
}

#endif
