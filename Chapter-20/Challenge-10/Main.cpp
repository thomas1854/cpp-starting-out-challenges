/*
Challenge 10:
    10. maxNode Function
    Add a member function named maxNode to the NumberList class discussed in this 
    chapter. The function should return the largest value stored in the list. Use recursion in 
    the function to traverse the list. Demonstrate the function in a driver program.
*/

#include <iostream>
#include "NumberList.h"
using namespace std;

/**
 * @brief Main function demonstrating NumberList class functionality
 * @return 0 on successful execution
 */
int main(void)
{
    // Create a NumberList object
    NumberList numberList;
    
    // Append nodes to the end of the list
    numberList.appendNode(10.5);
    numberList.appendNode(15.5);
    numberList.appendNode(20.5);
    numberList.appendNode(5.5);
    
    // Insert nodes in sorted order
    numberList.insertNode(12.5);
    numberList.insertNode(3.5);
    
    cout << "List after appending and inserting nodes:" << endl;
    numberList.displayList();

    // Find and display the maximum value
    cout << "Maximum value in the list: " << numberList.maxNode() << endl;
    
    return 0;
}