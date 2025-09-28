/*
Challenge-06: 
    6. Highest Common Factor
    Write a recursive function that finds the highest common factor (H.C.F.) of two numbers. 
    The function should accept two numbers as arguments and return their H.C.F. 
    Demonstrate the function in a program.
*/

#include <iostream>
#include <algorithm>
using namespace std;

/**
 * @brief Calculates HCF using Euclidean algorithm
 * @param x First integer
 * @param y Second integer
 * @return HCF of x and y
 */
int getHCF(int x, int y)
{
    if (max(x, y) % min(x, y) == 0)
        return min(x, y);
    return getHCF(max(x, y) % min(x, y), min(x, y));
}

int main()
{
    cout << "HCF of 24 and 54 is: " << getHCF(24, 54) << endl;
    cout << "HCF of 48 and 180 is: " << getHCF(48, 180) << endl;
    cout << "HCF of 7 and 13 is: " << getHCF(7, 13) << endl;
    return 0;
}