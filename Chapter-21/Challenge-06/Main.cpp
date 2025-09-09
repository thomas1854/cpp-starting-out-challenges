/*
Challenge 06:
    6. Tree Assignment Operators, Copy Constructors, and Move Constructors
    Design an overloaded copy assignment operator, a move assignment operator, a
    copy constructor, and a move constructor for the template you designed in
    Programming Challenge 1. Demonstrate them in a driver program.
*/

#include <iostream>
#include "BinaryTree.h"

// Function to test move construction
// Takes a BinaryTree by value (copy happens at call site)
// and returns it, which invoke move constructor.
BinaryTree<int> testMoveConstruct(BinaryTree<int> binaryTree)
{
    return binaryTree; // returned by value
}

int main()
{
    BinaryTree<int> tree;

    // Insert multiple nodes into the tree
    tree.insertNode(10);
    tree.insertNode(5);
    tree.insertNode(15);
    tree.insertNode(3);
    tree.insertNode(7);
    tree.insertNode(70);

    // --------------------------
    // Test copy constructor
    // --------------------------
    BinaryTree<int> constructedTree = tree;  // copy construction
    constructedTree.remove(15);
    constructedTree.insertNode(3000);
    constructedTree.insertNode(4000);
    constructedTree.insertNode(5000);

    // --------------------------
    // Test copy assignment
    // --------------------------
    tree = constructedTree;  // copy assignment replaces contents of tree

    // --------------------------
    // Test move constructor
    // --------------------------
    BinaryTree<int> movedTree = testMoveConstruct(tree);
    movedTree.insertNode(100);
    movedTree.insertNode(150);

    // --------------------------
    // Display results
    // --------------------------
    std::cout << "Final tree (in-order traversal):" << std::endl;
    tree.displayInOrder();

    std::cout << "Moved tree (in-order traversal):" << std::endl;
    movedTree.displayInOrder();

    return 0;
}
