#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <iomanip>

using namespace std;

int main() {
    // Open file for reading
    ifstream phoneFile("phone_directory.txt");
    
    if (!phoneFile) {
        cerr << "Error: Could not open phone directory file!" << endl;
        return 1;
    }
    
    cout << "Phone Directory" << endl;
    cout << "==============" << endl;
    cout << setw(15) << left << "Phone Number" << " | " << "Name" << endl;
    cout << "--------------- | ---------------" << endl;
    
    string line;
    long phoneNumber;
    string name;
    
    while (getline(phoneFile, line)) {
        // Parse the line using stringstream
        stringstream ss(line);
        
        // Extract phone number and name separated by comma
        if (getline(ss, line, ',')) {
            phoneNumber = stol(line);
            
            if (getline(ss, name)) {
                cout << setw(15) << left << phoneNumber << " | " << name << endl;
            }
        }
    }
    
    cout << "\nEnd of directory" << endl;
    
    return 0;
}