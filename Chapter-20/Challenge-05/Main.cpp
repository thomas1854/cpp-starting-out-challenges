/*
Challenge-05: 
    5. Recursive Multiplication`
    Write a recursive function that accepts two arguments into the parameters x and y. 
    The function should return the value of x times y. Remember, multiplication can be 
    performed as repeated addition:
    7 * 4 = 4 + 4 + 4 + 4 + 4 + 4 + 4
*/

#include <iostream>
using namespace std;


/**
 * Recursive multiplication implementation using repeated addition
 */

#include <iostream>
using namespace std;

/**
 * Multiplies two integers using recursion
 * @param x Multiplier (must be non-negative)
 * @param y Multiplicand  
 * @return Product of x and y
 */
int recursiveMultiplication(int x, int y)
{
    // Base case
    if (x == 0)
        return 0;
    
    // Recursive case
    return y + recursiveMultiplication(x - 1, y);
}

/**
 * Main function - demonstrates recursive multiplication
 */
int main(void)
{
    // Demonstrate recursive multiplication with 7 * 4
    cout << "7 * 4 = " << recursiveMultiplication(7, 4) << endl;
    
    return 0;
}