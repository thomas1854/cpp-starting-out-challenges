#include <iostream>
#include <map>
#include <fstream>
using namespace std;

int main(void)
{
    // Map each alphabetic to its encrypted value
    map<char, char> codes =
        {
            {'A', '!'},
            {'a', '"'},
            {'B', '#'},
            {'b', '$'},
            {'C', '%'},
            {'c', '&'},
            {'D', '\''},
            {'d', '('},
            {'E', ')'},
            {'e', '*'},
            {'F', '+'},
            {'f', ','},
            {'G', '-'},
            {'g', '.'},
            {'H', '/'},
            {'h', '0'},
            {'I', '1'},
            {'i', '2'},
            {'J', '3'},
            {'j', '4'},
            {'K', '5'},
            {'k', '6'},
            {'L', '7'},
            {'l', '8'},
            {'M', '9'},
            {'m', ':'},
            {'N', ';'},
            {'n', '<'},
            {'O', '='},
            {'o', '>'},
            {'P', '?'},
            {'p', '@'},
            {'Q', '['},
            {'q', '\\'},
            {'R', ']'},
            {'r', '^'},
            {'S', '_'},
            {'s', '`'},
            {'T', '{'},
            {'t', '|'},
            {'U', '}'},
            {'u', '~'},
            {'V', 'A'},
            {'v', 'B'},
            {'W', 'C'},
            {'w', 'D'},
            {'X', 'E'},
            {'x', 'F'},
            {'Y', 'G'},
            {'y', 'H'},
            {'Z', 'I'},
            {'z', 'J'}};

    // Initialize input file stream object (ifs) to read palin text file
    // Initialize output file stream object (ofs) to write encrypted text file
    ifstream ifs("Text.txt");
    ofstream ofs("encrypted.txt");
    char c;
    // Read each character
    while (ifs.get(c))
    {   
        // Write its mapped value to encrypted file
        ofs << codes[c];
    }

    // Close file streams
    ifs.close();
    ofs.close();

    // Initialize input file stream object (ifs) to read encrypted text file
    ifstream eifs("encrypted.txt");
    // Read each character
    while (eifs.get(c))
    {
        // Iterate through the map to find the original value of this encrypted character
        for (auto &pr : codes)
        {
            if (pr.second == c)
            {
                cout << pr.first;
                break;
            }
        }
    }
    return 0;
}