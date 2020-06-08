#include <iostream>
#include <vector>

#ifndef STACK_HPP
#define STACK_HPP

// create a forward declaration of the class and operator<<
template <typename Type>
class Stack;

template <typename Type>
std::ostream& operator<<(std::ostream& output, const Stack<Type>& stack);

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
  Type get_top();

  // stack operations
  void push(Type item);
  Type pop();

  // overloading operators
  friend std::ostream& operator<< <> (std::ostream& output,
                                    const Stack<Type>& stack);
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
Type Stack<Type>::pop() {
  Type old = data[size - 1];
  data.pop_back();
  size--;
  return old;
}

template <typename Type>
Type Stack<Type>::get_top() {
  return data[size - 1];
}

template <typename Type> 
std::ostream& operator<<(std::ostream& output, const Stack<Type>& stack) {
  output << "Stack: ["; 
  for(int i = stack.size - 1; i >= 0; --i) {
    // output << stack.data[i] << std::endl; 
    if (i != 0){
      output << stack.data[i] << ", "; 
    } else {
      output << stack.data[i] << "] "; 
    }
  }

  return output; 
}

#endif
