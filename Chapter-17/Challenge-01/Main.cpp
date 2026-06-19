/**
 * Challenge-01:
 *  1. Unique Words
        Write a program that opens a specified text file then displays a list of all the unique
        words found in the file.
        Hint: Store each word as an element of a set.
 */
#include <iostream>
#include <fstream>
#include <set>
using namespace std;

int main(void)
{
    ifstream file("Text.txt");
    string word;
    set<string> uniqueWords;
    // Read all words from the file and insert each word in the set of uniqueWords
    while (file >> word)
        uniqueWords.insert(word);
    file.close();
    // Print all the unique words found in the file
    cout << "List of all the unique words found in the file: " << endl;
    for (string word : uniqueWords)
    {
        cout << word << endl;
    }
    return 0;
}