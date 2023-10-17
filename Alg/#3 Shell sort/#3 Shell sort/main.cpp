#include <iostream>
#include <vector>
#include <time.h>

#include "midland++.hpp"

int main() {
    
    /**
     - сгенерировать 9 различных массивов, заполненных случайными значениями: (размером 10000, 100000 и 1000000 элементов, для каждого по три диапазона значений: -10/10, -1000/1000, -100000/100000). Полученные массивы записать в файл и приложить к ответу (эти же выборки будут затем использоваться для других лабораторных);
     - совершить хотя бы по три запуска каждого алгоритма выбора диапазона на каждом тестовом массиве и вычислить среднее время работы алгоритма для каждого из массивов (экономьте своё время, написав заранее несколько вызовов сортировок, а не перезапуская каждый раз программу). Полученные данные в виде отчёта также приложите к ответу.
     */
    
    std::vector<int> nums_10k_10;
    std::vector<int> nums_10k_1000;
    std::vector<int> nums_10k_100000;
    fillRandomNums(nums_10k_10, 10000, -10, 10);
    fillRandomNums(nums_10k_1000, 10000, -1000, 1000);
    fillRandomNums(nums_10k_100000, 10000, -100000, 100000);
    createFileWithVector("nums_10k_10.txt", nums_10k_10);
    createFileWithVector("nums_10k_1000.txt", nums_10k_1000);
    createFileWithVector("nums_10k_100000.txt", nums_10k_100000);
    
    std::vector<int> nums_100k_10;
    std::vector<int> nums_100k_1000;
    std::vector<int> nums_100k_100000;
    fillRandomNums(nums_100k_10, 100000, -10, 10);
    fillRandomNums(nums_100k_1000, 100000, -1000, 1000);
    fillRandomNums(nums_100k_100000, 100000, -100000, 100000);
    createFileWithVector("nums_100k_10.txt", nums_100k_10);
    createFileWithVector("nums_100k_1000.txt", nums_100k_1000);
    createFileWithVector("nums_100k_100000.txt", nums_100k_100000);
    
    std::vector<int> nums_1kk_10;
    std::vector<int> nums_1kk_1000;
    std::vector<int> nums_1kk_100000;
    fillRandomNums(nums_1kk_10, 1000000, -10, 10);
    fillRandomNums(nums_1kk_1000, 1000000, -1000, 1000);
    fillRandomNums(nums_1kk_100000, 1000000, -100000, 100000);
    createFileWithVector("nums_1kk_10.txt", nums_1kk_10);
    createFileWithVector("nums_1kk_1000.txt", nums_1kk_1000);
    createFileWithVector("nums_1kk_100000.txt", nums_1kk_100000);
    
    {
    //Источник алгоритмов выбора шага: https://en.wikipedia.org/wiki/Shellsort#Applications
        
        /* Шаги Шелла */
        {
            {
                {
                    clock_t start = clock();
                    ShellSort(nums_10k_10);
                    clock_t end = clock();
                    double seconds = (double)(end - start) / CLOCKS_PER_SEC;
                    std::cout << "ShellSort: nums_10k_10\n-Time - " << seconds << "s" << std::endl;
                }
                assert(checkIncrease(nums_10k_10));
                
                {
                    clock_t start = clock();
                    ShellSort(nums_10k_1000);
                    clock_t end = clock();
                    double seconds = (double)(end - start) / CLOCKS_PER_SEC;
                    std::cout << "ShellSort: nums_10k_1000\n-Time - " << seconds << "s" << std::endl;
                }
                assert(checkIncrease(nums_10k_1000));
                
                {
                    clock_t start = clock();
                    ShellSort(nums_10k_100000);
                    clock_t end = clock();
                    double seconds = (double)(end - start) / CLOCKS_PER_SEC;
                    std::cout << "ShellSort: nums_10k_100000\n-Time - " << seconds << "s" << std::endl;
                }
                assert(checkIncrease(nums_10k_100000));
            }
            std::cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << std::endl;
            {
                {
                    clock_t start = clock();
                    ShellSort(nums_100k_10);
                    clock_t end = clock();
                    double seconds = (double)(end - start) / CLOCKS_PER_SEC;
                    std::cout << "ShellSort: nums_100k_10\n-Time - " << seconds << "s" << std::endl;
                }
                assert(checkIncrease(nums_100k_10));
                
                {
                    clock_t start = clock();
                    ShellSort(nums_100k_1000);
                    clock_t end = clock();
                    double seconds = (double)(end - start) / CLOCKS_PER_SEC;
                    std::cout << "ShellSort: nums_100k_1000\n-Time - " << seconds << "s" << std::endl;
                }
                assert(checkIncrease(nums_100k_1000));
                
                {
                    clock_t start = clock();
                    ShellSort(nums_100k_100000);
                    clock_t end = clock();
                    double seconds = (double)(end - start) / CLOCKS_PER_SEC;
                    std::cout << "ShellSort: nums_100k_100000\n-Time - " << seconds << "s" << std::endl;
                }
                assert(checkIncrease(nums_100k_100000));
            }
            std::cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << std::endl;
            {
                {
                    clock_t start = clock();
                    ShellSort(nums_1kk_10);
                    clock_t end = clock();
                    double seconds = (double)(end - start) / CLOCKS_PER_SEC;
                    std::cout << "ShellSort: nums_1kk_10\n-Time - " << seconds << "s" << std::endl;
                }
                assert(checkIncrease(nums_1kk_10));
                
                {
                    clock_t start = clock();
                    ShellSort(nums_1kk_1000);
                    clock_t end = clock();
                    double seconds = (double)(end - start) / CLOCKS_PER_SEC;
                    std::cout << "ShellSort: nums_1kk_1000\n-Time - " << seconds << "s" << std::endl;
                }
                assert(checkIncrease(nums_100k_1000));
                
                {
                    clock_t start = clock();
                    ShellSort(nums_1kk_100000);
                    clock_t end = clock();
                    double seconds = (double)(end - start) / CLOCKS_PER_SEC;
                    std::cout << "ShellSort: nums_1kk_100000\n-Time - " << seconds << "s" << std::endl;
                }
                assert(checkIncrease(nums_1kk_100000));
            }
        }
        
        /*
        //Шаги Хиббарда
        {
            {
                clock_t start = clock();
                ShellSortHibbard(nums_100k_10);
                clock_t end = clock();
                double seconds = (double)(end - start) / CLOCKS_PER_SEC;
                std::cout << "Time ShellSortHibbard - " << seconds << "s" << std::endl;
            }
            assert(checkIncrease(nums_100k_10));
        }
        
        
        //Шаги Кнута
        {
            clock_t start = clock();
            ShellSortKnuth(temp2);
            clock_t end = clock();
            double seconds = (double)(end - start) / CLOCKS_PER_SEC;
            std::cout << "Time ShellSortKnuth - " << seconds << "s" << std::endl;
        }
        assert(checkIncrease(temp2));
        */
    }
    
    return 0;
}

