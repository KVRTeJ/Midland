#pragma once

#include <iostream>

template <typename Type>
void printVector(const std::vector<Type>& vector) {
    
    std::cout << "[";
    for(auto it = vector.begin(); it != vector.end(); ++it) {
        if(it != vector.begin()) {
            std::cout << ", ";
        }
        std::cout << *it;
    }
    std::cout << "]" << std::endl;
    
}

bool fillRandomNums(std::vector<int>& vector, const int size = 5,
                    const int min = 1, const int max = 10);

void insertionSort(std::vector<int>& nums, const  int step = 1);

bool checkIncrease(const std::vector<int> nums, const int step = 1);

