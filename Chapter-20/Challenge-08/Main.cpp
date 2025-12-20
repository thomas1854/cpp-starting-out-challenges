/*
Challenge 08:
    8. Arithmetic Progression Series
    In an arithmetic progression (A.P.) series, each element can be calculated by adding a 
    fixed number (called the common difference) to the previous element. Write a recursive 
    function that prints an A.P. series. The function should accept the first term, the com
    mon difference, and the number of terms as arguments. Test with a driver program.
*/

/**
 * @file Main.cpp
 * @brief Prints an arithmetic progression using recursion
 */

#include <iostream>
using namespace std;

/**
 * @brief Recursively prints terms of an arithmetic progression
 * @param firstTerm Current term to print
 * @param commonDifference Difference between consecutive terms
 * @param terms Number of remaining terms to print
 */
void printArithmeticProgression(int firstTerm, int commonDifference, int terms)
{
    if (terms > 0)
    {
        cout << firstTerm << ' ';
        printArithmeticProgression(firstTerm + commonDifference, commonDifference, terms - 1);
    }
}

/**
 * @brief Main entry point
 * @return 0 on success
 */
int main(void)
{
    printArithmeticProgression(1, 5, 3);
    return 0;
}