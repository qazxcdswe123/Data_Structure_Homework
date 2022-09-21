//
// Created by yn on 19/9/2022.
//

#ifndef CH2_SINGLYLINKEDLIST_H
#define CH2_SINGLYLINKEDLIST_H

template<class T>
class SinglyLinkedList;

template<class T>
class LinkedListNode {
    friend class SinglyLinkedList<T>;

protected:
    T data;
    LinkedListNode *next;
};

template<class T>
class SinglyLinkedList {
private:
    LinkedListNode<T> *head = nullptr;
    int currentLength = 0;

public:
//    SinglyLinkedList();
    ~SinglyLinkedList();

    bool insertAfterPosition(int position, T value);
    bool remove(int position);
    int getCurrentLength() const;
    int search(const T x) const;
    T getDataAtPosition(int position) const;
};


#endif //CH2_SINGLYLINKEDLIST_H
