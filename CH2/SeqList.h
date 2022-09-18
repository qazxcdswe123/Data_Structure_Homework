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
    ~SeqList() { delete[] element; }

    int size() const { return maxSize; } // get the maximum size of the list
    int length() const { return lastPosition + 1; } // get the current length of the list
    int search(const T &x) const; // return the position of x
    int locate(int i) const; // return the position of the ith element

    T *getData(int i) const {
        return (i > 0 && i <= lastPosition) ? &element[i - 1] : nullptr;
    } // return a pointer to the ith element, i start from 1
    void setData(int i, T &x) {
        if (i > 0 && i <= lastPosition) element[i - 1] = x;
    } // set the ith element to x, i start from 1

    bool insert(int i, T &x); // insert x just after the ith element
    bool remove(int i, T &x); // remove the ith element and return it in x
    bool isEmpty() const { return lastPosition == -1; } // return true if the list is empty, otherwise return false
    bool isFull() const {
        return lastPosition == maxSize - 1;
    } // return true if the list is full, otherwise return false
    void input(); // add an element to the end of the list
    void output() const; // output the elements to the screen
    void sort(); // sort the elements in the list

    SeqList<T> &operator=(const SeqList<T> &L); // copy the elements of L to this list
};


#endif //DS_NEW_SEQLIST_H
