#include <iostream>
#include <cassert>
#include "BinaryTree.h"

int main()
{
    BinaryTree<int> tree;

    // Insert nodes
    tree.insertNode(10);
    tree.insertNode(5);
    tree.insertNode(15);
    tree.insertNode(3);
    tree.insertNode(7);

    std::cout << "After inserts: nodes=" << tree.getNodesCount()
              << " leaves=" << tree.getLeafNodesCount() << std::endl;

    // Delete a leaf
    tree.remove(7);
    std::cout << "After remove(7): nodes=" << tree.getNodesCount()
              << " leaves=" << tree.getLeafNodesCount() << std::endl;

    // Delete a node with one child (5 has left child 3)
    tree.remove(5);
    std::cout << "After remove(5): nodes=" << tree.getNodesCount()
              << " leaves=" << tree.getLeafNodesCount() << std::endl;

    // Delete a leaf 15
    tree.remove(15);
    std::cout << "After remove(15): nodes=" << tree.getNodesCount()
              << " leaves=" << tree.getLeafNodesCount() << std::endl;
    return 0;
}