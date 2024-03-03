#include "Medicine.h" // Including the header file for the Medicine class.

Medicine::Medicine() { // Definition of default constructor
    // Initializing member variables to default values
    name = "";
    code = 0;
    expiryDate = "";
    price = new float[2]; // Allocating memory for price array to store purchase and selling prices
    price[0] = 0.0; // Initializing purchase price
    price[1] = 0.0; // Initializing selling price
    location = "";
    quantity = 0;
}

Medicine::Medicine(string name, int code, string expiryDate, float purchasePrice, float sellingPrice, string location, int quantity) {
    // Definition of parameterized constructor
    // Setting member variables to provided values
    this->name = name;
    this->code = code;
    this->expiryDate = expiryDate;
    price = new float[2]; // Allocating memory for price array to store purchase and selling prices
    price[0] = purchasePrice; // Setting purchase price
    price[1] = sellingPrice; // Setting selling price
    this->location = location;
    this->quantity = quantity;
}

Medicine::~Medicine() { // Definition of destructor
    delete[] price; // Deallocating memory for price array
}

void Medicine::setName(string name) { // Setter method for name
    this->name = name;
}

void Medicine::setCode(int code) { // Setter method for code
    this->code = code;
}

void Medicine::setExpiryDate(string expiryDate) { // Setter method for expiry date
    this->expiryDate = expiryDate;
}

void Medicine::setPurchasePrice(float purchasePrice) { // Setter method for purchase price
    price[0] = purchasePrice;
}

void Medicine::setSellingPrice(float sellingPrice) { // Setter method for selling price
    price[1] = sellingPrice;
}

void Medicine::setLocation(string location) { // Setter method for location
    this->location = location;
}

void Medicine::setQuantity(int quantity) { // Setter method for quantity
    this->quantity = quantity;
}

string Medicine::getName() { // Getter method for name
    return name;
}

int Medicine::getCode() { // Getter method for code
    return code;
}

string Medicine::getExpiryDate() { // Getter method for expiry date
    return expiryDate;
}

float Medicine::getPurchasePrice() { // Getter method for purchase price
    return price[0];
}

float Medicine::getSellingPrice() { // Getter method for selling price
    return price[1];
}

string Medicine::getLocation() { // Getter method for location
    return location;
}

int Medicine::getQuantity() { // Getter method for quantity
    return quantity;
}

void Medicine::writeToFile() { // Method to write medicine details to a file
    ofstream file("medicine_list.txt", ios::app); // Opening file in append mode
    if (!file.is_open()) { // Checking if file is opened successfully
        throw runtime_error("Unable to open file for writing."); // Throwing runtime error if file opening fails
    }
    // Writing medicine details to file
    file << name << setw(12) << code << setw(12) << expiryDate << setw(12) << price[0] << setw(12) << price[1] << setw(12) << location << setw(12) << quantity << endl;
    file.close(); // Closing the file
}

string Medicine::toString() { // Method to convert medicine object to a string and check the state of the object
    return "Name: " + name + ", Code: " + to_string(code) + ", Expiry Date: " + expiryDate + ", Purchase Price: " + to_string(price[0]) + ", Selling Price: " + to_string(price[1]) + ", Location: " + location + ", Quantity: " + to_string(quantity);
}

int Medicine::countMedicines() { // Static method to count the number of medicines in the file
    ifstream file("medicine_list.txt"); // Opening file for reading
    if (!file.is_open()) { // Checking if file is opened successfully
        throw runtime_error("Unable to open file for reading."); // Throwing runtime error if file opening fails
    }
    int count = 0;
    string line;
    while (getline(file, line)) { // Counting lines in the file
        count++;
    }
    file.close(); // Closing the file
    return count;
}

string Medicine::viewAllMedicines() { // Static method to view all medicine records
    ifstream file("medicine_list.txt"); // Opening file for reading
    if (!file.is_open()) { // Checking if file is opened successfully
        throw runtime_error("Unable to open file for reading."); // Throwing runtime error if file opening fails
    }
    string result;
    string line;
    while (getline(file, line)) { // Reading lines from the file and appending to result
        result += line + "\n";
    }
    file.close(); // Closing the file
    return result;
}
