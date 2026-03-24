#ifndef QUEUE_H
#define QUEUE_H
#include <iostream>
#include <new>
using namespace std;

template<typename T>
class DoubleEndedQueue
{
private:
    class QueueNode
    {
    public:
        T data;              
        QueueNode* next;     
        QueueNode* prev;     
        
        QueueNode(T value)
        {
            data = value;
            prev = nullptr;
            next = nullptr;
        }
    };
    
    QueueNode* front;   
    QueueNode* rear;    
    int numItems;       
    
public:
    DoubleEndedQueue()
    {
        front = rear = nullptr;
        numItems = 0;
    }
    
    ~DoubleEndedQueue();
    
    DoubleEndedQueue(const DoubleEndedQueue<T>& obj);
    
    bool insert_rear(T value);
    void delete_front(T& variable);

    bool insert_front(T value);
    void delete_rear(T& variable);

    bool isEmpty();
};

template<typename T>
bool DoubleEndedQueue<T>::isEmpty()
{
    if (numItems == 0)
        return true;
    else 
        return false;
}

template<typename T>
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