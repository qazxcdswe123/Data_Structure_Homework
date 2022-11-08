//
// Created by yn on 4/11/2022.
//

#include "HuffmanTree.h"
#include <queue>

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
void HuffmanTree<T>::createHuffmanTree(T *data, const int *weight, int size) {
    auto *nodes = new HuffmanTreeNode<T>[size];
    // initialize nodes with their data and count
    for (int i = 0; i < size; ++i) {
        nodes[i].data = data[i];
        nodes[i].count = weight[i];
        nodes[i].leftChild = nullptr;
        nodes[i].rightChild = nullptr;
        nodes[i].parent = nullptr;
    }

    auto *nodeQueue = new std::priority_queue<HuffmanTreeNode<T>, std::vector<HuffmanTreeNode<T>>, std::less<HuffmanTreeNode<T>>>;

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
        newNode->count = node1->count + node2->count;
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
    delete nodeQueue;
    delete[] nodes;
}

template<class T>
int HuffmanTree<T>::getHeight(HuffmanTreeNode<T> *node) {
    if (node == nullptr) {
        return -1;
    }

    int leftHeight = getHeight(node->leftChild);
    int rightHeight = getHeight(node->rightChild);

    return leftHeight > rightHeight ? leftHeight + 1 : rightHeight + 1;
}

template<class T>
void HuffmanTree<T>::computeWeightOfTree(HuffmanTreeNode<T> *node, int &weight) {
    if (node == nullptr) {
        return;
    }
    int height = getHeight(node);
    weight += height * node->count;
    computeWeightOfTree(node->leftChild, weight);
    computeWeightOfTree(node->rightChild, weight);
}

template<class T>
HuffmanTreeNode<T> *HuffmanTree<T>::getRoot() {
    return root;
}