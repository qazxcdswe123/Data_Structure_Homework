//
// Created by yn on 2/11/2022.
//

#ifndef CH5_BINARYTREE_H
#define CH5_BINARYTREE_H

/*
 * 1、以二叉链表表示二叉树,创建二叉树
2、基本操作函数:构造函数、析构函数、复制构造函数、赋值运算等,以及二叉树的复制和删除基本操作。
2、输出二叉树3、二叉树的先序、中序、后序遍历和按层遍历(递归和非递归) 4、统计和输出二叉树结构特征(包含部分设计性实验) : (1)输出结点的左右孩子、叶子结点。
(2)统计:结点个数、叶子个数、深(高)度、度为 1 和 2 的结点个数、结点的层次。
(3)采用先序遍历算法输出从根到叶子结点的路径以及从叶子结点到的根逆路径。
5、用二叉树表示一个简单算术表达式,重新设计栈的应用的简单计算器。
 */

template<class T>
struct TreeNode {
    T data;
    TreeNode<T> *leftChild;
    TreeNode<T> *rightChild;
    TreeNode<T> *parent;
};

template<class T>
class BinaryTree {
private:

};

#endif //CH5_BINARYTREE_H
