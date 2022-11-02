//
// Created by yn on 19/9/2022.
//

#include "SinglyLinkedList.h"
#include <iostream>

template<class T>
SinglyLinkedList<T>::~SinglyLinkedList() {
    LinkedListNode<T> *p = head;
    while (p != nullptr) {
        LinkedListNode<T> *q = p;
        p = p->next;
        delete q;
    }
}


template<class T>
bool SinglyLinkedList<T>::insertAfterPosition(int position, T value) {
    if (position < 0 || position > currentLength) {
        return false;
    }
    LinkedListNode<T> *p = head;
    if (head == nullptr || position == 0) {
        head = new LinkedListNode<T>;
        head->data = value;
        head->next = p;
    } else {
        for (int i = 0; i < position - 1; ++i) {
            p = p->next;
        }
        auto *q = new LinkedListNode<T>;
        q->data = value;
        q->next = p->next;
        p->next = q;
    }
    currentLength++;
    return true;
}

template<class T>
bool SinglyLinkedList<T>::remove(int position) {
    if (position < 0 || position > currentLength) {
        return false;
    }
    if (position == 0) {
        LinkedListNode<T> *p = head;
        head = head->next;
        delete p;
    } else {
        LinkedListNode<T> *p = head;
        for (int i = 0; i < position - 1; ++i) {
            p = p->next;
        }
        LinkedListNode<T> *q = p->next;
        p->next = q->next;
        delete q;
    }
    currentLength--;
    return true;
}

template<class T>
int SinglyLinkedList<T>::getCurrentLength() const {
    return currentLength;
}

template<class T>
int SinglyLinkedList<T>::search(const T x) const {
    LinkedListNode<T> *p = head;
    int i = 0;
    while (p != nullptr) {
        if (p->data == x) {
            return i;
        }
        p = p->next;
        ++i;
    }
    return -1; // not found
}

template<class T>
T SinglyLinkedList<T>::getDataAtPosition(int position) const {
    LinkedListNode<T> *p = head;
    for (int i = 0; i < position; ++i) {
        p = p->next;
    }
    return p->data;
}

template<class T>
void SinglyLinkedList<T>::sort() {
    // bubble sort
    LinkedListNode<T> *p = head;
    for (int i = 0; i < currentLength - 1; ++i) {
        LinkedListNode<T> *q = p->next;
        for (int j = i + 1; j < currentLength; ++j) {
            if (q->data < p->data) {
                T temp = p->data;
                p->data = q->data;
                q->data = temp;
            }
            q = q->next;
        }
        p = p->next;
    }
}

template<class T>
void SinglyLinkedList<T>::print() {
    LinkedListNode<T> *p = head;
    while (p != nullptr) {
        std::cout << p->data << " ";
        p = p->next;
    }
    std::cout << std::endl;
}

template<class T>
void SinglyLinkedList<T>::removeDuplicates() {
    LinkedListNode<T> *p = head;
    while (p != nullptr) {
        LinkedListNode<T> *q = p;
        while (q->next != nullptr) {
            if (q->next->data == p->data) {
                LinkedListNode<T> *r = q->next;
                q->next = r->next;
                delete r;
            } else {
                q = q->next;
            }
        }
        p = p->next;
    }
}