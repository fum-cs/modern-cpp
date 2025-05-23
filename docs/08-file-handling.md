---
layout: default
title:  File Handling
nav_order: 11
tags: [Computer Science Dept., Ferdowsi University of Mashhad, علوم کامپیوتر دانشگاه فردوسی مشهد]
---

# C++ File Handling Tutorial
{: .no_toc }

## Table of contents
{: .no_toc .text-delta }

1. TOC
{:toc}

---



This tutorial covers the basics of file handling in C++. We'll explore how to read from and write to files using various techniques.

## 1. Introduction to File Streams

C++ provides several classes for file handling through the `<fstream>` header:
- `ofstream`: Output file stream for writing to files
- `ifstream`: Input file stream for reading from files
- `fstream`: File stream for both reading and writing

## 2. Writing to Files

### Basic File Writing

```cpp
// Program 01_basic_write.cpp
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
```

This program demonstrates:
- Creating an output file stream with `ofstream`
- Writing text to a file using the insertion operator (`<<`)
- Automatic file closing when the stream goes out of scope

### Writing Numbers to Files

```cpp
// Program 03_numbers_write.cpp
```

This program shows how to:
- Write formatted numerical data to a file
- Use loops to generate and write multiple values

## 3. Reading from Files

### Basic File Reading

```cpp
// Program 02_basic_read.cpp
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
```

This program demonstrates:
- Opening a file for reading with `ifstream`
- Reading a file line by line using `getline()`
- Error checking to ensure the file opened successfully


### Writing Numbers to File

```cpp
// Program 03_numbers_write.cpp
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
```

### Reading Numbers from Files

```cpp
// Program 04_numbers_read.cpp
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

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
```

This program shows how to:
- Read numerical data from a file
- Use the extraction operator (`>>`) to read formatted data
- Format the output for better readability

### Reading Word by Word

```cpp
// Program 05_word_by_word.cpp
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
```

This program demonstrates:
- Reading a file word by word instead of line by line
- Counting words in a file

## 4. Appending to Files

```cpp
// Program 06_append_to_file.cpp
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
```

This program shows how to:
- Open a file in append mode using the `ios::app` flag
- Add new content to the end of an existing file

## 5. Binary File Operations

Binary files store data in the same format as it's represented in memory, without any formatting or conversion.

### Writing Binary Data

```cpp
// Program 07_binary_write.cpp
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
```

This program demonstrates:
- Creating a structure to hold data
- Opening a file in binary mode
- Using `write()` to write binary data to a file

### Reading Binary Data

```cpp
// Program 08_binary_read.cpp
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
```

This program shows how to:
- Open a binary file for reading
- Use `read()` to read binary data from a file
- Display the structured data

## 6. File Positioning (Further Reading)

```cpp
// Program 09_file_position.cpp
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    // Open file for both reading and writing
    fstream file("position_demo.txt", ios::in | ios::out | ios::trunc);
    
    if (!file) {
        cerr << "Error: Could not open file!" << endl;
        return 1;
    }
    
    // Write some data to the file
    file << "Line 1: This is the first line." << endl;
    file << "Line 2: This is the second line." << endl;
    file << "Line 3: This is the third line." << endl;
    
    // Get current position
    streampos currentPos = file.tellp();
    cout << "Current position after writing: " << currentPos << endl;
    
    // Move to the beginning of the file for reading
    file.seekg(0, ios::beg);
    
    // Read and display the file content
    string line;
    cout << "\nFile content:" << endl;
    while (getline(file, line)) {
        cout << line << endl;
    }
    
    // Move to a specific position and modify content
    file.seekp(0, ios::beg); // Move to the beginning
    file << "MODIFIED: This replaces the first line.";
    
    // Move to the beginning again and read the modified content
    file.seekg(0, ios::beg);
    cout << "\nModified file content:" << endl;
    while (getline(file, line)) {
        cout << line << endl;
    }
    
    return 0;
}
```

This program demonstrates:
- Opening a file for both reading and writing
- Using `tellp()` and `tellg()` to get the current position
- Using `seekp()` and `seekg()` to move to specific positions in the file
- Modifying content at specific positions

## 7. Error Handling

