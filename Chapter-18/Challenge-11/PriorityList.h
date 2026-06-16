#ifndef PRIORITYLIST_H
#define PRIORITYLIST_H
#include <iostream>

/**
 * @file PriorityList.h
 * @brief Minimal singly-linked priority list.
 *
 * Nodes are ordered by ascending priority (lower value = higher priority).
 */

class PriorityList
{
private:
    /**
     * @brief Node for PriorityList
     */
    struct PriorityListNode
    {
        int data;               /**< stored value */
        int nodePriority;       /**< priority (lower == higher priority) */
        PriorityListNode *next; /**< pointer to next node */

        PriorityListNode(int data, int nodePriority, PriorityListNode *next = nullptr)
            : data(data), nodePriority(nodePriority), next(next)
        {
        }
    };

    PriorityListNode *head; /**< head of the list */

public:
    /** @brief Construct an empty PriorityList */
    PriorityList() : head(nullptr) {}

    /**
     * @brief Insert a node preserving ascending priority order.
     * @param data value to store
     * @param priority node priority (lower values come before higher)
     */
    void addNode(int data, int priority)
    {
        if (head == nullptr)
        {
            head = new PriorityListNode(data, priority);
            return;
        }

        if (head->nodePriority > priority)
        {
            head = new PriorityListNode(data, priority, head);
            return;
        }

        PriorityListNode *current = head;
        while (current->next != nullptr && current->next->nodePriority <= priority)
        {
            current = current->next;
        }

        current->next = new PriorityListNode(data, priority, current->next);
    }

    /** @brief Print stored data values (data only) */
    void displayList()
    {
        PriorityListNode *current = head;
        while (current != nullptr)
        {
            std::cout << current->data;
            if (current->next != nullptr)
                std::cout << "->";
            current = current->next;
        }
        std::cout << std::endl;
    }

    /** @brief Free nodes */
    ~PriorityList()
    {
        while (head != nullptr)
        {
            PriorityListNode *temp = head;
            head = head->next;
            delete temp;
        }
    }
};

#endif