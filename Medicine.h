#pragma once
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <stdexcept>
using namespace std;

class Medicine {
    string name;
    int code;
    string expiryDate;
    float* price;
    string location;
    int quantity;

public:
    Medicine(); // Default constructor
    Medicine(string name, int code, string expiryDate, float purchasePrice, float sellingPrice, string location, int quantity); // Parameterized constructor
    ~Medicine(); // Destructor

    // Setter methods
    void setName(string name);
    void setCode(int code);
    void setExpiryDate(string expiryDate);
    void setPurchasePrice(float purchasePrice);
    void setSellingPrice(float sellingPrice);
    void setLocation(string location);
    void setQuantity(int quantity);

    // Getter methods
    string getName();
    int getCode();
    string getExpiryDate();
    float getPurchasePrice();
    float getSellingPrice();
    string getLocation();
    int getQuantity();

    void writeToFile(); // Method to write medicine details to a file
    string toString(); // Method to convert medicine object to a string and check the state of the object
    static int countMedicines(); // Static method to count the number of medicines in the file
    static string viewAllMedicines(); // Static method to view all medicine records
};
