#include <iostream>
#include <vector>

#include "Stack.hpp"

int main() {
  Stack<int> simp;

  for (int i = 0; i < 10; i++) {
    simp.push(i);
  }
  
  simp.cout_stack();
  std::cout << std::endl << simp.get_size() << std::endl;

  return 0;
}
