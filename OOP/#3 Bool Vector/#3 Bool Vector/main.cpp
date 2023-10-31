#include <iostream>

#include "midland++.hpp"

int main() {
    BoolVector a = "1111111111", b(8);
    a.print();
    b.scan();
    b.print();
    
    return 0;
}
