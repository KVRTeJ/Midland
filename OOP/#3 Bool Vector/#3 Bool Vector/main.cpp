#include <iostream>

#include "midland++.hpp"

int main() {
    
    BoolVector t(16, 0);
    t[2] = true;
    t[10] = true;
    t = ~t;
    t.print();
    /*
    t = t >> 16;
    t.print();
    
    
    return 0;
     */
    
    if(t[0] == true) {
        std::cout << "t[2] == t[10] " << std::endl;
    }
    if(t[1] == t[1]) {
        std::cout << "t[1] == t[1] " << std::endl;
    }
    
    return 0;
}
