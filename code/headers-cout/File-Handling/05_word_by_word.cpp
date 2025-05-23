#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    // Create an input file stream
    ifstream inFile("basic_output.txt");
    
    if (!inFile) {
        cerr << "Error: Could not open file for reading!" << endl;
        return 1;
    }
    
    // Read the file word by word
    string word;
    int wordCount = 0;
    
    cout << "Reading file word by word:" << endl;
    
    while (inFile >> word) {
        wordCount++;
        cout << "Word " << wordCount << ": " << word << endl;
    }
    
    cout << "Total words: " << wordCount << endl;
    
    return 0;
}