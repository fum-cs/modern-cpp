// 02-height.cpp : define the same variable name in two different namespaces

#include <iostream>
#include <format>
using namespace std;

namespace Wonderland {
    auto alice_height_m{ 0.15 };
}

namespace VictorianEngland {
    auto alice_height_m{ 0.9 };
}

int main() {
    cout << format("Alice\'s height varies between {}m and {}m\n",
        Wonderland::alice_height_m,
        VictorianEngland::alice_height_m);
}
