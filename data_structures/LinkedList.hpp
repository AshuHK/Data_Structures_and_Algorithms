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

  LinkedNode<Type1, Type2>* search(Type1 key);

  LinkedNode<Type1, Type2> remove_back();
  LinkedNode<Type1, Type2> remove_front();

  void update(Type1 key, Type2 new_value);

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

/**
 * Adds a new node at the end of the linked list
 * @param key - sets the key for the new node
 * @param value - sets the value for the new node
 *
 * @return - None
 */
template <typename Type1, typename Type2>
void LinkedList<Type1, Type2>::add_back(Type1 key, Type2 value) {
  LinkedNode<Type1, Type2>* new_node = new LinkedNode(key, value);

  if (head == nullptr) {
    head = new_node;
    size++;
  } else {
    LinkedNode<Type1, Type2>* iterator = head;
    while (iterator->next != nullptr) {
      iterator = iterator->next;
    }
    iterator->next = new_node;
    size++;
  }
}

/**
 * Adds a new node at the front of the linked list
 * @param key - sets the key for the new node
 * @param value - sets the value for the new node
 *
 * @return - None
 */
template <typename Type1, typename Type2>
void LinkedList<Type1, Type2>::add_front(Type1 key, Type2 value) {
  LinkedNode<Type1, Type2>* new_node = new LinkedNode(key, value);

  if (head == nullptr) {
    head = new_node;
    size++;
  } else {
    new_node->next = head;
    head = new_node;
    size++;
  }
}

/**
 * Search for a node in the list with a specific key
 * @param key - key to be searched for in the linked list
 *
 * @return - pointer to the node within the linked list
 */
template <typename Type1, typename Type2>
LinkedNode<Type1, Type2>* LinkedList<Type1, Type2>::search(Type1 key) {
  for (LinkedNode<Type1, Type2>* iterator = head; iterator != nullptr;
       iterator = iterator->next) {
    if (iterator->key == key) {
      return iterator;
    }
  }
  return nullptr;
}

/**
 * Returns and removes the last node in the linked list
 * @param None
 *
 * @return - a copy of the removed node in the linked list
 */
template <typename Type1, typename Type2>
LinkedNode<Type1, Type2> LinkedList<Type1, Type2>::remove_back() {
  if (size != 0) {
    if (head->next == nullptr) {
      Type1 removed_key = head->key;
      Type2 removed_value = head->value;

      head = nullptr;
      delete head;
      size--;
      return LinkedNode<Type1, Type2>(removed_key, removed_value);
    }

    LinkedNode<Type1, Type2>* second_last = head;
    while (second_last->next->next != nullptr) {
      second_last = second_last->next;
    }

    Type1 removed_key = second_last->next->key;
    Type2 removed_value = second_last->next->value;

    second_last->next = nullptr;
    delete second_last->next;
    size--;

    return LinkedNode<Type1, Type2>(removed_key, removed_value);
  }
  return LinkedNode<Type1, Type2>();
}

/**
 * Returns and removes the first node in the linked list
 * @param None
 *
 * @return - a copy of the removed node in the linked list
 */
template <typename Type1, typename Type2>
LinkedNode<Type1, Type2> LinkedList<Type1, Type2>::remove_front() {
  if (size != 0) {
    LinkedNode<Type1, Type2>* old_node = head;

    Type1 removed_key = old_node->key;
    Type2 removed_value = old_node->value;

    head = head->next;
    delete old_node;
    size--;

    return LinkedNode<Type1, Type2>(removed_key, removed_value);
  }
  return LinkedNode<Type1, Type2>();
}

/**
 * Updates the value for a specific key in the linked list
 * @param key - key to be searched
 * @param new_value - the value that will replace the value for key
 *
 * @return - None
 */
template <typename Type1, typename Type2>
void LinkedList<Type1, Type2>::update(Type1 key, Type2 new_value) {
  LinkedNode<Type1, Type2>* iterator = head;
  while (iterator != nullptr) {
    if (iterator->key == key) {
      break;
    }
    iterator = iterator->next;
  }
  iterator->value = new_value;
}

/**
 * Overloads the << operator and puts the linked list into the output stream
 * @param output - a reference to an output stream
 * @param list - a constant reference to a linked list
 *
 * @return output - the referenced output stream
 */
template <typename Type1, typename Type2>
std::ostream& operator<<(std::ostream& output,
                         const LinkedList<Type1, Type2>& list) {
  output << "Linked List: ";

  for (LinkedNode<Type1, Type2>* iterator = list.head; iterator != nullptr;
       iterator = iterator->next) {
    if (iterator->next != nullptr) {
      output << (*iterator) << " -> ";
    } else {
      output << (*iterator);
    }
  }

  return output;
}

#endif
