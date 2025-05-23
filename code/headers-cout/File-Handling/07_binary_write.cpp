#include <iostream>
#include <fstream>

using namespace std;

struct Student {
    char name[50];
    int age;
    double gpa;
};

int main() {
    // Create sample student data
    Student students[3] = {
        {"Alice Smith", 20, 3.75},
        {"Bob Johnson", 22, 3.45},
        {"Carol Davis", 21, 3.91}
    };
    
    // Open file in binary mode for writing
    ofstream outFile("students.bin", ios::binary);
    
    if (!outFile) {
        cerr << "Error: Could not open file for binary writing!" << endl;
        return 1;
    }
    
    // Write the array of structures to the file
    outFile.write(reinterpret_cast<char*>(students), sizeof(students));
    
    cout << "Binary data has been written to students.bin" << endl;
    
    return 0;
}