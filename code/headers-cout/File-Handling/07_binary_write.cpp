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
    Student students[5] = {
        {"Anne Shirley", 11, 3.98},  // Highly imaginative and intelligent
        {"Diana Barry", 11, 3.65},   // Anne's kindred spirit and best friend
        {"Gilbert Blythe", 12, 3.89}, // Anne's academic rival 
        {"Ruby Gillis", 11, 3.20},    // One of Anne's schoolmates 
        {"Josie Pye", 11, 3.10}       // Another schoolmate who often competes with Anne
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