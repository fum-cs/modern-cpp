#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    // Create an input file stream
    ifstream inFile("basic_output.txt");
    
    // Check if file opened successfully
    if (!inFile) {
        cerr << "Error: Could not open file for reading!" << endl;
        return 1;
    }
    
    // Read the file line by line
    string line;
    int lineNumber = 1;
    
    while (getline(inFile, line)) {
        cout << "Line " << lineNumber << ": " << line << endl;
        lineNumber++;
    }
    
    // File is automatically closed when inFile goes out of scope
    cout << "Finished reading the file." << endl;
    
    return 0;
}