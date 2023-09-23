#include <iostream>

#include "midland++.hpp"

/*
int getSizeString(std::string string) {
    
    int size = 0;
    
    
    for(const auto &i : string) {
    //for(auto i = string.begin(); i != string.end(); ++i)
        
        if(i >= 'а' && i <= 'я')
        
    }
    
    
    return size;
}
*/

void printArray(int* array, int size) {
    
    for(int i = 0; i < size; i++) {
        
        std::cout << array[i] << std::endl;
        
    }
    std::cout << std::endl;
}
