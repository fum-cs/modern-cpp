// 01-title.cpp : output the title page of a well-known book

#include <iostream>
#include <format>
using namespace std;

int main() {
    cout << format(1+R"(
                   Alice's
                Adventures In
                 Wonderland

                     by
                LEWIS CARROLL
)");
}