```cpp
// Program 10_error_handling.cpp
#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

int main() {
    // Try to open a file that doesn't exist
    ifstream inFile("nonexistent_file.txt");
    
    // Check if file opened successfully
    if (!inFile) {
        cerr << "Error: Could not open nonexistent_file.txt" << endl;
        cerr << "Error state: " << strerror(errno) << endl;
    }
    
    // Try to create a file in a directory that doesn't exist
    ofstream outFile("nonexistent_directory/new_file.txt");
    
    if (!outFile) {
        cerr << "Error: Could not create file in nonexistent directory" << endl;
        cerr << "Error state: " << strerror(errno) << endl;
    }
    
    // Try to open a file with proper error handling
    string filename = "test_file.txt";
    ifstream testFile(filename);
    
    try {
        if (!testFile) {
            throw runtime_error("Could not open file: " + filename);
        }
        
        // File operations would go here
        
    } catch (const exception& e) {
        cerr << "Exception: " << e.what() << endl;
    }
    
    cout << "Program continues despite file errors" << endl;
    
    return 0;
}
```

This program shows:
- How to check if a file opened successfully
- Error reporting using `cerr`
- Using exceptions for more robust error handling

## 8. Practical Example: Phone Directory

### Reading Anne_of_Green_Gables.txt

```cpp
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
```

This program:

1. Opens the Anne_of_Green_Gables.txt file
2. Reads it line by line
3. Displays each line to the console
4. Pauses after every 20 lines to make it easier to read
5. Shows the total number of lines at the end

### Writing to a Phone Directory

```cpp
// Program 11_phone_directory_write.cpp
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    // Open file for writing
    ofstream phoneFile("phone_directory.txt");
    
    if (!phoneFile) {
        cerr << "Error: Could not open file for writing!" << endl;
        return 1;
    }
    
    long phoneNumber;
    string name;
    
    cout << "Phone Directory Entry System" << endl;
    cout << "===========================" << endl;
    cout << "Enter phone number and name (enter 0 as phone number to quit)" << endl;
    
    while (true) {
        cout << "\nPhone Number: ";
        cin >> phoneNumber;
        
        if (phoneNumber == 0)
            break;
        
        // Clear the input buffer
        cin.ignore();
        
        cout << "Name: ";
        getline(cin, name);
        
        // Write to file
        phoneFile << phoneNumber << "," << name << endl;
        
        cout << "Entry added successfully!";
    }
    
    cout << "\nAll entries have been saved to phone_directory.txt" << endl;
    
    return 0;
}
```

This program demonstrates:
- Creating a simple phone directory application
- Reading user input and writing it to a file
- Using a comma as a delimiter between fields

### Reading from a Phone Directory

```cpp
// Program 12_phone_directory_read.cpp
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <iomanip>

using namespace std;

int main() {
    // Open file for reading
    ifstream phoneFile("phone_directory.txt");
    
    if (!phoneFile) {
        cerr << "Error: Could not open phone directory file!" << endl;
        return 1;
    }
    
    cout << "Phone Directory" << endl;
    cout << "==============" << endl;
    cout << setw(15) << left << "Phone Number" << " | " << "Name" << endl;
    cout << "--------------- | ---------------" << endl;
    
    string line;
    long phoneNumber;
    string name;
    
    while (getline(phoneFile, line)) {
        // Parse the line using stringstream
        stringstream ss(line);
        
        // Extract phone number and name separated by comma
        if (getline(ss, line, ',')) {
            phoneNumber = stol(line);
            
            if (getline(ss, name)) {
                cout << setw(15) << left << phoneNumber << " | " << name << endl;
            }
        }
    }
    
    cout << "\nEnd of directory" << endl;
    
    return 0;
}
```

This program shows:
- Reading and parsing a CSV-like file format
- Using `stringstream` to parse each line
- Displaying formatted output

## Summary

This tutorial covered the essential aspects of file handling in C++:

1. **Basic Operations**: Opening, reading, writing, and closing files
2. **Text Files**: Reading and writing text data
3. **Binary Files**: Reading and writing binary data
4. **File Positioning**: Moving within a file
5. **Error Handling**: Dealing with file operation errors
6. **Practical Application**

File handling is a fundamental skill in C++ programming, allowing you to store and retrieve data persistently. These examples provide a foundation for more advanced file operations in your applications.