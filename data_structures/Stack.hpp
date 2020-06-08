#include <vector>
#ifndef STACK_HPP
#define STACK_HPP

template <typename Type> 
class Stack {
 private:
  std::vector<Type> data;
  int size = 0;

 public:
  Stack();
  ~Stack();
};

// Stack::Stack() {}
// Stack::~Stack() {}

#endif
