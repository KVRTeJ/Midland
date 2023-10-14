#include <iostream>
#include <vector>

#include "midland++.hpp"

int main() {
    
    std::vector<int> temp;
    
    fillRandomNums(temp);
    
    printVector(temp);
    
    insertionSortWithStep(temp, 2);

    printVector(temp);
    
    std::cout << checkIncrease(temp) << std::endl;
    
    return 0;
}
