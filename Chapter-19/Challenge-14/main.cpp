/*
Challenge-14:
    14. Evaluation of a Postfix Expression
        Write a program to evaluate a postfix expression using a stack. To evaluate the string, 
        the program should scan each character in the string. If the character is a digit, its value 
        is pushed on a stack. If the character is an operator Q ( +, – , *, or / ), the top two 
        elements are popped in the variables A and B, the operation B Q A is performed, and 
        the result is pushed back on the stack. The final result is stored on the top of the stack.
*/
#include <iostream>
#include "../Challenge-02/Stack.h"

using namespace std;

/**
 * @brief Checks if a character is a digit (0-9).
 * @param c The character to check.
 * @return true if digit, false otherwise.
 */
bool isDigit(char c)
{
    return c >= '0' && c <= '9';
}

/**
 * @brief Checks if a character is a valid arithmetic operator.
 * @param c The character to check.
 * @return true if operator (+, -, *, /), false otherwise.
 */
bool isOperator(char c)
{
    return c == '+' || c == '-' || c == '*' || c == '/';
}

/**
 * @brief Exception thrown when an invalid postfix expression is encountered.
 */
class InvalidExpressionException{};

/**
 * @brief Evaluates a postfix (Reverse Polish Notation) expression.
 * @param postfixExpression A string containing the postfix expression (single-digit operands only).
 * @return The integer result of the evaluated expression.
 * @throws InvalidExpressionException if the expression contains invalid characters.
 */
int postfixEvaluation(string postfixExpression)
{
    Stack<int> st;
    for (char c : postfixExpression)
    {
        if (isDigit(c))
            st.push(c - '0');
        else if (isOperator(c))
        {
            int op2;
            st.pop(op2);
            int op1;
            st.pop(op1);
            switch (c)
            {
            case '+': st.push(op1 + op2); break;
            case '-': st.push(op1 - op2); break;
            case '*': st.push(op1 * op2); break;
            case '/': st.push(op1 / op2); break;
            default:  break;
            }
        }
        else
        {
            throw InvalidExpressionException();
        }
    }
    int result;
    st.pop(result);
    return result;
}

/**
 * @brief Entry point. Evaluates a hardcoded postfix expression and prints the result.
 */
int main(void)
{
    string postfixExpression = "6523+8*+3+*";
    try
    {
        int result = postfixEvaluation(postfixExpression);
        cout << "Postfix Expression : " << postfixExpression << endl;
        cout << "Evaluated Result   : " << result << endl;
    }
    catch (const InvalidExpressionException&)
    {
        cout << "Error: Invalid postfix expression \"" << postfixExpression << "\"." << endl;
    }
    return 0;
}