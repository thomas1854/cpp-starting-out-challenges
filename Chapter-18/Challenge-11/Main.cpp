#include <iostream>
#include "PriorityList.h"

int main()
{
    PriorityList list;

    std::cout << "Action: add 10 with priority 2\n";
    std::cout << "Expect: 10\n";
    list.addNode(10, 2);
    list.displayList();

    std::cout << "Action: add 20 with priority 1\n";
    std::cout << "Expect: 20->10\n";
    list.addNode(20, 1);
    list.displayList();

    std::cout << "Action: add 30 with priority 2\n";
    std::cout << "Expect: 20->10->30\n";
    list.addNode(30, 2);
    list.displayList();

    std::cout << "Action: add 40 with priority 3\n";
    std::cout << "Expect: 20->10->30->40\n";
    list.addNode(40, 3);
    list.displayList();
    
    return 0;
}