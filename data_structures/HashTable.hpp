#include <iostream>
#include <vector>

#ifndef HASHTABLE_HPP
#define HASHTABLE_HPP

template <typename Type1, typename Type2>
class HashNode {
 public:
  // basic constructor with key and value pair
  HashNode(Type1 key, Type2 value);

  // setters and getters
  Type1 get_key();
  Type2 get_value();
  void set_value(Type2 value);
  HashNode* get_next();
  void set_next(HashNode<Type1, Type2>* next);

 private:
  Type1 key;
  Type2 value;
  HashNode* next = nullptr;
};

/**
 * Constructor taking in a key and value
 * @param key - a key to set the node to
 * @param value - a value to set the node to
 */
template <typename Type1, typename Type2>
HashNode<Type1, Type2>::HashNode<Type1, Type2>(Type1 key, Type2 value) {
  this->key = key;
  this->value = value;
}

/**
 * Returns the key of the node
 * @param None
 *
 * @return - the key of the node
 */
template <typename Type1, typename Type2>
Type1 HashNode<Type1, Type2>::get_key() {
  return key;
}

/**
 * Returns the value of the node
 * @param None
 *
 * @return - the value of the node
 */
template <typename Type1, typename Type2>
Type2 HashNode<Type1, Type2>::get_value() {
  return value;
}

/**
 * Sets the value of the node to a new value
 * @param value - the new value to set the node to
 *
 * @return - None
 */
template <typename Type1, typename Type2>
void HashNode<Type1, Type2>::set_value(Type2 value) {
  this->value = value;
}

/**
 * Returns the next node in the hash table
 * @param None
 *
 * @return - a pointer to the next node in the hash table
 */
template <typename Type1, typename Type2>
HashNode<Type1, Type2>* HashNode<Type1, Type2>::get_next() {
  return next;
}

/**
 * Sets next node in the hashtable to a new node
 * @param next - a pointer to a hash node
 *
 * @return - None
 */
template <typename Type1, typename Type2>
void HashNode<Type1, Type2>::set_next(HashNode<Type1, Type2>* next) {
  this->next = next;
}

template <typename Type1, size_t table_size>
struct KeyHash {
  unsigned long operator()(const Type1& key) const {
    return reinterpret_cast<unsigned long>(key) % table_size;
  }
};

template <typename Type1, typename Type2, size_t table_size,
          typename Type3 = KeyHash<Type1, table_size>>
class HashTable {
 public:
  HashTable() : table(), hash_function() {}

  ~HashTable() {
    for (size_t i = 0; i < table_size; ++i) {
      HashNode<Type1, Type2>* entry = table[i];

      while (entry != nullptr) {
        HashNode<Type1, Type2>* prev = entry;
        entry = entry->get_next();
        delete prev;
      }

      table[i] = nullptr;
    }
  }

  bool get(Type1 key, Type2 value) {
    unsigned long hash_value = hash_function(key);
    HashNode<Type1, Type2>* entry = table[hash_value];

    while (entry != nullptr) {
      if (entry->get_key() == key) {
        value = entry->get_value();
        return true;
      }
      entry = entry->get_next();
    }

    return false;
  }

  void put(Type1 key, Type2 value) {
    unsigned long hash_value = hash_function(key);
    HashNode<Type1, Type2>* prev = nullptr;
    HashNode<Type1, Type2>* entry = table[hash_value];

    while (entry != nullptr && entry->get_key() != key) {
      prev = entry;
      entry = entry->get_next();
    }

    if (entry == nullptr) {
      entry = new HashNode<Type1, Type2>(key, value);

      if (prev == nullptr) {
        table[hash_value] = entry;
      } else {
        prev->set_next(entry);
      }
    } else {
      entry->set_value(value);
    }
  }

  void remove(Type1 key) {
    unsigned long hash_value = hash_function(key);
    HashNode<Type1, Type2>* prev = nullptr;
    HashNode<Type1, Type2>* entry = table[hash_value];
  }

 private:
};

#endif