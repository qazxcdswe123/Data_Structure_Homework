//
// Created by yn on 19/9/2022.
//

#include "LinkedList.h"

template<class T>
LinkedList<T>::~LinkedList() {
    LinkedListNode<T> *p = first;
    while (p != nullptr) {
        LinkedListNode<T> *q = p;
        p = p->next;
        delete q;
    }
}

template<class T>
LinkedList<T> LinkedList<T>::newNode() {
    auto *p = new LinkedListNode<T>;
    p->next = nullptr;
    return p;
}

template<class T>
bool LinkedList<T>::insert(int position, T &value) {
    if (position < 0 || position > currentLength) {
        return false;
    }
    LinkedListNode<T> *p = first;
    for (int i = 0; i < position - 1; ++i) {
        p = p->next;
    }
    LinkedListNode<T> *q = newNode();
    q->data = value;
    q->next = p->next;
    p->next = q;
    ++currentLength;
    return true;
}

template<class T>
bool LinkedList<T>::remove(int position) {
    if (position < 0 || position > currentLength) {
        return false;
    }
    LinkedListNode<T> *p = first;
    for (int i = 0; i < position - 1; ++i) {
        p = p->next;
    }
    LinkedListNode<T> *q = p->next;
    p->next = q->next;
    delete q;
    --currentLength;
    return true;
}

template<class T>
int LinkedList<T>::getCurrentLength() const {
    return currentLength;
}

template<class T>
int LinkedList<T>::search(const T &x) const {
    LinkedListNode<T> *p = first;
    int i = 0;
    while (p != nullptr) {
        if (p->data == x) {
            return i;
        }
        p = p->next;
        ++i;
    }
    return -1;
}

template<class T>
T LinkedList<T>::getData(int position) const {
    LinkedListNode<T> *p = first;
    for (int i = 0; i < position; ++i) {
        p = p->next;
    }
    return p->data;
}