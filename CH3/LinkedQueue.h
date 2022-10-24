//
// Created by yn on 17/10/2022.
//

#ifndef CH3_LINKEDQUEUE_H
#define CH3_LINKEDQUEUE_H

#include "../CH2/SinglyLinkedList.h"
#include "Queue.h"

#include <iostream>

template<class T>
class LinkedQueue: public Queue<T> {
private:
    friend class LinkedQueue<T>;
    LinkedListNode<T> *front = nullptr;
    LinkedListNode<T> *rear = nullptr;

public:
    LinkedQueue();
    ~LinkedQueue();

    bool enqueue(const T value);
    T dequeue();
    T getFront() const;
    bool isEmpty() const;
    void makeEmpty();
    int getSize() const;
    friend std::ostream &operator<<(std::ostream &os, const LinkedQueue<T> &queue);
};

#endif //CH3_LINKEDQUEUE_H
