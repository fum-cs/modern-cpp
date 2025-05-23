#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

struct Student {
    char name[50];
    int age;
    double gpa;
};

int main() {
    // Create an array to hold the read data
    Student students[3];
    
    // Open file in binary mode for reading
    ifstream inFile("students.bin", ios::binary);
    
    if (!inFile) {
        cerr << "Error: Could not open file for binary reading!" << endl;
        return 1;
    }
    
    // Read the array of structures from the file
    inFile.read(reinterpret_cast<char*>(students), sizeof(students));
    
    // Display the read data
    cout << "Student Information:" << endl;
    cout << "-------------------" << endl;
    
    for (int i = 0; i < 3; i++) {
        cout << "Name: " << students[i].name << endl;
        cout << "Age: " << students[i].age << endl;
        cout << "GPA: " << fixed << setprecision(2) << students[i].gpa << endl;
        cout << "-------------------" << endl;
    }
    
    return 0;
}