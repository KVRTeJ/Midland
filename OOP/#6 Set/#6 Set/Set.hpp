#pragma once

#include <iostream>

#include "BoolVector.hpp"

class Set : public BoolVector {
public:
    Set(const char value = 'a') {
        m_set = new BoolVector(127);
        m_set->set((int) value, 1);
        m_cardinalis = 1;
        m_cardinalis <<= 1;
    }
    Set(const char* string);
    ~Set() {delete m_set;}
    int cardinalis() const {return m_cardinalis;}
private:
    BoolVector* m_set = nullptr;
    int m_cardinalis = 0;//мощность -> 2^n?, n = 0, 256 ?
    
};
