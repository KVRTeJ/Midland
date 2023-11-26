#include "List.hpp"

int main() {
    const unsigned pos = 0;
    char a[5] = {'a', 'b', 'c', 'd', 'e'};
    Array<char> ar(a, 5);
    List<char> list(ar);
    list += list;
    list.pop(pos + 5);
    std::cout << list << std::endl;
    return 0;
}
