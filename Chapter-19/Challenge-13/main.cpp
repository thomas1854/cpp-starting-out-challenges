/**
 *  Challenge 13: 
 *  
    13. Double-ended Queue
        Write a class template that will implement a double-ended dynamic queue of any data 
        type. The template should have the member functions insert_front, delete_front, 
        insert_rear, and delete_rear. Demonstrate the class in a driver program.
 */

#include <iostream>
#include "DoubleEndedQueue.h"
using namespace std;

int main(void)
{
    DoubleEndedQueue<int> deque;
    
    // Test insert_rear and insert_front
    deque.insert_rear(1);
    deque.insert_rear(2);
    deque.insert_front(0);
    deque.insert_front(-1);
    
    // Should print: -1 0 1 2
    int value;
    while (!deque.isEmpty()) {
        deque.delete_front(value);
        cout << value << " ";
    }
    cout << endl;
    
    // Test delete_rear
    deque.insert_rear(1);
    deque.insert_rear(2);
    deque.insert_rear(3);
    
    deque.delete_rear(value);
    cout << "Removed last: " << value << endl; // Should be 3
    
    deque.delete_front(value);
    cout << "Removed last: " << value << endl; // Should be 1
    
    deque.delete_front(value);
    cout << "Removed first: " << value << endl; // Should be 2

    return 0;
}