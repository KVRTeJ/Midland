#include <iostream>
#include <vector>

#include "midland++.hpp"

int main() {
    
    std::vector<int> temp;
    
    temp.push_back(2);
    temp.push_back(3);
    temp.push_back(4);
    temp.push_back(5);
    temp.push_back(1);
    
    printVector(temp);
    
    insertionSort(temp);
    
    printVector(temp);
    
    
    
    return 0;
}
