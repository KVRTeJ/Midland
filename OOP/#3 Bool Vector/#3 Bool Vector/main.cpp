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
}
