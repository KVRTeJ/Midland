#include "List.hpp"

int main() {
    const unsigned pos = 2;
    List<int> a(5, 3);
    a.push(pos, 10);
    std::cout << a << std::endl;
    return 0;
}
