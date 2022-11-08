//
// Created by yn on 4/11/2022.
//

#ifndef CH5_HUFFMANTREE_H
#define CH5_HUFFMANTREE_H

template<class T>
struct HuffmanTreeNode {
    T data;
    int count;
    HuffmanTreeNode<T> *leftChild;
    HuffmanTreeNode<T> *rightChild;
    HuffmanTreeNode<T> *parent;

    bool operator<(const HuffmanTreeNode<T> &node) const {
        return count < node.count;
    }
};


template<class T>
class HuffmanTree {
public:
    HuffmanTree();

    ~HuffmanTree();

    void createHuffmanTree(T *data, const int *weight, int n);

    void deleteTree(HuffmanTreeNode<T> *&node);

    int getHeight(HuffmanTreeNode<T> *node);

    void computeWeightOfTree(HuffmanTreeNode<T> *node, int &weight);

    HuffmanTreeNode<T> *getRoot();

private:
    HuffmanTreeNode<T> *root;
};


#endif //CH5_HUFFMANTREE_H
