#include <iostream>
#include <vector>

#include "midland++.hpp"

std::string generateFileName(const int numsSize, const int numsRange);
 
int main() {
    
    const int TIMES_ALGORYTHM = 3;
    
    std::vector<int> origin, copy;
    
    double totalTime = 0;
    clock_t start, end;
    for(int size = 10'000; size <= 1'000'000; size *= 10) {
        std::cout << "Size = " << size << std::endl;
        for(int range = 10; range <= 100'000; range *= 100) {
            std::cout << " Range [-" << range << ";" << range << "]" << std::endl;
            readFromFile(generateFileName(size, range), origin);
            for(int i = 0; i < TIMES_ALGORYTHM; ++i) {
                copy = origin;
                start = clock();
                BitSort(copy, range);
                end = clock();
                assert(checkIncrease(copy));
                totalTime += (double)(end - start) / CLOCKS_PER_SEC;
            }
            std::cout << "   Medium time - " << totalTime/TIMES_ALGORYTHM << std::endl;
            totalTime = 0;
        }
        std::cout << std::endl;
    }
    
    return 0;
    
}

std::string generateFileName(const int numsSize, const int numsRange) {
    
    std::string fileName = "nums_";
    
    int counterK = 0;
    int i = numsSize;
    
    while(i % 1000 == 0) {
        if((i % 1000) == 0) {
            ++counterK;
        }
        i /= 1000;
    }
    
    fileName += std::to_string(i);
    while(counterK > 0) {
        fileName += "k";
        --counterK;
    }
    
    fileName += "_" + std::to_string(numsRange) + ".txt";

    return fileName;
    
}
