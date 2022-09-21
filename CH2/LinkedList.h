//
// Created by yn on 19/9/2022.
//

#ifndef CH2_LINKEDLIST_H
#define CH2_LINKEDLIST_H

template<class T>
class LinkedList;

template<class T>
class LinkedListNode {
    friend class LinkedList<T>;

protected:
    T data;
    LinkedListNode *next;
};

template<class T>
class LinkedList {
private:
    LinkedListNode<T> *head = nullptr;
    int currentLength = 0;

public:
//    LinkedList();
    ~LinkedList();

    bool insert(int position, T value);
    bool remove(int position);
    int getCurrentLength() const;
    int search(const T x) const;
    T getDataAtPosition(int position) const;
};


#endif //CH2_LINKEDLIST_H
