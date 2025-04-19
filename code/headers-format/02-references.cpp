// 02-references.cpp : introducing l-value references

#include <iostream>
#include <format>
using namespace std;

int alice_age{ 9 };

int main() {
    cout << format("Alice\'s age is {}\n", alice_age);
    int& alice_age_ref = alice_age;
    alice_age_ref = 10;
    cout << format("Alice\'s age is now {}\n", alice_age);
}
