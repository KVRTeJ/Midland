#include <iostream>

#include "midland++.hpp"

int main() {
    BoolVector temp = "11101010", t1(9, 0), t2(9, 1), t3;
    std::cout << t1 << t2;
    t3 = t1 | t2;
    std::cout << t1 << t2 << "t3" << t3;
    return 0;
}
