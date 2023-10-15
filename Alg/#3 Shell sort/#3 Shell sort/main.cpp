#include <iostream>
#include <vector>

#include "midland++.hpp"

int main() {
    
    std::vector<int> temp;
    
    fillRandomNums(temp, 10);
    //temp.push_back(0);
    
    printVector(temp);
    
/* Шаги Шелла */
    {
        int step = (((unsigned int) temp.size()) - 1) / 2;
        while(step > 0) {
            insertionSortWithStep(temp, step);
            step /= 2;
        }
    }
    
    
    //insertionSortWithStep(temp, 1);
    printVector(temp);
    
    checkIncrease(temp);
    
    return 0;
}
