#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    // Open file for writing
    ofstream phoneFile("phone_directory.txt");
    
    if (!phoneFile) {
        cerr << "Error: Could not open file for writing!" << endl;
        return 1;
    }
    
    long phoneNumber;
    string name;
    
    cout << "Phone Directory Entry System" << endl;
    cout << "===========================" << endl;
    cout << "Enter phone number and name (enter 0 as phone number to quit)" << endl;
    
    while (true) {
        cout << "\nPhone Number: ";
        cin >> phoneNumber;
        
        if (phoneNumber == 0)
            break;
        
        // Clear the input buffer
        cin.ignore();
        
        cout << "Name: ";
        getline(cin, name);
        
        // Write to file
        phoneFile << phoneNumber << "," << name << endl;
        
        cout << "Entry added successfully!";
    }
    
    cout << "\nAll entries have been saved to phone_directory.txt" << endl;
    
    return 0;
}