//
// Created by yn on 17/10/2022.
//

#ifndef CH3_QUEUE_H
#define CH3_QUEUE_H


template<class T>
class Queue {
public:
    virtual bool enqueue(T x) = 0;
    virtual T dequeue() = 0;
    virtual T getFront() const = 0;
    virtual bool isEmpty() const = 0;
//    virtual bool isFull() const = 0;
//    LinkedQueue doesn't have this method
    virtual int getSize() const = 0;
};


#endif //CH3_QUEUE_H
