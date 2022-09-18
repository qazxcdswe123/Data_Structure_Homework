//
// Created by yn on 14/9/2022.
//

#ifndef DS_NEW_LINEARLIST_H
#define DS_NEW_LINEARLIST_H

template<class T>
class LinearList {
public:
//    LinearList(); Abstract class can omit constructor
//    virtual ~LinearList() = default;

    virtual int getTotalSize() const = 0;             // return the maximum number of elements in the list
    virtual int getCurrentLength() const = 0;           // return the number of elements in the list
    virtual int search(const T &x) const = 0; // return the position of x
    virtual T *getData(int i) const = 0;      // return a pointer to the ith element
    virtual bool setData(int i, T &x) = 0;    // set the ith element to x
    virtual bool insert(int i, T &x) = 0;     // insert x just after the ith element
    virtual bool remove(int i, T &x) = 0;     // remove the ith element and return it in x
    virtual bool isEmpty() const = 0;         // return true if the list is empty, otherwise return false
    virtual bool isFull() const = 0;          // return true if the list is full, otherwise return false
    virtual void sort() = 0;                  // sort the elements in the list
    virtual void print() const = 0;                // print the elements to the screen

    // no need to make operator overloading virtual in abstract class
//    virtual LinearList<T> &operator=(const LinearList<T> &L) = 0; // copy the elements of L to this list
};


#endif //DS_NEW_LINEARLIST_H
