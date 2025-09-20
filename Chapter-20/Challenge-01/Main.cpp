/*
Challenge-01:
     1. Iterative Function for Character Count
     Write an iterative version (using loop) of the recursive function shown in this chapter to 
     count the number of times a character appears in a string. Test with a driver program.
*/

#include <iostream>
#include <string>

using namespace std;

/**
 * @brief Counts the number of times a specific character appears in a string
 * 
 * This function iterates through each character in the input string and
 * counts how many times the specified character appears.
 * 
 * @param str The string to search in
 * @param c The character to count
 * @return int The number of occurrences of character c in string str
 * 
 * @example
 * countChar("Hello World!", 'l') returns 3
 * countChar("Programming", 'g') returns 2
 */
int countChar(string str, char c) {
    int ocurrences_number = 0;
    
    // Iterate through each character in the string
    for (int i = 0; i < str.size(); i++) {
        // Check if current character matches the target character
        if (str[i] == c) {
            ocurrences_number++;
        }
    }
    
    return ocurrences_number;
}

/**
 * @brief Main function - Entry point of the program
 * 
 * Demonstrates the usage of countChar function by counting
 * the occurrences of character 'l' in the string "Hello World!"
 * 
 * @return int Returns 0 to indicate successful execution
 */
int main(void) {
    // Define the string and character to search for
    string testString = "Hello World!";
    char searchChar = 'l';
    
    // Count occurrences and display the result with improved formatting
    int count = countChar(testString, searchChar);
    
    cout << "String: \"" << testString << "\"" << endl;
    cout << "Character '" << searchChar << "' appears " << count 
         << " time" << (count != 1 ? "s" : "") << " in the string." << endl;
    
    return 0;
}