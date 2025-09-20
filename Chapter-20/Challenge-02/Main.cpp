/*
Challenge-02:
    2. Recursive Conversion
    Convert the following function to one that uses recursion:
    void doAgain()
    {  char answer;
    do { cout << "Executing function. Press Y to execute again.";
            cin >> answer;
        } while ( answer == 'y' || answer == 'Y' );
    }
    Demonstrate the function with a driver program.
*/

#include <iostream>
using namespace std;

/**
 * @brief Recursively executes based on user input
 * 
 * Prompts user to press 'Y' to execute again. If user enters 'Y' or 'y',
 * the function calls itself recursively.
 */
void doAgain() {
    char answer;
    cout << "Executing function. Press Y to execute again. ";
    cin >> answer;
    
    // Check for 'Y' or 'y' to continue recursion
    if (answer == 'Y' || answer == 'y')
        doAgain();
    
    return;
}

/**
 * @brief Main function
 * @return 0 on successful execution
 */
int main(void) {
    doAgain();
    return 0;
}