#include "List.hpp"

int main() {
    
    Array<int> array(10);
    array.setRandomNumbers(-1, 10);
    array.print();
    List<int> a(array);
    std::cout << a << std::endl;
    a.bubbleSort();
    std::cout << a << std::endl;
    
    return 0;
}

