/**
 * Challenge-10:
 *  10. Encrypting Filter
 *      Write a program that opens a text file and reads its contents into a queue of characters. 
        The program should then dequeue each character and substitute it with the character 
        that comes five places after it in the ASCII character set, and store it in a second file.
 */

#include <iostream>
#include <fstream>
#include "../Challenge-04/Queue.h"
using namespace std;

/**
 * @brief Encrypts a file using a Caesar cipher with modulo 128 wrapping
 * 
 * This function reads a file character by character, applies a Caesar cipher
 * encryption (shift of 5 with ASCII wrapping at 128), and writes the result
 * to a new file with "-encrypted" inserted before the file extension.
 * 
 * @param fileName The path to the input file to be encrypted
 * 
 * @details
 * - Reads entire file content into a Queue<char>
 * - Applies Caesar cipher: (ASCII_value + 5) % 128
 * - Creates output file by inserting "-encrypted" before extension
 * - Example: "TextFile.txt" becomes "TextFile-encrypted.txt"
 * 
 * @note The encryption is reversible by subtracting 5 (with proper modulo handling)
 * @warning Uses weak encryption suitable only for educational purposes
 * 
 * @pre Input file must exist and be readable
 * @post Creates a new encrypted file, original file remains unchanged
 */
void encryptingFilter(const string &fileName)
{
    // Open input file for reading
    ifstream inputFileStream(fileName);
    if (!inputFileStream)
    {
        cerr << "Error: Unable to open input file '" << fileName 
             << "'. Please check the file path and try again." << endl;
        return;
    }
    
    Queue<char> fileContentQueue;
    char c;
    
    // Read entire file into queue
    while (inputFileStream.get(c))
        fileContentQueue.enqueue(c);
    
    inputFileStream.close();
    
    // Generate output filename by inserting "-encrypted" before extension
    string fullOutputFileName = fileName;
    auto index = fullOutputFileName.find('.');
    if (index != string::npos)
        fullOutputFileName.insert(index, "-encrypted");
    else
        fullOutputFileName.append("-encrypted");
    
    // Open output file for writing
    ofstream outputFileStream(fullOutputFileName);
    if (!outputFileStream)
    {
        cerr << "Error: Unable to create output file '" << fullOutputFileName 
             << "'. Please check write permissions." << endl;
        return;
    }
    
    // Encrypt and write each character
    while (!fileContentQueue.isEmpty())
    {
        fileContentQueue.dequeue(c);
        int filteredCharASCII = static_cast<unsigned char>(c);
        filteredCharASCII += 5;
        filteredCharASCII %= 128;
        outputFileStream.put(char(filteredCharASCII));
    }
    
    outputFileStream.close();
    cout << "Success: File content encrypted and saved to '" 
         << fullOutputFileName << "'." << endl;
}

/**
 * @brief Main entry point of the program
 * 
 * Encrypts the file "TextFile.txt" using the encryptingFilter function.
 * 
 * @return 0 on successful execution
 */
int main(void)
{
    encryptingFilter("TextFile.txt");
    return 0;
}