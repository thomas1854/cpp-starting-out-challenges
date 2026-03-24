#ifndef QUEUE_H
#define QUEUE_H
#include <iostream>
#include <new>
using namespace std;

/**
 * @brief A double-ended queue (deque) implementation using a doubly linked list.
 * This class allows efficient insertion and deletion from both ends.
 */
template<typename T>
class DoubleEndedQueue
{
private:
    /**
     * @brief Node structure for the doubly linked list.
     */
    class QueueNode
    {
    public:
        T data;              /**< The data stored in the node. */
        QueueNode* next;     /**< Pointer to the next node. */
        QueueNode* prev;     /**< Pointer to the previous node. */
        
        /**
         * @brief Constructor for QueueNode.
         * @param value The value to store in the node.
         */
        QueueNode(T value)
        {
            data = value;
            prev = nullptr;
            next = nullptr;
        }
    };
    
    QueueNode* front;   /**< Pointer to the front of the deque. */
    QueueNode* rear;    /**< Pointer to the rear of the deque. */
    int numItems;       /**< Number of items in the deque. */
    
public:
    /**
     * @brief Default constructor.
     */
    DoubleEndedQueue()
    {
        front = rear = nullptr;
        numItems = 0;
    }
    
    /**
     * @brief Destructor.
     */
    ~DoubleEndedQueue();
    
    /**
     * @brief Copy constructor.
     * @param obj The deque to copy from.
     */
    DoubleEndedQueue(const DoubleEndedQueue<T>& obj);
    
    /**
     * @brief Inserts an element at the rear of the deque.
     * @param value The value to insert.
     * @return True if insertion was successful, false if memory allocation failed.
     */
    bool insert_rear(T value);
    
    /**
     * @brief Removes and returns the element from the front of the deque.
     * @param variable Reference to store the removed value.
     */
    void delete_front(T& variable);

    /**
     * @brief Inserts an element at the front of the deque.
     * @param value The value to insert.
     * @return True if insertion was successful, false if memory allocation failed.
     */
    bool insert_front(T value);
    
    /**
     * @brief Removes and returns the element from the rear of the deque.
     * @param variable Reference to store the removed value.
     */
    void delete_rear(T& variable);

    /**
     * @brief Checks if the deque is empty.
     * @return True if empty, false otherwise.
     */
    bool isEmpty();
};

template<typename T>
/**
 * @brief Checks if the deque is empty.
 */
bool DoubleEndedQueue<T>::isEmpty()
{
    if (numItems == 0)
        return true;
    else 
        return false;
}

template<typename T>
/**
 * @brief Inserts an element at the rear of the deque.
 */
bool DoubleEndedQueue<T>::insert_rear(T value)
{
    try
    {
        QueueNode* newNode = new QueueNode(value);
        if (isEmpty())
            front = rear = newNode;
        else 
        {
            newNode->prev = rear;
            rear->next = newNode;
            rear = newNode;
        }
        numItems++;
        return true;
    }
    catch(const std::bad_alloc& e)
    {
        cerr << "ERROR: Memory allocation failed in insertion operation - " << e.what() << endl;
        return false;
    }
}

template<typename T>
/**
 * @brief Inserts an element at the front of the deque.
 */
bool DoubleEndedQueue<T>::insert_front(T value)
{
    try
    {
        QueueNode* newNode = new QueueNode(value);
        if (isEmpty())
            front = rear = newNode;
        else 
        {
            QueueNode* previousFirstNode = front;
            front = newNode;
            newNode->next = previousFirstNode;
            previousFirstNode->prev = newNode;
        }
        numItems++;
        return true;
    }
    catch(const std::bad_alloc& e)
    {
        cerr << "ERROR: Memory allocation failed in insertion operation - " << e.what() << endl;
        return false;
    }
}

template<typename T>
/**
 * @brief Removes and returns the element from the front of the deque.
 */
void DoubleEndedQueue<T>::delete_front(T& variable)
{
    if (isEmpty()) 
        cout << "The queue is empty." << endl;
    else 
    {
        variable = front->data;
        QueueNode* temp = front;
        front = front->next;
        delete temp;
        numItems--;
        temp = nullptr;
        if (front == nullptr)
            rear = nullptr;
        else 
            front->prev = nullptr;
    }
}

template<typename T>
/**
 * @brief Removes and returns the element from the rear of the deque.
 */
void DoubleEndedQueue<T>::delete_rear(T& variable)
{
    if (isEmpty()) 
        cout << "The queue is empty." << endl;
    else 
    {
        variable = rear->data;
        QueueNode* temp = rear;
        rear = rear->prev;
        delete temp;
        numItems--;
        temp = nullptr;
        if (rear == nullptr)
            front = nullptr;
        else 
            rear->next = nullptr;
    }
}

template<typename T>
/**
 * @brief Destructor that cleans up all nodes.
 */
DoubleEndedQueue<T>::~DoubleEndedQueue()
{
    while (front != nullptr)
    {
        QueueNode* temp = front;
        front = front->next;
        delete temp;
        temp = nullptr;
    }
    rear = nullptr;
}

template<typename T>
/**
 * @brief Copy constructor that creates a deep copy of the deque.
 */
DoubleEndedQueue<T>::DoubleEndedQueue(const DoubleEndedQueue<T>& obj)
{
    front = rear = nullptr;
    numItems = 0;
    QueueNode* temp = obj.front;
    while (temp != nullptr)
    {
        insert_rear(temp->data);
        temp = temp->next;
    }
}
#endif