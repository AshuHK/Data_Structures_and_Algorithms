#include <iostream>
#include <vector>

#include "Stack.hpp"

int main() {
  Stack<int> simp;

  for (int i = 0; i < 10; i++) {
    simp.push(i);
  }

  simp.cout_stack();

  std::cout << std::endl << simp.pop() << std::endl;
  std::cout << simp.pop() << std::endl;
  std::cout << simp.pop() << std::endl << std::endl; 
  simp.cout_stack();

  std::cout << std::endl << simp.get_size() << std::endl;
  std::cout << simp.get_top() << std::endl; 

  return 0;
}
