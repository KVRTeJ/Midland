#include <iostream>
#include <vector>

#include "midland++.hpp"

int main() {

    HoareSort nums(10);
    nums.fillRandom(10, 100);
    
    std::cout << nums << std::endl;
    
    return 0;
}
