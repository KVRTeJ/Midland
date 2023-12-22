#include "Set.hpp"


int main() {
    Set temp;
    std::cin >> temp;
    std::cout << temp;
    
    return -1;
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
    return 0;
}
