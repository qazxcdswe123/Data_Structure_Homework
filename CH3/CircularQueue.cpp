//
// Created by yn on 17/10/2022.
//

#include "CircularQueue.h"

template<class T>
CircularQueue<T>::CircularQueue(int size) {
    maxSize = size;
    dataArray = new T[maxSize];
    length = front = rear = 0;
}

template<class T>
CircularQueue<T>::~CircularQueue() {
    delete[] dataArray;
}

template<class T>
bool CircularQueue<T>::enQueue(T x) {
if (isFull()) {
        return false;
    }
    dataArray[rear] = x;
    rear = (rear + 1) % maxSize;
    length++;
    return true;
}

template<class T>
T CircularQueue<T>::deQueue() {
    if (isEmpty()) {
        throw "Queue is empty";
    }
    T temp = dataArray[front];
    front = (front + 1) % maxSize;
    length--;
    return temp;
}

template<class T>
T CircularQueue<T>::getHead() const {
    if (isEmpty()) {
        throw "Queue is empty";
    }
    return dataArray[front];
}

template<class T>
void CircularQueue<T>::makeEmpty() {
    front = rear = length = 0;
}

template<class T>
bool CircularQueue<T>::isEmpty() const {
    return length == 0;
}

template<class T>
bool CircularQueue<T>::isFull() const {
    return length == maxSize;
}

template<class T>
int CircularQueue<T>::getSize() const {
    return length;
}

template<class T>
std::ostream &operator<<(std::ostream &os, const CircularQueue<T> &queue) {
    for (int i = queue.front; i < queue.rear; i++) {
        os << queue.dataArray[i] << " ";
    }
    return os;
}

