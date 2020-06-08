#include <iostream> 
#include <vector> 

template <typename Type>
class Queue
{
private:
  std::vector<Type> data; 
  size_t size; 
  unsigned int capacity; 

public:
  Queue();
  Queue(int capacity); 
};
