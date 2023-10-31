#include <iostream>

#include "midland++.hpp"

int main() {
    BoolVector a(17, 11);
    unsigned int t = 0;
    //a.set(t);
    //a.unSet(t);
    a.scan();
    a.print();
    
    return 0;
}
