//
// Created by yn on 26/9/2022.
//

#include "LinkedStack.h"

template<typename T>
LinkedStack<T>::LinkedStack() {
    top = nullptr;
}

template<typename T>
void LinkedStack<T>::makeEmpty() {
    LinkedListNode<T> *p;
    while (top != nullptr) {
        p = top;
        top = top->next;
        delete p;
    }
}

template<typename T>
LinkedStack<T>::~LinkedStack() {
    makeEmpty();
}

template<typename T>
bool LinkedStack<T>::push(T value) {
    LinkedListNode<T> *p = new LinkedListNode<T>;
    p->data = value;
    p->next = top;
    top = p;
    return true;
}

template<typename T>
bool LinkedStack<T>::pop() {
    if (top == nullptr) {
        return false;
    }
    LinkedListNode<T> *p = top;
    top = top->next;
    delete p;
    return true;
}

template<typename T>
T LinkedStack<T>::getTop() const {
    if (top == nullptr) {
        return T();
    }
    return top->data;
}

template<typename T>
bool LinkedStack<T>::isEmpty() const {
    return top == nullptr;
}

template<typename T>
int LinkedStack<T>::getSize() const {
    int count = 0;
    LinkedListNode<T> *p = top;
    while (p != nullptr) {
        count++;
        p = p->next;
    }
    return count;
}

template<typename T>
std::ostream &operator<<(std::ostream &os, const LinkedStack<T> &stack) {
    LinkedListNode<T> *p = stack.top;
    while (p != nullptr) {
        os << p->data << " ";
        p = p->next;
    }
    return os;
}