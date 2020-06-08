#include <iostream>
#include <vector>

#ifndef QUEUE_HPP
#define QUEUE_HPP

// create a forward declaration of the class and operator<<
template <typename Type>
class Queue;

template <typename Type>
std::ostream& operator<<(std::ostream& output, const Queue<Type>& queue);

// complete definition of an array based stack
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

/**
 * Default constructor for the queue
 *  Sets the capacity to a default value of 10
 */
template <typename Type>
Queue<Type>::Queue() {
  this->capacity = 10;
  this->size = 0;
}

/**
 * Constructor that takes in a value for the capacity of the queue
 * @param capacity - max capacity of the queue
 */
template <typename Type>
Queue<Type>::Queue(unsigned int capacity) {
  this->capacity = capacity;
  this->size = 0;
}

/**
 * Returns the number of elements in the queue
 * @return - the number of elements in the queue
 */
template <typename Type>
size_t Queue<Type>::get_size() {
  return size;
}

/**
 * Returns the front of the queue
 * @return - the front element in the queue
 */
template <typename Type>
Type Queue<Type>::get_front() {
  if (!is_empty()) {
    return data[0];
  } else {
    std::cout << "ERROR: Queue is empty" << std::endl;
    exit(EXIT_FAILURE);
  }
}

/**
 * Returns the back element in the queue
 * @return - the back element in the queue
 */
template <typename Type>
Type Queue<Type>::get_back() {
  if (!is_empty()) {
    return data[size - 1];
  } else {
    std::cout << "ERROR: Queue is empty" << std::endl;
    exit(EXIT_FAILURE);
  }
}

/**
 * Places an element into the queue
 * @param item - the new item to be pushed onto the queue
 */
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

/**
 * Removes and returns the back element in the queue
 * @return - the removed element in the queue
 */
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

/**
 * Returns if the queue is empty
 * @return - boolean if the queue is empty
 */
template <typename Type>
bool Queue<Type>::is_empty() {
  return size == 0;
}

/**
 * Return if the queue is full
 * @return - boolean if the queue is full
 */
template <typename Type>
bool Queue<Type>::is_full() {
  return size == capacity;
}

/**
 * Overloaded the << operator for output streams
 * @param output - reference to the output stream
 * @param queue - constant reference to a queue to put into the stream
 *
 * @return output - using the referenced output stream
 */
template <typename Type>
std::ostream& operator<<(std::ostream& output, const Queue<Type>& queue) {
  output << "Queue: ";

  for (Type item : queue.data) {
    output << item << " ";
  }

  return output;
}

#endif
