/**
 * Challenge-01:
 *  1. Your Own Linked List
        Design your own linked list class to hold a series of integers. The class should have 
        member functions for appending, inserting, and deleting nodes. Don’t forget to add a 
        destructor that destroys the list. Demonstrate the class with a driver program.
 */

#include <iostream>
#include "LinkedList.h"

int main()
{
    LinkedList list;

    std::cout << "Appending 10, 20, 30" << std::endl;
    list.append(10);
    list.append(20);
    list.append(30);

    list.displayList();

    std::cout << "Insert 5 at position 1" << std::endl;
    list.insert(5, 1);

    list.displayList();

    std::cout << "Insert 25 at position 4" << std::endl;
    list.insert(25, 4);

    list.displayList();

    std::cout << "Trying invalid insert at position 100" << std::endl;
    if (!list.insert(999, 100))
        std::cout << "Insert failed as expected" << std::endl;

    list.displayList();

    std::cout << "Deleting node at position 2" << std::endl;
    list.deleteNode(2);

    list.displayList();

    std::cout << "Trying invalid delete at position 100" << std::endl;
    if (!list.deleteNode(100))
        std::cout << "Delete failed as expected" << std::endl;

    list.displayList();

    std::cout << "Is empty: " << (list.isEmpty() ? "yes" : "no") << std::endl;

    std::cout << "Original list: ";
    list.displayList();
    std::cout << std::endl;
    
    LinkedList copyList(list);
    std::cout << "Copied list: ";
    copyList.displayList();
    std::cout << std::endl;
    
    std::cout << "Cleaning up and exiting." << std::endl;
    return 0;
}
