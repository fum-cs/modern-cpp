#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    // Open file for both reading and writing
    fstream file("position_demo.txt", ios::in | ios::out | ios::trunc);
    
    if (!file) {
        cerr << "Error: Could not open file!" << endl;
        return 1;
    }
    
    // Write some data to the file
    file << "Line 1: This is the first line." << endl;
    file << "Line 2: This is the second line." << endl;
    file << "Line 3: This is the third line." << endl;
    
    // Get current position
    streampos currentPos = file.tellp();
    cout << "Current position after writing: " << currentPos << endl;
    
    // Move to the beginning of the file for reading
    file.seekg(0, ios::beg);
    
    // Read and display the file content
    string line;
    cout << "\nFile content:" << endl;
    while (getline(file, line)) {
        cout << line << endl;
    }
    
    // Move to a specific position and modify content
    file.seekp(0, ios::beg); // Move to the beginning
    file << "MODIFIED: This replaces the first line.";
    
    // Move to the beginning again and read the modified content
    file.seekg(0, ios::beg);
    cout << "\nModified file content:" << endl;
    while (getline(file, line)) {
        cout << line << endl;
    }
    
    return 0;
}