#include <iostream>
#include <vector>
#include <math.h>
#include <time.h>

#include "midland++.hpp"

int main() {
    
    std::vector<int> temp, temp1, temp2;
    
    fillRandomNums(temp, 1000000);
    temp1 = temp;
    temp2 = temp;
    
    {
    //Источник https://en.wikipedia.org/wiki/Shellsort#Applications
        /* Шаги Шелла */
        {
            for( int step = ((unsigned int) temp.size()) / 2; step > 0; step /= 2) {
                insertionSortWithStep(temp, step);
            }
        }
        checkIncrease(temp);
        
        /* Шаги Хиббарда */
        {
            int step = 1;
            while(step < temp1.size()) {
                step *= 2;
            }
            step /= 2;
            --step;
            
            for(;step > 0; step /= 2) {
                insertionSortWithStep(temp1, step);
            }
        }
        checkIncrease(temp1);
        
        
        /* Шаги Кнута */
        {
            int step = 1;
            while(step < temp2.size() / 3) {
                step = (step * 3 + 1);
            }
            for(;step > 0; step /= 3) {
                insertionSortWithStep(temp2, step);
            }
        }
        checkIncrease(temp2);
    }
    
    return 0;
}
