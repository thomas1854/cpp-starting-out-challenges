/**
 * Challenge-15
 *  15. Test of Language
    A language allows strings to be only in the form of anbn, where n is a positive integer. Thus, 
    the string ‘aaaaabbbbb’ is valid but the strings ‘aaaabbb’, or ‘aaabbbb’, or ‘aabbaabb’ are 
    invalid. 
    Write a function that accepts a string as an argument and tests whether it belongs to 
    the language. The function should scan the string from the beginning, push all the ‘a’s 
    in a stack, and start to pop them when the ‘b’s are encountered. The function should 
    report any discrepancies in the number of ‘a’s and ‘b’s as a failure. Demonstrate the 
    function in a program.
 */

#include <iostream>
#include <stack>
using namespace std;

/**
 * @brief Tests whether a string belongs to the language a^n b^n
 * 
 * This function validates strings that consist of n consecutive 'a's 
 * followed by n consecutive 'b's, where n is a positive integer.
 * It uses a stack-based approach: pushing all 'a's onto the stack
 * and popping them when 'b's are encountered.
 * 
 * @param str The input string to validate
 * @return true if the string belongs to the language a^n b^n
 * @return false otherwise (mismatched counts, wrong order, or invalid characters)
 * 
 * @note Valid examples: "ab", "aabb", "aaabbb"
 * @note Invalid examples: "aabbaabb", "aaabbb", "ba", "abc"
 */
bool testLanguage(const string& str)
{
    stack<char> st;
    bool seenB = false;  ///< Flag to track if any 'b' has been encountered
    
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] == 'a')
        {
            if (seenB)  // 'a' after 'b' violates a^n b^n pattern
                return false;
            st.push(str[i]);
        }
        else if (str[i] == 'b')
        {
            if (st.empty())  // More 'b's than 'a's
                return false;
            
            st.pop();
            seenB = true;
        }
        else 
            return false;  // Invalid character (not 'a' or 'b')
    }
    
    if (st.empty())  // All 'a's matched with 'b's
        return true;
    else 
        return false;  // More 'a's than 'b's
}

/**
 * @brief Main function demonstrating the language validator
 * 
 * Tests the testLanguage function with valid and invalid strings
 * and prints the results to standard output.
 * 
 * @return 0 on successful execution
 */
int main(void)
{
    if (testLanguage("aaaaabbbbb"))
        cout << "aaaaabbbbb is valid" << endl;
    else 
        cout << "aaaaabbbbb is invalid" << endl;

    if (testLanguage("aabbaabb"))
        cout << "aabbaabb is valid" << endl;
    else 
        cout << "aabbaabb is invalid" << endl;
        
    return 0;
}