#include <iostream>

#include "midland++.hpp"

int main() {
    
    BoolVector a = "11001100", b(8, 1), c(22, 0);
    
    //c = a ^ b;
    std::cout << c;
    ~c;
    std::cout << c;
    
    return 0;
}
