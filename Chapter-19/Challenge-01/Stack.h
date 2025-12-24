#ifndef STACK_H
#define STACK_H
#include <iostream>
using namespace std;

/**
 * @brief A template-based stack implementation using dynamic arrays.
 * @tparam T The type of elements stored in the stack.
 */
template<typename T>
class Stack
{
private:
    T* stackArray;      ///< Dynamic array to store stack elements.
    int top;            ///< Index of the top element (-1 when empty).
    int stackSize;      ///< Maximum capacity of the stack.
    
public:    
    /**
     * @brief Constructs a stack with specified size.
     * @param size Maximum capacity of the stack.
     */
    Stack(int);
    
    /**
     * @brief Destructor to free allocated memory.
     */
    ~Stack();
    
    /**
     * @brief Copy constructor for deep copying.
     * @param obj Stack object to copy from.
     */
    Stack(const Stack&);
    
    /**
     * @brief Pushes an element onto the stack.
     * @param value The value to push.
     */
    void push(T);
    
    /**
     * @brief Pops the top element from the stack.
     * @param variable Reference to store the popped value.
     */
    void pop(T&);
    
    /**
     * @brief Checks if the stack is empty.
     * @return true if empty, false otherwise.
     */
    bool isEmpty();
    
    /**
     * @brief Checks if the stack is full.
     * @return true if full, false otherwise.
     */
    bool isFull();
};

template<typename T>
Stack<T>::Stack(int size)
{
    this->stackSize = size;
    stackArray = new T[size];
    top = -1;
}

template<typename T>
Stack<T>::Stack(const Stack& obj)
{
    if (obj.stackSize > 0)
        stackArray = new T[stackSize];
    else 
        stackArray = nullptr;
    
    stackSize = obj.stackSize;

    for (int i = 0; i < stackSize; i++)
        stackArray[i] = obj.stackArray[i];
    
    top = obj.top;
}

template<typename T>
Stack<T>::~Stack()
{
    if (stackSize > 0)
        delete[] stackArray;
}

template<typename T>
bool Stack<T>::isFull()
{
    if (top == stackSize - 1)
        return true;
    else 
        return false;
}

template<typename T>
bool Stack<T>::isEmpty()
{
    if (top == -1)
        return true;
    else 
        return false;
}

template<typename T>
void Stack<T>::push(T value)
{
    if (isFull())
        cout << "The stack is full." << endl;
    else 
    {
        top++;
        stackArray[top] = value;
    }
}

template<typename T>
void Stack<T>::pop(T& variable)
{
    if (isEmpty())
        cout << "The stack is empty." << endl;
    else 
    {
        variable = stackArray[top];
        top--;
    }
}

#endif