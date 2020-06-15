#include <iostream>
#include <vector>

#ifndef HASHTABLE_HPP
#define HASHTABLE_HPP

template <typename Type1, typename Type2>
class HashNode {
 public:
  HashNode(const Type1& key, const Type2& value);

 private:
  Type1 key;
  Type2 value;
  HashNode* next = nullptr;

  // setters and getters
  Type1 get_key();
  Type2 get_value();
  void set_value(Type2 value);
  HashNode* get_next();
  void set_next(HashNode<Type1, Type2>* next);
};

/**
 * Constructor taking in a key and value
 */
template <typename Type1, typename Type2>
HashNode<Type1, Type2>::HashNode<Type1, Type2>(const Type1& key,
                                               const Type2& value) {
  this->key = key;
  this->value = value;
}

template <typename Type1, typename Type2> 
Type1 HashNode<Type1, Type2>::get_key() {
  return key; 
}

template <typename Type1, typename Type2> 
Type2 HashNode<Type1, Type2>::get_value() {
  return value; 
}




#endif
