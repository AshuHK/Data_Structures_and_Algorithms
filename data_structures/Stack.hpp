#include <iostream>
#include <vector>

#ifndef STACK_HPP
#define STACK_HPP

// create a forward declaration of the class and operator<<
template <typename Type>
class Stack;

template <typename Type>
std::ostream& operator<<(std::ostream& output, const Stack<Type>& stack);

// complete definition of an array based stack
template <typename Type>
class Stack {
 private:
  std::vector<Type> data;
  size_t size;
  unsigned int capacity;

 public:
  // constructors
  Stack();
  Stack(unsigned int capacity);

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

/**
 * Default constructor for the stack
 *  Sets the capacity to a default value of 10
 *
 * @param None
 */
template <typename Type>
Stack<Type>::Stack() {
  this->capacity = 10;
  this->size = 0;
}

/**
 * Constuctor that takes a value for the capacity of the stack
 * @param capacity - max capacity of the stack
 */
template <typename Type>
Stack<Type>::Stack(unsigned int capacity) {
  this->capacity = capacity;
  this->size = 0;
}

/**
 * Returns the number of elements in the stack
 * @param None
 *
 * @return - number of elements in the stack
 */
template <typename Type>
size_t Stack<Type>::get_size() {
  return size;
}

/**
 * Pushes an element onto the stack
 * @param item - new item to put onto the stack
 *
 * @return - None
 */
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

/**
 * Removes and returns the top element from the stack
 * @param None
 *
 * @return - the removed element from the stack
 */
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

/**
 * Returns the top element from the stack
 * @param None
 *
 * @return - the top element in the stack
 */
template <typename Type>
Type Stack<Type>::get_top() {
  if (!is_empty()) {
    return data[size - 1];
  } else {
    std::cout << "ERROR: Stack is empty" << std::endl;
    exit(EXIT_FAILURE);
  }
}

/**
 * Returns if the stack is empty
 * @param None
 *
 * @return - boolean if the stack is empty
 */
template <typename Type>
bool Stack<Type>::is_empty() {
  return size == 0;
}

/**
 * Returns if the stack is full
 * @param None
 *
 * @return - boolean if the stack is full
 */
template <typename Type>
bool Stack<Type>::is_full() {
  return size == capacity;
}

/**
 * Overloaded the << operator for output streams
 * @param output - reference to the output stream
 * @param stack - constant reference to a stack to put in the stream
 *
 * @return output - using the referenced output stream
 */
template <typename Type>
std::ostream& operator<<(std::ostream& output, const Stack<Type>& stack) {
  output << "Stack: ";

  for (const Type& item : stack.data) {
    output << item << " ";
  }

  return output;
}

#endif
