// 02-constants.cpp : introducing the const keyword

#include <iostream>
#include <format>
using namespace std;

const double PI = 3.14159265358979;

int main() {
    auto const APPROX_E = 3;
    cout << format("pi is almost exactly {}, while e is approximately {}\n",
        PI, APPROX_E);
}
