#include <iostream>
#include <vector>
#include <algorithm>
#include "midland++.hpp"

int main() {
    
    std::vector<int> nums;
    
    
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
    
    
    //fillRandomNums(nums, 10);
    printVectorInt(nums);
    
    for(int i = (int) nums.size()/2 - 1; i >= 0; i--) {
        sift(nums, nums.size(), i);
    }
    
    for(int i = (int) nums.size() - 1; i > 1; --i) {
        std::swap(nums[0], nums[i]);
        
        sift(nums, i, 0);
    }
    
    printVectorInt(nums);
    
    return 0;
}
