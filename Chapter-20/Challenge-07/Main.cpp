/*
Challenge-07: 
    7. Sum of Odd Numbers
    Write a function that accepts two integer arguments and returns the sum of all the odd 
    integers in between the two numbers. For example, if 20 and 50 are passed as argu
    ments, the function will return the sum of 21, 23, 25, . . ., 49. Use recursion to calculate 
    the sum. Demonstrate the function in a program.  
*/

#include <iostream>
using namespace std;

/**
 * @brief Calculates the sum of all odd numbers in a range (inclusive)
 * @param current The starting number of the range
 * @param end The ending number of the range (inclusive)
 * @return The sum of all odd numbers between current and end (inclusive)
 */
int sumOdd(int current, int end)
{
    if (current == end)
    {
        if (end % 2 == 1)
            return end;
        else
            return 0;
    }

    if (current % 2 == 1)
        return sumOdd(current + 1, end) + current;
    else
        return sumOdd(current + 1, end);
}

int main(void)
{
    cout << "Sum of odd numbers from 20 to 50: " << sumOdd(20, 50) << endl;
    return 0;
}