/*
Challenge-05: 
    5. Tree Width
    Write a member function, for the template you designed in Programming
    Challenge 1 that returns the width of the tree. The width
    of the tree is the largest number of nodes in the same level. Demonstrate the function
    in a driver program.
*/

#include <iostream>
#include "BinaryTree.h"

int main()
{
    BinaryTree<int> tree;

    // Show width before inserting any nodes
    std::cout << "Initial tree width: " << tree.getTreeWidth() << std::endl;

    // Insert nodes
    tree.insertNode(9);
    tree.insertNode(30);
    tree.insertNode(4);
    tree.insertNode(40);
    tree.insertNode(10);
    tree.insertNode(8);
    tree.insertNode(3);

    // Show tree width after insertions
    std::cout << "Tree width after insertions: " << tree.getTreeWidth() << std::endl;

    // Remove nodes
    tree.remove(4);
    tree.remove(10);

    // Show tree width after deletions
    std::cout << "Tree width after deletions: " << tree.getTreeWidth() << std::endl;

    return 0;
}
