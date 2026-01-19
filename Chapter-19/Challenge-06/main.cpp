#include <iostream>
#include "StringStack.h"
using namespace std;

int main(void)
{
    StringStack stringStack;
    stringStack.push("Alice");
    stringStack.push("Bob");
    stringStack.push("Thomas");
    cout << "Current stack size: " << stringStack.size() << endl;
    string str;
    stringStack.pop(str);
    cout << "Popped value: " << str << endl;
    cout << "Current stack size: " << stringStack.size() << endl;
    return 0;
}