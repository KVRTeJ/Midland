#include <iostream>
#include <vector>

#include "midland++.hpp"

void readFileToVector(const char *name, std::vector<int>& nums) {
    
    FILE *f;
    f = fopen (name, "r");
    assert(f != NULL);
    
    nums.clear();
    
    {
        int x;
        while (fscanf (f, "%d", &x) != EOF)
            nums.push_back(x);
    }
    
    fclose (f);
}

bool printVectorInt(const std::vector<int>& nums) {
    
    std::cout << "[";
    for(auto it = nums.begin(); it != nums.end(); ++it) {
        if(it != nums.begin()) {
            std::cout << ", ";
        }
        std::cout << *it;
    }
    std::cout << "]" << std::endl;
    
    return true;
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

bool checkIncrease(const std::vector<int> nums) {
    
    for(auto it = nums.begin() + 1; it != nums.end(); ++it) {
        if(*(it - 1) > *it) {
            std::cerr << "bool checkIncrease ended with false" << std::endl;
            return false;
        }
    }
    
    return true;
    
}


