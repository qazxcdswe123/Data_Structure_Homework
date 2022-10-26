//
// Created by yn on 24/10/2022.
//

#ifndef CH3_DOUBLEENDEDQUEUE_H
#define CH3_DOUBLEENDEDQUEUE_H

template <class T>
class DoubleEndedQueue {
private:
    int front;
    int rear;
    int maxSize;
    T *dataArray;

public:
    explicit DoubleEndedQueue(int size);
    ~DoubleEndedQueue();
    bool isEmpty() const;
    bool isFull() const;
    void enQueueFront(T data);
    void enQueueRear(T data);
    void makeEmpty();
    T deQueueFront();
    T deQueueRear();
};

#endif //CH3_DOUBLEENDEDQUEUE_H
