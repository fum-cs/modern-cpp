// 02-assign.cpp : assign to local variables

#include <iostream>
#include <format>
using namespace std;

int main() {
    int i = 1, j = 2;
    unsigned k;
    cout << format("(1) i = {}, j = {}, k = {}\n", i, j, k);
    i = j;
    j = 3;
    k = -1;
    cout << format("(2) i = {}, j = {}, k = {}\n", i, j, k);
}
