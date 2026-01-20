#ifndef MATHSTACK_H
#define MATHSTACK_H
#include <iostream>
#include "../Challenge-02/Stack.h"
using namespace std;

/**
 * @class MathStack
 * @brief A stack class that provides mathematical operations on integer elements.
 * 
 * Extends the base Stack<int> class with arithmetic operations including
 * multiplication, division, sum, and product of stack elements.
 */
class MathStack : public Stack<int>
{
public:
    void mult();
    void div();
    void addAll();
    void multAll();
};

/**
 * @brief Multiplies the top two elements and pushes the result.
 * 
 * Pops two operands, multiplies them, and pushes the result back.
 * Prints error if fewer than 2 elements exist.
 */
void MathStack::mult()
{
    if (size() < 2)
    {
        cout << "Invalid operation" << endl;
    }
    else 
    {
        int operand1, operand2;
        pop(operand2);
        pop(operand1);
        push(operand1 * operand2);
    }
}

/**
 * @brief Divides the second-to-top element by the top element.
 * 
 * Pops two operands, performs integer division, and pushes the result.
 * Prints error if fewer than 2 elements exist.
 * @warning Does not check for division by zero.
 */
void MathStack::div()
{
    if (size() < 2)
    {
        cout << "Invalid operation" << endl;
    }
    else 
    {
        int operand1, operand2;
        pop(operand2);
        pop(operand1);
        if (operand2 == 0)
        {
            cout << "Error: Division by zero" << endl;
            push(operand1);  // Restore first operand
        }
        else
        {
            push(operand1 / operand2);
        }
    }
}

/**
 * @brief Sums all elements in the stack.
 * 
 * Pops all elements, computes their sum, and pushes the result.
 * If stack is empty, pushes 0.
 */
void MathStack::addAll()
{
    int sumAll = 0;
    while (size())
    {
        int operand;
        pop(operand);
        sumAll += operand;
    }
    push(sumAll);
}

/**
 * @brief Multiplies all elements in the stack.
 * 
 * Pops all elements, computes their product, and pushes the result.
 * If stack is empty, pushes 1.
 */
void MathStack::multAll()
{
    int multAllVal = 1;
    while (size())
    {
        int operand;
        pop(operand);
        multAllVal *= operand;
    }
    push(multAllVal);
}
#endif