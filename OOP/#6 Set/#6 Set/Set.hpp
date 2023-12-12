#pragma once

#include "BoolVector.hpp"

class Set : public BoolVector {
public:
    Set(const char value = (char) 0) {
        m_set = new BoolVector(MAX_CARDINALIS);
        
        if(value - NEEDLESS_TABLE >= 0 && value - NEEDLESS_TABLE < MAX_CARDINALIS) {
            m_set->set((int) value - NEEDLESS_TABLE, 1);
        }
        
    }
    Set(const char* string);
    Set(const Set& other);
    ~Set() {delete m_set;}
    
    int cardinalis() const {return m_set->weight();}
    bool contains(const char value) const {if(value < 0 && value >= MAX_CARDINALIS) return false;
        return m_set->operator[]((int) value);}
    char max() const;
    char min() const;
    
    Set& operator = (const Set& other);
    Set& operator |= (const Set& other) {*m_set |= *other.m_set; return *this;}
    Set operator | (const Set& other) const;
    Set& operator &= (const Set& other) {*m_set &= *other.m_set; return *this;}
    Set operator & (const Set& other) const;
    Set& operator /= (const Set& other);
    Set operator / (const Set& other) const;
    Set& operator += (const char value);
    Set operator + (const char value) const;
    Set& operator -= (const char value);
    Set operator - (const char value) const;
    Set operator ~ () const;
    bool operator == (const Set& other) const {return *m_set == *other.m_set;}
    bool operator != (const Set& other) const {return !(*this == other);}
    
    static const int MAX_CARDINALIS = 95;
private:
    static const int NEEDLESS_TABLE = 32;
    BoolVector* m_set = nullptr;
    
};

std::ostream& operator << (std::ostream& stream, const Set& other);
std::istream& operator >> (std::istream& stream, Set& other);
