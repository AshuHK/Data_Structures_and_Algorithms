#include <iostream>
#include <string>
#include <vector>

#include "Queue.hpp"
#include "Stack.hpp"

int main() {

  Queue<int> queue; 

  for(int i = 0; i < 10; i++) {
    queue.enqueue(i); 
    std::cout << queue << std::endl; 
  }

  std::cout << std::endl; 

  Stack<int> stack; 
  for(int i = 0; i < 10; i++) {
    stack.push(i); 
    std::cout << stack << std::endl; 
  }

  for(int i = 0; i < 8; i++) {
    stack.pop(); 
    std::cout << stack << std::endl; 
  }

  stack.pop(); 
  std::cout << stack << std::endl; 

  stack.pop(); 
  std::cout << stack << std::endl; 


  // std::cout << queue.get_size() << std::endl; 

  // std::cout << queue << std::endl; 

  // Stack<int> stack;
  

  return 0;
}
