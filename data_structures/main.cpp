#include <iostream>
#include <vector>

#include "Stack.hpp"

int main() {
  std::vector<int> data{1, 2, 3, 4, 5};

  Stack<int> simp; 

  for(int i = 0; i < 10; i++){
    simp.push(i); 
  }
  std::cout << simp << std::endl; 
  std::cout << simp.get_size() << std::endl; 

  return 0;
}
