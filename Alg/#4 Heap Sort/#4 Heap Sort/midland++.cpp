#include <iostream>
#include <vector>

#include "midland++.hpp"

void readFileToVector(const std::string& name, std::vector<int>& nums) {
    
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

void sift(std::vector<int>& nums, const int size, int index) {
    
    int j = 2 * index + 1;
    
    while(index < size) {
        
        if(j < size) {
            if((j + 1) < size)
                if(nums[j + 1] > nums[j])
                    j = j + 1;
            if(nums[index] < nums[j]) {
                std::swap(nums[index], nums[j]);
                index = j;
                j = 2 * index + 1;
            }
            else {
                index += size;
            }
        }
        else { //j > nums.size()
            index += size;
        }
        
    }
    
}

void heapSort(std::vector<int>& nums) {
    
    const int size = (int) nums.size();
    
    for(int i = size/2 - 1; i >= 0; i--) {
        sift(nums, size, i);
    }

    for(int i = size - 1; i > 0; --i) {
        std::swap(nums[0], nums[i]);
        sift(nums, i);
    }
    
}
