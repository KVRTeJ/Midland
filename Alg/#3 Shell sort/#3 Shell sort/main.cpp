#include <iostream>
#include <vector>

#include "midland++.hpp"

int main() {
    
    std::vector<int> temp;
    
    fillRandomNums(temp);
    temp.push_back(0);
    
    printVector(temp);
    
    
    {
        int step = (((unsigned int) temp.size()) - 1) / 2;
        while(step > 0) {
            insertionSortWithStep(temp, step);
            std::cout << "step - " << step << std::endl;
            printVector(temp);
            step /= 2;
        }
    }
    
    //insertionSortWithStep(temp, 2);
    printVector(temp);
    
    std::cout << checkIncrease(temp) << std::endl;
    
    return 0;
}
