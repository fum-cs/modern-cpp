---
layout: default
title: Introduction to Structs in C++
nav_order: 8
tags: [C++, Structs, Basics,Computer Science Dept., Ferdowsi University of Mashhad, علوم کامپیوتر دانشگاه فردوسی مشهد]
---

# Introduction to Structs in C++
{: .no_toc }

## Table of contents
{: .no_toc .text-delta }

1. TOC
{:toc}

---

## What is a `struct`?

In C++, a `struct` (short for "structure") is a user-defined data type that allows grouping multiple variables of different types into a single entity. It is particularly useful for representing objects with multiple attributes.

### Syntax

The basic syntax for defining a `struct` is as follows:

```cpp
struct StructName {
    // Member variables
    Type1 member1;
    Type2 member2;
    // ...
};
```

### Example: Defining and Using a `struct`

Here is an example of a `struct` representing a student:

```cpp
#include <iostream>
#include <string>
using namespace std;

struct Student {
    string name;
    int age;
    float grade;
};

int main() {
    Student student1;

    // Assign values to the struct members
    student1.name = "Alice";
    student1.age = 20;
    student1.grade = 85.5;

    // Access and display the struct members
    cout << "Name: " << student1.name << endl;
    cout << "Age: " << student1.age << endl;
    cout << "Grade: " << student1.grade << endl;

    return 0;
}
```

### Output

```
Name: Alice
Age: 20
Grade: 85.5
```

---

## Passing `struct` to Functions

You can pass a `struct` to a function in three ways: by value, by reference, or by pointer.

### Example: Passing by Value

When passing by value, a copy of the `struct` is made:

```cpp
#include <iostream>
#include <string>
using namespace std;

struct Student {
    string name;
    int age;
    float grade;
};

void displayStudent(Student s) {
    cout << "Name: " << s.name << ", Age: " << s.age << ", Grade: " << s.grade << endl;
}

int main() {
    Student student1 = {"Bob", 21, 90.0};
    displayStudent(student1);
    return 0;
}
```

### Example: Passing by Reference

Passing by reference avoids copying and allows modifying the original `struct`:

```cpp
void updateGrade(Student &s, float newGrade) {
    s.grade = newGrade;
}
```

### Example: Passing by Pointer

Passing by pointer is another way to modify the original `struct`:

```cpp
void updateGrade(Student *s, float newGrade) {
    s->grade = newGrade;
}
```

---

## Using Pointers with `struct`

You can create pointers to `struct` objects and access their members using the arrow operator (`->`).

### Example: Pointer to a `struct`

```cpp
#include <iostream>
#include <string>
using namespace std;

struct Student {
    string name;
    int age;
    float grade;
};

int main() {
    Student student1 = {"Charlie", 22, 88.0};
    Student *ptr = &student1;

    // Access members using the pointer
    cout << "Name: " << ptr->name << endl;
    cout << "Age: " << ptr->age << endl;
    cout << "Grade: " << ptr->grade << endl;

    return 0;
}
```

### Output

```
Name: Charlie
Age: 22
Grade: 88
```

---

## Summary

- A `struct` groups multiple variables into a single entity.
- You can pass `struct` objects to functions by value, reference, or pointer.
- Pointers to `struct` objects allow efficient access and modification of their members.

For more details, visit the [C++ Tutorial](https://codemistic.github.io/cpp).