#include "List.hpp"

int main() {
    const unsigned pos = 4;
    List<int> a(5, 6);
    a.push(pos, 4);
    a.push(-1, 10);
    std::cout << a << std::endl;
    return 0;
}
