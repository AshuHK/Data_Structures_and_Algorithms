#include <iostream>
#include <string>
#include <vector>

#include "Queue.hpp"
#include "Stack.hpp"

int main() {

  Queue<int> queue; 

  std::cout << queue.get_size() << std::endl; 

  for(int i = 0; i < 10; i++) {
    queue.enqueue(i); 
  }

  std::cout << queue.get_size() << std::endl; 

  std::cout << queue << std::endl; 

  return 0;
}
