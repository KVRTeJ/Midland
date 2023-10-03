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
    Array t(temp, 5), a(10, 0), b(5, 1), c(1, 10), tt;
    
    tt.print();
    tt = t + 5;
    tt.print();
    std::cout << tt.getMinElement() << std::endl;
    tt.setRandomNumbers(1, 10);
    tt.print();
    tt.sort();
    tt.print();
    
    
    

    
    return 0;
}
