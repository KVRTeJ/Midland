#include <iostream>
#include <vector>

#include "midland++.hpp"



void printVector(const std::vector<int>& nums) {
    std::cout << "[";
    
    for(auto it = nums.begin(); it != nums.end(); ++it) {
        if(it != nums.begin())
            std::cout << ", ";
        std::cout << *it;
    }
    
    std::cout << "]";
    std::cout << std::endl;
}

bool fillRandom(std::vector<int>& nums, const int& min, const int& max) {
    
    srand( (unsigned int) time(0) );
    for(auto it = nums.begin(); it != nums.end(); ++it) {
        *it = rand() % (max - min + 1) + min;
    }
    
    return true;
}


bool readFromFile(const std::string& name, std::vector<int>& nums) {
    
    FILE *f;
    f = fopen (name.c_str(), "r");
    assert(f != NULL);
    
    nums.clear();
    
    {
        int x;
        while (fscanf (f, "%d", &x) != EOF)
            nums.push_back(x);
    }
    
    fclose (f);
    
    return true;
}


bool checkIncrease(const std::vector<int> nums) {
    
    for(auto it = nums.begin(); it != nums.end() - 1; ++it) {
        if(*(it) > *(it + 1) )
            return false;
    }
    
    return true;
}

void BitSortPositive(std::vector<int>& nums, int left, int right, int k) {
    if(left >= right || k < 0)
        return;
    
    int i = left, j = right;
    int mask = 1 << k;
    while(i <= j) {
        while(i <= j && !(mask & nums[i]) ) {
            i++;
        }
        while(i <= j && mask & nums[j]) {
            j--;
        }
        if(i <= j) {
            std::swap(nums[i], nums[j]);
            i++;
            j--;
        }
    }
    
    BitSortPositive(nums, left, j, k - 1);
    BitSortPositive(nums, i, right, k - 1);
    
}

bool checkNegative(const int& num) {
    int mask = 1 << 31;
    if(mask & num)
        return true;
    
    return false;
}

void BitSort(std::vector<int>& nums, int maxNum) {
    
    int i = 0, j = (unsigned) nums.size() - 1;
    
    int pivot = 0;
    while(i <= j) {
        while(nums[i] < pivot) {
            i++;
        }
        while(nums[j] >= pivot) {
            j--;
        }
        if(i <= j) {
            std::swap(nums[i], nums[j]);
            i++;
            j--;
        }
    }
    
    
    int k = 0;
    while (maxNum) {
        maxNum = maxNum >> 1;
        k++;
    }
    
    BitSortPositive(nums, 0, j, k);
    BitSortPositive(nums, i, (unsigned) nums.size() -1, k);
    
}
