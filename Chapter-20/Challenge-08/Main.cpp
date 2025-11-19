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