//
// Created by yn on 17/10/2022.
//

#ifndef CH3_CIRCULARQUEUE_H
#define CH3_CIRCULARQUEUE_H

#include "Queue.h"

#include <iostream>

template<class T>
class CircularQueue : public Queue<T> {
private:
    T *dataArray;
    int front;
    int rear;
    unsigned int maxSize;
    unsigned int length;

public:
    explicit CircularQueue(int size = 10);
    ~CircularQueue();
    bool enqueue(T x) final;
    T dequeue() final;
    T getFront() const final;
    void makeEmpty();
    bool isEmpty() const final;
    bool isFull() const;
    int getSize() const final;
    friend std::ostream &operator<<(std::ostream &os, const CircularQueue<T> &queue);
};

#endif //CH3_CIRCULARQUEUE_H