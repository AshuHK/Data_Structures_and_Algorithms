#include <iostream>
#include <ostream>
#include <vector>

#ifndef STACK_HPP
#define STACK_HPP

template <typename Type>
class Stack {
 private:
  std::vector<Type> data;
  size_t size = 0;

 public:
  // constructors and destructors
  Stack() = default;
  ~Stack();

  // setters and getters
  size_t get_size();

  // stack operations
  void push(Type item);
  Type pop();
  Type peek_top();

  void cout_stack(); 

  // operation overloads
  // TODO: FIX THIS 
  // friend std::ostream& operator<<(std::ostream& output, Stack<Type>& stack);
};

template <typename Type>
Stack<Type>::~Stack() {
  std::cout << "The stack has been destroyed" << std::endl;
}

template <typename Type>
size_t Stack<Type>::get_size() {
  return size;
}

template <typename Type>
void Stack<Type>::push(Type item) {
  data.push_back(item);
  size++;
}

template <typename Type>
Type Stack<Type>::pop() {}

template <typename Type>
Type Stack<Type>::peek_top() {}

// TODO: FIX THIS 
// template <typename Type>
// std::ostream& operator<<(std::ostream& output, Stack<Type>& stack) {
//   for (int i = stack.data.size() - 1; i >= 0; --i) {
//     output << stack.data[i] << std::endl;
//   }
//   return output;
// }


template <typename Type> 
void Stack<Type>::cout_stack(){
  for(int i = size - 1; i >= 0; --i){
    std::cout << data[i] << std::endl; 
  }
}


#endif
