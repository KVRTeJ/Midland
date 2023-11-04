#include <iostream>

#include "midland++.hpp"

int main() {
    //по умолчанию
    BoolVector temp = "11101010", tem;
    std::cout << temp;
    temp.set(0);
    std::cout << temp;
    return 0;
}
