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
    
    int temp[5] = {1, 2, 3, 4, 5};
    Array<int> t(temp, 5), a(10, 0), b(5, 1), c(1, 10), tt(5, 10);
    
    tt.setRandomNumbers(1, 5);
    
    //tt += tt;
    
    Array<int>::Iterator it = tt.begin();
    
    it = 2;
    std::cout << it.getPosition() << std::endl;
    
    //std::cin >> tt;
    tt.print();
    
    Array<int>::Iterator begin = tt.begin(), end = tt.begin();
    
    begin = 1;
    end = 3;
    
    tt.removeInRange(begin, end);
    
    std::cout << tt;
    
    
    return 0;
}
