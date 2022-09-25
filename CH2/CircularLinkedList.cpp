//
// Created by yn on 22/9/2022.
//

#include "CircularLinkedList.h"
#include <iostream>

template<class T>
CircularLinkedList<T>::~CircularLinkedList() {
    LinkedListNode<T> *p = head;
    for (int i = 0; i < currentLength; ++i) {
        LinkedListNode<T> *q = p;
        p = p->next;
        delete q;
    }
}

template<class T>
bool CircularLinkedList<T>::insertAfterPosition(int position, T value) {
    if (position < 0 || position > currentLength) {
        return false;
    }
    LinkedListNode<T> *p = head;
    if (head == nullptr || position == 0) {
        head = new LinkedListNode<T>;
        head->data = value;
        head->next = p;
        head->prev = p;
    } else {
        for (int i = 0; i < position - 1; ++i) {
            p = p->next;
        }
        auto *q = new LinkedListNode<T>;
        q->data = value;
        q->next = p->next;
        q->prev = p;
        p->next->prev = q;
        p->next = q;
    }
    currentLength++;
    return true;
}

template<class T>
bool CircularLinkedList<T>::remove(int position) {
    if (position < 0 || position > currentLength) {
        return false;
    }
    if (position == 0) {
        LinkedListNode<T> *p = head;
        head = head->next;
        head->prev = p->prev;
        p->prev->next = head;
        delete p;
    } else {
        LinkedListNode<T> *p = head;
        for (int i = 0; i < position - 1; ++i) {
            p = p->next;
        }
        LinkedListNode<T> *q = p->next;
        p->next = q->next;
        q->next->prev = p;
        delete q;
    }
    currentLength--;

    return true;
}

template<class T>
void CircularLinkedList<T>::print() const {
    LinkedListNode<T> *p = head;
    for (int i = 0; i < currentLength; ++i) {
        std::cout << "#" << i << ": " << p->data << std::endl;
        p = p->next;
    }
}


template<class T>
bool CircularLinkedList<T>::isEmpty() const {
    return currentLength == 0;
}

template<class T>
int CircularLinkedList<T>::getCurrentLength() const {
    return currentLength;
}

template<class T>
int CircularLinkedList<T>::search(const T valueToSearch) const {
    LinkedListNode<T> *p = head;
    for (int i = 0; i < currentLength; ++i) {
        if (p->data == valueToSearch) {
            return i;
        }
        p = p->next;
    }
    return -1;
}

template<class T>
T CircularLinkedList<T>::getDataAtPosition(int position) const {
    if (position < 0 || position > currentLength) {
        return T();
    }
    LinkedListNode<T> *p = head;
    for (int i = 0; i < position; ++i) {
        p = p->next;
    }
    return p->data;
}
