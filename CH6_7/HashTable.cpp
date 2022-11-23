//
// Created by yn on 23/11/2022.
//

#include "HashTable.h"

#include <iostream>

template<class T>
HashTable<T>::HashTable(int capacity) {
    this->capacity = capacity;
    size = 0;
    table = new T[capacity];
}

template<class T>
HashTable<T>::~HashTable() {
    delete[] table;
}

template<class T>
std::uint64_t HashTable<T>::hash(T data) const {
    std::uint64_t hash = 0;
    for (int i = 0; i < data.length(); i++) {
        // awful hash function
        hash += data[i];
    }
    return hash % capacity;
}

template<class T>
bool HashTable<T>::insert(T data) {
    if (size == capacity) {
        return false;
    }

    int index = hash(data);
    while (table[index] != "") {
        index = (index + 1) % capacity;
    }
    table[index] = data;
    size++;
    return true;
}

template<class T>
bool HashTable<T>::remove(T data) {
    int index = hash(data);
    while (table[index] != data) {
        index = (index + 1) % capacity;
        if (table[index] == "" || index == hash(data)) {
            return false;
        }
    }
    table[index] = "";
    size--;
    return true;
}

template<class T>
bool HashTable<T>::search(T data) const {
    int index = hash(data);
    while (table[index] != data) {
        index = (index + 1) % capacity;
        if (table[index] == "" || index == hash(data)) {
            return false;
        }
    }
    return true;
}

template<class T>
void HashTable<T>::print() const {
    for (int i = 0; i < capacity; i++) {
        std::cout << table[i] << " ";
    }
    std::cout << std::endl;
}