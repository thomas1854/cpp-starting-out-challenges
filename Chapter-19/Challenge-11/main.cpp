/**
 * Challenge-11:
 *  11. File Compare
 *      Write a program that opens two text files and reads their contents into two separate 
        queues. The program should then determine whether the files are identical by compar
        ing the characters in the queues. When two nonidentical characters are encountered, 
        the program should display a message indicating that the files are not the same. If both 
        queues contain the same set of characters, a message should be displayed indicating 
        that the files are identical.
 */

#include <iostream>
#include <fstream>
#include "../Challenge-04/Queue.h"
using namespace std;

/**
 * @brief Compares two text files character by character to determine if they are identical
 * 
 * This function reads two files into separate queues and compares them character by character.
 * The comparison is case-sensitive and includes all whitespace characters.
 * 
 * @param filename1 Path to the first file to compare
 * @param filename2 Path to the second file to compare
 * 
 * @note The function prints the result to standard output
 * @note If either file cannot be opened, an error message is displayed
 */
void fileCompare(string filename1, string filename2)
{
    // Open both input file streams
    ifstream inputFileStream1(filename1), inputFileStream2(filename2); 
    
    // Validate first file opened successfully
    if (!inputFileStream1)
    {
        cerr << "Error: Unable to open file '" << filename1 << "'" << endl;
        return;
    }

    // Validate second file opened successfully
    if (!inputFileStream2)
    {
        cerr << "Error: Unable to open file '" << filename2 << "'" << endl;
        return;
    }

    // Load file contents into queues
    Queue<char> fileContentQueue1, fileContentQueue2;
    char c;
    
    // Read all characters from first file
    while (inputFileStream1.get(c))
        fileContentQueue1.enqueue(c);
    
    // Read all characters from second file
    while (inputFileStream2.get(c))
        fileContentQueue2.enqueue(c);

    // Compare queues character by character
    while (!fileContentQueue1.isEmpty())
    {
        // If queue2 is empty but queue1 isn't, files differ in length
        if (fileContentQueue2.isEmpty())
        {
            cout << "Result: Files are NOT identical (different lengths)" << endl;
            return;
        }

        char c1, c2;
        fileContentQueue1.dequeue(c1);
        fileContentQueue2.dequeue(c2);
        
        // Compare characters
        if (c1 != c2)
        {
            cout << "Result: Files are NOT identical (content differs)" << endl; 
            return;
        }
    }

    // Check if queue2 has remaining characters
    if (!fileContentQueue2.isEmpty()) 
    {
        cout << "Result: Files are NOT identical (different lengths)" << endl;
        return;
    }
    
    cout << "Result: Files are identical" << endl;
}

/**
 * @brief Main entry point of the program
 * 
 * Demonstrates the fileCompare function by comparing two predefined text files.
 * 
 * @return int Exit status (0 for success)
 */
int main(void)
{
    fileCompare("Text-File1.txt", "Text-File2.txt");
    return 0;
}