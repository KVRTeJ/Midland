#include <iostream>

#include "midland++.hpp"

int main() {
    BoolVector a = "111100001111000011110000";
    a >>= 1;
    a.print();
    return 0;
}
