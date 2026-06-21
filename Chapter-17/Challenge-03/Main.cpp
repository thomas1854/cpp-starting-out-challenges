#include <iostream>
#include <fstream>
#include <map>
using namespace std;

int main(void)
{
    ifstream input_file("challenge3.txt");
    string str;
    int count_read_words = 0;          // Used to detect each word is key or value
    map<string, string> key_value_map; // Map store key-value pairs
    string key, value;                 // Store each key with its correspondent value
    while (input_file >> str)          // Read each word
    {
        if (count_read_words % 2 == 0) // If read word counter is even it means that the word is key
        {
            key = str;
        }
        else // Otherwise, the word is value
        {
            value = str;
            key_value_map[key] = value;
        }
        count_read_words++; // Increment read word counter each time
    }
    input_file.close();
    ofstream output_file("json_text.json"); // Creates json file with the read data
    // Write the data in the specified format (as JSON file)
    output_file << '{';
    for (pair<string, string> pr : key_value_map)
    {
        output_file << '"' << pr.first << '"' << ": " << '"' << pr.second << '"' << ',';
    }
    output_file.seekp(-1, ios::cur);
    output_file << '}' << endl;
    output_file.close();
    return 0;
}