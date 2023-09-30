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
    int temp[5] = {1, 3, 3, 1, 2};
    Array t(temp, 5);
    //t.sort();
    t.print();
    t.removeIndex(2);
    t.print();
    std::cout << t.getMaxElementIndex() << " - " << t.getMinElementIndex() << std::endl;
    
    return 0;
}
