#include <iostream>
#include <string>
#include <vector>

#include "Queue.hpp"
#include "Stack.hpp"

int main() {
  Queue<int> queue(10);

  for (int i = 0; i < 10; i++) {
    std::cout << queue << std::endl;
    queue.enqueue(i);
  }

  std::cout << queue << std::endl;

  for (int i = 0; i < 10; i++) {
    queue.dequeue();
    std::cout << queue << std::endl;
  }

  std::cout << std::endl;

  Stack<int> stack(10);

  for (int i = 0; i < 10; i++) {
    std::cout << stack << std::endl;
    stack.push(i);
  }

  std::cout << stack << std::endl;

  for (int i = 0; i < 10; i++) {
    stack.pop();
    std::cout << stack << std::endl;
  }

  return 0;
}
