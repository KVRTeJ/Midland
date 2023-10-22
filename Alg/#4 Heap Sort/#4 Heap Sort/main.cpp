#include <iostream>
#include <vector>
#include <algorithm>
#include "midland++.hpp"
#include <time.h>

int main() {
    
    std::vector<int> nums;
    
    /*
    nums.push_back(5);
    nums.push_back(9);
    nums.push_back(1);
    nums.push_back(9);
    nums.push_back(8);
    nums.push_back(1);
    nums.push_back(10);
    nums.push_back(5);
    nums.push_back(5);
    nums.push_back(9);
    */
    
    fillRandomNums(nums, 1'000'000, -100'000, 100'000);
    //printVectorInt(nums);
    
    clock_t start = clock();
    heapSort(nums);
    clock_t end = clock();
    double seconds = (double) (end - start)/CLOCKS_PER_SEC;
    std::cout << "Time - " << seconds << "s." << std::endl;
    //printVectorInt(nums);
    assert(checkIncrease(nums));
    
    return 0;
}
