#include "List.hpp"

int main() {
    Array<int> array(10);
    array.setRandomNumbers(-1, 10);
    array.print();
    List<int> a(array);
    std::cout << a << std::endl;
    a.erase(a.begin(), a.end() - 1);
    std::cout << a << std::endl;
    
    return 0;
}

