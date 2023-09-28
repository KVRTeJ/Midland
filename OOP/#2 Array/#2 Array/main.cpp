#include <iostream>

#include "midland++.hpp"


double calculateAvg(Array array) {
    
    if(array.getArraySize() == 0) {
        return 0;
    }
    
    double temp = 0;
    for(int i = 0; i < array.getArraySize(); i++) {
        temp += array[i];
    }
    
    return temp/array.getArraySize();
    
}

int main() {
    
    Array t(10, 2), t1(1, 1);
    t1 = t;
    t[2] = 10;
    t.print();
    t1.print();
    
    return 0;
}
