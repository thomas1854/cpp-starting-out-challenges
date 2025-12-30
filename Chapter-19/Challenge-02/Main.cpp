/*
    Challenge-02:
        2. Dynamic Stack Template
        Write your own version of a class template that will create a dynamic stack of any 
        data type. Demonstrate the class with a driver program.
*/

#include <iostream>
#include "Stack.h"
using namespace std;

/**
 * @brief Demonstrates basic stack operations.
 * 
 * Creates a stack of doubles, pushes multiple values,
 * and pops the top element.
 */
int main(void)
{
    Stack<double> st;
    st.push(10.5);
    st.push(156.33);
    st.push(3.14);
    st.push(14.3);
    st.push(2036.6);
    st.push(123.456);  
    double item;
    st.pop(item);
    cout << "Popped Value: " << item << endl;
    return 0;
}