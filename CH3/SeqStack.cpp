//
// Created by yn on 26/9/2022.
//

#include "SeqStack.h"

template<class T>
SeqStack<T>::~SeqStack() {
    delete[] dataArray;
}

template<class T>
bool SeqStack<T>::isEmpty() const {
    return top == -1;
}

template<class T>
bool SeqStack<T>::isFull() const {
    return top == maxSize - 1;
}

template<class T>
int SeqStack<T>::getSize() const {
    return top + 1;
}

template<class T>
void SeqStack<T>::makeStackEmpty() {
    top = -1;
}

template<class T>
SeqStack<T>::SeqStack(int initSize) {
    maxSize = initSize;
    dataArray = new T[maxSize];
    top = -1;
}

template<class T>
void SeqStack<T>::doubleSpace() {
    T *tmp = dataArray;
    maxSize *= 2;
    dataArray = new T[maxSize];
    for (int i = 0; i <= top; ++i) {
        dataArray[i] = tmp[i];
    }
    delete[] tmp;
}

template<class T>
void SeqStack<T>::push(T x) {
    if (isFull()) {
        doubleSpace();
    }
    dataArray[++top] = x;
}

template<class T>
T SeqStack<T>::pop() {
    if (isEmpty()) {
        throw "Stack is empty!";
    }
    return dataArray[top--];
}

template<class T>
T SeqStack<T>::getTop() const {
    if (isEmpty()) {
        throw "Stack is empty!";
    }
    return dataArray[top];
}

template<class T>
std::ostream &operator<<(std::ostream &os, const SeqStack<T> &stack) {
    for (int i = 0; i <= stack.top; ++i) {
        os << stack.dataArray[i] << " ";
    }
    return os;
}

