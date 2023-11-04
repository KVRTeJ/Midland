#include <iostream>

#include "midland++.hpp"

int main() {
    BoolVector temp = "111010111", t1(9, 0), t2(9, 1), t3;
    temp.set(0, 8, 0);
    std::cout << temp;
    return 0;
}
