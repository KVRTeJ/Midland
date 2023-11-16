#pragma once

#include <iostream>
#include <vector>

#include "BoolVector.hpp"

class BoolMatrix {
public:
    BoolMatrix(const int colCount = 3, const int rowCount = 3, const bool value = false);
    BoolMatrix(std::vector< std::vector<char> > matrix);
    BoolMatrix(char** matrix, const int colCount, const int rowCount);
    BoolMatrix(const BoolMatrix& other);
    ~BoolMatrix();
    
    int getRowCount() const {return m_columnCount;}
    int getColumnCount() const {return m_rowCount;}
    int getWeight() const;
    int getWeight(const int row) const;
    BoolVector getConjunctionRows() const;
    BoolVector getDisjunctionRows() const;
    
    void set(const int row, const int col, const bool value);
    void set(const int row, const int from,
             const int to, const bool value);
    
    void invert(const int row, const int col);
    void invert(const int row, const int from,
                const int to);
    
    void swap(BoolMatrix& other);
    
    BoolMatrix& operator = (const BoolMatrix& other);
    BoolVector& operator [] (const int index);
    const BoolVector& operator [] (const int index) const;
    BoolMatrix operator & (const BoolMatrix& other) const;
    BoolMatrix operator | (const BoolMatrix& other) const;
    BoolMatrix operator ^ (const BoolMatrix& other) const;
    BoolMatrix& operator &= (const BoolMatrix& other);
    BoolMatrix& operator |= (const BoolMatrix& other);
    BoolMatrix& operator ^= (const BoolMatrix& other);
    BoolMatrix operator ~ () const;
    
private:
    BoolVector* m_rows = nullptr;
    int m_columnCount = 0;
    int m_rowCount = 0;
};

std::istream& operator >> (std::istream& stream, BoolMatrix& other);
std::ostream& operator << (std::ostream& stream, const BoolMatrix& other);

