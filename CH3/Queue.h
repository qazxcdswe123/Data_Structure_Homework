//
// Created by yn on 17/10/2022.
//

#ifndef CH3_QUEUE_H
#define CH3_QUEUE_H


template<class T>
class Queue {
public:
    virtual bool enQueue(T x) = 0;
    virtual T deQueue() = 0;
    virtual T getHead() const = 0;
    virtual bool isEmpty() const = 0;
    virtual bool isFull() const = 0;
    virtual int getSize() const = 0;
};


#endif //CH3_QUEUE_H
