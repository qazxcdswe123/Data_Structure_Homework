//
// Created by yn on 26/9/2022.
//

#ifndef CH3_SEQSTACK_H
#define CH3_SEQSTACK_H

#include "Stack.h"
#include <iostream>

template<class T>
class SeqStack : public Stack<T> {
private:
    T *dataArray;
    int top;
    int maxSize;

    void doubleSpace();

public:
    explicit SeqStack(int initSize = 10);

    ~SeqStack();

    void push(T x) final;

    T pop() final;

    T getTop() const final;

    bool isEmpty() const final;

    bool isFull() const final;

    int getSize() const final;

    void makeStackEmpty();

    friend std::ostream &operator<<(std::ostream &os, const SeqStack<T> &stack);
};


#endif //CH3_SEQSTACK_H
