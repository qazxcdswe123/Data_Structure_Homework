//
// Created by yn on 4/11/2022.
//

#ifndef CH5_HUFFMANTREE_H
#define CH5_HUFFMANTREE_H

template<class T>
struct HuffmanTreeNode {
    HuffmanTreeNode(T value, int weight) {
        this->data = value;
        this->weight = weight;
        this->leftChild = nullptr;
        this->rightChild = nullptr;
        this->parent = nullptr;
    }

    T data;
    int weight;
    HuffmanTreeNode<T> *leftChild;
    HuffmanTreeNode<T> *rightChild;
    HuffmanTreeNode<T> *parent;

    bool operator<(const HuffmanTreeNode<T> &node) const {
        return weight < node.weight;
    }
};


template<class T>
class HuffmanTree {
public:
    HuffmanTree();

    ~HuffmanTree();

    void createHuffmanTree(T *data, const int *weight, int n);

    void deleteTree(HuffmanTreeNode<T> *&node);

    int computeWeight(HuffmanTreeNode<T> *node);

private:
    HuffmanTreeNode<T> *root;
};


#endif //CH5_HUFFMANTREE_H
