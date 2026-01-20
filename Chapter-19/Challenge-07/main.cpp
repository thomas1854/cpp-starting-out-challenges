#include <iostream>
#include "MathStack.h"
using namespace std;

int main(void)
{
    MathStack mathStack;
    mathStack.push(10);
    mathStack.push(20);
    mathStack.push(30);
    mathStack.push(40);
    mathStack.push(50);
    mathStack.mult();
    cout << "50 * 40 = " << mathStack.peek() << endl;
    mathStack.multAll();
    cout << "2000 * 30 * 20 * 10 = " << mathStack.peek() << endl;
    mathStack.push(2);
    mathStack.div();
    cout << "12000000 / 2 = " << mathStack.peek() << endl;
    mathStack.push(5500);
    mathStack.addAll();
    cout << "6000000 + 5500 = " << mathStack.peek() << endl;
    return 0;
}