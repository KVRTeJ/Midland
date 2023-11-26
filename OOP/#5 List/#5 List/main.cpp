#include "List.hpp"

int main() {
    List<int> l(5, 1);
    List<int> a(l);
    a.swap(l);
    std::cout << a << std::endl;
    return 0;
}
