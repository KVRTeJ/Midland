#include <iostream>

#include "midland++.hpp"

int main() {
    BoolVector t;
    t[2] = true;
    t.print();
    t[0] = t[0] ^ t[2];
    t.print();
    return 0;
}
