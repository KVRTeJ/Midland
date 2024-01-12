#include "Set.hpp"
#include "assert.h"
#include <chrono>
#include <thread>

int main() {
    Set a, b, c;
    c = ~a;
    for(int i = 0; i < 150; ++i) {
        a += (char) i;
        if(i > 31 && i < 127)
            assert(a.contains((char) i));
        b = ~a;
        assert( !(b.contains((char) i)) );
        std::cout << "a = " << a << "\nb = " << b << "\n";
        assert((a | b) == c);
    }
    
    std::cout << "The First test comleted. . .\n" << std::endl;
    std::cout << "The Second test started in. . .\n";
    for(int i = 5; i >= 1; --i) {
        std::cout << i << "\n";
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
    
    std::cout << "Enter foo: ";
    Set foo;
    std::cin >> foo;
    /*
     /NULL, /SOH, /STX, /ETX, /EOT, /ENQ, /ACK, /BEL, /BS, /HT, /LF, /VT, /FF, /CR, /SO, /SI, /DLE, /DC1, /DC2, /DC3, /DC4, /NAK, /SYN, /ETB, /CAN, /EM, /SUB, /ESC, /FS, /GS, /RS, /US, /SPACE /FAKE
     */
    foo -= ',';
    foo -= 'F';
    foo -= 'A';
    Set boo(foo);
    boo -= 'K';
    boo -= 'E';
    boo -= '/';
    foo = boo;
    std::cout << "Key Words: \n" << foo << std::endl;
    assert(boo.cardinalis() == Set::NOT_ENTERED_CHARAPTERS.size());
    int i = 0;
    while(foo.cardinalis() != 0) {
        if(i % 2)
            foo -= foo.max();
        else
            foo -= foo.min();
        ++i;
        boo = foo;
        if(boo == foo) {
            std::cout << boo << std::endl;
        } else if(boo != foo) {
            assert(false);
        } else {
            assert(false);
        }
        assert(boo.cardinalis() == Set::NOT_ENTERED_CHARAPTERS.size() - i);
    }
    
    return 0;
}
