#include <iostream>
#include <vector>
#include <time.h>

#include "midland++.hpp"

std::string generateFileName(int numsSize, int numsRange) {
    
    std::string fileName;
    ;;;
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
            return "ShellSort";
            break;
        case 1:
            return "ShellSortHibbard";
            break;
        case 2:
            return "ShellSortKnuth";
            break;
        default:
            assert(false);
            break;
    }
}

typedef void (*algoritm)(std::vector<int>& nums);

int main() {
    
    std::vector<int> origin, copy;
    algoritm typeAlg[3];
    typeAlg[0] = shellSort;
    typeAlg[1] = shellSortHibbard;
    typeAlg[2] = shellSortKnuth;

    origin.push_back(1);//Temp
    
    const int AMOUNT_ALGORYTHMS = 3, TIMES_ALGORYTHM = 3;
    double totalTime = 0;
    clock_t start, end;
    
    for(int size = 10'000; size <= 1'000'000; size *= 10) {
        for(int range = 10; range <= 100'000; range *= 100) {
            //fileName = generateFileName
            //readFileToVector(fileName, origin);
            for(int i = 0; i < AMOUNT_ALGORYTHMS; ++i) {
                std::cout << getNameAlgoritm(i) << "\n-size: " << size << "\n-range: " << range << std::endl;
                for(int i = 0; i < TIMES_ALGORYTHM; ++i) {
                    copy = origin;
                    start = clock();
                    typeAlg[i](copy);
                    end = clock();
                    assert(checkIncrease(copy));
                    totalTime += (double)(end - start) / CLOCKS_PER_SEC;
                }
                /**std::cout EnumeratorsAlgoritms **/
                std::cout << "-Medium time - " << totalTime/TIMES_ALGORYTHM << std::endl;
                totalTime = 0;
            
            }
        }
    }

/*
    {
    //Источник алгоритмов выбора шага: https://en.wikipedia.org/wiki/Shellsort#Applications
        
        //Шаги Шелла
        {
            {
                {
                    readFileToVector("nums_10k_10.txt", nums_10k_10);
                    clock_t start = clock();
                    ShellSort(nums_10k_10);
                    clock_t end = clock();
                    assert(checkIncrease(nums_10k_10));
                    double seconds = (double)(end - start) / CLOCKS_PER_SEC;
                    std::cout << "ShellSort: nums_10k_10\n-Time - " << seconds << "s";
                    
                    readFileToVector("nums_10k_10.txt", nums_10k_10);
                    clock_t start1 = clock();
                    ShellSort(nums_10k_10);
                    clock_t end1 = clock();
                    assert(checkIncrease(nums_10k_10));
                    double seconds1 = (double)(end1 - start1) / CLOCKS_PER_SEC;
                    std::cout << ", " << seconds1 << "s";
                    
                    readFileToVector("nums_10k_10.txt", nums_10k_10);
                    clock_t start2 = clock();
                    ShellSort(nums_10k_10);
                    clock_t end2 = clock();
                    assert(checkIncrease(nums_10k_10));
                    double seconds2 = (double)(end2 - start2) / CLOCKS_PER_SEC;
                    std::cout << ", " << seconds2 << "s" << std::endl;;
                    
                    double mediumTime = (seconds + seconds1 + seconds2) / 3;
                    std::cout << "-Medium time - " << mediumTime << "s" << std::endl;
                }
                
                {
                    readFileToVector("nums_10k_1000.txt", nums_10k_1000);
                    clock_t start = clock();
                    ShellSort(nums_10k_1000);
                    clock_t end = clock();
                    assert(checkIncrease(nums_10k_1000));
                    double seconds = (double)(end - start) / CLOCKS_PER_SEC;
                    std::cout << "ShellSort: nums_10k_1000\n-Time - " << seconds << "s";
                    
                    readFileToVector("nums_10k_1000.txt", nums_10k_1000);
                    clock_t start1 = clock();
                    ShellSort(nums_10k_1000);
                    clock_t end1 = clock();
                    assert(checkIncrease(nums_10k_1000));
                    double seconds1 = (double)(end1 - start1) / CLOCKS_PER_SEC;
                    std::cout << ",  " << seconds1 << "s";
                    
                    readFileToVector("nums_10k_1000.txt", nums_10k_1000);
                    clock_t start2 = clock();
                    ShellSort(nums_10k_1000);
                    clock_t end2 = clock();
                    assert(checkIncrease(nums_10k_1000));
                    double seconds2 = (double)(end2 - start2) / CLOCKS_PER_SEC;
                    std::cout << ", " << seconds2 << "s" << std::endl;
                    
                    double mediumTime = (seconds + seconds1 + seconds2) / 3;
                    std::cout << "-Medium time - " << mediumTime << "s" << std::endl;
                }
                
                {
                    readFileToVector("nums_10k_100000.txt", nums_10k_100000);
                    clock_t start = clock();
                    ShellSort(nums_10k_100000);
                    clock_t end = clock();
                    assert(checkIncrease(nums_10k_100000));
                    double seconds = (double)(end - start) / CLOCKS_PER_SEC;
                    std::cout << "ShellSort: nums_10k_100000\n-Time - " << seconds << "s";
                    
                    readFileToVector("nums_10k_100000.txt", nums_10k_100000);
                    clock_t start1 = clock();
                    ShellSort(nums_10k_100000);
                    clock_t end1 = clock();
                    assert(checkIncrease(nums_10k_100000));
                    double seconds1 = (double)(end1 - start1) / CLOCKS_PER_SEC;
                    std::cout << ", " << seconds1 << "s";
                    
                    readFileToVector("nums_10k_100000.txt", nums_10k_100000);
                    clock_t start2 = clock();
                    ShellSort(nums_10k_100000);
                    clock_t end2 = clock();
                    assert(checkIncrease(nums_10k_100000));
                    double seconds2 = (double)(end2 - start2) / CLOCKS_PER_SEC;
                    std::cout << ", " << seconds2 << "s" << std::endl;
                    
                    double mediumTime = (seconds + seconds1 + seconds2) / 3;
                    std::cout << "-Medium time - " << mediumTime << "s" << std::endl;
                }
            }
            std::cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << std::endl;
            {
                {
                    readFileToVector("nums_100k_10.txt", nums_100k_10);
                    clock_t start = clock();
                    ShellSort(nums_100k_10);
                    clock_t end = clock();
                    assert(checkIncrease(nums_100k_10));
                    double seconds = (double)(end - start) / CLOCKS_PER_SEC;
                    std::cout << "ShellSort: nums_100k_10\n-Time - " << seconds << "s";
                    
                    readFileToVector("nums_100k_10.txt", nums_100k_10);
                    clock_t start1 = clock();
                    ShellSort(nums_100k_10);
                    clock_t end1 = clock();
                    assert(checkIncrease(nums_100k_10));
                    double seconds1 = (double)(end1 - start1) / CLOCKS_PER_SEC;
                    std::cout << ", " << seconds1 << "s";
                    
                    readFileToVector("nums_100k_10.txt", nums_100k_10);
                    clock_t start2 = clock();
                    ShellSort(nums_100k_10);
                    clock_t end2 = clock();
                    assert(checkIncrease(nums_100k_10));
                    double seconds2 = (double)(end2 - start2) / CLOCKS_PER_SEC;
                    std::cout << ", " << seconds2 << "s" << std::endl;;
                    
                    double mediumTime = (seconds + seconds1 + seconds2) / 3;
                    std::cout << "-Medium time - " << mediumTime << "s" << std::endl;
                }
                
                
                {
                    readFileToVector("nums_100k_1000.txt", nums_100k_1000);
                    clock_t start = clock();
                    ShellSort(nums_100k_1000);
                    clock_t end = clock();
                    assert(checkIncrease(nums_100k_1000));
                    double seconds = (double)(end - start) / CLOCKS_PER_SEC;
                    std::cout << "ShellSort: nums_100k_1000\n-Time - " << seconds << "s";
                    
                    readFileToVector("nums_100k_1000.txt", nums_100k_1000);
                    clock_t start1 = clock();
                    ShellSort(nums_100k_1000);
                    clock_t end1 = clock();
                    assert(checkIncrease(nums_100k_1000));
                    double seconds1 = (double)(end1 - start1) / CLOCKS_PER_SEC;
                    std::cout << ", " << seconds1 << "s";
                    
                    readFileToVector("nums_100k_1000.txt", nums_100k_1000);
                    clock_t start2 = clock();
                    ShellSort(nums_100k_1000);
                    clock_t end2 = clock();
                    assert(checkIncrease(nums_100k_1000));
                    double seconds2 = (double)(end2 - start2) / CLOCKS_PER_SEC;
                    std::cout << ", " << seconds2 << "s" << std::endl;
                    
                    double mediumTime = (seconds + seconds1 + seconds2) / 3;
                    std::cout << "-Medium time - " << mediumTime << "s" << std::endl;
                }
                
                {
                    readFileToVector("nums_100k_100000.txt", nums_100k_100000);
                    clock_t start = clock();
                    ShellSort(nums_100k_100000);
                    clock_t end = clock();
                    assert(checkIncrease(nums_100k_100000));
                    double seconds = (double)(end - start) / CLOCKS_PER_SEC;
                    std::cout << "ShellSort: nums_100k_100000\n-Time - " << seconds << "s";
                    
                    readFileToVector("nums_100k_100000.txt", nums_100k_100000);
                    clock_t start1 = clock();
                    ShellSort(nums_100k_100000);
                    clock_t end1 = clock();
                    assert(checkIncrease(nums_100k_100000));
                    double seconds1 = (double)(end1 - start1) / CLOCKS_PER_SEC;
                    std::cout << ", " << seconds1 << "s";
                    
                    readFileToVector("nums_100k_100000.txt", nums_100k_100000);
                    clock_t start2 = clock();
                    ShellSort(nums_100k_100000);
                    clock_t end2 = clock();
                    assert(checkIncrease(nums_100k_100000));
                    double seconds2 = (double)(end2 - start2) / CLOCKS_PER_SEC;
                    std::cout << ", " << seconds2 << "s" << std::endl;
                    
                    double mediumTime = (seconds + seconds1 + seconds2) / 3;
                    std::cout << "-Medium time - " << mediumTime << "s" << std::endl;
                }
            }
            std::cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << std::endl;
            {
                {
                    readFileToVector("nums_1kk_10.txt", nums_1kk_10);
                    clock_t start = clock();
                    ShellSort(nums_1kk_10);
                    clock_t end = clock();
                    assert(checkIncrease(nums_1kk_10));
                    double seconds = (double)(end - start) / CLOCKS_PER_SEC;
                    std::cout << "ShellSort: nums_1kk_10\n-Time - " << seconds << "s";
                    
                    readFileToVector("nums_1kk_10.txt", nums_1kk_10);
                    clock_t start1 = clock();
                    ShellSort(nums_1kk_10);
                    clock_t end1 = clock();
                    assert(checkIncrease(nums_1kk_10));
                    double seconds1 = (double)(end1 - start1) / CLOCKS_PER_SEC;
                    std::cout << ", " << seconds1 << "s";
                    
                    readFileToVector("nums_1kk_10.txt", nums_1kk_10);
                    clock_t start2 = clock();
                    ShellSort(nums_1kk_10);
                    clock_t end2 = clock();
                    assert(checkIncrease(nums_1kk_10));
                    double seconds2 = (double)(end2 - start2) / CLOCKS_PER_SEC;
                    std::cout << ", " << seconds2 << "s" << std::endl;
                    
                    double mediumTime = (seconds + seconds1 + seconds2) / 3;
                    std::cout << "-Medium time - " << mediumTime << "s" << std::endl;
                }
                
                {
                    readFileToVector("nums_1kk_1000.txt", nums_1kk_1000);
                    clock_t start = clock();
                    ShellSort(nums_1kk_1000);
                    clock_t end = clock();
                    assert(checkIncrease(nums_100k_1000));
                    double seconds = (double)(end - start) / CLOCKS_PER_SEC;
                    std::cout << "ShellSort: nums_1kk_1000\n-Time - " << seconds << "s";
                    
                    readFileToVector("nums_1kk_1000.txt", nums_1kk_1000);
                    clock_t start1 = clock();
                    ShellSort(nums_1kk_1000);
                    clock_t end1 = clock();
                    assert(checkIncrease(nums_100k_1000));
                    double seconds1 = (double)(end1 - start1) / CLOCKS_PER_SEC;
                    std::cout << ", " << seconds1 << "s";
                    
                    readFileToVector("nums_1kk_1000.txt", nums_1kk_1000);
                    clock_t start2 = clock();
                    ShellSort(nums_1kk_1000);
                    clock_t end2 = clock();
                    assert(checkIncrease(nums_100k_1000));
                    double seconds2 = (double)(end2 - start2) / CLOCKS_PER_SEC;
                    std::cout << ", " << seconds2 << "s" << std::endl;
                    
                    double mediumTime = (seconds + seconds1 + seconds2) / 3;
                    std::cout << "-Medium time - " << mediumTime << "s" << std::endl;
                }
                
                {
                    readFileToVector("nums_1kk_100000.txt", nums_1kk_100000);
                    clock_t start = clock();
                    ShellSort(nums_1kk_100000);
                    clock_t end = clock();
                    assert(checkIncrease(nums_1kk_100000));
                    double seconds = (double)(end - start) / CLOCKS_PER_SEC;
                    std::cout << "ShellSort: nums_1kk_100000\n-Time - " << seconds << "s";
                    
                    readFileToVector("nums_1kk_100000.txt", nums_1kk_100000);
                    clock_t start1 = clock();
                    ShellSort(nums_1kk_100000);
                    clock_t end1 = clock();
                    assert(checkIncrease(nums_1kk_100000));
                    double seconds1 = (double)(end1 - start1) / CLOCKS_PER_SEC;
                    std::cout << ", " << seconds1 << "s";
                    
                    readFileToVector("nums_1kk_100000.txt", nums_1kk_100000);
                    clock_t start2 = clock();
                    ShellSort(nums_1kk_100000);
                    clock_t end2 = clock();
                    assert(checkIncrease(nums_1kk_100000));
                    double seconds2 = (double)(end2 - start2) / CLOCKS_PER_SEC;
                    std::cout << ", " << seconds2 << "s" << std::endl;
                    
                    double mediumTime = (seconds + seconds1 + seconds2) / 3;
                    std::cout << "-Medium time - " << mediumTime << "s" << std::endl;
                }
            }
        }
        
        std::cout << std::endl;
        
        //Шаги Хиббарда
         {
             {
                 {
                     readFileToVector("nums_10k_10.txt", nums_10k_10);
                     clock_t start = clock();
                     ShellSortHibbard(nums_10k_10);
                     clock_t end = clock();
                     assert(checkIncrease(nums_10k_10));
                     double seconds = (double)(end - start) / CLOCKS_PER_SEC;
                     std::cout << "ShellSortHibbard: nums_10k_10\n-Time - " << seconds << "s";
                     
                     readFileToVector("nums_10k_10.txt", nums_10k_10);
                     clock_t start1 = clock();
                     ShellSortHibbard(nums_10k_10);
                     clock_t end1 = clock();
                     assert(checkIncrease(nums_10k_10));
                     double seconds1 = (double)(end1 - start1) / CLOCKS_PER_SEC;
                     std::cout << ", " << seconds1 << "s";
                     
                     readFileToVector("nums_10k_10.txt", nums_10k_10);
                     clock_t start2 = clock();
                     ShellSortHibbard(nums_10k_10);
                     clock_t end2 = clock();
                     assert(checkIncrease(nums_10k_10));
                     double seconds2 = (double)(end2 - start2) / CLOCKS_PER_SEC;
                     std::cout << ", " << seconds2 << "s" << std::endl;;
                     
                     double mediumTime = (seconds + seconds1 + seconds2) / 3;
                     std::cout << "-Medium time - " << mediumTime << "s" << std::endl;
                 }
                 
                 {
                     readFileToVector("nums_10k_1000.txt", nums_10k_1000);
                     clock_t start = clock();
                     ShellSortHibbard(nums_10k_1000);
                     clock_t end = clock();
                     assert(checkIncrease(nums_10k_1000));
                     double seconds = (double)(end - start) / CLOCKS_PER_SEC;
                     std::cout << "ShellSortHibbard: nums_10k_1000\n-Time - " << seconds << "s";
                     
                     readFileToVector("nums_10k_1000.txt", nums_10k_1000);
                     clock_t start1 = clock();
                     ShellSortHibbard(nums_10k_1000);
                     clock_t end1 = clock();
                     assert(checkIncrease(nums_10k_1000));
                     double seconds1 = (double)(end1 - start1) / CLOCKS_PER_SEC;
                     std::cout << ",  " << seconds1 << "s";
                     
                     readFileToVector("nums_10k_1000.txt", nums_10k_1000);
                     clock_t start2 = clock();
                     ShellSortHibbard(nums_10k_1000);
                     clock_t end2 = clock();
                     assert(checkIncrease(nums_10k_1000));
                     double seconds2 = (double)(end2 - start2) / CLOCKS_PER_SEC;
                     std::cout << ", " << seconds2 << "s" << std::endl;
                     
                     double mediumTime = (seconds + seconds1 + seconds2) / 3;
                     std::cout << "-Medium time - " << mediumTime << "s" << std::endl;
                 }
                 
                 {
                     readFileToVector("nums_10k_100000.txt", nums_10k_100000);
                     clock_t start = clock();
                     ShellSortHibbard(nums_10k_100000);
                     clock_t end = clock();
                     assert(checkIncrease(nums_10k_100000));
                     double seconds = (double)(end - start) / CLOCKS_PER_SEC;
                     std::cout << "ShellSortHibbard: nums_10k_100000\n-Time - " << seconds << "s";
                     
                     readFileToVector("nums_10k_100000.txt", nums_10k_100000);
                     clock_t start1 = clock();
                     ShellSortHibbard(nums_10k_100000);
                     clock_t end1 = clock();
                     assert(checkIncrease(nums_10k_100000));
                     double seconds1 = (double)(end1 - start1) / CLOCKS_PER_SEC;
                     std::cout << ", " << seconds1 << "s";
                     
                     readFileToVector("nums_10k_100000.txt", nums_10k_100000);
                     clock_t start2 = clock();
                     ShellSortHibbard(nums_10k_100000);
                     clock_t end2 = clock();
                     assert(checkIncrease(nums_10k_100000));
                     double seconds2 = (double)(end2 - start2) / CLOCKS_PER_SEC;
                     std::cout << ", " << seconds2 << "s" << std::endl;
                     
                     double mediumTime = (seconds + seconds1 + seconds2) / 3;
                     std::cout << "-Medium time - " << mediumTime << "s" << std::endl;
                 }
             }
             std::cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << std::endl;
             {
                 {
                     readFileToVector("nums_100k_10.txt", nums_100k_10);
                     clock_t start = clock();
                     ShellSortHibbard(nums_100k_10);
                     clock_t end = clock();
                     assert(checkIncrease(nums_100k_10));
                     double seconds = (double)(end - start) / CLOCKS_PER_SEC;
                     std::cout << "ShellSortHibbard: nums_100k_10\n-Time - " << seconds << "s";
                     
                     readFileToVector("nums_100k_10.txt", nums_100k_10);
                     clock_t start1 = clock();
                     ShellSortHibbard(nums_100k_10);
                     clock_t end1 = clock();
                     assert(checkIncrease(nums_100k_10));
                     double seconds1 = (double)(end1 - start1) / CLOCKS_PER_SEC;
                     std::cout << ", " << seconds1 << "s";
                     
                     readFileToVector("nums_100k_10.txt", nums_100k_10);
                     clock_t start2 = clock();
                     ShellSortHibbard(nums_100k_10);
                     clock_t end2 = clock();
                     assert(checkIncrease(nums_100k_10));
                     double seconds2 = (double)(end2 - start2) / CLOCKS_PER_SEC;
                     std::cout << ", " << seconds2 << "s" << std::endl;;
                     
                     double mediumTime = (seconds + seconds1 + seconds2) / 3;
                     std::cout << "-Medium time - " << mediumTime << "s" << std::endl;
                 }
                 
                 
                 {
                     readFileToVector("nums_100k_1000.txt", nums_100k_1000);
                     clock_t start = clock();
                     ShellSortHibbard(nums_100k_1000);
                     clock_t end = clock();
                     assert(checkIncrease(nums_100k_1000));
                     double seconds = (double)(end - start) / CLOCKS_PER_SEC;
                     std::cout << "ShellSortHibbard: nums_100k_1000\n-Time - " << seconds << "s";
                     
                     readFileToVector("nums_100k_1000.txt", nums_100k_1000);
                     clock_t start1 = clock();
                     ShellSortHibbard(nums_100k_1000);
                     clock_t end1 = clock();
                     assert(checkIncrease(nums_100k_1000));
                     double seconds1 = (double)(end1 - start1) / CLOCKS_PER_SEC;
                     std::cout << ", " << seconds1 << "s";
                     
                     readFileToVector("nums_100k_1000.txt", nums_100k_1000);
                     clock_t start2 = clock();
                     ShellSortHibbard(nums_100k_1000);
                     clock_t end2 = clock();
                     assert(checkIncrease(nums_100k_1000));
                     double seconds2 = (double)(end2 - start2) / CLOCKS_PER_SEC;
                     std::cout << ", " << seconds2 << "s" << std::endl;
                     
                     double mediumTime = (seconds + seconds1 + seconds2) / 3;
                     std::cout << "-Medium time - " << mediumTime << "s" << std::endl;
                 }
                 
                 {
                     readFileToVector("nums_100k_100000.txt", nums_100k_100000);
                     clock_t start = clock();
                     ShellSortHibbard(nums_100k_100000);
                     clock_t end = clock();
                     assert(checkIncrease(nums_100k_100000));
                     double seconds = (double)(end - start) / CLOCKS_PER_SEC;
                     std::cout << "ShellSortHibbard: nums_100k_100000\n-Time - " << seconds << "s";
                     
                     readFileToVector("nums_100k_100000.txt", nums_100k_100000);
                     clock_t start1 = clock();
                     ShellSortHibbard(nums_100k_100000);
                     clock_t end1 = clock();
                     assert(checkIncrease(nums_100k_100000));
                     double seconds1 = (double)(end1 - start1) / CLOCKS_PER_SEC;
                     std::cout << ", " << seconds1 << "s";
                     
                     readFileToVector("nums_100k_100000.txt", nums_100k_100000);
                     clock_t start2 = clock();
                     ShellSortHibbard(nums_100k_100000);
                     clock_t end2 = clock();
                     assert(checkIncrease(nums_100k_100000));
                     double seconds2 = (double)(end2 - start2) / CLOCKS_PER_SEC;
                     std::cout << ", " << seconds2 << "s" << std::endl;
                     
                     double mediumTime = (seconds + seconds1 + seconds2) / 3;
                     std::cout << "-Medium time - " << mediumTime << "s" << std::endl;
                 }
             }
             std::cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << std::endl;
             {
                 {
                     readFileToVector("nums_1kk_10.txt", nums_1kk_10);
                     clock_t start = clock();
                     ShellSortHibbard(nums_1kk_10);
                     clock_t end = clock();
                     assert(checkIncrease(nums_1kk_10));
                     double seconds = (double)(end - start) / CLOCKS_PER_SEC;
                     std::cout << "ShellSortHibbard: nums_1kk_10\n-Time - " << seconds << "s";
                     
                     readFileToVector("nums_1kk_10.txt", nums_1kk_10);
                     clock_t start1 = clock();
                     ShellSortHibbard(nums_1kk_10);
                     clock_t end1 = clock();
                     assert(checkIncrease(nums_1kk_10));
                     double seconds1 = (double)(end1 - start1) / CLOCKS_PER_SEC;
                     std::cout << ", " << seconds1 << "s";
                     
                     readFileToVector("nums_1kk_10.txt", nums_1kk_10);
                     clock_t start2 = clock();
                     ShellSortHibbard(nums_1kk_10);
                     clock_t end2 = clock();
                     assert(checkIncrease(nums_1kk_10));
                     double seconds2 = (double)(end2 - start2) / CLOCKS_PER_SEC;
                     std::cout << ", " << seconds2 << "s" << std::endl;
                     
                     double mediumTime = (seconds + seconds1 + seconds2) / 3;
                     std::cout << "-Medium time - " << mediumTime << "s" << std::endl;
                 }
                 
                 {
                     readFileToVector("nums_1kk_1000.txt", nums_1kk_1000);
                     clock_t start = clock();
                     ShellSortHibbard(nums_1kk_1000);
                     clock_t end = clock();
                     assert(checkIncrease(nums_100k_1000));
                     double seconds = (double)(end - start) / CLOCKS_PER_SEC;
                     std::cout << "ShellSortHibbard: nums_1kk_1000\n-Time - " << seconds << "s";
                     
                     readFileToVector("nums_1kk_1000.txt", nums_1kk_1000);
                     clock_t start1 = clock();
                     ShellSortHibbard(nums_1kk_1000);
                     clock_t end1 = clock();
                     assert(checkIncrease(nums_100k_1000));
                     double seconds1 = (double)(end1 - start1) / CLOCKS_PER_SEC;
                     std::cout << ", " << seconds1 << "s";
                     
                     readFileToVector("nums_1kk_1000.txt", nums_1kk_1000);
                     clock_t start2 = clock();
                     ShellSortHibbard(nums_1kk_1000);
                     clock_t end2 = clock();
                     assert(checkIncrease(nums_100k_1000));
                     double seconds2 = (double)(end2 - start2) / CLOCKS_PER_SEC;
                     std::cout << ", " << seconds2 << "s" << std::endl;
                     
                     double mediumTime = (seconds + seconds1 + seconds2) / 3;
                     std::cout << "-Medium time - " << mediumTime << "s" << std::endl;
                 }
                 
                 {
                     readFileToVector("nums_1kk_100000.txt", nums_1kk_100000);
                     clock_t start = clock();
                     ShellSortHibbard(nums_1kk_100000);
                     clock_t end = clock();
                     assert(checkIncrease(nums_1kk_100000));
                     double seconds = (double)(end - start) / CLOCKS_PER_SEC;
                     std::cout << "ShellSortHibbard: nums_1kk_100000\n-Time - " << seconds << "s";
                     
                     readFileToVector("nums_1kk_100000.txt", nums_1kk_100000);
                     clock_t start1 = clock();
                     ShellSortHibbard(nums_1kk_100000);
                     clock_t end1 = clock();
                     assert(checkIncrease(nums_1kk_100000));
                     double seconds1 = (double)(end1 - start1) / CLOCKS_PER_SEC;
                     std::cout << ", " << seconds1 << "s";
                     
                     readFileToVector("nums_1kk_100000.txt", nums_1kk_100000);
                     clock_t start2 = clock();
                     ShellSortHibbard(nums_1kk_100000);
                     clock_t end2 = clock();
                     assert(checkIncrease(nums_1kk_100000));
                     double seconds2 = (double)(end2 - start2) / CLOCKS_PER_SEC;
                     std::cout << ", " << seconds2 << "s" << std::endl;
                     
                     double mediumTime = (seconds + seconds1 + seconds2) / 3;
                     std::cout << "-Medium time - " << mediumTime << "s" << std::endl;
                 }
             }
         }
        
         std::cout << std::endl;
        
        //Шаги Кнута
        {
            {
                {
                    readFileToVector("nums_10k_10.txt", nums_10k_10);
                    clock_t start = clock();
                    ShellSortKnuth(nums_10k_10);
                    clock_t end = clock();
                    assert(checkIncrease(nums_10k_10));
                    double seconds = (double)(end - start) / CLOCKS_PER_SEC;
                    std::cout << "ShellSortKnuth: nums_10k_10\n-Time - " << seconds << "s";
                    
                    readFileToVector("nums_10k_10.txt", nums_10k_10);
                    clock_t start1 = clock();
                    ShellSortKnuth(nums_10k_10);
                    clock_t end1 = clock();
                    assert(checkIncrease(nums_10k_10));
                    double seconds1 = (double)(end1 - start1) / CLOCKS_PER_SEC;
                    std::cout << ", " << seconds1 << "s";
                    
                    readFileToVector("nums_10k_10.txt", nums_10k_10);
                    clock_t start2 = clock();
                    ShellSortKnuth(nums_10k_10);
                    clock_t end2 = clock();
                    assert(checkIncrease(nums_10k_10));
                    double seconds2 = (double)(end2 - start2) / CLOCKS_PER_SEC;
                    std::cout << ", " << seconds2 << "s" << std::endl;;
                    
                    double mediumTime = (seconds + seconds1 + seconds2) / 3;
                    std::cout << "-Medium time - " << mediumTime << "s" << std::endl;
                }
                
                {
                    readFileToVector("nums_10k_1000.txt", nums_10k_1000);
                    clock_t start = clock();
                    ShellSortKnuth(nums_10k_1000);
                    clock_t end = clock();
                    assert(checkIncrease(nums_10k_1000));
                    double seconds = (double)(end - start) / CLOCKS_PER_SEC;
                    std::cout << "ShellSortKnuth: nums_10k_1000\n-Time - " << seconds << "s";
                    
                    readFileToVector("nums_10k_1000.txt", nums_10k_1000);
                    clock_t start1 = clock();
                    ShellSortKnuth(nums_10k_1000);
                    clock_t end1 = clock();
                    assert(checkIncrease(nums_10k_1000));
                    double seconds1 = (double)(end1 - start1) / CLOCKS_PER_SEC;
                    std::cout << ",  " << seconds1 << "s";
                    
                    readFileToVector("nums_10k_1000.txt", nums_10k_1000);
                    clock_t start2 = clock();
                    ShellSortKnuth(nums_10k_1000);
                    clock_t end2 = clock();
                    assert(checkIncrease(nums_10k_1000));
                    double seconds2 = (double)(end2 - start2) / CLOCKS_PER_SEC;
                    std::cout << ", " << seconds2 << "s" << std::endl;
                    
                    double mediumTime = (seconds + seconds1 + seconds2) / 3;
                    std::cout << "-Medium time - " << mediumTime << "s" << std::endl;
                }
                
                {
                    readFileToVector("nums_10k_100000.txt", nums_10k_100000);
                    clock_t start = clock();
                    ShellSortKnuth(nums_10k_100000);
                    clock_t end = clock();
                    assert(checkIncrease(nums_10k_100000));
                    double seconds = (double)(end - start) / CLOCKS_PER_SEC;
                    std::cout << "ShellSortKnuth: nums_10k_100000\n-Time - " << seconds << "s";
                    
                    readFileToVector("nums_10k_100000.txt", nums_10k_100000);
                    clock_t start1 = clock();
                    ShellSortKnuth(nums_10k_100000);
                    clock_t end1 = clock();
                    assert(checkIncrease(nums_10k_100000));
                    double seconds1 = (double)(end1 - start1) / CLOCKS_PER_SEC;
                    std::cout << ", " << seconds1 << "s";
                    
                    readFileToVector("nums_10k_100000.txt", nums_10k_100000);
                    clock_t start2 = clock();
                    ShellSortKnuth(nums_10k_100000);
                    clock_t end2 = clock();
                    assert(checkIncrease(nums_10k_100000));
                    double seconds2 = (double)(end2 - start2) / CLOCKS_PER_SEC;
                    std::cout << ", " << seconds2 << "s" << std::endl;
                    
                    double mediumTime = (seconds + seconds1 + seconds2) / 3;
                    std::cout << "-Medium time - " << mediumTime << "s" << std::endl;
                }
            }
            std::cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << std::endl;
            {
                {
                    readFileToVector("nums_100k_10.txt", nums_100k_10);
                    clock_t start = clock();
                    ShellSortKnuth(nums_100k_10);
                    clock_t end = clock();
                    assert(checkIncrease(nums_100k_10));
                    double seconds = (double)(end - start) / CLOCKS_PER_SEC;
                    std::cout << "ShellSortKnuth: nums_100k_10\n-Time - " << seconds << "s";
                    
                    readFileToVector("nums_100k_10.txt", nums_100k_10);
                    clock_t start1 = clock();
                    ShellSortKnuth(nums_100k_10);
                    clock_t end1 = clock();
                    assert(checkIncrease(nums_100k_10));
                    double seconds1 = (double)(end1 - start1) / CLOCKS_PER_SEC;
                    std::cout << ", " << seconds1 << "s";
                    
                    readFileToVector("nums_100k_10.txt", nums_100k_10);
                    clock_t start2 = clock();
                    ShellSortKnuth(nums_100k_10);
                    clock_t end2 = clock();
                    assert(checkIncrease(nums_100k_10));
                    double seconds2 = (double)(end2 - start2) / CLOCKS_PER_SEC;
                    std::cout << ", " << seconds2 << "s" << std::endl;;
                    
                    double mediumTime = (seconds + seconds1 + seconds2) / 3;
                    std::cout << "-Medium time - " << mediumTime << "s" << std::endl;
                }
                
                
                {
                    readFileToVector("nums_100k_1000.txt", nums_100k_1000);
                    clock_t start = clock();
                    ShellSortKnuth(nums_100k_1000);
                    clock_t end = clock();
                    assert(checkIncrease(nums_100k_1000));
                    double seconds = (double)(end - start) / CLOCKS_PER_SEC;
                    std::cout << "ShellSortKnuth: nums_100k_1000\n-Time - " << seconds << "s";
                    
                    readFileToVector("nums_100k_1000.txt", nums_100k_1000);
                    clock_t start1 = clock();
                    ShellSortKnuth(nums_100k_1000);
                    clock_t end1 = clock();
                    assert(checkIncrease(nums_100k_1000));
                    double seconds1 = (double)(end1 - start1) / CLOCKS_PER_SEC;
                    std::cout << ", " << seconds1 << "s";
                    
                    readFileToVector("nums_100k_1000.txt", nums_100k_1000);
                    clock_t start2 = clock();
                    ShellSortKnuth(nums_100k_1000);
                    clock_t end2 = clock();
                    assert(checkIncrease(nums_100k_1000));
                    double seconds2 = (double)(end2 - start2) / CLOCKS_PER_SEC;
                    std::cout << ", " << seconds2 << "s" << std::endl;
                    
                    double mediumTime = (seconds + seconds1 + seconds2) / 3;
                    std::cout << "-Medium time - " << mediumTime << "s" << std::endl;
                }
                
                {
                    readFileToVector("nums_100k_100000.txt", nums_100k_100000);
                    clock_t start = clock();
                    ShellSortKnuth(nums_100k_100000);
                    clock_t end = clock();
                    assert(checkIncrease(nums_100k_100000));
                    double seconds = (double)(end - start) / CLOCKS_PER_SEC;
                    std::cout << "ShellSortKnuth: nums_100k_100000\n-Time - " << seconds << "s";
                    
                    readFileToVector("nums_100k_100000.txt", nums_100k_100000);
                    clock_t start1 = clock();
                    ShellSortKnuth(nums_100k_100000);
                    clock_t end1 = clock();
                    assert(checkIncrease(nums_100k_100000));
                    double seconds1 = (double)(end1 - start1) / CLOCKS_PER_SEC;
                    std::cout << ", " << seconds1 << "s";
                    
                    readFileToVector("nums_100k_100000.txt", nums_100k_100000);
                    clock_t start2 = clock();
                    ShellSortKnuth(nums_100k_100000);
                    clock_t end2 = clock();
                    assert(checkIncrease(nums_100k_100000));
                    double seconds2 = (double)(end2 - start2) / CLOCKS_PER_SEC;
                    std::cout << ", " << seconds2 << "s" << std::endl;
                    
                    double mediumTime = (seconds + seconds1 + seconds2) / 3;
                    std::cout << "-Medium time - " << mediumTime << "s" << std::endl;
                }
            }
            std::cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << std::endl;
            {
                {
                    readFileToVector("nums_1kk_10.txt", nums_1kk_10);
                    clock_t start = clock();
                    ShellSortKnuth(nums_1kk_10);
                    clock_t end = clock();
                    assert(checkIncrease(nums_1kk_10));
                    double seconds = (double)(end - start) / CLOCKS_PER_SEC;
                    std::cout << "ShellSortKnuth: nums_1kk_10\n-Time - " << seconds << "s";
                    
                    readFileToVector("nums_1kk_10.txt", nums_1kk_10);
                    clock_t start1 = clock();
                    ShellSortKnuth(nums_1kk_10);
                    clock_t end1 = clock();
                    assert(checkIncrease(nums_1kk_10));
                    double seconds1 = (double)(end1 - start1) / CLOCKS_PER_SEC;
                    std::cout << ", " << seconds1 << "s";
                    
                    readFileToVector("nums_1kk_10.txt", nums_1kk_10);
                    clock_t start2 = clock();
                    ShellSortKnuth(nums_1kk_10);
                    clock_t end2 = clock();
                    assert(checkIncrease(nums_1kk_10));
                    double seconds2 = (double)(end2 - start2) / CLOCKS_PER_SEC;
                    std::cout << ", " << seconds2 << "s" << std::endl;
                    
                    double mediumTime = (seconds + seconds1 + seconds2) / 3;
                    std::cout << "-Medium time - " << mediumTime << "s" << std::endl;
                }
                
                {
                    readFileToVector("nums_1kk_1000.txt", nums_1kk_1000);
                    clock_t start = clock();
                    ShellSortKnuth(nums_1kk_1000);
                    clock_t end = clock();
                    assert(checkIncrease(nums_100k_1000));
                    double seconds = (double)(end - start) / CLOCKS_PER_SEC;
                    std::cout << "ShellSortKnuth: nums_1kk_1000\n-Time - " << seconds << "s";
                    
                    readFileToVector("nums_1kk_1000.txt", nums_1kk_1000);
                    clock_t start1 = clock();
                    ShellSortKnuth(nums_1kk_1000);
                    clock_t end1 = clock();
                    assert(checkIncrease(nums_100k_1000));
                    double seconds1 = (double)(end1 - start1) / CLOCKS_PER_SEC;
                    std::cout << ", " << seconds1 << "s";
                    
                    readFileToVector("nums_1kk_1000.txt", nums_1kk_1000);
                    clock_t start2 = clock();
                    ShellSortKnuth(nums_1kk_1000);
                    clock_t end2 = clock();
                    assert(checkIncrease(nums_100k_1000));
                    double seconds2 = (double)(end2 - start2) / CLOCKS_PER_SEC;
                    std::cout << ", " << seconds2 << "s" << std::endl;
                    
                    double mediumTime = (seconds + seconds1 + seconds2) / 3;
                    std::cout << "-Medium time - " << mediumTime << "s" << std::endl;
                }
                
                {
                    readFileToVector("nums_1kk_100000.txt", nums_1kk_100000);
                    clock_t start = clock();
                    ShellSortKnuth(nums_1kk_100000);
                    clock_t end = clock();
                    assert(checkIncrease(nums_1kk_100000));
                    double seconds = (double)(end - start) / CLOCKS_PER_SEC;
                    std::cout << "ShellSortKnuth: nums_1kk_100000\n-Time - " << seconds << "s";
                    
                    readFileToVector("nums_1kk_100000.txt", nums_1kk_100000);
                    clock_t start1 = clock();
                    ShellSortKnuth(nums_1kk_100000);
                    clock_t end1 = clock();
                    assert(checkIncrease(nums_1kk_100000));
                    double seconds1 = (double)(end1 - start1) / CLOCKS_PER_SEC;
                    std::cout << ", " << seconds1 << "s";
                    
                    readFileToVector("nums_1kk_100000.txt", nums_1kk_100000);
                    clock_t start2 = clock();
                    ShellSortKnuth(nums_1kk_100000);
                    clock_t end2 = clock();
                    assert(checkIncrease(nums_1kk_100000));
                    double seconds2 = (double)(end2 - start2) / CLOCKS_PER_SEC;
                    std::cout << ", " << seconds2 << "s" << std::endl;
                    
                    double mediumTime = (seconds + seconds1 + seconds2) / 3;
                    std::cout << "-Medium time - " << mediumTime << "s" << std::endl;
                }
            }
        }
        
    }
    */
    
    return 0;
}

