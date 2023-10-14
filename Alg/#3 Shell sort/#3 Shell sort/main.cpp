#include <iostream>
#include <vector>

#include "midland++.hpp"

int main() {
    
    std::vector<int> temp;
    
    fillRandomNums(temp);
    
    printVector(temp);
    
    insertionSort(temp, 2);
    
    //temp.push_back(0);
    printVector(temp);
    
    std::cout << checkIncrease(temp) << std::endl;
    
    return 0;
}
