/*
7. Queue Converter
    Write a program that stores a series of numbers in a binary tree. Then have the program insert the values into a queue in ascending order.
    Dequeue the values and display them on the screen to confirm that they were stored in the proper order.
*/

#include <iostream>
#include <queue>
#include "BinaryTree.h"

// Recursive function that performs an in-order traversal of the binary tree
// and stores the node values in a queue.
//
// Parameters:
//   treeRoot - pointer to the current node in the binary tree
//   qu       - reference to a queue where the traversal result will be stored
//
// Traversal order: Left subtree -> Current node -> Right subtree
template<typename T>
void queueTree(typename BinaryTree<T>::Node* treeRoot, std::queue<T>& qu)
{
    if (treeRoot != nullptr)  // base case: stop if we reach an empty subtree
    {
        // Traverse the left subtree
        queueTree(treeRoot->left, qu);

        // Visit the current node: push its value into the queue
        qu.push(treeRoot->value);

        // Traverse the right subtree
        queueTree(treeRoot->right, qu);
    }
}

int main()
{
    std::queue<int> qu;       // Queue to hold values collected from the tree
    BinaryTree<int> tree;     // Create a binary search tree of integers

    // Insert multiple nodes into the tree.
    // The BinaryTree class will automatically position them
    // according to binary search tree rules.
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

    // Perform in-order traversal (to be sorted in the queue) of the tree and
    // store the node values in the queue 
    queueTree(tree.getRootNodePtr(), qu);

    // Print the values from the queue one by one.
    // Since we used in-order traversal, the output will be sorted.
    while (!qu.empty())
    {
        std::cout << qu.front() << std::endl;  // Get the next element
        qu.pop();                              // Remove it from the queue
    }

    return 0;
}
