//
// Created by yn on 24/10/2022.
//

#include "DoubleEndedQueue.h"
template <class T>
DoubleEndedQueue<T>::DoubleEndedQueue(int size) {
    maxSize = size;
    dataArray = new T[maxSize];
    front = -1;
    rear = -1;
}

template <class T>
DoubleEndedQueue<T>::~DoubleEndedQueue() {
    delete [] dataArray;
}

template <class T>
bool DoubleEndedQueue<T>::isEmpty() const {
    return front == -1 && rear == -1;
}

template <class T>
bool DoubleEndedQueue<T>::isFull() const {
    return (front == 0 && rear == maxSize - 1) || (front == rear + 1);
}

template <class T>
void DoubleEndedQueue<T>::enQueueFront(T data) {
    if (isFull()) {
        throw "Queue is full";
    }
    if (isEmpty()) {
        front = rear = 0;
    } else if (front == 0) {
        front = maxSize - 1;
    } else {
        front--;
    }
    dataArray[front] = data;
}

template <class T>
void DoubleEndedQueue<T>::enQueueRear(T data) {
    if (isFull()) {
        throw "Queue is full";
    }
    if (isEmpty()) {
        front = rear = 0;
    } else if (rear == maxSize - 1) {
        rear = 0;
    } else {
        rear++;
    }
    dataArray[rear] = data;
}

template <class T>
T DoubleEndedQueue<T>::deQueueFront() {
    if (isEmpty()) {
        throw "Queue is empty";
    }
    T data = dataArray[front];
    if (front == rear) {
        front = rear = -1;
    } else if (front == maxSize - 1) {
        front = 0;
    } else {
        front++;
    }
    return data;
}

template <class T>
T DoubleEndedQueue<T>::deQueueRear() {
    if (isEmpty()) {
        throw "Queue is empty";
    }
    T data = dataArray[rear];
    if (front == rear) {
        front = rear = -1;
    } else if (rear == 0) {
        rear = maxSize - 1;
    } else {
        rear--;
    }
    return data;
}

template <class T>
void DoubleEndedQueue<T>::makeEmpty() {
    front = rear = -1;
}