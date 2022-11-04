//
// Created by yn on 4/11/2022.
//

#include "HuffmanTree.h"
#include <queue>
#include <functional>

template<class T>
HuffmanTree<T>::HuffmanTree() {
    root = nullptr;
}

template<class T>
void HuffmanTree<T>::deleteTree(HuffmanTreeNode<T> *&node) {
    if (node == nullptr) {
        return;
    }

    deleteTree(node->leftChild);
    deleteTree(node->rightChild);
    delete node;
    node = nullptr;
}

template<class T>
HuffmanTree<T>::~HuffmanTree() {
    deleteTree(root);
}

template<class T>
void HuffmanTree<T>::createHuffmanTree(T *data, int *weight, int size) {
    auto *nodes = new HuffmanTreeNode<T>[size];
    // initialize nodes with their data and weight
    for (int i = 0; i < size; ++i) {
        nodes[i].data = data[i];
        nodes[i].weight = weight[i];
        nodes[i].leftChild = nullptr;
        nodes[i].rightChild = nullptr;
        nodes[i].parent = nullptr;
    }

    auto *nodeQueue = new std::priority_queue<HuffmanTreeNode<T>, std::vector<HuffmanTreeNode<T>>, std::greater<>>;
    for (int i = 0; i < size; ++i) {
        nodeQueue->push(nodes[i]);
    }

    for (int i = 0; i < size - 1; ++i) {
        auto *node1 = new HuffmanTreeNode<T>;
        auto *node2 = new HuffmanTreeNode<T>;
        *node1 = nodeQueue->top();
        nodeQueue->pop();
        *node2 = nodeQueue->top();
        nodeQueue->pop();

        auto *newNode = new HuffmanTreeNode<T>;
        newNode->data = node1->data + node2->data;
        newNode->weight = node1->weight + node2->weight;
        newNode->leftChild = node1;
        newNode->rightChild = node2;
        newNode->parent = nullptr;

        node1->parent = newNode;
        node2->parent = newNode;

        nodeQueue->push(*newNode);
    }

    root = new HuffmanTreeNode<T>;
    *root = nodeQueue->top();
    nodeQueue->pop();
}

template<class T>
int HuffmanTree<T>::computeWeight(HuffmanTreeNode<T> *node) {
    if (node == nullptr) {
        return 0;
    }

    return node->weight + computeWeight(node->leftChild) + computeWeight(node->rightChild);
}