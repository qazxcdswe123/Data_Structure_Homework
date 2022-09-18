//
// Created by yn on 14/9/2022.
//

#ifndef DS_NEW_SEQLIST_H
#define DS_NEW_SEQLIST_H

#include "LinearList.h"

const int defaultSize = 100;

template<class T>
class SeqList : public LinearList<T> {
protected:
    T *element;
    int maxSize; // the maximum size of the list permitted
    int lastPosition;

    void resize(const int newSize);

public:
    explicit SeqList(int size = defaultSize);

    SeqList(const SeqList<T> &L); // copy constructor
    ~SeqList(); // destructor

    int getTotalSize() const override; // get the maximum size of the list
    int getCurrentLength() const override; // get the current getCurrentLength of the list
    int search(const T &x) const override; // return the position of x

    T *getDataPointer(int i) const override; // return a pointer to the ith element, i start from 1
    bool setData(int i,
                 T &x) override; // set the ith element to x, i start from 1, return true if success, otherwise return false

    bool insert(int i, T &x) override; // insert x just after the ith element
    bool remove(int i, T &x) override; // remove the ith element and return it in x
    bool isEmpty() const override; // return true if the list is empty, otherwise return false
    bool isFull() const override; // return true if the list is full, otherwise return false
    void print() const override; // print the elements to the screen
    void sort() override; // sort the elements in the list

    SeqList<T> &operator=(const SeqList<T> &L); // copy the elements of L to this list
};


#endif //DS_NEW_SEQLIST_H
