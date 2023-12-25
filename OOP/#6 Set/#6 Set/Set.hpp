#pragma once

#include "BoolVector.hpp"

class Set : public BoolVector {
public:
    Set(const char value = (char) MAX_CARDINALIS)
    : BoolVector(MAX_CARDINALIS)
    {
        if(value < MAX_CARDINALIS) {
            set((int) value, 1);
        }
        
    }
    Set(const char* str);
    Set(const Set& other);
    
    int cardinalis() const {return weight();}
    bool contains(const char value) const {
        if((unsigned) value >= MAX_CARDINALIS) // if value < 0 => max unsigned => > 127
            return false;
        return operator[]((int) value);
    }
    char max() const;
    char min() const;
    void clear() { *this = Set();}
    
    Set& operator = (const Set& other);
    Set& operator |= (const Set& other) { BoolVector::operator |= (other); return *this;}
    Set operator | (const Set& other) const;
    Set& operator &= (const Set& other) { BoolVector::operator &= (other); return *this;; return *this;}
    Set operator & (const Set& other) const;
    Set& operator /= (const Set& other);
    Set operator / (const Set& other) const;
    Set& operator += (const char value);
    Set operator + (const char value) const;
    Set& operator -= (const char value);
    Set operator - (const char value) const;
    Set operator ~ () const;
    bool operator == (const Set& other) const { return BoolVector::operator == (other);}
    bool operator != (const Set& other) const {return !(*this == other);}
    
    static const int MAX_CARDINALIS;
    static const std::vector<std::string> NOT_ENTERED_CHARAPTERS;
    
private:
    
};

std::ostream& operator << (std::ostream& stream, const Set& other);
std::istream& operator >> (std::istream& stream, Set& other);
