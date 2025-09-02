#pragma once
#ifndef BINARYTREE_H
#define BINARYTREE_H
#include <iostream>

// Template class for a Binary Search Tree (BST) that can store values of any type T
template<typename T>
class BinaryTree
{
private:
    // Counter to track the total number of nodes in the BinaryTree.
    // Incremented on node insertion and decremented on node deletion.
    int nodesCounter = 0;

    // Counter to track the number of leaf (terminal) nodes in the BinaryTree.
    // Update this when leaf nodes are created or removed.
    int leafNodeCounter = 0;

    // Inner struct representing a node in the binary tree
    struct TreeNode
    {
        T value;           // The value stored in the node
        TreeNode* left;    // Pointer to the left child node
        TreeNode* right;   // Pointer to the right child node
    };

    TreeNode* root;        // Pointer to the root node of the tree

    // Private helper methods for recursive operations
    void insert(TreeNode*&, TreeNode*&);          // Inserts a new node into the tree
    void makeDeletion(TreeNode*&);                // Handles the deletion of a node
    void displayInOrder(TreeNode*) const;         // Displays nodes in-order (left, root, right)
    void displayPostOrder(TreeNode*) const;       // Displays nodes post-order (left, right, root)
    void displayPreOrder(TreeNode*) const;        // Displays nodes pre-order (root, left, right)
    void destroySubtree(TreeNode*);               // Recursively deletes all nodes in a subtree
    void deleteNode(TreeNode*&, T);               // Finds and deletes a node with a given value

public:
    // Constructor: Initializes an empty tree
    BinaryTree()
    {
        root = nullptr;
    }

    // Destructor: Frees all nodes in the tree
    ~BinaryTree()
    {
        destroySubtree(root);
    }

    // Public methods for tree operations
    void insertNode(T);                // Inserts a new value into the tree
    void remove(T);                    // Removes a value from the tree
    bool searchNode(T) const;          // Searches for a value in the tree

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

    // Returns the total number of nodes in the tree
    int getNodesCount() const;

    // Returns the total number of leaf nodes in the tree
    int getLeafNodesCount() const;
};

// Inserts a new node with the given value into the tree
template<typename T>
void BinaryTree<T>::insertNode(T val)
{
    // Create a new node with the provided value
    TreeNode* newNode = new TreeNode;
    newNode->left = nullptr;
    newNode->right = nullptr;
    newNode->value = val;

    // Insert the new node into the tree starting from the root
    insert(root, newNode);
    nodesCounter++; // Increment counter when a new node is inserted
    leafNodeCounter++; // New nodes are created as leaves — increment leaf-node count (adjust elsewhere if an existing leaf becomes internal).
}

