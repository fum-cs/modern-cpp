#include <iostream>
#include <fstream>

using namespace std;

int main() {
    // Create an output file stream
    ofstream outFile("basic_output.txt");
    
    // Check if file opened successfully
    if (!outFile) {
        cerr << "Error: Could not open file for writing!" << endl;
        return 1;
    }
    
    // Write some text to the file
    outFile << "Hello, this is my first file!" << endl;
    outFile << "Writing to files in C++ is easy." << endl;
    outFile << "This is line number 3." << endl;
    
    // File is automatically closed when outFile goes out of scope
    cout << "Data has been written to basic_output.txt" << endl;
    
    return 0;
}