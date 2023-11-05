#include <iostream>

#include "midland++.hpp"

int main() {
    BoolVector temp = "10101010101010", t;
    std::cout << temp;
    temp >>= 3;
    std::cout << temp;
    return 0;
}
