#include <iostream>

#include "midland++.hpp"

template <typename Type>
double calculateAvg(Array<Type> array) {
    
    if(array.getSize() == 0) {
        return 0;
    }
    
    double temp = 0;
    for(int i = 0; i < array.getSize(); i++) {
        temp += array[i];
    }
    
    return temp/array.getSize();
    
}

int main() {
    char  s[5] = "hllo";
    Array<char> string(1, 10), tString(s, 5);
    
    std::cout << string << std::endl;
    std::cout << tString << std::endl;
    
    
    return 0;
}
