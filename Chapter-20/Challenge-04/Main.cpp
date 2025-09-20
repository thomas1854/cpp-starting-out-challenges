/*
Challenge-04
     4. Print Reverse Array
     Write a recursive function that accepts a numeric array and a number indicating the 
     number of array elements as arguments. The function should display the array in 
     reverse order. Demonstrate the function in a program.
*/

#include <iostream>
using namespace std;

/**
 * @brief Recursively prints array elements in reverse order
 * 
 * Uses recursion to traverse to the end of the array first,
 * then prints elements while returning from recursive calls.
 * 
 * @param arr The array to print
 * @param array_elements_number Total number of elements in the array
 * @param index Current index (default: 0)
 */
void printReverseArray(int arr[], int array_elements_number, int index = 0) {
    // Base case: reached end of array
    if (index == array_elements_number)
        return;
    
    // Recursive call to reach the end first
    printReverseArray(arr, array_elements_number, index + 1);
    
    // Print current element after returning from recursion
    cout << arr[index] << ' ';
}

/**
 * @brief Main function
 * @return 0 on successful execution
 */
int main(void) {
    int array_elements_number = 5;
    int arr[array_elements_number] = {1, 2, 3, 4, 5};
    
    // Display original array
    cout << "Original array: " << endl;
    for (int i = 0; i < array_elements_number; i++)
        cout << arr[i] << ' ';
    cout << endl;
    
    // Display reversed array
    cout << "Reversed array: " << endl;
    printReverseArray(arr, array_elements_number);
    cout << endl;
    
    return 0;
}