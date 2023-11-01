#include <iostream>

#include "midland++.hpp"

int main() {
    
    BoolVector a = "11001100", b(8, 1), c(22);
    
    /*
    //c = a ^ b;
    std::cout << c;
    c[0] = c[0] ^ 1;
    std::cout << c;
    */
    a[0] = a[0] ^ 0;
    std::cout << a;
    return 0;
}
