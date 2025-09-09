#pragma once
#ifndef BINARYTREE_H
#define BINARYTREE_H
#include <iostream>
#include <algorithm>
#include <functional>

// Template class for a Binary Search Tree (BST) that can store values of any type T
template <typename T>
class BinaryTree
{
private:
    // Inner struct representing a node in the binary tree
    struct TreeNode
    {
        T value;         // The value stored in the node
        TreeNode *left;  // Pointer to the left child node
        TreeNode *right; // Pointer to the right child node
    };

    TreeNode *root; // Pointer to the root node of the tree

    // Private helper methods for recursive operations
    void insert(TreeNode *&, TreeNode *&);   // Inserts a new node into the tree
    void makeDeletion(TreeNode *&);          // Handles the deletion of a node
    void displayInOrder(TreeNode *) const;   // Displays nodes in-order (left, root, right)
    void displayPostOrder(TreeNode *) const; // Displays nodes post-order (left, right, root)
    void displayPreOrder(TreeNode *) const;  // Displays nodes pre-order (root, left, right)
    void destroySubtree(TreeNode *);         // Recursively deletes all nodes in a subtree
    void deleteNode(TreeNode *&, T);         // Finds and deletes a node with a given value

public:
    // Constructor: Initializes an empty tree
    BinaryTree()
    {
        root = nullptr;
    }

    // Move constructor - transfers ownership from another BinaryTree
    BinaryTree(BinaryTree<T> &&binaryTree);

    // Copy constructor - creates deep copy of another BinaryTree
    BinaryTree(const BinaryTree<T> &binaryTree);

    // Copy assignment operator - assigns deep copy of another BinaryTree
    BinaryTree<T> &operator=(const BinaryTree<T> &binaryTree);

    // Move assignment operator (swap trick).
    // Swaps the root pointer with the rvalue's root, so this tree takes ownership
    // and the temporary's destructor cleans up the old tree.
    BinaryTree<T>& operator=(BinaryTree<T>&& binaryTree);
    
    // Destructor: Frees all nodes in the tree
    ~BinaryTree()
    {
        std::cout << "Tree destructor invoked!" << std::endl;
        destroySubtree(root);
    }

    // Public methods for tree operations
    void insertNode(T);       // Inserts a new value into the tree
    void remove(T);           // Removes a value from the tree
    bool searchNode(T) const; // Searches for a value in the tree

    // Public methods for displaying the tree in different traversal orders
    void displayInOrder() const
    {
        displayInOrder(root);
    }

    void displayPostOrder() const
    {
        displayPostOrder(root);
    }

    void displayPreOrder() const
    {
        displayPreOrder(root);
    }
};

// Inserts a new node with the given value into the tree
template <typename T>
void BinaryTree<T>::insertNode(T val)
{
    // Create a new node with the provided value
    TreeNode *newNode = new TreeNode;
    newNode->left = nullptr;
    newNode->right = nullptr;
    newNode->value = val;

    // Insert the new node into the tree starting from the root
    insert(root, newNode);
}

// Recursive helper method to insert a new node into the tree
template <typename T>
void BinaryTree<T>::insert(TreeNode *&nodePtr, TreeNode *&newNode)
{
    // If the current node is null, place the new node here
    if (nodePtr == nullptr)
        nodePtr = newNode;
    // If the new value is less than the current node's value, go left
    else if (newNode->value < nodePtr->value)
        insert(nodePtr->left, newNode);
    // If the new value is greater, go right
    else
        insert(nodePtr->right, newNode);
}

// Displays the tree in-order (left subtree, current node, right subtree)
template <typename T>
void BinaryTree<T>::displayInOrder(TreeNode *nodePtr) const
{
    if (nodePtr)
    {
        // Recursively traverse the left subtree
        displayInOrder(nodePtr->left);
        // Print the current node's value
        std::cout << nodePtr->value << std::endl;
        // Recursively traverse the right subtree
        displayInOrder(nodePtr->right);
    }
}

// Displays the tree pre-order (current node, left subtree, right subtree)
template <typename T>
void BinaryTree<T>::displayPreOrder(TreeNode *nodePtr) const
{
    if (nodePtr)
    {
        // Print the current node's value first
        std::cout << nodePtr->value << std::endl;
        // Recursively traverse the left subtree
        displayPreOrder(nodePtr->left);
        // Recursively traverse the right subtree
        displayPreOrder(nodePtr->right);
    }
}

// Displays the tree post-order (left subtree, right subtree, current node)
template <typename T>
void BinaryTree<T>::displayPostOrder(TreeNode *nodePtr) const
{
    if (nodePtr)
    {
        // Recursively traverse the left subtree
        displayPostOrder(nodePtr->left);
        // Recursively traverse the right subtree
        displayPostOrder(nodePtr->right);
        // Print the current node's value last
        std::cout << nodePtr->value << std::endl;
    }
}

// Searches for a value in the tree; returns true if found, false otherwise
template <typename T>
bool BinaryTree<T>::searchNode(T value) const
{
    TreeNode *nodePtr = root;
    // Traverse the tree until the value is found or we reach a null node
    while (nodePtr)
    {
        if (nodePtr->value == value)
            return true; // Value found
        else if (nodePtr->value < value)
            nodePtr = nodePtr->right; // Search right subtree
        else
            nodePtr = nodePtr->left; // Search left subtree
    }
    return false; // Value not found
}

