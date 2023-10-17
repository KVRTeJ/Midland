#pragma once

#include <iostream>

void createFileWithVector (const char *name, const std::vector<int>& nums);

void readFileToVector(const char *name, std::vector<int>& nums);

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

bool fillRandomNums(std::vector<int>& vector, const long int size = 5,
                    const int min = 1, const int max = 10);

void insertionSortWithStep(std::vector<int>& nums, const long int step = 1);

bool checkIncrease(const std::vector<int> nums);

void ShellSort(std::vector<int>& nums);

void ShellSortHibbard(std::vector<int>& nums);

void ShellSortKnuth(std::vector<int>& nums);


