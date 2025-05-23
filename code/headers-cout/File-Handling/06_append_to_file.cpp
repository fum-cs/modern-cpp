#include <iostream>
#include <fstream>

using namespace std;

int main() {
    // Open file in append mode
    ofstream outFile("basic_output.txt", ios::app);
    
    if (!outFile) {
        cerr << "Error: Could not open file for appending!" << endl;
        return 1;
    }
    
    // Append new content to the file
    outFile << "\nThis line was appended later." << endl;
    outFile << "Appending is done using ios::app flag." << endl;
    
    cout << "Data has been appended to basic_output.txt" << endl;
    
    return 0;
}