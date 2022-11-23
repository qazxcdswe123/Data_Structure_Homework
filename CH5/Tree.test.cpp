//
// Created by yn on 31/10/2022.
//
#include "BinaryTree.cpp"
#include "HuffmanTree.cpp"
#include "AVLTree.cpp"

#include <catch2/catch_test_macros.hpp>

TEST_CASE("BinaryTree", "[BinaryTree]") {
    SECTION("init") {
        BinaryTree<char> tree('A');
        tree.insert('B', tree.getRoot(), true);
        tree.insert('C', tree.getRoot(), false);
        tree.insert('D', tree.getRoot()->leftChild, true);
        tree.insert('E', tree.getRoot()->leftChild, false);
        tree.insert('F', tree.getRoot()->rightChild, false);
        tree.insert('G', tree.getRoot()->leftChild->rightChild, true);

        SECTION("Testing Tree Traversal") {
            tree.inOrderTreeWalk(tree.getRoot());
            std::cout << std::endl;
            tree.preOrderTreeWalk(tree.getRoot());
            std::cout << std::endl;
            tree.postOrderTreeWalk(tree.getRoot());
            std::cout << std::endl;
            tree.levelOrderTreeWalk(tree.getRoot());
            std::cout << std::endl;
        }

        SECTION("Testing Tree Search") {
            REQUIRE(tree.search('A', tree.getRoot()));
            REQUIRE(tree.search('B', tree.getRoot()));
            REQUIRE(tree.search('C', tree.getRoot()));
            REQUIRE(tree.search('D', tree.getRoot()));
            REQUIRE(tree.search('E', tree.getRoot()));
            REQUIRE(tree.search('F', tree.getRoot()));
            REQUIRE(tree.search('G', tree.getRoot()));
            REQUIRE(!tree.search('H', tree.getRoot()));
        }

        SECTION("Testing Utilities") {
            REQUIRE(tree.getNumberOfLeaves(tree.getRoot()) == 3);
            REQUIRE(tree.getNumberOfNodes(tree.getRoot()) == 7);
            REQUIRE(tree.getHeight(tree.getRoot()) == 3);
        }
    }
}

TEST_CASE("Huffman Tree", "[HuffmanTree]") {
    SECTION("init") {
        HuffmanTree<int> Tree;
        int dataArray[] = {2, 5, 3, 1};
        int countArray[] = {7, 5, 2, 4};
        Tree.createHuffmanTree(dataArray, countArray, 4);

        SECTION("Testing getHeight") {
            REQUIRE(Tree.getHeight(Tree.getRoot()) == 3);
            REQUIRE(Tree.getHeight(Tree.getRoot()->leftChild) == 2);
        }

        SECTION("Verify that the count is correct") {
            int originalWeight = 0;
            for (int i = 0; i < 4; ++i) {
                originalWeight += dataArray[i] * countArray[i];
            }
            int weight = 0;
            Tree.computeWeightOfTree(Tree.getRoot(), weight);
            REQUIRE(weight != originalWeight);
        }
    }
}

TEST_CASE("AVL Tree", "[AVLTree]") {
    SECTION("INIT") {
        AVLTree<int> tree;
        tree.insert(tree.getRoot(), 2);
        tree.insert(tree.getRoot(), 5);
        tree.insert(tree.getRoot(), 10);
        tree.insert(tree.getRoot(), 20);
        tree.insert(tree.getRoot(), 30);

        SECTION("Test deletion") {
            tree.preOrder(tree.getRoot());
            std::cout << std::endl;
            tree.deleteNode(tree.getRoot(), 10);
            tree.deleteNode(tree.getRoot(), 20);
            tree.preOrder(tree.getRoot());
        }
    }
}