// Removes a node with the given value from the tree
template <typename T>
void BinaryTree<T>::remove(T val)
{
    deleteNode(root, val);
}

// Recursive helper method to find and delete a node with the given value
template <typename T>
void BinaryTree<T>::deleteNode(TreeNode *&nodePtr, T val)
{
    // If the current node is null, nothing to delete
    if (nodePtr == nullptr)
        std::cout << "Cannot delete empty node." << std::endl;
    // If the value is greater, search the right subtree
    else if (nodePtr->value < val)
        deleteNode(nodePtr->right, val);
    // If the value is smaller, search the left subtree
    else if (nodePtr->value > val)
        deleteNode(nodePtr->left, val);
    // If the value matches, perform the deletion
    else
        makeDeletion(nodePtr);
}

// Handles the deletion of a node, adjusting the tree structure
template <typename T>
void BinaryTree<T>::makeDeletion(TreeNode *&nodePtr)
{
    TreeNode *tempNodePtr = nullptr; // Temporary pointer for node to be deleted

    // If the node is null (shouldn't happen, but check for safety)
    if (nodePtr == nullptr)
    {
        std::cout << "Cannot delete empty node." << std::endl;
    }
    // Case 1: Node has no left child; replace with right child
    else if (nodePtr->left == nullptr)
    {
        tempNodePtr = nodePtr;
        nodePtr = nodePtr->right;
        delete tempNodePtr;
    }
    // Case 2: Node has no right child; replace with left child
    else if (nodePtr->right == nullptr)
    {
        tempNodePtr = nodePtr;
        nodePtr = nodePtr->left;
        delete tempNodePtr;
    }
    // Case 3: Node has two children; replace with the smallest value in the right subtree
    else
    {
        tempNodePtr = nodePtr->right;
        // Find the leftmost node in the right subtree (smallest value)
        while (tempNodePtr->left)
            tempNodePtr = tempNodePtr->left;
        // Attach the left subtree of the node being deleted to the leftmost node
        tempNodePtr->left = nodePtr->left;
        tempNodePtr = nodePtr;
        // Replace the node with its right subtree
        nodePtr = tempNodePtr->right;
        delete tempNodePtr;
    }
}

// Recursively destroys a subtree by deleting all its nodes
template <typename T>
void BinaryTree<T>::destroySubtree(TreeNode *nodePtr)
{
    if (nodePtr)
    {
        // Recursively delete the left subtree
        if (nodePtr->left)
            destroySubtree(nodePtr->left);
        // Recursively delete the right subtree
        if (nodePtr->right)
            destroySubtree(nodePtr->right);
        // Delete the current node
        delete nodePtr;
    }
}

// Copy assignment operator
template <typename T>
BinaryTree<T> &BinaryTree<T>::operator=(const BinaryTree<T> &binaryTree)
{
    std::cout<< "Copy assignment operator invoked!" << std::endl;
    // Self-assignment check
    if (this == &binaryTree)
        return *this;

    // Clean up existing tree
    destroySubtree(root);

    // Deep copy helper function
    std::function<TreeNode *(TreeNode *)> copyTree = [&](TreeNode *nodePtr) -> TreeNode *
    {
        if (nodePtr)
        {
            TreeNode *newNode = new TreeNode;
            newNode->value = nodePtr->value;
            newNode->left = copyTree(nodePtr->left);
            newNode->right = copyTree(nodePtr->right);
            return newNode;
        }
        return nullptr;
    };

    // Copy the source tree
    root = copyTree(binaryTree.root);
    return *this;
}

// Move constructor
template <typename T>
BinaryTree<T>::BinaryTree(BinaryTree<T> &&binaryTree)
{
    std::cout<< "Move constructor invoked!" << std::endl;
    // Transfer ownership of root
    root = binaryTree.root;
    binaryTree.root = nullptr; // Leave source in valid state
}

// Copy constructor
template <typename T>
BinaryTree<T>::BinaryTree(const BinaryTree<T> &binaryTree)
{
    std::cout<< "Copy constructor invoked!" << std::endl;
    // Deep copy helper function
    std::function<TreeNode *(TreeNode *)> copyTree = [&](TreeNode *nodePtr) -> TreeNode *
    {
        if (nodePtr != nullptr)
        {
            TreeNode *newNode = new TreeNode;
            newNode->value = nodePtr->value;
            newNode->left = copyTree(nodePtr->left);
            newNode->right = copyTree(nodePtr->right);
            return newNode;
        }
        
        return nullptr;
    };

    // Create deep copy of source tree
    root = copyTree(binaryTree.root);
}

// Move assignment operator (uses swap trick).
// Efficiently transfers ownership by swapping root pointers.
// After the swap, this object owns the rvalue's tree, and the rvalue
// owns the old tree, which will be destroyed when it goes out of scope.
template<typename T>
BinaryTree<T>& BinaryTree<T>::operator=(BinaryTree<T>&& binaryTree)
{
    std::cout << "Move assignment operator invoked!" << std::endl;
    std::swap(root, binaryTree.root);
    return *this;
}
#endif