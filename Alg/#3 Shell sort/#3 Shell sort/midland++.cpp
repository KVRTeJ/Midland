#include <iostream>
#include <vector>
#include <algorithm>
#include <time.h>
#include <string>
#include "midland++.hpp"

void createFileWithVector(const std::string name, const std::vector<int>& nums) {
    
    char* fileName = new char [name.length() + 1];
    std::strcpy(fileName, name.c_str());
    
    FILE *f = fopen (fileName, "w");
    assert(f != NULL);
    
    for(auto it = nums.begin(); it != nums.end(); ++it) {
        fprintf(f, "%d ", *it);
    }
    
    delete [] fileName;
    fclose (f);
    
}

void readFileToVector(const std::string name, std::vector<int>& nums) {
    
    char* fileName = new char [name.length() + 1];
    std::strcpy(fileName, name.c_str());
    
    FILE *f;
    f = fopen (fileName, "r");
    assert(f != NULL);
    
    nums.clear();
    
    {
        int x;
        while (fscanf (f, "%d", &x) != EOF)
            nums.push_back(x);
    }
    
    delete [] fileName;
    fclose (f);
}


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
    
    assert(!nums.empty());
    
    for(auto it = nums.begin() + 1; it != nums.end(); ++it) {
        if(*(it - 1) > *it) {
            std::cerr << "bool checkIncrease ended with false" << std::endl;
            return false;
        }
    }
    
    return true;
    
}

//Источник алгоритмов выбора шага: https://en.wikipedia.org/wiki/Shellsort#Applications

void shellSort(std::vector<int>& nums) {
    
    for( int step = ((unsigned int) nums.size()) / 2; step > 0; step /= 2) {
        insertionSortWithStep(nums, step);
    }
    
}

void shellSortHibbard(std::vector<int>& nums) {
    
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

void shellSortKnuth(std::vector<int>& nums) {
    
    int step = 1;
    while(step < nums.size() / 3) {
        step = (step * 3 + 1);
    }
    for(;step > 0; step /= 3) {
        insertionSortWithStep(nums, step);
    }
    
}
