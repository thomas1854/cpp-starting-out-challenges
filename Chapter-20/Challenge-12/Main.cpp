/*
    Challenge-12:
        12. Ackermann’s Function
        Ackermann’s Function is a recursive mathematical algorithm that can be used to 
        test how well a computer performs recursion. Write a function A(m, n) that solves 
        Ackermann’s Function.
*/

/**
 * @brief Implementation of the Ackermann function
 */

#include <iostream>
using namespace std;

/**
 * @brief Computes the Ackermann function A(m, n)
 * 
 * A recursive function defined by:
 * - A(0, n) = n + 1
 * - A(m, 0) = A(m-1, 1)
 * - A(m, n) = A(m-1, A(m, n-1))
 * 
 * @param m First parameter (non-negative integer)
 * @param n Second parameter (non-negative integer)
 * @return The value of A(m, n)
 * @warning Grows extremely rapidly; use caution with m >= 4
 */
int A(int m, int n)
{
    if (m == 0) 
        return n + 1;
    else if (n == 0)
        return A(m - 1, 1);
    else 
        return A(m - 1, A(m, n - 1));
}

/**
 * @brief Main function demonstrating the Ackermann function
 * @return 0 on successful execution
 */
int main(void)
{
    cout << "A(0, 0) = " << A(0, 0) << endl;
    cout << "A(0, 1) = " << A(0, 1) << endl;
    cout << "A(1, 1) = " << A(1, 1) << endl;
    cout << "A(1, 2) = " << A(1, 2) << endl;
    cout << "A(1, 3) = " << A(1, 3) << endl;
    cout << "A(2, 2) = " << A(2, 2) << endl;
    cout << "A(3, 2) = " << A(3, 2) << endl;
    return 0;
}