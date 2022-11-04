//
// Created by yn on 4/11/2022.
//

#ifndef CH5_HUFFMANTREE_H
#define CH5_HUFFMANTREE_H

template<class T>
struct HuffmanTreeNode {
    T data;
    int weight;
    HuffmanTreeNode<T> *leftChild;
    HuffmanTreeNode<T> *rightChild;
    HuffmanTreeNode<T> *parent;
};


template<class T>
class HuffmanTree {
public:
    HuffmanTree();

    ~HuffmanTree();

    void createHuffmanTree(T *data, int *weight, int n);

    void deleteTree(HuffmanTreeNode<T> *&node);

    int computeWeight(HuffmanTreeNode<T> *node);

private:
    HuffmanTreeNode<T> *root;
};


#endif //CH5_HUFFMANTREE_H
