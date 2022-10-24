//
// Created by yn on 24/10/2022.
//

#include "PriorityQueue.h"

template<class T>
void PriorityQueue<T>::heapify(int i) {
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    int largest = i;
    if (l < length && dataArray[l] > dataArray[i]) {
        largest = l;
    }
    if (r < length && dataArray[r] > dataArray[largest]) {
        largest = r;
    }
    if (largest != i) {
        std::swap(dataArray[i], dataArray[largest]);
        heapify(largest);
    }
}

template<class T>
void PriorityQueue<T>::buildMaxHeap() {
    for (int i = length / 2 - 1; i >= 0; i--) {
        heapify(i);
    }
}

template<class T>
PriorityQueue<T>::PriorityQueue(int size) {
    maxSize = size;
    dataArray = new T[maxSize];
    length = 0;
}

template<class T>
PriorityQueue<T>::~PriorityQueue() {
    delete[] dataArray;
}

template<class T>
bool PriorityQueue<T>::enqueue(T x) {
    if (isFull()) {
        return false;
    }
    dataArray[length] = x;
    length++;
    buildMaxHeap();
    return true;
}

template<class T>
T PriorityQueue<T>::dequeue() {
    if (isEmpty()) {
        throw "Queue is empty";
    }
    T result = dataArray[0];
    dataArray[0] = dataArray[length - 1];
    length--;
    heapify(0);
    return result;
}

template<class T>
T PriorityQueue<T>::getFront() const {
    if (isEmpty()) {
        throw "Queue is empty";
    }
    return dataArray[0];
}

template<class T>
void PriorityQueue<T>::makeEmpty() {
    length = 0;
}

template<class T>
bool PriorityQueue<T>::isEmpty() const {
    return length == 0;
}

template<class T>
bool PriorityQueue<T>::isFull() const {
    return length == maxSize;
}

template<class T>
int PriorityQueue<T>::getSize() const {
    return length;
}

template<class T>
std::ostream &operator<<(std::ostream &os, const PriorityQueue<T> &queue) {
    for (int i = 0; i < queue.length; i++) {
        os << queue.dataArray[i] << " ";
    }
    return os;
}