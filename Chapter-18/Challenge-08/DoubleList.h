/**
 * @file DoubleList.h
 * @brief Simple templated doubly-linked list.
 *
 * Minimal example providing insert, append, delete, search and display.
 * Intended for learning; not production-hardened.
 */
#ifndef DOUBLELIST_H
#define DOUBLELIST_H

#include <iostream>

/**
 * @tparam T element type
 * @class DoubleList
 * @brief Templated doubly-linked list.
 *
 * - insert/delete positions: 1-based.
 * - listSearch(): 0-based index, returns -1 if not found.
 * - displayList requires operator<< for T.
 */
template<typename T>
class DoubleList
{
private:
    /**
     * @struct DoubleListNode
         * @brief Internal node storing a T value.
     */
    struct DoubleListNode
    {
        T data;                /**< stored value */
        DoubleListNode *next;    /**< next node (nullptr at end) */
        DoubleListNode *prev;    /**< previous node (nullptr at head) */

        /**
         * Constructor
         * @param value Value to store
         * @param nextNode Next pointer (default nullptr)
         * @param prevNode Prev pointer (default nullptr)
         */
        DoubleListNode(const T& value, DoubleListNode *nextNode = nullptr, DoubleListNode *prevNode = nullptr)
        {
            data = value;
            next = nextNode;
            prev = prevNode;
        }
    };

    DoubleListNode *head; /**< first node or nullptr */
    DoubleListNode *tail; /**< last node or nullptr */

public:
    /**
     * @brief Create empty list
     */
    DoubleList()
    {
        head = nullptr;
        tail = nullptr;
    }

    /**
     * @brief Copy constructor (deep copy)
     */
    DoubleList(const DoubleList &obj)
    {
        head = nullptr;
        tail = nullptr;
        DoubleListNode *node = obj.head;
        DoubleListNode *last = nullptr;
        while (node != nullptr)
        {
            if (head == nullptr)
                head = last = new DoubleListNode(node->data);
            else
            {
                last->next = new DoubleListNode(node->data, nullptr, last);
                last = last->next;
            }
            node = node->next;
        }
        tail = last;
    }

    /**
     * @brief Insert value at the front
     * @param value value to insert
     * @note Indexing: N/A (front insertion)
     */
    void insertFirst(const T& value)
    {
        if (isEmpty())
            head = tail = new DoubleListNode(value);
        else
        {
            DoubleListNode *newNode = new DoubleListNode(value, head);
            head->prev = newNode;
            head = newNode;
        }
    }

    /**
     * @brief Append value at the end
     * @param value value to append
     * @note Indexing: N/A (end insertion)
     */
    void append(const T& value)
    {
        if (isEmpty())
            head = tail = new DoubleListNode(value);
        else
        {
            tail->next = new DoubleListNode(value, nullptr, tail);
            tail = tail->next;
        }
    }

    /**
     * @brief Insert value at a 1-based position
     * @param value value to insert
     * @param position 1-based position where to insert (1 == front)
     * @return true on success, false if position invalid
     * @note Indexing: 1-based
     */
    bool insert(const T& value, int position)
    {
        if (position < 1)
        {
            std::cout << "No such position." << std::endl;
            return false;
        }
        else if (position == 1)
        {
            insertFirst(value);
        }
        else
        {
            DoubleListNode *current = head;
            for (int i = 2; i < position; i++)
            {
                if (current != nullptr)
                    current = current->next;
            }

            if (current != nullptr)
            {
                if (current->next != nullptr)
                {
                    DoubleListNode *newNode = new DoubleListNode(value, current->next, current);
                    current->next->prev = newNode;
                    current->next = newNode;
                }
                else
                    append(value);
            }
            else
            {
                std::cout << "No such position." << std::endl;
                return false;
            }
        }
        return true;
    }

    /**
     * @brief Delete the first node
     * @return true on success, false if list empty
     * @note Indexing: N/A
     */
    bool deleteFirst()
    {
        if (isEmpty())
        {
            std::cout << "Linked list is already empty." << std::endl;
            return false;
        }

        DoubleListNode *nodeToDelete = head;
        if (head == tail)
        {
            head = tail = nullptr;
        }
        else
        {
            head = head->next;
            head->prev = nullptr;
        }
        delete nodeToDelete;
        return true;
    }

    /**
     * @brief Delete the last node
     * @return true on success, false if list empty
     * @note Indexing: N/A
     */
    bool deleteLast()
    {
        if (isEmpty())
        {
            std::cout << "Linked list is already empty." << std::endl;
            return false;
        }

        DoubleListNode *nodeToDelete = tail;
        if (head == tail)
        {
            head = tail = nullptr;
        }
        else
        {
            tail = tail->prev;
            tail->next = nullptr;
        }
        delete nodeToDelete;
        return true;
    }

    /**
     * @brief Delete node at 1-based position
     * @param position 1-based position to delete (1 == first)
     * @return true on success, false if position invalid or list empty
     * @note Indexing: 1-based
     */
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
                deleteFirst();
            }
            else
            {
                DoubleListNode *current = head;
                for (int i = 2; i < position; i++)
                {
                    if (current == nullptr)
                        break;
                    current = current->next;
                }

                if (current != nullptr && current->next != nullptr)
                {
                    DoubleListNode *nodeToDelete = current->next;
                    current->next = nodeToDelete->next;
                    if (nodeToDelete->next != nullptr)
                    {
                        nodeToDelete->next->prev = current;
                    }
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

    /**
     * @brief Check whether the list is empty
     * @return true if empty
     * @note Indexing: N/A
     */
    bool isEmpty()
    {
        return head == nullptr;
    }

    /**
     * @brief Print list content to stdout
     * @note Indexing: N/A
     */
    void displayList()
    {
        DoubleListNode *current = head;
        while (current != nullptr)
        {
            std::cout << current->data;
            if (current != nullptr && current->next != nullptr)
                std::cout << " -> ";
            current = current->next;
        }
        std::cout << std::endl;
    }

    /**
     * @brief Destroy list and free nodes
     */
    ~DoubleList()
    {
        while (!isEmpty())
            deleteNode(1);
    }

    /**
     * @brief Search for value and return 0-based index
     * @param value value to search
     * @return 0-based index if found, -1 otherwise
     * @note Indexing: 0-based
     */
    int listSearch(const T& value)
    {
        DoubleListNode *currNode = head;
        int position = 0;
        while (currNode != nullptr)
        {
            if (currNode->data == value)
                return position;

            currNode = currNode->next;
            position++;
        }
        return -1;
    }
};
#endif