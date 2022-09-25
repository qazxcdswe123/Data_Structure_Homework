//
// Created by yn on 22/9/2022.
//

#ifndef CH2_CIRCULARLINKEDLIST_H
#define CH2_CIRCULARLINKEDLIST_H

// use doubly linked list to make it circular

template<class T>
class CircularLinkedList;

template<class T>
class LinkedListNode {
    friend class CircularLinkedList<T>;

protected:
    T data;
    LinkedListNode *next;
    LinkedListNode *prev;
};

template<class T>
class CircularLinkedList {
private:
    LinkedListNode<T> *head = nullptr;
    int currentLength = 0;

public:
    ~CircularLinkedList();

    bool insertAfterPosition(int position, T value);
    bool remove(int position);
    bool isEmpty() const;
    int getCurrentLength() const;
    int search(const T x) const;
    T getDataAtPosition(int position) const;
    void print() const;
};


#endif //CH2_CIRCULARLINKEDLIST_H
