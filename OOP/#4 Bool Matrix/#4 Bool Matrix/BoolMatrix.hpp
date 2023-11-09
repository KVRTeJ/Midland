#pragma once

#include <iostream>

#include "../../#3 Bool Vector/#3 Bool Vector/BoolVector.hpp"

class BoolMatrix {
public:
    class BoolVector;
public:
    BoolMatrix() { std::cout << "Hello World" << std::endl; }
    
private:
    BoolVector* matrix = nullptr;
    const int rowSize = 0;
    const int columnSize = 0;
};
