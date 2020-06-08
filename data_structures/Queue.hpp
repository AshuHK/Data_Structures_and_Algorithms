#include <iostream>
#include <vector>

#ifndef QUEUE_HPP 
#define QUEUE_HPP

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
  Queue(int capacity);

  // setter and gettesr
  size_t get_size();
  Type get_front();
  Type get_back();

  // main queue operations 
  void enqueue(Type item);
  Type dequeue(Type item);

  bool is_empty();
  bool is_full();
};

#endif
