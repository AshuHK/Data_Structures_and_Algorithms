#include <iostream>
#include <vector>

#ifndef QUEUE_HPP
#define QUEUE_HPP

// create a forward declaration of the class and operator<<
template <typename Type>
class Queue;

template <typename Type>
std::ostream& operator<<(std::ostream& output, const Queue<Type>& queue);

template <typename Type>
class Queue {
 private:
  std::vector<Type> data;
  size_t size;
  unsigned int capacity;

 public:
  // constructors
  Queue();
  Queue(unsigned int capacity);

  // setter and getters
  size_t get_size();
  Type get_front();
  Type get_back();

  // main queue operations
  void enqueue(Type item);
  Type dequeue();

  bool is_empty();
  bool is_full();

  // overloading operators
  friend std::ostream& operator<<<>(std::ostream& output,
                                    const Queue<Type>& queue);
};

template <typename Type>
Queue<Type>::Queue() {
  this->capacity = 10;
  this->size = 0;
}

template <typename Type>
Queue<Type>::Queue(unsigned int capacity) {
  this->capacity = capacity;
  this->size = 0;
}

template <typename Type>
size_t Queue<Type>::get_size() {
  return size;
}

template <typename Type>
Type Queue<Type>::get_front() {
  if (!is_empty()) {
    return data[0];
  } else {
    std::cout << "ERROR: Queue is empty" << std::endl;
    exit(EXIT_FAILURE);
  }
}

template <typename Type>
Type Queue<Type>::get_back() {
  if (!is_empty()) {
    return data[size - 1];
  } else {
    std::cout << "ERROR: Queue is empty" << std::endl;
    exit(EXIT_FAILURE);
  }
}

template <typename Type>
void Queue<Type>::enqueue(Type item) {
  if (!is_full()) {
    data.push_back(item);
    size++;
  } else {
    std::cout << "ERROR: Queue is full" << std::endl;
    exit(EXIT_FAILURE);
  }
}

template <typename Type>
Type Queue<Type>::dequeue() {
  if (!is_empty()) {
    Type old = data[size - 1];
    data.erase(data.begin());
    size--;
    return old;
  } else {
    std::cout << "ERROR: Queue is empty" << std::endl;
    exit(EXIT_FAILURE);
  }
}

template <typename Type>
bool Queue<Type>::is_empty() {
  return size == 0;
}

template <typename Type>
bool Queue<Type>::is_full() {
  return size == capacity;
}

template <typename Type>
std::ostream& operator<<(std::ostream& output, const Queue<Type>& queue) {
  output << "Queue: ";

  for (Type item : queue.data) {
    output << item << " ";
  }

  return output;
}

#endif
