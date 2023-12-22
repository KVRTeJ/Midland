#pragma once

#include "BoolVector.hpp"
#include "midland++.hpp"

class Set : public BoolVector {
public:
    Set(const char value = (char) MAX_CARDINALIS)
    : BoolVector(MAX_CARDINALIS)
    {
        m_set = new BoolVector(MAX_CARDINALIS);
        if(value < MAX_CARDINALIS) {
            m_set->set((int) value, 1);
        }
        
    }
    Set(const char* string);
    Set(const Set& other);
    ~Set() {delete m_set;}
    
    int cardinalis() const {return m_set->weight();}
    bool contains(const char value) const {
        if((unsigned) value >= MAX_CARDINALIS) // if value < 0 => max unsigned => > 127
            return false;
        return m_set->operator[]((int) value);
    }
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
    
    static const int MAX_CARDINALIS;
    static const std::vector<std::string> NOT_ENTERED_CHARAPTERS;
    
private:
    
    BoolVector* m_set = nullptr;
    
};

std::ostream& operator << (std::ostream& stream, const Set& other);
std::istream& operator >> (std::istream& stream, Set& other);
