//
// Created by yn on 26/9/2022.
//

#ifndef CH3_LINKEDSTACK_H
#define CH3_LINKEDSTACK_H

#include "../CH2/SinglyLinkedList.h"
#include "Stack.h"

#include <iostream>

template <typename T>
class LinkedStack: public Stack<T> {
private:
    LinkedListNode<T> *top = nullptr;

public:
    LinkedStack();
    ~LinkedStack();

    bool push(T value) final;
    bool pop() final;
    T getTop() const final;
    bool isEmpty() const final;
    int getSize() const final;
    friend std::ostream &operator<<(std::ostream &os, const LinkedStack<T> &stack);
    void makeEmpty();
};


#endif //CH3_LINKEDSTACK_H
