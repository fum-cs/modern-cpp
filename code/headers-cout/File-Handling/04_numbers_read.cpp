#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

int main() {
    // Create an input file stream
    ifstream inFile("numbers.txt");
    
    if (!inFile) {
        cerr << "Error: Could not open file for reading!" << endl;
        return 1;
    }
    
    // Read numbers from the file
    int number, square;
    
    cout << "Reading from numbers.txt:" << endl;
    cout << "Number | Square" << endl;
    cout << "-------|-------" << endl;
    
    while (inFile >> number >> square) {
        cout << setw(7) << number << " | " << setw(6) << square << endl;
    }
    
    cout << "Finished reading the file." << endl;
    
    return 0;
}