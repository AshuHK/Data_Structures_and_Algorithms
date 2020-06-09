#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

#include "LinkedList.hpp"
#include "Queue.hpp"
#include "Stack.hpp"

void test_queue() {
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
}

void test_stack() {
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
}

void test_linkednode() {
  LinkedNode<std::string, int> node1;
  node1.key = "Ashu";
  node1.value = 5555;

  LinkedNode<std::string, int> node2;
  node2.key = "Ashu";
  node2.value = 5555;

  LinkedNode<double, char> node3;
  node3.key = 1.555;
  node3.value = 'C';

  LinkedNode<double, char> node4(1.555, 'C');

  std::cout << std::boolalpha << (node1 == node2) << std::endl;
  std::cout << std::boolalpha << (node3 == node4) << std::endl;

  std::cout << node1 << std::endl;
  std::cout << node1.key << " " << node1.value << std::endl;
}

int main() {
  // test_queue();
  // test_stack();
  // test_linkednode();

  LinkedList<std::string, int> list;

  // std::cout << list.get_size() << std::endl; 
  // std::cout << list.get_head() << std::endl; 

  return 0;
}
