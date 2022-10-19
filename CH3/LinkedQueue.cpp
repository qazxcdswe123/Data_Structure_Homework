//
// Created by yn on 17/10/2022.
//

#include "LinkedQueue.h"

template<class T>
void LinkedQueue<T>::makeEmpty() {
    LinkedListNode<T> *p = front;
    while (p != nullptr) {
        LinkedListNode<T> *q = p;
        p = p->next;
        delete q;
    }
    front = nullptr;
    rear = nullptr;
}

template<class T>
LinkedQueue<T>::~LinkedQueue() {
    makeEmpty();
}

template<class T>
LinkedQueue<T>::LinkedQueue() {
    front = nullptr;
    rear = nullptr;
}

template<class T>
bool LinkedQueue<T>::enqueue(const T value) {
    auto *p = new LinkedListNode<T>;
    p->data = value;
    p->next = nullptr;
    if (front == nullptr) {
        front = p;
        rear = p;
    } else {
        rear->next = p;
        rear = p;
    }
    return true;
}

template<class T>
T LinkedQueue<T>::dequeue() {
    if (front == nullptr) {
        throw "Queue is empty";
    }
    LinkedListNode<T> *p = front;
    front = front->next;
    T value = p->data;
    delete p;
    return value;
}

template<class T>
T LinkedQueue<T>::getFront() const {
    if (front == nullptr) {
        throw "Queue is empty";
    }
    return front->data;
}

template<class T>
bool LinkedQueue<T>::isEmpty() const {
    return front == nullptr;
}

template<class T>
int LinkedQueue<T>::getSize() const {
    int length = 0;
    LinkedListNode<T> *p = front;
    while (p != nullptr) {
        length++;
        p = p->next;
    }
    return length;
}

template<class T>
std::ostream &operator<<(std::ostream &os, const LinkedQueue<T> &queue) {
    LinkedListNode<T> *p = queue.front;
    while (p != nullptr) {
        os << p->data << " ";
        p = p->next;
    }
    return os;
}