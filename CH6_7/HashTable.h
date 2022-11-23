//
// Created by yn on 23/11/2022.
//

#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <cstdint>

// hash table implementation using linear probing
template<class T>
class HashTable {
private:
    int size;
    int capacity;
    T *table;

    std::uint64_t hash(T data) const;

public:
    explicit HashTable(int capacity);

    ~HashTable();

    bool insert(T data);

    bool remove(T data);

    bool search(T data) const;

    void print() const;
};


#endif //HASHTABLE_H
