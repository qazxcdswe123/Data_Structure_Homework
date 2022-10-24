//
// Created by yn on 24/10/2022.
//

#ifndef CH3_PRIORITYQUEUE_H
#define CH3_PRIORITYQUEUE_H

#include "Queue.h"
#include <iostream>

// Priority Queue using heap data structure
template<class T>
class PriorityQueue : public Queue<T> {
private:
    void heapify(int i);

    void buildMaxHeap();

    T *dataArray;
    int length;
    int maxSize;

public:
    explicit PriorityQueue(int size = 10);
    ~PriorityQueue();
    bool enqueue(T x) final;
    T dequeue() final;
    T getFront() const final;
    void makeEmpty();
    bool isEmpty() const final;
    bool isFull() const;
    int getSize() const final;
    friend std::ostream &operator<<(std::ostream &os, const PriorityQueue<T> &queue);
};

#endif //CH3_PRIORITYQUEUE_H