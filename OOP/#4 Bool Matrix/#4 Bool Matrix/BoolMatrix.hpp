#pragma once

#include <iostream>
#include <vector>

#include "../../#3 Bool Vector/#3 Bool Vector/BoolVector.hpp"

class BoolMatrix {
public:
    BoolMatrix(const int columnSize = 3, const int rowSize = 3, const bool value = false);
    BoolMatrix(std::vector< std::vector<char> > matrix);//
    BoolMatrix(char** matrix, const int columnSize, const int rowSize);
    BoolMatrix(char** matrix);/* FIXME */
    BoolMatrix(const BoolMatrix& other);
    BoolMatrix(BoolMatrix&& other);
    ~BoolMatrix();
    
    int getRowSize() const {return m_rowSize;}
    int getColumnSize() const {return m_columnSize;}
    int getWeight() const;
    int getWeight(const int columnIndex) const;
    BoolVector getConjunctionRows() const;
    BoolVector getDisjunctionRows() const;
    
    void set(const int columnIndex, const int indexInRow, const bool value);
    void set(const int columnIndex, const int posFromInRow,
             const int posToInRow, const bool value);
    
    void invert(const int columnIndex, const int indexInRow);
    void invert(const int columnIndex, const int posFromInRow,
                const int posToInRow);
    
    void swap(BoolMatrix& other);
    
    BoolMatrix& operator = (const BoolMatrix& other);
    BoolVector& operator [] (const int index);
    BoolMatrix operator & (const BoolMatrix& other) const;
    BoolMatrix operator | (const BoolMatrix& other) const;
    BoolMatrix operator ^ (const BoolMatrix& other) const;
    BoolMatrix& operator &= (const BoolMatrix& other);
    BoolMatrix& operator |= (const BoolMatrix& other);
    BoolMatrix& operator ^= (const BoolMatrix& other);
    BoolMatrix operator ~ () const;
    
private:
    BoolVector* m_rows = nullptr;
    int m_rowSize = 0;
    int m_columnSize = 0;
};

std::istream& operator >> (std::istream& stream, BoolMatrix& other);
std::ostream& operator << (std::ostream& stream, BoolMatrix& other);

