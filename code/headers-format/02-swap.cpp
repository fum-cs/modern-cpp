// 02-swap.cpp : attempt to swap the values of an int and a double

#include <iostream>
#include <format>
using namespace std;

int main() {
    int a = 1;
    double b = 2.5;
    cout << format("(1) a = {}, b = {}\n", a, b);
    a = 2.5;
    b = 1;
    cout << format("(2) a = {}, b = {}\n", a, b);
}
