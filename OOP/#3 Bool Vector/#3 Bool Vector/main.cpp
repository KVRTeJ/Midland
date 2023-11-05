#include <iostream>

#include "midland++.hpp"

int main() {
    BoolVector temp = "10101010101010", t;
    t = temp >> 1;
    std::cout << temp << t;
    return 0;
}
