/*
Challenge 02:
    2. Node Counter
    Write a member function, for the template you designed in Programming 
    Challenge 1 that counts and returns the number of nodes in the tree. 
    Demonstrate the function in a driver program.
*/

#include <iostream>
#include <string>
#include "BinaryTree.h"
using namespace std;

// Defines a Person class to store name and age, used as the data type for the BinaryTree
class Person
{
private:
    string name; // Stores the person's name
    int age;     // Stores the person's age
public:
    // Default constructor: Initializes an empty Person object
    Person()
    {
        name = "";
        age = 0;
    }
    // Parameterized constructor: Initializes a Person with given name and age
    Person(string name, int age)
    {
        this->name = name;
        this->age = age;
    }
    // Less-than operator: Compares Person objects based on age for BST ordering
    bool operator<(const Person& personObject)
    {
        return this->age < personObject.age;
    }
    // Greater-than operator: Compares Person objects based on age
    bool operator>(const Person& personObject)
    {
        return this->age > personObject.age;
    }
    // Equality operator: Checks if two Person objects have the same name and age
    bool operator==(const Person& personObject)
    {
        return (this->age == personObject.age) && (this->name == personObject.name);
    }

    // Declare stream insertion operator as a friend to allow printing Person objects
    friend ostream& operator<<(ostream&, Person);
};

// Overloads the stream insertion operator to print Person objects
ostream& operator<<(ostream& stream, Person personObj)
{
    stream << "Name: " << personObj.name << "\t\t" << "Age: " << personObj.age << endl;
    return stream;
}

// Main function to test the BinaryTree class with Person objects
int main(void)
{

    /*
    The data type stored in the BinaryTree must define overloaded operators :
        - '<' and '>' for ordering nodes in the binary search tree (BST). 
        - '==' for comparing nodes during search and deletion operations. 
        - '<<' for printing node values to the console.
    */


    // Create a BinaryTree to store Person objects (The type of object to store in tree has to have overloaded operators < > == <<)
    BinaryTree<Person> tree;
    cout << "Inserting nodes.." << endl;
    cout << "\n\n\n";

    // Insert multiple Person objects into the tree, ordered by age
    tree.insertNode(Person("Thomas", 20));
    tree.insertNode(Person("Emily", 25));
    tree.insertNode(Person("Michael", 30));
    tree.insertNode(Person("Sarah", 22));
    tree.insertNode(Person("Daniel", 28));
    tree.insertNode(Person("Olivia", 19));
    tree.insertNode(Person("James", 35));
    tree.insertNode(Person("Sophia", 27));
    tree.insertNode(Person("William", 40));
    tree.insertNode(Person("Emma", 23));

    // Display the current number of nodes in the BinaryTree
    cout << "The tree currently contains " << tree.getNodesCount() << (tree.getNodesCount() == 1 ? " node" : " nodes") << "." << endl;
    cout << "\n\n\n";

    // Display the tree using in-order traversal (sorted by age)
    cout << "Display the tree in-order: " << endl;
    tree.displayInOrder();
    cout << "\n\n\n";

    // Display the tree using pre-order traversal (root first)
    cout << "Display the tree pre-order: " << endl;
    tree.displayPreOrder();
    cout << "\n\n\n";

    // Display the tree using post-order traversal (root last)
    cout << "Display the tree post-order: " << endl;
    tree.displayPostOrder();
    cout << "\n\n\n";

    // Search for a specific Person object in the tree
    cout << "Searching for Person(\"Thomas\", 20): ";
    if (tree.searchNode(Person("Thomas", 20)))
        cout << "Person(\"Thomas\", 20) is exist" << endl;
    else
        cout << "Person(\"Thomas\", 20) is not exist" << endl;
    cout << "\n\n\n";

    // Remove a Person object from the tree
    cout << "Reomving Person(\"Michael\", 30).." << endl;
    tree.remove(Person("Michael", 30));
    cout << "\n\n\n";

    // Display the current number of nodes in the BinaryTree
    cout << "The tree currently contains " << tree.getNodesCount() << (tree.getNodesCount() == 1 ? " node" : " nodes") << "." << endl;
    cout << "\n\n\n";

    // Search for the removed Person object to verify deletion
    cout << "Searching for Person(\"Michael\", 30): ";
    if (tree.searchNode(Person("Michael", 30)))
        cout << "Person(\"Michael\", 30) is exist" << endl;
    else
        cout << "Person(\"Michael\", 30) is not exist" << endl;
    cout << "\n\n\n";

    // Attempt to remove a non-existent Person object
    cout << "Reomving Person(\"NoOne\", 0).." << endl;
    tree.remove(Person("NoOne", 0));
    cout << "\n\n\n";

    // Display the current number of nodes in the BinaryTree
    cout << "The tree currently contains " << tree.getNodesCount() << (tree.getNodesCount() == 1 ? " node" : " nodes") << "." << endl;
    cout << "\n\n\n";
    return 0;
}