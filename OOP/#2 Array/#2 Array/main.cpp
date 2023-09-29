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
    int temp[5] = {1, 3, 3, 5, 2};
    Array t(temp, 5);
    t.sort();
    t.print();
    t.insert(5, 99);
    t.print();
    return 0;
}
