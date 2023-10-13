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

void insertionSort(std::vector<int>& nums);

