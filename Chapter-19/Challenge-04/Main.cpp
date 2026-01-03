/*
Challenge-04
    4. Dynamic Queue Template
    Write your own version of a class template that will create a dynamic queue of any data 
    type. Demonstrate the class with a driver program.
*/
/**
 * @file main.cpp
 * @brief Demonstrates the usage of the templated Queue class
 */

#include <iostream>
#include "Queue.h"
using namespace std;

/**
 * @brief Main function that demonstrates queue operations
 * 
 * Creates a queue of doubles, enqueues several values,
 * then dequeues and displays the first value.
 * 
 * @return 0 on successful execution
 */
int main(void)
{
    Queue<double> qu;  ///< Queue to store double values
    
    // Enqueue values to the queue
    qu.enqueue(10.5);
    qu.enqueue(156.33);
    qu.enqueue(3.14);
    qu.enqueue(14.3);
    qu.enqueue(2036.6);
    qu.enqueue(123.456);  
    
    double val;  ///< Variable to store dequeued value
    qu.dequeue(val);
    cout << val << endl;  // Should output 10.5 (first in, first out)
    
    return 0;
}