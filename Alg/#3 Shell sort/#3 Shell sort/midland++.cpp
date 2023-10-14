#include <iostream>
#include <vector>
#include <algorithm>
#include <time.h>

#include "midland++.hpp"

bool fillRandomNums(std::vector<int>& vector, const int size,
                    const int min, const int max) {
    
    assert(min < max && size >= 0);
    
    srand((unsigned int) time(0));
    
    for(int i = 0; i < size; ++i) {
        vector.push_back(rand() % (max - min + 1) + min);
    }
    
    return true;
    
}

void insertionSortWithStep(std::vector<int>& nums, const int step) {
    
    assert(step > 0);
    
    for(unsigned int i = 0; i < nums.size(); i += step) {
        for(int j = i; j > 0 && nums[j - step] > nums[j]; j -= step) {
            std::swap(nums[j - step], nums[j]);
        }
    }
}

bool checkIncrease(const std::vector<int> nums, const int step) {
    
    for(auto it = nums.begin() + 1; it != nums.end(); ++it) {
        if(*(it - 1) > *it) {
            std::cerr << "bool checkIncrease ended with false" << std::endl;
            return false;
        }
    }
    
    return true;
    
}

