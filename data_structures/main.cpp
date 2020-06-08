#include <iostream>
#include <vector>

#include "Stack.hpp"

int main() {
  Stack<int> simp(10);

  for (int i = 0; i < 10; i++) {
    simp.push(i);
  }
  std::cout << simp << std::endl; 
  std::cout << simp.get_size() << std::endl; 
  std::cout << simp.get_top() << std::endl; 

  for(int i = 10; i >= 0; --i) {
    simp.pop(); 
  }

  std::cout << simp << std::endl;
  std::cout << simp.get_size() << std::endl; 
  std::cout << simp.get_top() << std::endl; 
  return 0;
}
