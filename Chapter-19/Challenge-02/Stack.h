/**
 * @file Stack.h
 * @brief Template-based stack implementation using a linked list
 */

#ifndef STACK_H
#define STACK_H
#include <iostream>
using namespace std;

/**
 * @brief A dynamic stack data structure implemented with linked nodes
 * @tparam T The type of elements stored in the stack
 */
template<typename T>
class Stack
{
private:
    /**
     * @brief Node structure for the linked list
     */
    struct StackNode
    {
        T value;              ///< Data stored in the node
        StackNode* next;      ///< Pointer to the next node
        
        /**
         * @brief Constructs a new node
         * @param item The value to store
         */
        StackNode(T item)
        {
            value = item;
            next = nullptr;
        }
    };
    
    StackNode* top;  ///< Pointer to the top of the stack
    /**
     * @brief Recursively copies nodes from another stack in correct order.
     * @param stackNode Pointer to the node to copy from the source stack.
     */
    void copyStack(StackNode* stackNode);
public:
    /**
     * @brief Constructs an empty stack
     */
    Stack()
    {
        top = nullptr;
    }
    
    /**
     * @brief Constructs a stack initialized with a copy of another stack object
     * @param obj is the stack object to be copied
     */
    Stack(const Stack& obj);

    /**
     * @brief Checks if the stack is empty
     * @return true if stack is empty, false otherwise
     */
    bool isEmpty();
    
    /**
     * @brief Pushes an item onto the stack
     * @param item The item to push
     */
    void push(T item);
    
    /**
     * @brief Pops an item from the stack
     * @param item Reference to store the popped value
     * @note Prints error message if stack is empty
     */
    void pop(T& item);
    
    /**
     * @brief Destroys the stack and frees all memory
     */
    ~Stack();
};

template<typename T>
void Stack<T>::push(T item)
{
    StackNode* newNode = new StackNode(item);
    if (isEmpty())
        top = newNode;
    else 
    {
        newNode->next = top;
        top = newNode;
    }
}

template<typename T>
void Stack<T>::pop(T& item)
{
    if (isEmpty())
        cout << "The stack is empty." << endl;
    else 
    {
        item = top->value;
        StackNode* temp = top;
        top = top->next;
        delete temp;
    }
}

template<typename T>
bool Stack<T>::isEmpty()
{
    if (top == nullptr)
        return true;
    else 
        return false;
}

template<typename T>
Stack<T>::~Stack()
{
    StackNode* nodePtr = top;
    StackNode* temp = nullptr;
    while (nodePtr != nullptr)
    {
        temp = nodePtr;
        nodePtr = nodePtr->next;
        delete temp;
    }
}

template<typename T>
void Stack<T>::copyStack(StackNode* const stackNode)
{
    if (stackNode == nullptr)
        return;
    copyStack(stackNode->next);
    push(stackNode->value);
}

template<typename T>
Stack<T>::Stack(const Stack& obj)
{
    top = nullptr;
    copyStack(obj.top);
}
#endif