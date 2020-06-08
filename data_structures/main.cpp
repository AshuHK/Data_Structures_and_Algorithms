#include <iostream>
#include <vector>

#include "Stack.hpp"

int main() {
  std::vector<int> data{1, 2, 3, 4, 5};

  Stack<int> simp; 
  simp.push(1); 
  simp.push(2); 
  std::cout << simp.get_size() << std::endl; 

  std::cout << simp.pop() << std::endl; 
  std::cout << simp.get_size() << std::endl; 

  return 0;
}
