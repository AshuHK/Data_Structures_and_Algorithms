#include <iostream>
#include <vector>

#ifndef HASHTABLE_HPP
#define HASHTABLE_HPP

template <typename Type1, typename Type2>
class HashNode {
 public:
  // basic constructor with key and value pair
  HashNode(Type1 _key, Type2 _value) {
    key = _key;
    value = _value;
  }

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

// basic hash function as a struct to generate indicies
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
  // default constructor
  HashTable() : table(), hash_function() {}

  /**
   * Destructor that goes through each pointer and delete each of them
   */
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

  /**
   * Gets the value for the specific key
   * @param key - key to find the matching value for
   *
   * @return - the value for the matching key
   */
  Type2 get(Type1 key) {
    unsigned long hash_value = hash_function(key);
    HashNode<Type1, Type2>* entry = table[hash_value];

    while (entry != nullptr) {
      if (entry->get_key() == key) {
        return entry->get_value();
      }
      entry = entry->get_next();
    }

    return NULL;
  }

  /**
   * Puts a new key-value pair into the hash table
   * @param key - key for the new node in the hash table
   * @param value - value for the new node in the hash table
   *
   * @return - None
   */
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

  /**
   * Removes the node with a specific key value
   * @param key - key of the node to be removed
   *
   * @return - None
   */
  void remove(Type1 key) {
    unsigned long hash_value = hash_function(key);
    HashNode<Type1, Type2>* prev = nullptr;
    HashNode<Type1, Type2>* entry = table[hash_value];

    while (entry != nullptr && entry->get_key() != key) {
      prev = entry;
      entry = entry->get_next();
    }

    if (entry == nullptr) {
      // key not found
      return;
    } else {
      if (prev == nullptr) {
        table[hash_value] = entry->get_next();
      } else {
        prev->set_next(entry->get_next());
      }

      delete entry;
    }
  }

  /**
   * Outputs all of the key-value pairs in the hash table
   * @param None
   *
   * @return - None
   */
  void output() {
    for (size_t i = 0; i < table_size; ++i) {
      HashNode<Type1, Type2>* entry = table[i];

      while (entry != nullptr) {
        std::cout << entry->get_key() << " : " << entry->get_value()
                  << std::endl;
        entry = entry->get_next();
      }
    }
  }

 private:
  HashNode<Type1, Type2>* table[table_size];
  Type3 hash_function;
};

#endif
