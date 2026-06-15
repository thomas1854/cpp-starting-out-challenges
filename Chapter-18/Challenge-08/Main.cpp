#include <iostream>
#include "DoubleList.h"

int main()
{
    // Create list and perform simple operations; comments show intended result
    DoubleList<int> list;

    // insertFirst(10) -> list: 10
    list.insertFirst(10);
    list.displayList();

    // append(20) -> list: 10 -> 20
    list.append(20);
    list.displayList();

    // insert(15, 2) -> list: 10 -> 15 -> 20
    list.insert(15, 2);
    list.displayList();

    // insert invalid position -> expect false
    bool ok = list.insert(5, 10);
    std::cout << "insert at pos 10 returned " << ok << " (expected false)" << std::endl;

    // listSearch(15) -> returns 0-based index (expected 1)
    int pos = list.listSearch(15);
    std::cout << "listSearch(15) returned " << pos << " (expected 1)" << std::endl;

    // deleteFirst() -> removes 10 -> list: 15 -> 20
    list.deleteFirst();
    list.displayList();

    // deleteLast() -> removes 20 -> list: 15
    list.deleteLast();
    list.displayList();

    // deleteNode(1) -> removes 15 -> list: (empty)
    list.deleteNode(1);
    list.displayList();

    // isEmpty() -> expected true (1)
    std::cout << "isEmpty: " << list.isEmpty() << " (expected 1)" << std::endl;

    // Append a few values -> list: 1 -> 2 -> 3
    list.append(1);
    list.append(2);
    list.append(3);
    list.displayList();

    // Copy constructor -> copy should contain same values
    DoubleList<int> copy(list);
    copy.displayList();

    // insert into copy at position 2 -> copy: 1 -> 9 -> 2 -> 3
    copy.insert(9, 2);
    copy.displayList();

    // listSearch on copy -> should find 9 at 0-based index 1
    std::cout << "copy.listSearch(9) = " << copy.listSearch(9) << " (expected 1)" << std::endl;

    return 0;
}
