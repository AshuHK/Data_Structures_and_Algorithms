#include <iostream>
#include <string>
#include <vector>

#include "Queue.hpp"
#include "Stack.hpp"

int main() {
  Queue<int> queue;

  std::cout << queue << std::endl;

  for (int i = 0; i < 10; i++) {
    queue.enqueue(i);
    std::cout << queue << std::endl;
  }

  Stack<int> stack;

  std::cout << stack << std::endl;

  for (int i = 0; i < 10; i++) {
    stack.push(i);
    std::cout << stack << std::endl;
  }

  for(int i = 0; i < 10; i++) {
    stack.pop(); 
    std::cout << stack << std::endl; 
  }

  return 0;
}
