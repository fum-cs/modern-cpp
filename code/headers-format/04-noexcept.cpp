// 04-noexcept.cpp : a noexcept function throwing an exception

#include <iostream>
#include <format>
#include <stdexcept>
using namespace std;

void throw_if_zero(int i) noexcept {
    if (!i) {
        throw runtime_error("found a zero");
    }
    cout << format("throw_if_zero(): {}\n", i);
}

int main() {
    cout << format("Entering main()\n");
    try {
        throw_if_zero(1);
        throw_if_zero(0);
    }
    catch(exception& e) {
        cout << format("Caught an exception: {}\n", e.what());
    }
    cout << format("Leaving main()\n");
}
