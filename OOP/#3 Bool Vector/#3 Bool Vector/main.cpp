#include <iostream>

#include "midland++.hpp"

int main() {
    //по умолчанию
    BoolVector temp(9, 1);
    std::cout << temp;
    temp[1] = ~temp[8];
    //[1 1 1 1 1 1 1 1] [0 0 0 0 0 0 0 0]
    //исправляет 8 индекс
    std::cout << temp;
    return 0;
}
