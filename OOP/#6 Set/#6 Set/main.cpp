#include "Set.hpp"

int main() {
    Set a = "abc", b = "n";
    std::cout << a << " " << b << std::endl;
    a /= b;
    std::cout << a.cardinalis() << std::endl;
    return 0;
}
