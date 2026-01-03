#ifndef QUEUE_H
#define QUEUE_H
#include <iostream>
using namespace std;

/**
 * @brief A templated queue data structure implemented using a linked list
 * @tparam T The type of elements stored in the queue
 */
template<typename T>
class Queue
{
private:
    /**
     * @brief Internal node structure for the linked list
     */
    class QueueNode
    {
    public:
        T data;              ///< The data stored in the node
        QueueNode* next;     ///< Pointer to the next node
        
        /**
         * @brief Constructor for QueueNode
         * @param value The value to store in the node
         */
        QueueNode(T value)
        {
            data = value;
            next = nullptr;
        }
    };
    
    QueueNode* front;   ///< Pointer to the front of the queue
    QueueNode* rear;    ///< Pointer to the rear of the queue
    int numItems;       ///< Number of items in the queue
    
public:
    /**
     * @brief Default constructor - creates an empty queue
     */
    Queue()
    {
        front = rear = nullptr;
        numItems = 0;
    }
    
    /**
     * @brief Destructor - deallocates all nodes in the queue
     */
    ~Queue();
    
    /**
     * @brief Copy constructor - creates a deep copy of another queue
     * @param obj The queue to copy
     */
    Queue(const Queue& obj);
    
    /**
     * @brief Adds an element to the rear of the queue
     * @param value The value to add
     */
    void enqueue(T value);
    
    /**
     * @brief Removes an element from the front of the queue
     * @param variable Reference variable to store the dequeued value
     */
    void dequeue(T& variable);
    
    /**
     * @brief Checks if the queue is empty
     * @return true if the queue is empty, false otherwise
     */
    bool isEmpty();
};

template<typename T>
bool Queue<T>::isEmpty()
{
    if (numItems == 0)
        return true;
    else 
        return false;
}

template<typename T>
void Queue<T>::enqueue(T value)
{
    QueueNode* newNode = new QueueNode(value);
    if (isEmpty())
        front = rear = newNode;
    else 
    {
        rear->next = newNode;
        rear = newNode;
    }
    numItems++;
}

template<typename T>
void Queue<T>::dequeue(T& variable)
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
    }
}

template<typename T>
Queue<T>::~Queue()
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
Queue<T>::Queue(const Queue& obj)
{
    front = rear = nullptr;
    numItems = 0;
    QueueNode* temp = obj.front;
    while (temp != nullptr)
    {
        enqueue(temp->data);
        temp = temp->next;
    }
}
#endif