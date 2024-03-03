#include <iostream> // Including necessary header files
#include "Medicine.h" // Including the header file for the Medicine class
using namespace std; // Using the standard namespace

int main() { // Main function definition
    string name, expiryDate, location; // Declaring variables to store user input
    int code, quantity;
    float purchasePrice, sellingPrice;

    Medicine medicine; // Creating an instance of the Medicine class

    cout << "Enter details for a medicine: " << endl; // Prompting user to enter medicine details

    cout << "Enter name of the medicine: "; // Getting name of the medicine
    getline(cin, name);

    cout << "Enter code of the medicine: "; // Getting code of the medicine
    cin >> code;
    cin.ignore(); // Ignore newline character left in the input buffer

    cout << "Enter expiry date of the medicine: "; // Getting expiry date of the medicine
    getline(cin, expiryDate);

    cout << "Enter purchase price of the medicine: "; // Getting purchase price of the medicine
    cin >> purchasePrice;

    cout << "Enter selling price of the medicine: "; // Getting selling price of the medicine
    cin >> sellingPrice;

    cout << "Enter location of the medicine: "; // Getting location of the medicine
    cin.ignore(); // Ignore newline character left in the input buffer
    getline(cin, location);

    cout << "Enter quantity of the medicine: "; // Getting quantity of the medicine
    cin >> quantity;

    // Setting medicine object properties using setter methods
    medicine.setName(name);
    medicine.setCode(code);
    medicine.setExpiryDate(expiryDate);
    medicine.setPurchasePrice(purchasePrice);
    medicine.setSellingPrice(sellingPrice);
    medicine.setLocation(location);
    medicine.setQuantity(quantity);

    // Writing medicine details to file
    medicine.writeToFile();

    // Displaying medicine details
    cout << "\nMedicine details: " << endl;
    cout << medicine.toString() << endl;

    // Displaying count of medicines in the file
    cout << "\nCount of medicines in the file: " << Medicine::countMedicines() << endl;

    // Viewing all medicine records
    cout << "\nViewing all medicine records: " << endl;
    cout << medicine.viewAllMedicines() << endl;

    return 0; // Returning 0 to indicate successful execution
}
