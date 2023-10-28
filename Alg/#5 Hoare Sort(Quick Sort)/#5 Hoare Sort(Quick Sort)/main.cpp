#include <iostream>
#include <vector>

#include "midland++.hpp"

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

int main() {

    HoareSort nums(10, 9);
    //nums.fillRandom(-10, 10);
    
    //nums.readFromFile(generateFileName(10000, 10));
    std::cout << nums << std::endl;
    nums.checkIncrease();
    
    return 0;
    
}
