#include <iostream>
#include <vector>
#include <time.h>

#include "midland++.hpp"

std::string generateFileName(int numsSize, int numsRange) {
    
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
    
    fileName += "_";
    fileName += std::to_string(numsRange);
    fileName += ".txt";

    return fileName;
    
}

enum EnumeratorsAlgoritms {
    ShellSort = 0,
    ShellSortHibbard,
    ShellSortKnuth,
};

std::string getNameAlgoritm(const int &i) {
    switch (i) {
        case 0:
            return "->ShellSort";
            break;
        case 1:
            return "->ShellSortHibbard";
            break;
        case 2:
            return "->ShellSortKnuth";
            break;
        default:
            assert(false);
            break;
    }
}

typedef void (*algoritm)(std::vector<int>& nums);

int main() {
    
    const int AMOUNT_ALGORYTHMS = 3, TIMES_ALGORYTHM = 3;
    
    std::vector<int> origin, copy;
    algoritm typeAlg[AMOUNT_ALGORYTHMS];
    typeAlg[0] = shellSort;
    typeAlg[1] = shellSortHibbard;
    typeAlg[2] = shellSortKnuth;
    
    double totalTime = 0;
    clock_t start, end;
    for(int size = 10'000; size <= 1'000'000; size *= 10) {
        std::cout << "=-=-=-= Size = " << size << " -=-=-=-"<< std::endl;
        for(int range = 10; range <= 100'000; range *= 100) {
            std::cout << "=-=-= Range [-" << range << ";" << range << "] -=-=-"<< std::endl;
            readFileToVector(generateFileName(size, range), origin);
            //printVector(origin);
            for(int i = 0; i < AMOUNT_ALGORYTHMS; ++i) {
                std::cout << getNameAlgoritm(i) << "\n size: " << size << "\n range: " << range << std::endl;
                for(int i = 0; i < TIMES_ALGORYTHM; ++i) {
                    copy = origin;
                    start = clock();
                    typeAlg[i](copy);
                    end = clock();
                    assert(checkIncrease(copy));
                    totalTime += (double)(end - start) / CLOCKS_PER_SEC;
                }
                std::cout << " Medium time - " << totalTime/TIMES_ALGORYTHM << std::endl;
                totalTime = 0;
            
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
        std::cout << std::endl;
    }
    
    return 0;
}

