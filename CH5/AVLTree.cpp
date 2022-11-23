//
// Created by yn on 18/11/2022.
//

#include "AVLTree.h"

#include <algorithm>
#include <iostream>

template<class T>
AVLTree<T>::AVLTree() {
    root = nullptr;
}

template<class T>
void AVLTree<T>::deleteTree(Node<T> *&node) {
    if (node == nullptr) {
        return;
    }

    deleteTree(node->leftChild);
    deleteTree(node->rightChild);
    delete node;
    node = nullptr;
}

template<class T>
AVLTree<T>::~AVLTree() {
    deleteTree(root);
}

template<class T>
const int AVLTree<T>::getHeight(Node<T> *node) const {
    if (node == nullptr) {
        return 0;
    }
    return node->height;
}

template<class T>
Node<T> *AVLTree<T>::rightRotate(Node<T> *&node) {
    auto *leftChild = node->leftChild;
    node->leftChild = leftChild->rightChild;
    leftChild->rightChild = node;
    node->height = std::max(getHeight(node->leftChild), getHeight(node->rightChild)) + 1;
    leftChild->height = std::max(getHeight(leftChild->leftChild), getHeight(leftChild->rightChild)) + 1;
    return leftChild;
}

template<class T>
Node<T> *AVLTree<T>::leftRotate(Node<T> *&node) {
    auto *rightChild = node->rightChild;
    node->rightChild = rightChild->leftChild;
    rightChild->leftChild = node;
    node->height = std::max(getHeight(node->leftChild), getHeight(node->rightChild)) + 1;
    rightChild->height = std::max(getHeight(rightChild->leftChild), getHeight(rightChild->rightChild)) + 1;
    return rightChild;
}

template<class T>
const int AVLTree<T>::getBalanceFactor(Node<T> *node) const {
    if (node == nullptr) {
        return 0;
    }
    return getHeight(node->leftChild) - getHeight(node->rightChild);
}

template<class T>
Node<T> *AVLTree<T>::newNode(T data) {
    auto *node = new Node<T>;
    node->data = data;
    node->height = 1;
    node->leftChild = nullptr;
    node->rightChild = nullptr;
    return node;
}

template<class T>
Node<T> *AVLTree<T>::insert(Node<T> *node, T data) {
    if (node == nullptr) {
        return newNode(data);
    }

    if (data < node->data) {
        node->leftChild = insert(node->leftChild, data);
    } else if (data > node->data) {
        node->rightChild = insert(node->rightChild, data);
    } else {
        return node;
    }

    node->height = std::max(getHeight(node->leftChild), getHeight(node->rightChild)) + 1;

    auto balanceFactor = getBalanceFactor(node);

    if (balanceFactor > 1 && data < node->leftChild->data) {
        return rightRotate(node);
    }

    if (balanceFactor < -1 && data > node->rightChild->data) {
        return leftRotate(node);
    }

    if (balanceFactor > 1 && data > node->leftChild->data) {
        node->leftChild = leftRotate(node->leftChild);
        return rightRotate(node);
    }

    if (balanceFactor < -1 && data < node->rightChild->data) {
        node->rightChild = rightRotate(node->rightChild);
        return leftRotate(node);
    }

    return node;
}

template<class T>
Node<T> *AVLTree<T>::minimum(Node<T> *node) {
    if (node->leftChild == nullptr) {
        return node;
    }
    return minimum(node->leftChild);
}

template<class T>
Node<T> *AVLTree<T>::deleteNode(Node<T> *node, T data) {
    if (node == nullptr) {
        return nullptr;
    }

    if (data < node->data) {
        node->leftChild = deleteNode(node->leftChild, data);
    } else if (data > node->data) {
        node->rightChild = deleteNode(node->rightChild, data);
    } else {
        // node with only one child or no child
        if (node->leftChild == nullptr || node->rightChild == nullptr) {
            auto *temp = node->leftChild ? node->leftChild : node->rightChild;
            if (temp == nullptr) { // no child
                temp = node;
                node = nullptr;
            } else { // one child
                *node = *temp;
            }
            delete temp;
        } else { // node with two children
            auto *temp = minimum(node->rightChild);
            node->data = temp->data;
            node->rightChild = deleteNode(node->rightChild, temp->data);
        }
    }

    if (node == nullptr) {
        return node;
    }

    node->height = std::max(getHeight(node->leftChild), getHeight(node->rightChild)) + 1;

    auto balanceFactor = getBalanceFactor(node);

    if (balanceFactor > 1 && getBalanceFactor(node->leftChild) >= 0) {
        return rightRotate(node);
    }

    if (balanceFactor > 1 && getBalanceFactor(node->leftChild) < 0) {
        node->leftChild = leftRotate(node->leftChild);
        return rightRotate(node);
    }

    if (balanceFactor < -1 && getBalanceFactor(node->rightChild) <= 0) {
        return leftRotate(node);
    }

    if (balanceFactor < -1 && getBalanceFactor(node->rightChild) > 0) {
        node->rightChild = rightRotate(node->rightChild);
        return leftRotate(node);
    }

    return node;
}

template<class T>
void AVLTree<T>::preOrder(Node<T> *node) const {
    if (node == nullptr) {
        return;
    }
    std::cout << node->data << " ";
    preOrder(node->leftChild);
    preOrder(node->rightChild);
}

template<class T>
Node<T> *AVLTree<T>::getRoot() const {
    return root;
}
