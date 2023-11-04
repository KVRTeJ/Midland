#include <iostream>

#include "midland++.hpp"

int main() {
    //по умолчанию
    BoolVector temp = "10101010", tem;
    std::cout << temp;
    tem[0] = ~temp[0];
    std::cout << temp;
    std::cout << tem;
    //if(temp[0] == tem[0])
        std::cout << "true" << std::endl;
    return 0;
}
