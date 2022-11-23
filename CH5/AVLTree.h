//
// Created by yn on 18/11/2022.
//

#ifndef SINGLYLINKEDLIST_CPP_AVLTREE_H
#define SINGLYLINKEDLIST_CPP_AVLTREE_H

template<class T>
struct Node {
    T data;
    int height;
    Node<T> *leftChild;
    Node<T> *rightChild;

    bool operator<(const Node<T> &node) const {
        return data < node.data;
    }
};

template<class T>
class AVLTree {
private:
    Node<T> *root;

    Node<T> *leftRotate(Node<T> *&node);

    Node<T> *rightRotate(Node<T> *&node);

public:
    AVLTree();

    ~AVLTree();

    Node<T> *newNode(T data);

    Node<T> *insert(Node<T> *node, T data);

    Node<T> *deleteNode(Node<T> *node, T data);

    Node<T> *minimum(Node<T> *node);

    const int getBalanceFactor(Node<T> *node) const;

    void deleteTree(Node<T> *&node);

    const int getHeight(Node<T> *node) const;

    Node<T> *getRoot() const;

    void preOrder(Node<T> *node) const;


};


#endif //SINGLYLINKEDLIST_CPP_AVLTREE_H
