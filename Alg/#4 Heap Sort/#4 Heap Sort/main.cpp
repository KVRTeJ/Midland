//
//  main.cpp
//  #4 Heap Sort
//
//  Created by Dmitriy on 18.10.2023.
//

#include <iostream>
#include <vector>

#include "midland++.hpp"

int main() {
    
    std::vector<int> nums;
    
    fillRandomNums(nums, 10);
    
    printVectorInt(nums);
    
    checkIncrease(nums);
    
    return 0;
}
