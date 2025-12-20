#ifndef NUMBERLIST_H
#define NUMBERLIST_H

/**
 * @brief A singly linked list class for managing double values
 */
class NumberList {
private:
    /**
     * @brief Node structure containing a value and pointer to next node
     */
    struct ListNode {
        double value;           ///< The numeric value stored in this node
        struct ListNode *next;  ///< Pointer to the next node
    };
    
    ListNode *head;  ///< Pointer to the first node in the list

public:
    /**
     * @brief Constructor - initializes an empty list
     */
    NumberList() { head = nullptr; }
    
    /**
     * @brief Destructor - deallocates all nodes
     */
    ~NumberList();
    
    /**
     * @brief Appends a new node to the end of the list
     * @param num The value to append
     */
    void appendNode(double num);
    
    /**
     * @brief Inserts a new node in sorted order
     * @param num The value to insert
     */
    void insertNode(double num);
    
    /**
     * @brief Deletes the first node with the specified value
     * @param num The value to delete
     */
    void deleteNode(double num);
    
    /**
     * @brief Displays all values in the list
     */
    void displayList() const;
    
    /**
     * @brief Recursively finds the maximum value starting from given node
     * @param ptr Pointer to the current node
     * @return The maximum value found
     */
    double maxNode(ListNode* ptr);
    
    /**
     * @brief Finds the maximum value in the list
     * @return The maximum value
     */
    double maxNode() { return maxNode(head); }
};

#endif