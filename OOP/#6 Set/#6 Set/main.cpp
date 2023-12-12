#include "Set.hpp"

int main() {
    Set a, b;
    for(int i = 0; i < 150; ++i) {
        a += (char) i;
        b = ~a;
        std::cout << "a = " << a << "\nb = " << b << "\n";
    }
    return 0;
}
