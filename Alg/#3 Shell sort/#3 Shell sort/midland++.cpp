#include <iostream>
#include <vector>
#include <algorithm>
#include <time.h>

#include "midland++.hpp"

bool fillRandomNums(std::vector<int>& vector, const long int size,
                    const int min, const int max) {
    
    assert(min < max && size >= 0);
    
    srand((unsigned int) time(0));
    
    for(int i = 0; i < size; ++i) {
        vector.push_back(rand() % (max - min + 1) + min);
    }
    
    return true;
    
}

void insertionSortWithStep(std::vector<int>& nums, const long int step) {
    
    assert(step > 0 && step <= nums.size());
    
    int j;
    for(int i = 0; i < nums.size() - step; ++i) {
        j = i;
        while(j >= 0 && nums[j] > nums[j + step]) {
            std::swap(nums[j], nums[j + step]);
            j -= step;
        }
    }
    
}

bool checkIncrease(const std::vector<int> nums) {
    
    for(auto it = nums.begin() + 1; it != nums.end(); ++it) {
        if(*(it - 1) > *it) {
            std::cerr << "bool checkIncrease ended with false" << std::endl;
            return false;
        }
    }
    
    return true;
    
}

void ShellSort(std::vector<int>& nums) {
    
    for( int step = ((unsigned int) nums.size()) / 2; step > 0; step /= 2) {
        insertionSortWithStep(nums, step);
    }
    
}

void ShellSortHibbard(std::vector<int>& nums) {
    
    int step = 1;
    while(step < nums.size()) {
        step *= 2;
    }
    step /= 2;
    --step;
    
    for(;step > 0; step /= 2) {
        insertionSortWithStep(nums, step);
    }
    
}

void ShellSortKnuth(std::vector<int>& nums) {
    
    int step = 1;
    while(step < nums.size() / 3) {
        step = (step * 3 + 1);
    }
    for(;step > 0; step /= 3) {
        insertionSortWithStep(nums, step);
    }
    
}
