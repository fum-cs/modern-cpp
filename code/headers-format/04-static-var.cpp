// 04-static-var.cpp : preserving function state in a static variable

#include <iostream>
#include <format>
using namespace std;

void f() {
    static int s{1};
    cout << format("{}\n", s);
    ++s;
}

int main() {
    f();
    f();
    f();
}
