#include <iostream>
#include "NumberList.h"
using namespace std;

/**
 * @brief Appends a new node to the end of the list
 * @param num The value to append
 */
void NumberList::appendNode(double num)
{
    ListNode *newNode;
    ListNode *nodePtr;

    newNode = new ListNode;
    newNode->value = num;
    newNode->next = nullptr;

    if (!head)
        head = newNode;
    else
    {
        nodePtr = head;

        while (nodePtr->next)
            nodePtr = nodePtr->next;

        nodePtr->next = newNode;
    }
}

/**
 * @brief Displays all values in the list
 */
void NumberList::displayList() const
{
    ListNode *nodePtr;

    nodePtr = head;

    while (nodePtr)
    {
        cout << nodePtr->value << endl;

        nodePtr = nodePtr->next;
    }
}

/**
 * @brief Inserts a new node in sorted order
 * @param num The value to insert
 */
void NumberList::insertNode(double num)
{
    ListNode *newNode;
    ListNode *nodePtr;
    ListNode *previousNode = nullptr;

    newNode = new ListNode;
    newNode->value = num;

    if (!head)
    {
        head = newNode;
        newNode->next = nullptr;
    }
    else
    {
        nodePtr = head;

        previousNode = nullptr;

        while (nodePtr != nullptr && nodePtr->value < num)
        {
            previousNode = nodePtr;
            nodePtr = nodePtr->next;
        }

        if (previousNode == nullptr)
        {
            head = newNode;
            newNode->next = nodePtr;
        }
        else
        {
            previousNode->next = newNode;
            newNode->next = nodePtr;
        }
    }
}

/**
 * @brief Deletes the first node with the specified value
 * @param num The value to delete
 */
void NumberList::deleteNode(double num)
{
    ListNode *nodePtr;
    ListNode *previousNode;

    if (!head)
        return;

    if (head->value == num)
    {
        nodePtr = head->next;
        delete head;
        head = nodePtr;
    }
    else
    {
        nodePtr = head;

        while (nodePtr != nullptr && nodePtr->value != num)
        {
            previousNode = nodePtr;
            nodePtr = nodePtr->next;
        }

        if (nodePtr)
        {
            previousNode->next = nodePtr->next;
            delete nodePtr;
        }
    }
}

/**
 * @brief Destructor - deallocates all nodes in the list
 */
NumberList::~NumberList()
{
    ListNode *nodePtr;
    ListNode *nextNode;

    nodePtr = head;

    while (nodePtr != nullptr)
    {
        nextNode = nodePtr->next;

        delete nodePtr;

        nodePtr = nextNode;
    }
}

/**
 * @brief Recursively finds the maximum value starting from given node
 * @param listNode Pointer to the current node
 * @return The maximum value found from this node to the end of the list
 */
double NumberList::maxNode(ListNode *listNode)
{
    if (listNode->next != nullptr)
    {
        double maxNodeAfter = maxNode(listNode->next);
        if (listNode->value > maxNodeAfter)
            return listNode->value;
        else 
            return maxNodeAfter;
    }
    else 
        return listNode->value;
}