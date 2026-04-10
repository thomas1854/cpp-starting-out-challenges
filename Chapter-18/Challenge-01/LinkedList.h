#ifndef LINKEDLIST_H
#define LINKEDLIST_H

/**
 * @file LinkedList.h
 * @brief Simple singly-linked list implementation for educational use.
 */

#include <iostream>

/**
 * @class LinkedList
 * @brief Singly-linked list storing integer values.
 *
 * Supports append, insert, delete, isEmpty, and destructor cleanup.
 */
class LinkedList
{
private:
    /**
     * @struct ListNode
     * @brief Node container for LinkedList.
     */
    struct ListNode
    {
        int data;       ///< value stored in node
        ListNode *next; ///< pointer to next node

        /**
         * @brief Construct a ListNode.
         * @param value node value
         * @param nextNode next node pointer (default nullptr)
         */
        ListNode(int value, ListNode *nextNode = nullptr)
        {
            data = value;
            next = nextNode;
        }
    };

    ListNode *head; ///< pointer to first list node

public:
    /**
     * @brief Construct an empty LinkedList.
     */
    LinkedList()
    {
        head = nullptr;
    }

    /**
     * @brief Constructs the list with the content of another list
     */
    LinkedList(const LinkedList& obj)
    {
        head = nullptr;  
        ListNode* node = obj.head;
        ListNode* last = nullptr;
        while (node != nullptr)
        {
            if (head == nullptr)
                head = last = new ListNode(node->data);
            else 
            {
                last->next = new ListNode(node->data);
                last = last->next;
            }
            node = node->next;
        }
    }

    void append(int value)
    {
        if (isEmpty())
            head = new ListNode(value);
        else
        {
            ListNode *current = head;
            while (current->next != nullptr)
                current = current->next;
            current->next = new ListNode(value);
        }
    }

    bool insert(int value, int position)
    {
        if (position < 1)
        {
            std::cout << "No such position." << std::endl;
            return false;
        }
        else if (position == 1)
        {
            head = new ListNode(value, head);
        }
        else
        {
            ListNode *current = head;
            for (int i = 2; i < position; i++)
            {
                if (current != nullptr)
                    current = current->next;
            }

            if (current != nullptr)
            {
                ListNode *newNode = new ListNode(value, current->next);
                current->next = newNode;
            }
            else
            {
                std::cout << "No such position." << std::endl;
                return false;
            }
        }
        return true;
    }

    bool deleteNode(int position)
    {
        if (isEmpty())
        {
            std::cout << "Linked list is already empty." << std::endl;
            return false;
        }
        else
        {
            if (position < 1)
            {
                std::cout << "No such position." << std::endl;
                return false;
            }
            else if (position == 1)
            {
                ListNode *nodeToDelete = head;
                head = head->next;
                delete nodeToDelete;
            }
            else
            {
                ListNode *current = head;
                for (int i = 2; i < position; i++)
                {
                    if (current == nullptr)
                        break;
                    current = current->next;
                }

                if (current != nullptr && current->next != nullptr)
                {
                    ListNode *nodeToDelete = current->next;
                    current->next = current->next->next;
                    delete nodeToDelete;
                }
                else
                {
                    std::cout << "No such position." << std::endl;
                    return false;
                }
            }
        }

        return true;
    }

    bool isEmpty()
    {
        return head == nullptr;
    }

    void displayList()
    {
        ListNode* current = head;
        while(current != nullptr)
        {
            std::cout << current->data;
            if (current != nullptr && current->next != nullptr)
                std::cout << " -> ";
            current = current->next;
        }
        std::cout << std::endl;
    }

    ~LinkedList()
    {
        while (!isEmpty())
            deleteNode(1);
    }

    void reverseList()
    {
        ListNode* current = head;
        ListNode* previous = nullptr;
        while (current != nullptr)
        {
            ListNode* nextNode = current->next;
            current->next = previous;
            previous = current;
            current = nextNode;
        }
        head = previous;
    }
};
#endif