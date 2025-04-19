// 04-inline.cpp : use of an inline function

#include <iostream>
#include <format>
using namespace std;

inline void swap(int& x, int& y) {
    auto z = x;
    x = y;
    y = z;
}

int main() {
    int a = 1, b = 2;
    cout << format("(1) a = {}, b = {}\n", a, b);
    swap(a, b);
    cout << format("(2) a = {}, b = {}\n", a, b);
}
