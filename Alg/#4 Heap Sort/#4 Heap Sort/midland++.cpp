#include <iostream>
#include <vector>

#include "midland++.hpp"

void readFileToVector(const char *name, std::vector<int>& nums) {
    
    FILE *f;
    f = fopen (name, "r");
    assert(f != NULL);
    
    nums.clear();
    
    {
        int x;
        while (fscanf (f, "%d", &x) != EOF)
            nums.push_back(x);
    }
    
    fclose (f);
}

bool printVectorInt(const std::vector<int>& nums) {
    
    std::cout << "[";
    for(auto it = nums.begin(); it != nums.end(); ++it) {
        if(it != nums.begin()) {
            std::cout << ", ";
        }
        std::cout << *it;
    }
    std::cout << "]" << std::endl;
    
    return true;
}

bool fillRandomNums(std::vector<int>& vector, const long int size,
                    const int min, const int max) {
    
    assert(min < max && size >= 0);
    
    srand((unsigned int) time(0));
    
    for(int i = 0; i < size; ++i) {
        vector.push_back(rand() % (max - min + 1) + min);
    }
    
    return true;
    
}

bool checkIncrease(const std::vector<int> nums) {
    
    for(auto it = nums.begin() + 1; it != nums.end(); ++it) {
        if(*(it - 1) > *it) {
            std::cerr << "bool checkIncrease ended with false" << std::endl;
            return false;
        }
    }
    
    return true;
    
}

void sift(std::vector<int>& nums, const int size, int index) {
    
    int j = 2 * index + 1;
    
    while(index < size) {
        
        if(j < size) {
            if((j + 1) < size)
                if(nums[j + 1] > nums[j])
                    j = j + 1;
            if(nums[index] < nums[j]) {
                std::swap(nums[index], nums[j]);
                index = j;
                j = 2 * index + 1;
            }
            else {
                index += size;
            }
        }
        else { //j > nums.size()
            index += size;
        }
        
    }
    
}

void heapSort(std::vector<int>& nums) {
    
    const int size = (int) nums.size();
    
    //Построение максимальной и упорядочной пирамиды(корень - максимальный элемент)
    //Начало - элементы, которые имеют потомков
    for(int i = size/2 - 1; i >= 0; i--) {
        sift(nums, size, i);
    }
    
    //i = size - 1
    //nums[0] - максимальный, nums[i] - минимальный.
    //Исходя из этих данных:
    //Меняем местами nums[0] и nums[i].
    //Получаем максимальный элемент на i позции.
    //Так как нету элементов больше этого, понижаем i на 1
    //и получаем отсортированную часть
    //размером (size - 1) - (i - 1)
    
    //i - количество неупорядочных элементов
    for(int i = size - 1; i > 0; --i) {
        std::swap(nums[0], nums[i]);
        sift(nums, i);
    }
    
}
