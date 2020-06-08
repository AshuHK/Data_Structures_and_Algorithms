#include <vector>
#ifndef STACK_HPP
#define STACK_HPP

template <typename Type> 
class Stack {
 private:
  std::vector<Type> data;
  size_t size = 0;

 public:
  Stack();
  ~Stack();

  std::vector<Type> get_data(); 
  void push(Type item); 
};

// Stack::Stack() {}
// Stack::~Stack() {}

template <typename Type>
void Stack::push(Type item) {
  data.push_back(item); 
}

#endif
