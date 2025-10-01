/*
Challenge-09:
    9. String Reverser
    Write a recursive function that accepts a string object as its argument and prints the 
    string in reverse order. Demonstrate the function in a driver program.
*/

#include <iostream>
using namespace std;

/**
 * @brief Prints a string in reverse order using recursion
 * @param str The string to be reversed
 * @param index Current position in the string (defaults to 0)
 */
void stringReverser(string str, int index = 0)
{
    if (index == str.size()) return;
    stringReverser(str, index + 1);
    cout << str[index];
}

int main(void)
{
    stringReverser("ABCDEF");
    cout << endl;
    return 0;
}