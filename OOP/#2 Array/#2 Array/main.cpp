#include <iostream>

#include "midland++.hpp"

int main() {
    
    int array[3] = {1, 2, 3};
    Array t, test(array), test2 = test;
    t.printArray();
    test.printArray();
    test2.printArray();
    std::cout << "size - " << test.getArraySize() << std::endl;
    std::cout << "size - " << test2.getArraySize() << std::endl;
    return 0;
}
