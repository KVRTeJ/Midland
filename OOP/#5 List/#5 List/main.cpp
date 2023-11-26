#include "List.hpp"

int main() {
    const unsigned pos = 0;
    char a[5] = {'a', 'b', 'c', 'd', 'e'};
    Array<char> ar(a, 5);
    List<char> list(ar);
    list += list;
    
    std::cout << list << std::endl;
    std::cout << list.getSize() << std::endl;
    
    List<char> list1(list);
    std::cout << list1.getSize() << std::endl;
    return 0;
}
