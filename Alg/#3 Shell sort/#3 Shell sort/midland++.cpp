#include <iostream>
#include <vector>
#include <algorithm>

#include "midland++.hpp"

void insertionSort(std::vector<int>& nums) {
    
    unsigned int size = (unsigned int) nums.size();
    
    for(int i = 1; i < size; ++i)
        for(int j = i; j > 0 && nums[j - 1] > nums[j]; j -= 1) {
            std::swap(nums[j - 1], nums[j]);
        }
    
}

