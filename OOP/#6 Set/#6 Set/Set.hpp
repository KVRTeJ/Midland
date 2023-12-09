#pragma once

#include <iostream>

#include "BoolVector.hpp"

class Set : public BoolVector {
public:
    Set(const char value = (char) 0) { //Или лучше = 'a' ?
        m_set = new BoolVector(N);
        m_set->set((int) value, 1);
        m_cardinalis = 1;
        m_cardinalis <<= 1;
    }
    Set(const char* string);
    Set(const Set& other);
    ~Set() {delete m_set;}
    
    int cardinalis() const {return m_cardinalis;}
    bool contains(const char value) const {return m_set->operator[]((int) value);}
    
    Set& operator = (const Set& other);
    Set& operator += (const char value);
    Set operator + (const char value) const;
    Set& operator -= (const char value);
    Set operator - (const char value) const;
    
    static const int N = 127;
private:
    BoolVector* m_set = nullptr;
    int m_cardinalis = 0;//мощность -> 2^n ?
    
};

std::ostream& operator << (std::ostream& stream, const Set& other);
std::istream& operator >> (std::istream& stream, Set& other);
