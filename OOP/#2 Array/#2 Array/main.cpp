#include <iostream>

#include "midland++.hpp"


double calculateAvg(Array array) {
    
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
    
    int temp[5] = {1, 2, 3, 4, 5};
    Array t(temp, 5), a(10, 0), b(5, 1), c(1, 10), tt(5, 10);
    
    tt.setRandomNumbers(1, 5);
    
    tt += tt;
    tt.print();
    
    return 0;
}
