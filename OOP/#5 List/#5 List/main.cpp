#include "List.hpp"

int main() {
    List<int> l(1, 5), a(2, 5), b;
    b = a + l;
    std::cout << b << std::endl;
    return 0;
}
