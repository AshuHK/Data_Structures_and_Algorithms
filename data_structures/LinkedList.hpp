#include <iostream>
#include <vector> 

#ifndef LINKEDLIST_HPP
#define LINKEDLIST_HPP

// forward declaraction of the linked list node and output stream function
template <typename Type1, typename Type2>
struct LinkedNode;

template <typename Type1, typename Type2>
std::ostream& operator<<(std::ostream& output,
                         const LinkedNode<Type1, Type2>& node);

// complete definition for the linked list node 
template <typename Type1, typename Type2>
struct LinkedNode {
  LinkedNode* next = nullptr;

  Type1 key;
  Type2 value;

  LinkedNode() = default;
  LinkedNode(Type1 key, Type2 value);

  bool operator==(const LinkedNode<Type1, Type2>& node);
  friend std::ostream& operator<<<>(std::ostream& output,
                                    const LinkedNode& node);
};

template <typename Type1, typename Type2>
LinkedNode<Type1, Type2>::LinkedNode(Type1 key, Type2 value) {
  this->key = key;
  this->value = value;
}

template <typename Type1, typename Type2>
std::ostream& operator<<(std::ostream& output,
                         const LinkedNode<Type1, Type2>& node) {
  output << "(" << node.key << " : " << node.value << ")";
  return output;
}

template <typename Type1, typename Type2>
bool LinkedNode<Type1, Type2>::operator==(
    const LinkedNode<Type1, Type2>& node) {
  if ((key == node.key) && (value == node.value)) {
    return true;
  } else {
    return false;
  }
}

template <typename Type1, typename Type2> 
class LinkedList {
  private: 
    LinkedNode* head = nullptr; 
    size_t size = 0; 

  public: 
    // constructors 
    LinkedList() = default; 
    LinkedList(std::vector<LinkedNode<Type1, Type2> nodes);  

    // setters and getters 
    size_t get_size(); 
    LinkedNode<Type1, Type2> * get_head(); 

    // Linked List operations
    void add_back(Type1 key, Type2 value); 
    void add_front(Type1 key, Type2 value); 

    LinkedNode<Type1, Type2> & search(Type1 key); 

    LinkedNode<Type1, Type2> remove_front(); 
    LinkedNode<Type1, Type2> remove_back(); 
    
    void update_value(Type1 key); 

}; 


#endif
