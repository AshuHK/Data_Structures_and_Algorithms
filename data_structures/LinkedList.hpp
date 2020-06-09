#include <iostream>
#include <vector>

#ifndef LINKEDLIST_HPP
#define LINKEDLIST_HPP

// forward declaraction of the linked list node and output operator
template <typename Type1, typename Type2>
struct LinkedNode;

template <typename Type1, typename Type2>
std::ostream& operator<<(std::ostream& output,
                         const LinkedNode<Type1, Type2>& node);

// complete definition for the linked list node
template <typename Type1, typename Type2>
struct LinkedNode {
  LinkedNode<Type1, Type2>* next = nullptr;
  Type1 key;
  Type2 value;

  // constructor and destructors
  LinkedNode() = default;
  LinkedNode(Type1 key, Type2 value);

  // overloaded operators
  bool operator==(const LinkedNode<Type1, Type2>& node);
  friend std::ostream& operator<<<>(std::ostream& output,
                                    const LinkedNode& node);
};

/**
 * Constructor that takes in a key and value pair for the LinkedNode
 * @param key - key for the node
 * @param value - value for the node
 */
template <typename Type1, typename Type2>
LinkedNode<Type1, Type2>::LinkedNode(Type1 key, Type2 value) {
  this->key = key;
  this->value = value;
}

/**
 * Overloaded the output stream operator by placing node into output stream
 * @param output - a reference to an output stream
 * @param node - a constant reference to a node to be placed into the stream
 *
 * @return - the reference output stream taken as a parameter
 */
template <typename Type1, typename Type2>
std::ostream& operator<<(std::ostream& output,
                         const LinkedNode<Type1, Type2>& node) {
  output << "(" << node.key << " : " << node.value << ")";
  return output;
}

/**
 * Overloaded the equivelance operator by comparing the key and value
 * @param node - a constant reference to a node to be compared to
 *
 * @return - boolean if the nodes are equal
 */
template <typename Type1, typename Type2>
bool LinkedNode<Type1, Type2>::operator==(
    const LinkedNode<Type1, Type2>& node) {
  if ((key == node.key) && (value == node.value)) {
    return true;
  } else {
    return false;
  }
}

// TODO: Finish this class
// forward declaration of the linked list and output stream operator
template <typename Type1, typename Type2>
class LinkedList;

template <typename Type1, typename Type2>
std::ostream& operator<<(std::ostream& output,
                         const LinkedList<Type1, Type2>& list);

template <typename Type1, typename Type2>
class LinkedList {
 private:
  LinkedNode<Type1, Type2>* head = nullptr;
  size_t size = 0;

 public:
  // constructors
  LinkedList() = default;
  LinkedList(std::vector<LinkedNode<Type1, Type2>> nodes);

  // setters and getters
  size_t get_size();
  LinkedNode<Type1, Type2>* get_head();

  // Linked List operations
  void add_back(Type1 key, Type2 value);
  void add_front(Type1 key, Type2 value);

  LinkedNode<Type1, Type2>& search(Type1 key);

  LinkedNode<Type1, Type2> remove_front();
  LinkedNode<Type1, Type2> remove_back();

  void update_value(Type1 key);

  // overloaded operations
  friend std::ostream& operator<<<>(std::ostream& output,
                                    const LinkedList<Type1, Type2>& list);
};

/**
 * Constructor that takes a vector of nodes and converts it into a linked list
 * @param nodes - a vector of nodes to be added to the linked list
 */
template <typename Type1, typename Type2>
LinkedList<Type1, Type2>::LinkedList(
    std::vector<LinkedNode<Type1, Type2>> nodes) {
  for (const LinkedNode<Type1, Type2>& node : nodes) {
    add_back(node.key, node.value);
  }
}

/**
 * Returns the number of elements in the linked list
 * @param None
 *
 * @return - number of elements in the linked list
 */
template <typename Type1, typename Type2>
size_t LinkedList<Type1, Type2>::get_size() {
  return size;
}

/**
 * Returns a pointer to the head of the linked list
 * @param None
 *
 * @return - pointer to the head of the linked list
 */
template <typename Type1, typename Type2>
LinkedNode<Type1, Type2>* LinkedList<Type1, Type2>::get_head() {
  return head;
}

#endif
