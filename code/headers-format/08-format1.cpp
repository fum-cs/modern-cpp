// 08-format1.cpp : Basic usage of format string

#include <iostream>
#include <format>
#include <string>
using namespace std;

int main() {
    string s{ "Formatted" };
    auto d{ 10.0 / 3.0 };
    auto i{ 20000 };
    cout << format("{0:20}:{2:8}, {1:12.11}\n", s, d, i);
}
