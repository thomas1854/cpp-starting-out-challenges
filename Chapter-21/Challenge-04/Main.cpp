/*
Challenge 04:
     4. Tree Height
     Write a member function, for the template you designed in Programming
     Challenge 1 that returns the height of the tree.
*/

#include <iostream>
#include "BinaryTree.h"

int main()
{
    BinaryTree<int> tree;

    // Display the height of the tree before any insertions
    std::cout << "Initial tree height: " << tree.getHeight() << std::endl;

    // Insert multiple nodes into the tree
    tree.insertNode(10);
    tree.insertNode(5);
    tree.insertNode(15);
    tree.insertNode(3);
    tree.insertNode(7);
    tree.insertNode(70);
    tree.insertNode(9);
    tree.insertNode(2);
    tree.insertNode(20);
    tree.insertNode(21);
    tree.insertNode(19);
    tree.insertNode(80);
    tree.insertNode(79);
    tree.insertNode(81);
    tree.insertNode(90);

    // Display the height of the tree after insertions
    std::cout << "Tree height after insertions: " << tree.getHeight() << std::endl;

    // Remove several nodes from the tree
    tree.remove(90);
    tree.remove(81);
    tree.remove(79);
    tree.remove(21);
    tree.remove(19);

    // Display the height of the tree after deletions
    std::cout << "Tree height after deletions: " << tree.getHeight() << std::endl;

    return 0;
}
