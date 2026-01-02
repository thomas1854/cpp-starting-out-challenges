/* Challenge-03
    3. Static Queue Template
    Write your own version of a class template that will create a static queue of any data 
    type. Demonstrate the class with a driver program.
*/

/**
 * @file main.cpp
 * @brief Driver program demonstrating circular queue template operations.
 */

#include <iostream>
#include "Queue.h"
using namespace std;

/**
 * @brief Demonstrates basic queue operations with a double type queue.
 * 
 * Creates a queue with capacity 5, attempts to enqueue 6 values (last one fails),
 * then dequeues and displays the front element (10.5).
 * 
 * @return 0 on successful execution.
 */
int main(void)
{
    Queue<double> qu(5);
    
    // Enqueue values (6th will fail - queue is full)
    qu.enqueue(10.5);
    qu.enqueue(156.33);
    qu.enqueue(3.14);
    qu.enqueue(14.3);
    qu.enqueue(2036.6);
    qu.enqueue(123.456);  // This will print "The queue is full."
    
    // Dequeue and display the front element
    double val;
    qu.dequeue(val);
    cout << val << endl;
    
    return 0;
}