#pragma once

#include <iostream>

#include "../../#3 Bool Vector/#3 Bool Vector/BoolVector.hpp"

class BoolMatrix {
public:
    class BoolVector;
public:
    BoolMatrix(const int rowSize = 3, const int columnSize = 3, const bool value = false) {
        std::cout << "Hello World" << std::endl;
    }
    BoolMatrix(const char** matrix);
    BoolMatrix(const BoolMatrix& other);
    BoolMatrix(BoolMatrix&& other);
    ~BoolMatrix();
    
    int getRowSize() const;
    int getColumnSize() const;
    
    bool swap();
    void scan();
    void print() const;
    
    int weight() const;
    
    
    BoolMatrix& operator = (const BoolMatrix& other);
    BoolMatrix& operator = (BoolMatrix&& other);
    
    
private:
    BoolVector* matrix = nullptr;
    const int rowSize = 0;
    const int columnSize = 0;
};

std::istream& operator << (std::istream& stream, BoolMatrix& other);
std::ostream& operator << (std::ostream& stream, BoolMatrix& other);

