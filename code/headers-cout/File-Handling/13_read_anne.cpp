#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    // Open the file for reading
    ifstream anneFile("Anne_of_Green_Gables.txt");
    
    // Check if the file opened successfully
    if (!anneFile) {
        cerr << "Error: Could not open Anne_of_Green_Gables.txt" << endl;
        return 1;
    }
    
    cout << "=== Anne of Green Gables ===" << endl;
    cout << "Reading the file line by line:" << endl;
    cout << "----------------------------" << endl;
    
    // Read and display the file line by line
    string line;
    int lineCount = 0;
    
    while (getline(anneFile, line)) {
        lineCount++;
        cout << line << endl;
        
        // Pause after every 20 lines to make reading easier
        if (lineCount % 20 == 0) {
            cout << "\nPress Enter to continue...";
            cin.get();
            cout << "----------------------------" << endl;
        }
    }
    
    cout << "\nEnd of file reached." << endl;
    cout << "Total lines read: " << lineCount << endl;
    
    // File is automatically closed when anneFile goes out of scope
    
    return 0;
}