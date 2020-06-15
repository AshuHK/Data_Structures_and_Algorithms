#include <iostream>
#include <vector>

#ifndef HASHTABLE_HPP
#define HASHTABLE_HPP

template <typename Type1, typename Type2>
class HashNode {
 public:
  HashNode(const Type1 & key, const Type2 & value);
 private:
  Type1 key;
  Type2 value;
  HashNode* next = nullptr;
};

/**
 * Constructor taking in a key and value 
 */
template <typename Type1, typename Type2> 
HashNode<Type1, Type2>::HashNode<Type1, Type2>(const Type1 & key, const Type2 & value) {
  this->key = key; 
  this->value = value; 
}

#endif
