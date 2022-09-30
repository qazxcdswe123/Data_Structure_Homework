//
// Created by yn on 25/9/2022.
//

#ifndef DS_NEW_STACK_H
#define DS_NEW_STACK_H

const int MAX_SIZE = 100;

template<class T>
class Stack {
public:
    virtual void push(T x) = 0;

    virtual T pop() = 0;

    virtual T getTop() const = 0;

    virtual bool isEmpty() const = 0;

    virtual bool isFull() const = 0;

    virtual int getSize() const = 0;
};


#endif //DS_NEW_STACK_H
