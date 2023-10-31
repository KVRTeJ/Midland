#include <iostream>

#include "midland++.hpp"

int main() {
    //BoolVector a(17, 11);
    //a.set(t);
    //a.unSet(t);
    //a.scan();
    BoolVector a = "111111111";
    a.print();
    
    BoolVector b = a;
    b.print();
    
    return 0;
}
