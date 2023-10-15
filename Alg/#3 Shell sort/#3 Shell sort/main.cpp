#include <iostream>
#include <vector>
#include <time.h>

#include "midland++.hpp"

int main() {
    
    std::vector<int> temp, temp1, temp2;
    
    fillRandomNums(temp, 10000000);
    temp1 = temp;
    temp2 = temp;
    
    {
    //Источник https://en.wikipedia.org/wiki/Shellsort#Applications
        
        /* Шаги Шелла */
        {
            clock_t start = clock();
            ShellSort(temp);
            clock_t end = clock();
            double seconds = (double)(end - start) / CLOCKS_PER_SEC;
            std::cout << "Time ShellSort - " << seconds << "s" << std::endl;
        }
        assert(checkIncrease(temp));
        
        /* Шаги Хиббарда */
        {
            clock_t start = clock();
            ShellSortHibbard(temp1);
            clock_t end = clock();
            double seconds = (double)(end - start) / CLOCKS_PER_SEC;
            std::cout << "Time ShellSortHibbard - " << seconds << "s" << std::endl;
        }
        assert(checkIncrease(temp1));
        
        /* Шаги Кнута */
        {
            clock_t start = clock();
            ShellSortKnuth(temp2);
            clock_t end = clock();
            double seconds = (double)(end - start) / CLOCKS_PER_SEC;
            std::cout << "Time ShellSortKnuth - " << seconds << "s" << std::endl;
        }
        assert(checkIncrease(temp2));
        
    }
    
    return 0;
}
