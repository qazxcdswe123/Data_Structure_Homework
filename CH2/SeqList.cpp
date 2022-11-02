//
// Created by yn on 14/9/2022.
//

#include "SeqList.h"
#include <iostream>

template<class T>
SeqList<T>::SeqList(int size) {
    if (size < 0) {
        std::cerr << "The size of the list must be positive." << std::endl;
        exit(1);
    }
    element = new(std::nothrow) T[size];
    if (element == nullptr) {
        std::cerr << "Memory allocation error." << std::endl;
        exit(1);
    }
    maxSize = size;
    lastPosition = -1;
}

template<class T>
SeqList<T>::~SeqList() {
    delete[] element;
}

// copy constructor
template<class T>
SeqList<T>::SeqList(const SeqList<T> &L) {
    maxSize = L.maxSize;
    lastPosition = L.lastPosition;
    element = new(std::nothrow) T[maxSize];
    if (element == nullptr) {
        std::cerr << "Memory allocation error." << std::endl;
        exit(1);
    }
    for (int i = 0; i <= lastPosition; ++i) {
        element[i] = L.element[i];
    }
}

template<class T>
int SeqList<T>::getTotalSize() const {
    return maxSize;
}

template<class T>
int SeqList<T>::getCurrentLength() const {
    return lastPosition + 1;
}

template<class T>
void SeqList<T>::resize(const int newSize) {
    if (newSize < 0) {
        std::cerr << "The size of the list must be positive." << std::endl;
        exit(1);
    }
    T *newElement = new(std::nothrow) T[newSize];
    if (newElement == nullptr) {
        std::cerr << "Memory allocation error." << std::endl;
        exit(1);
    }
    int n = (newSize < maxSize) ? newSize : maxSize;
    for (int i = 0; i < n; i++) {
        newElement[i] = element[i];
    }
    delete[] element;
    element = newElement;
    maxSize = newSize;
}

template<class T>
int SeqList<T>::search(const T &x) const {
    for (int i = 0; i <= lastPosition; ++i) {
        if (element[i] == x) {
            return i + 1;
        }
    }
    return -1;
}

template<class T>
T *SeqList<T>::getDataPointer(int i) const {
    return (i > 0 && i <= lastPosition) ? &element[i - 1] : nullptr;
}

template<class T>
bool SeqList<T>::setData(int i, T &x) {
    if (i < 1 || i > lastPosition) {
        return false;
    }
    element[i - 1] = x;
    return true;
}

// i start from 1
template<class T>
bool SeqList<T>::insert(int i, T &x) {
    if (i < 1 || i > lastPosition + 2) {
        return false;
    }
    if (lastPosition == maxSize - 1) {
        resize(maxSize + 1);
    }
    if (i == lastPosition + 2) {
        element[lastPosition + 1] = x;
    } else {
        for (int j = lastPosition; j >= i - 1; --j) {
            element[j + 1] = element[j];
        }
        element[i - 1] = x;
    }
    lastPosition++;
    return true;
}

template<class T>
bool SeqList<T>::remove(int i, T &x) {
    if (i < 1 || i > lastPosition + 1) {
        return false;
    }
    x = element[i - 1];
    for (int j = i; j <= lastPosition; ++j) {
        element[j - 1] = element[j];
    }
    lastPosition--;
    return true;
}

template<class T>
bool SeqList<T>::isEmpty() const {
    return lastPosition == -1;
}

template<class T>
bool SeqList<T>::isFull() const {
    return lastPosition == maxSize - 1;
}

template<class T>
void SeqList<T>::print() const {
    for (int i = 0; i <= lastPosition; ++i) {
        std::cout << "#" << i + 1 << ": " << element[i] << std::endl;
    }
    std::cout << std::endl;
}

template<class T>
void SeqList<T>::sort() {
    for (int i = 0; i < lastPosition; ++i) {
        for (int j = i + 1; j <= lastPosition; ++j) {
            if (element[i] > element[j]) {
                T temp = element[i];
                element[i] = element[j];
                element[j] = temp;
            }
        }
    }
}

template<class T>
SeqList<T> &SeqList<T>::operator=(const SeqList<T> &L) {
if (this != &L) {
        delete[] element;
        maxSize = L.maxSize;
        lastPosition = L.lastPosition;
        element = new(std::nothrow) T[maxSize];
        if (element == nullptr) {
            std::cerr << "Memory allocation error." << std::endl;
            exit(1);
        }
        for (int i = 0; i <= lastPosition; ++i) {
            element[i] = L.element[i];
        }
    }
    return *this;
}

template<class T>
void SeqList<T>::removeDuplicate() {
    for (int i = 0; i < lastPosition; ++i) {
        for (int j = i + 1; j <= lastPosition; ++j) {
            if (element[i] == element[j]) {
                for (int k = j; k <= lastPosition; ++k) {
                    element[k - 1] = element[k];
                }
                lastPosition--;
                j--;
            }
        }
    }
}