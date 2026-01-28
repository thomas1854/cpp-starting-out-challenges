/**
 * Challenge-12:
 *  12. Inventory Bin Stack
            Design an inventory class that stores the following members:
            serialNum:
            manufactDate:
            lotNum:
            An integer that holds a part’s serial number.
            A member that holds the date the part was manufactured.
            An integer that holds the part’s lot number.
            The class should have appropriate member functions for storing data into, and retriev
            ing data from, these members.
            Next, design a stack class that can hold objects of the class described above. If you 
            wish, you may use the template you designed in Programming Challenge 1 or 2.
            Last, design a program that uses the stack class described above. The program should 
            have a loop that asks the user if he or she wishes to add a part to inventory, or take a 
            part from inventory. The loop should repeat until the user is finished.
            If the user wishes to add a part to inventory, the program should ask for the serial 
            number, date of manufacture, and lot number. The data should be stored in an inven
            tory object, and pushed onto the stack.
            If the user wishes to take a part from inventory, the program should pop the top-most 
            part from the stack and display the contents of its member variables.
            When the user finishes the program, it should display the contents of the member val
            ues of all the objects that remain on the stack.
 * 
 */

#include <iostream>
#include <iomanip>
#include "../Challenge-02/Stack.h"
using namespace std;

/**
 * @class Inventory
 * @brief Represents an inventory item with serial number, manufacture date, and lot number
 */
class Inventory
{
private:
    int serialNum;      ///< Serial number of the part
    string manufactDate; ///< Date of manufacture
    int lotNum;         ///< Lot number of the part

public:
    /**
     * @brief Default constructor - initializes all fields to default values
     */
    Inventory()
    {
        this->lotNum = 0;
        this->manufactDate = "";
        this->serialNum = 0;
    }
    
    /**
     * @brief Parameterized constructor
     * @param serialNum Serial number of the part
     * @param manufactDate Manufacturing date as string
     * @param lotNum Lot number of the part
     */
    Inventory(int serialNum, string manufactDate, int lotNum)
    {
        this->lotNum = lotNum;
        this->manufactDate = manufactDate;
        this->serialNum = serialNum;
    }
    
    /**
     * @brief Gets the lot number
     * @return Lot number as integer
     */
    int getLotNum() const { return lotNum; }
    
    /**
     * @brief Gets the serial number
     * @return Serial number as integer
     */
    int getSerialNum() const { return serialNum; }
    
    /**
     * @brief Gets the manufacturing date
     * @return Manufacturing date as string
     */
    string getManufactDate() const { return manufactDate; }
};

/**
 * @brief Overloaded stream insertion operator for Inventory objects
 * @param outputStream Output stream reference
 * @param inventoryObject Inventory object to output
 * @return Reference to the output stream
 */
ostream &operator<<(ostream &outputStream, const Inventory &inventoryObject)
{
    outputStream << "Part serial number: " << inventoryObject.getSerialNum() << endl;
    outputStream << "Part date of manufacture: " << inventoryObject.getManufactDate() << endl;
    outputStream << "Part lot number: " << inventoryObject.getLotNum() << endl;
    return outputStream;
}

/**
 * @brief Adds a new part to the inventory stack
 * @param st Reference to the inventory stack
 * @note Prompts user for serial number, manufacture date, and lot number
 */
void addPart(Stack<Inventory> &st)
{
    int serialNum;
    string manufactDate;
    int lotNum;
    cout << "Enter part serial number: ";
    cin >> serialNum;
    cout << "Enter part date of manufacture: ";
    cin >> manufactDate;
    cout << "Enter part lot number: ";
    cin >> lotNum;
    Inventory inventory(serialNum, manufactDate, lotNum);
    st.push(inventory);
}

/**
 * @brief Removes and displays the top part from the inventory stack
 * @param st Reference to the inventory stack
 * @note Displays message if stack is empty
 */
void takePart(Stack<Inventory> &st)
{
    if (st.isEmpty())
        cout << "The inventory stack is empty." << endl;
    else
    {
        Inventory inventory;
        st.pop(inventory);
        cout << inventory << endl;
    }
}

/**
 * @brief Removes and displays all parts from the inventory stack
 * @param st Reference to the inventory stack
 * @note Empties the entire stack, displaying each item
 */
void finish(Stack<Inventory> &st)
{
    if (st.isEmpty())
        cout << "The inventory stack is empty." << endl;
    else
    {
        while (!st.isEmpty())
        {
            Inventory inventory;
            st.pop(inventory);
            cout << inventory << endl;
        }
    }
}

/**
 * @brief Main function - provides menu-driven interface for inventory management
 * @return Exit status (0 for success)
 * 
 * @details Menu options:
 * - 1: Add a new part to inventory
 * - 2: Remove and display top part
 * - 3: Remove and display all parts, then exit
 */
int main(void)
{
    Stack<Inventory> st;
    int option;
    do
    {
        string separator(20, '=');
        cout << separator << endl;
        cout << "|Choose an option: |" << endl;
        cout << "|1- Add part       |" << endl;
        cout << "|2- Take part      |" << endl;
        cout << "|3- Finish         |" << endl;
        cout << separator << endl;
        cin >> option;
        cin.ignore();
        switch (option)
        {
        case 1:
            addPart(st);
            break;
        case 2:
            takePart(st);
            break;
        case 3:
            finish(st);
            break;
        default:
            cout << "Invalid choice" << endl;
            break;
        }
    } while (option != 3);

    return 0;
}