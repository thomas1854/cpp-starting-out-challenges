/* 
    Challenge 08: 
        8. Employee Tree
*/

#include <iostream>
#include <string>
#include "BinaryTree.h"
using namespace std;

// EmployeeInfo class - represents an employee record with ID and name
class EmployeeInfo {
private:
    int employeeID;      // Unique identifier for the employee
    string employeeName; // Employee's full name
    
public:
    // Default constructor - creates empty employee record
    EmployeeInfo()
    {
        employeeID = 0;
        employeeName = "";
    }
    
    // Parameterized constructor - creates employee with given ID and name
    EmployeeInfo(int employeeID, string employeeName)
    {
        this->employeeID = employeeID;
        this->employeeName = employeeName;
    }
    
    // Less than operator - compares employees by ID for BST ordering
    // Used when inserting nodes to determine left/right placement
    bool operator<(const EmployeeInfo &personObject)
    {
        return this->employeeID < personObject.employeeID;
    }
    
    // Greater than operator - compares employees by ID for BST ordering
    // Used when inserting nodes to determine left/right placement
    bool operator>(const EmployeeInfo &personObject)
    {
        return this->employeeID > personObject.employeeID;
    }
    
    // Equality operator - checks if two employees have the same ID
    // Used for searching and comparing employee records
    bool operator==(const EmployeeInfo &personObject)
    {
        return (this->employeeID == personObject.employeeID);
    }
    
    // Friend function declaration for output stream operator
    friend ostream &operator<<(ostream &, EmployeeInfo);
};

// Output stream operator - defines how to display employee information
// Formats employee data for console output
ostream &operator<<(ostream &stream, EmployeeInfo personObj) {
    stream << "Employee ID Number: " << personObj.employeeID << "\t\t" 
           << "Employee Name: " << personObj.employeeName << endl;
    return stream;
}

// Main function - demonstrates BST operations with employee records
int main(void) {
    
    /*
    IMPORTANT: The data type stored in the BinaryTree must define overloaded operators:
        - '<' and '>' for ordering nodes in the binary search tree (BST).
        - '==' for comparing nodes during search and deletion operations.
        - '<<' for printing node values to the console.
    */
    
    // Create a BinaryTree instance to store EmployeeInfo objects
    // The tree will automatically order employees by their ID numbers
    BinaryTree<EmployeeInfo> tree;
    cout << "Inserting nodes.." << endl;
    cout << "\n\n\n";
    
    // Insert multiple EmployeeInfo objects into the tree
    // Each insertion will place the employee in the correct BST position based on ID
    tree.insertNode(EmployeeInfo(1021, "John Williams"));
    tree.insertNode(EmployeeInfo(1057, "Bill Witherspoon"));
    tree.insertNode(EmployeeInfo(2487, "Jennifer Twain"));
    tree.insertNode(EmployeeInfo(3769, "Sophia Lancaster"));
    tree.insertNode(EmployeeInfo(1017, "Debbie Reece"));
    tree.insertNode(EmployeeInfo(1275, "George McMullen"));
    tree.insertNode(EmployeeInfo(1899, "Ashley Smith"));
    tree.insertNode(EmployeeInfo(4218, "Josh Plemmons"));
    
    // Get employee ID to search for from user input
    int employeeID;
    cout << "Employee ID Number to search for: ";
    cin >> employeeID;
    
    // Search for employee by creating a temporary EmployeeInfo object with the target ID
    // The name field is empty since we're only comparing by ID
    EmployeeInfo empObj = tree.searchNode(EmployeeInfo(employeeID, ""));
    
    // Check if search was successful by comparing with default EmployeeInfo object
    // If searchNode returns default object, employee was not found
    if (empObj == EmployeeInfo())
        cout << "Employee with ID " << employeeID << " was not found in the tree." << endl;
    else 
        // Employee found - display their complete information
        cout << empObj << endl;
    
    return 0;
}