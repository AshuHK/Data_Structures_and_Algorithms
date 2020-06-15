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

void test_linked_node() {
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

void test_linked_list() {
  std::vector<LinkedNode<std::string, int>> data;
  data.push_back(LinkedNode<std::string, int>("Mom", -1111));
  data.push_back(LinkedNode<std::string, int>("Dad", 5555));
  data.push_back(LinkedNode<std::string, int>("Ashu", 5423));
  data.push_back(LinkedNode<std::string, int>("Dev", 9875));

  LinkedList<std::string, int> list(data);
  std::cout << list << std::endl << std::endl;

  list.update("Ashu", 2222);
  // comment this block
  // std::cout << list.remove_back() << std::endl;
  // std::cout << list.remove_back() << std::endl;
  // std::cout << list.remove_back() << std::endl;
  // std::cout << list.remove_back() << std::endl;

  // or this block
  // std::cout << list.remove_front() << std::endl;
  // std::cout << list.remove_front() << std::endl;
  // std::cout << list.remove_front() << std::endl;
  // std::cout << list.remove_front() << std::endl;

  // should print a blank node here cuz there's nothing left to remove
  // std::cout << list.remove_back() << std::endl;
  // std::cout << list.remove_front() << std::endl;

  std::cout << list << std::endl;

  LinkedNode<std::string, int>* head = list.get_head();
  if (head == nullptr) {
    std::cout << std::endl << "nullptr. Can't be dereferenced" << std::endl;
  } else {
    std::cout << std::endl << *head << std::endl;
  }
  std::cout << list.get_size() << std::endl;
}

void test_hash_table() {
  
}

int main() {
  // test_queue();
  // test_stack();
  // test_linked_node();
  // test_linked_list();

  // TODO work on hash tables
  test_hash_table();

  return 0;
}