// Recursive helper method to insert a new node into the tree
template<typename T>
void BinaryTree<T>::insert(TreeNode*& nodePtr, TreeNode*& newNode)
{
    // If nodePtr is non-null and currently a leaf (both children are null),
    // attaching newNode as a child will make nodePtr internal — decrement the leaf counter.
    if (nodePtr && nodePtr->left == nullptr && nodePtr->right == nullptr)
        leafNodeCounter--;

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
template<typename T>
void BinaryTree<T>::displayInOrder(TreeNode* nodePtr) const
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
template<typename T>
void BinaryTree<T>::displayPreOrder(TreeNode* nodePtr) const
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
template<typename T>
void BinaryTree<T>::displayPostOrder(TreeNode* nodePtr) const
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
template<typename T>
bool BinaryTree<T>::searchNode(T value) const
{
    TreeNode* nodePtr = root;
    // Traverse the tree until the value is found or we reach a null node
    while (nodePtr)
    {
        if (nodePtr->value == value)
            return true; // Value found
        else if (nodePtr->value < value)
            nodePtr = nodePtr->right; // Search right subtree
        else
            nodePtr = nodePtr->left;  // Search left subtree
    }
    return false; // Value not found
}

// Removes a node with the given value from the tree
template<typename T>
void BinaryTree<T>::remove(T val)
{
    deleteNode(root, val);
}

// Recursive helper method to find and delete a node with the given value
template<typename T>
void BinaryTree<T>::deleteNode(TreeNode*& nodePtr, T val)
{
    // If nodePtr is the parent of the node to delete, pre-adjust the leaf counter:
    // deleting a child that is currently a leaf can make the parent become a leaf
    // (when the parent has no other child). Detect those cases and increment
    // leafNodeCounter so the count stays correct after removal.
    if (nodePtr != nullptr && nodePtr->right != nullptr && nodePtr->right->value == val)
    {
        // Right child matches the value-to-delete. If that right child is a leaf
        // and the parent has no left child, the parent will become a leaf after
        // the right child is removed — increment the leaf counter.
        if (nodePtr->right->left == nullptr && nodePtr->right->right == nullptr && nodePtr->left == nullptr)
            leafNodeCounter++;
    }
    else if (nodePtr != nullptr && nodePtr->left != nullptr && nodePtr->left->value == val)
    {
        // Left child matches the value-to-delete. If that left child is a leaf
        // and the parent has no right child, the parent will become a leaf after
        // the left child is removed — increment the leaf counter.
        if (nodePtr->left->left == nullptr && nodePtr->left->right == nullptr && nodePtr->right == nullptr)
            leafNodeCounter++;
    }

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
    {
        // If nodePtr has no children it's a leaf — decrement the leaf-node counter
        if (nodePtr->left == nullptr && nodePtr->right == nullptr) 
            leafNodeCounter--;
        makeDeletion(nodePtr);
    }
}

// Handles the deletion of a node, adjusting the tree structure
template<typename T>
void BinaryTree<T>::makeDeletion(TreeNode*& nodePtr)
{
    TreeNode* tempNodePtr = nullptr; // Temporary pointer for node to be deleted

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
        nodesCounter--; // Decrement counter when a node is deleted
    }
    // Case 2: Node has no right child; replace with left child
    else if (nodePtr->right == nullptr)
    {
        tempNodePtr = nodePtr;
        nodePtr = nodePtr->left;
        delete tempNodePtr;
        nodesCounter--; // Decrement counter when a node is deleted
    }
    // Case 3: Node has two children; replace with the smallest value in the right subtree
    else
    {
        tempNodePtr = nodePtr->right;
        // Find the leftmost node in the right subtree (smallest value)
        while (tempNodePtr->left)
            tempNodePtr = tempNodePtr->left;

        // If the successor has no right child it was previously a leaf.
        // Attaching the deleted node's left subtree to this successor makes it internal,
        // so decrement the leaf counter to keep leafNodeCounter accurate.
        if (tempNodePtr->right == nullptr)
            leafNodeCounter--;

        // Attach the left subtree of the node being deleted to the leftmost node
        tempNodePtr->left = nodePtr->left;
        tempNodePtr = nodePtr;
        // Replace the node with its right subtree
        nodePtr = tempNodePtr->right;
        delete tempNodePtr;
        nodesCounter--; // Decrement counter when a node is deleted
    }
}

// Recursively destroys a subtree by deleting all its nodes
template<typename T>
void BinaryTree<T>::destroySubtree(TreeNode* nodePtr)
{
    if (nodePtr)
    {
        // Record whether this node is a leaf before recursing (children will be deleted)
        bool wasLeaf = (nodePtr->left == nullptr && nodePtr->right == nullptr);

        // Recursively delete children
        if (nodePtr->left)
            destroySubtree(nodePtr->left);
        if (nodePtr->right)
            destroySubtree(nodePtr->right);

        // Adjust counters based on the original node state
        if (wasLeaf)
            leafNodeCounter--;
        nodesCounter--;

        // Delete this node
        delete nodePtr;
        nodePtr = nullptr;
    }
}

// Returns the total number of nodes in the tree
template<typename T>
int BinaryTree<T>::getNodesCount() const
{
    return nodesCounter;
}

// Returns the total number of leaf nodes in the tree
template<typename T>
int BinaryTree<T>::getLeafNodesCount() const
{
    return leafNodeCounter;
}
#endif