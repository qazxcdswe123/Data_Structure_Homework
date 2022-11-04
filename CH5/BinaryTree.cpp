//
// Created by yn on 2/11/2022.
//

#include "BinaryTree.h"

#include <iostream>
#include <queue>

template<class T>
BinaryTree<T>::BinaryTree(T value) {
    root = new TreeNode<T>;
    root->data = value;
    root->leftChild = nullptr;
    root->rightChild = nullptr;
}

template<class T>
void BinaryTree<T>::deleteTree(TreeNode<T> *&node) {
    if (node == nullptr) {
        return;
    }

    deleteTree(node->leftChild);
    deleteTree(node->rightChild);
    delete node;
    node = nullptr;
}

template<class T>
BinaryTree<T>::~BinaryTree() {
    deleteTree(root);
}

template<class T>
TreeNode<T> *BinaryTree<T>::getRoot() {
    return root;
}

template<class T>
void BinaryTree<T>::insert(T value, TreeNode<T> *node, bool isLeftChild) {
    auto *newNode = new TreeNode<T>;
    newNode->data = value;
    newNode->leftChild = nullptr;
    newNode->rightChild = nullptr;
    newNode->parent = node;

    if (node == nullptr) {
        root = newNode;
    } else if (isLeftChild) {
        node->leftChild = newNode;
    } else {
        node->rightChild = newNode;
    }
}

template<class T>
void BinaryTree<T>::inOrderTreeWalk(TreeNode<T> *node) {
    if (node == nullptr) {
        return;
    }
    inOrderTreeWalk(node->leftChild);
    std::cout << node->data << " ";
    inOrderTreeWalk(node->rightChild);
}

template<class T>
void BinaryTree<T>::preOrderTreeWalk(TreeNode<T> *node) {
    if (node == nullptr) {
        return;
    }
    std::cout << node->data << " ";
    preOrderTreeWalk(node->leftChild);
    preOrderTreeWalk(node->rightChild);
}

template<class T>
void BinaryTree<T>::postOrderTreeWalk(TreeNode<T> *node) {
    if (node == nullptr) {
        return;
    }
    postOrderTreeWalk(node->leftChild);
    postOrderTreeWalk(node->rightChild);
    std::cout << node->data << " ";
}

template<class T>
void BinaryTree<T>::levelOrderTreeWalk(TreeNode<T> *node) {
    if (node == nullptr) {
        return;
    }
    std::queue<TreeNode<T> *> q;
    q.push(node);
    while (!q.empty()) {
        TreeNode<T> *p = q.front();
        q.pop();
        std::cout << p->data << " ";
        if (p->leftChild != nullptr) {
            q.push(p->leftChild);
        }
        if (p->rightChild != nullptr) {
            q.push(p->rightChild);
        }
    }
}

template<class T>
bool BinaryTree<T>::search(T value, TreeNode<T> *node) {
    if (node == nullptr) {
        return false;
    }
    if (node->data == value) {
        return true;
    }
    if (search(value, node->leftChild)) {
        return true;
    }
    if (search(value, node->rightChild)) {
        return true;
    }
    return false;
}

template<class T>
int BinaryTree<T>::getHeight(TreeNode<T> *node) {
    if (node == nullptr) {
        return -1;
    }
    int leftHeight = getHeight(node->leftChild);
    int rightHeight = getHeight(node->rightChild);
    return leftHeight > rightHeight ? leftHeight + 1 : rightHeight + 1;
}

template<class T>
int BinaryTree<T>::getNumberOfNodes(TreeNode<T> *node) {
    if (node == nullptr) {
        return 0;
    }
    return getNumberOfNodes(node->leftChild) + getNumberOfNodes(node->rightChild) + 1;
}

template<class T>
int BinaryTree<T>::getNumberOfLeaves(TreeNode<T> *node) {
    if (node == nullptr) {
        return 0;
    }
    if (node->leftChild == nullptr && node->rightChild == nullptr) {
        return 1;
    }
    return getNumberOfLeaves(node->leftChild) + getNumberOfLeaves(node->rightChild);
}