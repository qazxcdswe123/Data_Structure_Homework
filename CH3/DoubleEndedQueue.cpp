//
// Created by yn on 24/10/2022.
//

#include "DoubleEndedQueue.h"
template <class T>
DoubleEndedQueue<T>::DoubleEndedQueue(int size) {
    maxSize = size;
    dataArray = new T[maxSize];
    front = 0;
    rear = 0;
}

template <class T>
DoubleEndedQueue<T>::~DoubleEndedQueue() {
    delete [] dataArray;
}

template <class T>
bool DoubleEndedQueue<T>::isEmpty() const {
    return front == rear;
}

template <class T>
bool DoubleEndedQueue<T>::isFull() const {
    return (rear + 1) % maxSize == front;
}

template <class T>
void DoubleEndedQueue<T>::enQueueFront(T data) {
    if (isFull()) {
        throw "Queue is full";
    }
    front = (front - 1 + maxSize) % maxSize;
    dataArray[front] = data;
}

template <class T>
void DoubleEndedQueue<T>::enQueueRear(T data) {
    if (isFull()) {
        throw "Queue is full";
    }
    dataArray[rear] = data;
    rear = (rear + 1) % maxSize;
}

template <class T>
T DoubleEndedQueue<T>::deQueueFront() {
    if (isEmpty()) {
        throw "Queue is empty";
    }
    T data = dataArray[front];
    front = (front + 1) % maxSize;
    return data;
}

template <class T>
T DoubleEndedQueue<T>::deQueueRear() {
    if (isEmpty()) {
        throw "Queue is empty";
    }
    rear = (rear - 1 + maxSize) % maxSize;
    return dataArray[rear];
}

template <class T>
void DoubleEndedQueue<T>::makeEmpty() {
    front = rear = 0;
}