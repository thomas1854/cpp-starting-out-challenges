#ifndef STRINGSTACK_H
#define STRINGSTACK_H
#include "../Challenge-02/Stack.h"
#include <string>
using namespace std;

/**
 * @brief String stack with size tracking.
 */
class StringStack : public Stack<string>
{
private:
    int stackSize;
public:
    /** @brief Returns current size. */
    int size() { return stackSize; }
    
    /** @brief Constructs empty stack. */
    StringStack() { stackSize = 0; }
    
    /** @brief Pushes item onto stack. */
    void push(const string&);
    
    /** @brief Pops item from stack. */
    void pop(string&);
};

void StringStack::push(const string& item)
{
    Stack<string>::push(item);
    stackSize++;
}

void StringStack::pop(string& stringVariable)
{
    if (Stack<string>::pop(stringVariable))
        stackSize--;
}
#endif