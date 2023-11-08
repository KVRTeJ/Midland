#include <iostream>

#include "midland++.hpp"

int main() {
    
    {
        BoolVector foo(30, 1);
        foo[28] = ~foo[0];
        for (int i = 0; i <= foo.getLenth(); ++i) {
            std::cout << "shift: " << i << " " << (i / 10 ? "":" ");
            (foo << i).print();
        }
    }
    std::cout << " shift << ended;\n shift >> started;\n";
    {
        BoolVector foo(30, 1);
        foo[1] = ~foo[0];
        for (int i = 0; i <= foo.getLenth(); ++i) {
            std::cout << "shift: " << i << " " << (i / 10 ? "":" ");
            (foo >> i).print();
        }
    }
    return 0;
    
    BoolVector t(16, 0);
    t[2] = true;
    
    //t[11] = true;
    t = ~t;
    t[7] = false;
    t.print();
    t >>= 1;
    t.print();
    if(t[0] == true) {
        std::cout << "t[2] == true " << std::endl;
    }
    if(t[1] == t[1]) {
        std::cout << "t[1] == t[1] " << std::endl;
    }
    
    return 0;
}
