#include <iostream>
#include <string>
#include <vector>

#include "Queue.hpp"
#include "Stack.hpp"

int main() {

  Queue<int> queue; 

  std::cout << queue.get_size() << std::endl; 
  queue.enqueue(1); 
  queue.enqueue(2); 
  std::cout << queue.get_size() << std::endl; 

  return 0;
}
