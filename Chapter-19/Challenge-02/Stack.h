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
    int stackSize;        ///< Size of the stack
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
        stackSize = 0;
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
     * @return returns true if an elemente pushed successfully, false otherwise
     */
    bool push(T item);
    
    /**
     * @brief Pops an item from the stack
     * @param item Reference to store the popped value
     * @note Prints error message if stack is empty
     * @return Returns true if the value popped successfully, false otherwise
     */
    bool pop(T& item);
    
    /**
     * @brief Return the size of the stack
     * @return Number of elements currently stored in the stack
     */
    int size()
    { return stackSize; }

    /**
     * @brief Return the top value of the stack without removing it
     * @returns Top value of the stack
     */
    T peek()
    { return top->value; }


    /**
     * @brief Destroys the stack and frees all memory
     */
    ~Stack();
};

template<typename T>
bool Stack<T>::push(T item)
{
    try
    {
        StackNode* newNode = new StackNode(item);
        if (isEmpty())
            top = newNode;
        else 
        {
            newNode->next = top;
            top = newNode;
        }
        stackSize++;
        return true;
    }
    catch(const std::bad_alloc& e)
    {
        cerr << "ERROR: Memory allocation failed in push operation - " << e.what() << endl;
        return false;
    }
}

template<typename T>
bool Stack<T>::pop(T& item)
{
    if (isEmpty())
    {
        cout << "The stack is empty." << endl;
        return false;
    }
    else 
    {
        item = top->value;
        StackNode* temp = top;
        top = top->next;
        delete temp;
        stackSize--;
        return true;
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
    stackSize = obj.stackSize;
    copyStack(obj.top);
}
#endif