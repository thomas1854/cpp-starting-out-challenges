/*
    Challenge-11:
        11. Palindrome Detector
*/

#include <iostream>
using namespace std;

#include <iostream>
using namespace std;

/**
 * @brief Checks if a string is a palindrome (case-insensitive, ignoring non-alphanumeric characters)
 * @param str The input string to check
 * @param index Current recursion index (default: 0)
 * @return true if the string is a palindrome, false otherwise
 */
bool palindromeDetector(string str, int index = 0)
{
    static string reversedString = "";
    static string mainStringWithoutSpaces = "";
    if (index == str.size())
        return false;
    if (isalnum(str[index]))
        mainStringWithoutSpaces.push_back(tolower(str[index]));
    palindromeDetector(str, index + 1);
    if (isalnum(str[index]))
        reversedString.push_back(tolower(str[index]));
    return (reversedString == mainStringWithoutSpaces);
}

/**
 * @brief Tests the palindrome detector with sample strings
 */
int main(void)
{
    string str = "A man, a plan, a canal, Panama";
    if (palindromeDetector(str))
        cout << "\"" << str << "\"" << " is a palindrome statement." << endl;
    else 
        cout << "\"" << str << "\"" << " is not a palindrome statement." << endl;
    

    str = "Not a palindrome statement";
    if (palindromeDetector(str))
        cout << "\"" << str << "\"" << " is a palindrome statement." << endl;
    else 
        cout << "\"" << str << "\"" << " is not a palindrome statement." << endl;
    return 0;
}