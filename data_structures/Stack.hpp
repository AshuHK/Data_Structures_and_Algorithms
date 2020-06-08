#include <iostream>
#include <vector>

#ifndef STACK_HPP
#define STACK_HPP

// create a forward declaration of the class and operator<<
template <typename Type>
class Stack;

template <typename Type>
std::ostream& operator<<(std::ostream& output, const Stack<Type>& stack);

// complete definition
template <typename Type>
class Stack {
 private:
  std::vector<Type> data;
  size_t size = 0;
  int capacity = 10;

 public:
  // constructors and destructors
  Stack() = default;
  Stack(int capacity);
  ~Stack();

  // setters and getters
  size_t get_size();
  Type get_top();

  // stack operations
  void push(Type item);
  Type pop();
  bool is_empty();
  bool is_full();

  // overloading operators
  friend std::ostream& operator<<<>(std::ostream& output,
                                    const Stack<Type>& stack);
};

template <typename Type>
Stack<Type>::Stack(int capacity) {
  this->capacity = capacity;
}

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
  if (!is_full()) {
    data.push_back(item);
    size++;
  } else {
    std::cout << "ERROR: Stack is full" << std::endl;
    exit(EXIT_FAILURE);
  }
}

template <typename Type>
Type Stack<Type>::pop() {
  if (!is_empty()) {
    Type old = data[size - 1];
    data.pop_back();
    size--;
    return old;
  } else {
    std::cout << "ERROR: Stack is empty" << std::endl;
    exit(EXIT_FAILURE);
  }
}

template <typename Type>
Type Stack<Type>::get_top() {
  if(!is_empty()) {
    return data[size - 1];
  } else {
    std::cout << "ERROR: Stack is empty" << std::endl; 
    exit(EXIT_FAILURE); 
  }
}

template <typename Type>
bool Stack<Type>::is_empty() {
  return size == 0;
}

template <typename Type>
bool Stack<Type>::is_full() {
  return size == capacity;
}

template <typename Type>
std::ostream& operator<<(std::ostream& output, const Stack<Type>& stack) {
  output << "Stack: [";
  for (int i = stack.size - 1; i >= 0; --i) {
    if (i != 0) {
      output << stack.data[i] << ", ";
    } else {
      output << stack.data[i] << "] ";
    }
  }

  return output;
}

#endif
