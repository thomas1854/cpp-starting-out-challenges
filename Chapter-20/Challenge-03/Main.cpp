/**
 * @file Main.cpp
 * @brief Demonstration program for the QuickSort algorithm.
 * 
 * This program demonstrates the usage of the quickSort template function
 * by sorting an array of strings in ascending alphabetical order.
 */

#include <iostream>
#include "QuickSort.h"
using namespace std;

/**
 * @brief Main entry point of the program.
 * 
 * Demonstrates the QuickSort algorithm by:
 * 1. Creating an array of strings in unsorted order
 * 2. Sorting the array using quickSort()
 * 3. Displaying the sorted results
 * 
 * @return int Returns 0 upon successful execution.
 * 
 * @note The array is sorted in-place, modifying the original data.
 * 
 * Example output:
 * @code
 * AAA BBB CCC DDD FFF
 * @endcode
 */
int main(void)
{
    // Array of strings to be sorted
    string arr[] = {"DDD", "BBB", "AAA", "CCC", "FFF"};
    
    // Sort the array from index 0 to 4 (inclusive)
    quickSort(arr, 0, 4);
    
    // Display the sorted array
    for (auto& val : arr) cout << val << ' ';
    
    return 0;
}