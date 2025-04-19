// 02-scopes.cpp : define three variables with the same name in one program

#include <iostream>
#include <format>
using namespace std;

auto a{ 1.5f };

int main() {
    cout << format("(1) {}\n", a);
    auto a{ 2u };
    cout << format("(2) {}\n", a);
    {
        auto a{ 2.5 };
        cout << format("(3) {}\n", a);
    }
}
