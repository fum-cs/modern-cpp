#include <iostream>
#include <fstream>

using namespace std;

int main() {
    // Create an output file stream
    ofstream outFile("numbers.txt");
    
    if (!outFile) {
        cerr << "Error: Could not open file for writing!" << endl;
        return 1;
    }
    
    // Write squares of numbers from 1 to 10
    cout << "Writing squares of numbers 1-10 to numbers.txt" << endl;
    
    for (int i = 1; i <= 10; i++) {
        outFile << i << " " << (i * i) << endl;
    }
    
    cout << "Data has been written to numbers.txt" << endl;
    
    return 0;
}