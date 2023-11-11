#pragma once

#include <iostream>

#include "../../#3 Bool Vector/#3 Bool Vector/BoolVector.hpp"

class BoolMatrix {
public:
    BoolMatrix(const int rowSize = 3, const int columnSize = 3, const bool value = false);
    BoolMatrix(char** matrix);//
    BoolMatrix(const BoolMatrix& other);
    BoolMatrix(BoolMatrix&& other);
    ~BoolMatrix();
    
    int getRowSize() const {return m_rowSize;}
    int getColumnSize() const {return m_columnSize;}
    
    bool swap();
    void scan();
    void print() const;
    
    int weight() const;
    
    BoolMatrix& operator = (const BoolMatrix& other);
    BoolMatrix& operator = (BoolMatrix&& other);
    BoolVector& operator [] (const int index);
    
private:
    BoolVector* m_rows = nullptr;
    int m_rowSize = 0;
    int m_columnSize = 0;
};

std::istream& operator >> (std::istream& stream, BoolMatrix& other);
std::ostream& operator << (std::ostream& stream, BoolMatrix& other);

