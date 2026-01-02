#ifndef QUEUE_H
#define QUEUE_H
#include <iostream>
using namespace std;

/**
 * @brief A circular queue implementation using a dynamic array.
 * @tparam T The type of elements stored in the queue.
 */
template<typename T>
class Queue
{
private:
    T *queueArray;      ///< Dynamic array holding queue elements
    int front;          ///< Index of the front element
    int rear;           ///< Index of the rear element
    int numItems;       ///< Current number of items in the queue
    int size;           ///< Maximum capacity of the queue

public:
    /**
     * @brief Constructs a queue with specified capacity.
     * @param sizeParameter Maximum number of elements the queue can hold.
     */
    Queue(int sizeParameter)
    {
        size = sizeParameter;
        front = -1;
        rear = -1;
        numItems = 0;
        queueArray = new T[size];
    }

    /**
     * @brief Copy constructor - creates a deep copy of another queue.
     * @param obj The queue to copy from.
     */
    Queue(const Queue &obj);
    
    /**
     * @brief Destructor - deallocates dynamic memory.
     */
    ~Queue()
    {
        delete[] queueArray;
    }
    
    /**
     * @brief Adds an element to the rear of the queue.
     * @param value The element to enqueue.
     */
    void enqueue(T value);
    
    /**
     * @brief Removes and retrieves the front element.
     * @param variable Reference to store the dequeued element.
     */
    void dequeue(T &variable);
    
    /**
     * @brief Checks if the queue is full.
     * @return True if queue is at capacity, false otherwise.
     */
    bool isFull();
    
    /**
     * @brief Checks if the queue is empty.
     * @return True if queue has no elements, false otherwise.
     */
    bool isEmpty();
};

template<typename T>
Queue<T>::Queue(const Queue &obj)
{
    size = obj.size;
    front = obj.front;
    rear = obj.rear;
    numItems = obj.numItems;
    queueArray = new T[size];
    for (int i = 0; i < size; i++)
        queueArray[i] = obj.queueArray[i];
}
template<typename T>
void Queue<T>::enqueue(T value)
{
    if (isFull())
        cout << "The queue is full." << endl;
    else
    {
        rear = (rear + 1) % size;
        queueArray[rear] = value;
        numItems++;
    }
}
template<typename T>
void Queue<T>::dequeue(T &variable)
{
    if (isEmpty())
        cout << "The queue is empty." << endl;
    else
    {
        front = (front + 1) % size;
        variable = queueArray[front];
        numItems--;
    }
}
template<typename T>
bool Queue<T>::isFull()
{
    if (numItems == size)
        return true;
    else
        return false;
}
template<typename T>
bool Queue<T>::isEmpty()
{
    if (numItems == 0)
        return true;
    else
        return false;
}
#endif