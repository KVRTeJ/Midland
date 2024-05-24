#pragma once

#include <iostream>
#include <vector>
#include <assert.h>

class BoolVector {
    friend std::ostream& operator << (std::ostream& stream, const BoolVector& object);
    friend std::istream& operator >> (std::istream& stream, BoolVector& object);
private:
    class BoolRank;
public:
    BoolVector(const int lenth = CELL_SIZE, const bool value = false);
    BoolVector(const char* string);
    BoolVector(const std::vector<char>& string);
    BoolVector(const BoolVector& other);
    virtual ~BoolVector();
    
    void add(const char value, int unsignificantRankCount = 0);
    
    void setUnsignificantRankCount(const int value) {assert(value >= 0); m_unsignificantRankCount = value; m_lenght -= value;}
    int weight() const;
    int unsignificantRankCount() const {return m_unsignificantRankCount;}
    int lenth() const {return m_lenght;}
    int cellCount() const {return m_cellCount;}
    void print() const;
    void scan();
    
    void swap(BoolVector& other);
    void invert();
    void invert(const int position);
    void set(const int position, const bool value);
    void set(const int posFrom, const int posTo, const bool value);
    void set(const bool value);
    unsigned int getLenth() const {
        return m_lenght;
    }
    
    uint8_t* cells() const {return m_cells;}
    
    BoolRank operator [] (const int index);
    const BoolRank operator [] (const int index) const;
    BoolVector& operator = (const BoolVector& other);
    BoolVector& operator += (const bool value);
    BoolVector operator + (const bool value);
    BoolVector& operator += (const BoolVector& value);
    BoolVector operator ~ () const;
    BoolVector operator & (const BoolVector& other) const;
    BoolVector operator | (const BoolVector& other) const;
    BoolVector operator ^ (const BoolVector& other) const;
    BoolVector operator >> (const int value) const;
    BoolVector operator << (const int value) const;
    BoolVector& operator &= (const BoolVector& other);
    BoolVector& operator |= (const BoolVector& other);
    BoolVector& operator ^= (const BoolVector& other);
    BoolVector& operator >>= (int value);
    BoolVector& operator <<= (int value);
    bool operator == (const BoolVector& other) const;
    bool operator != (const BoolVector& other) const {return !(*this == other);}
    
    static const uint8_t CELL_SIZE = 8;
    
private:
    void m_setInCell(const int cellNumber, const int position);
    void m_unSetInCell(const int cellNumber, const int position);
    void m_printCell(const int cellNumber) const;
    void m_twich();
    
    uint8_t* m_cells = nullptr;
    unsigned int m_cellCount = 0;
    unsigned int m_lenght = 0;
    uint8_t m_unsignificantRankCount = 0;
    
};

class BoolVector::BoolRank {
public:
    BoolRank(uint8_t* cell, const int& maskPos) {
        m_cell = cell;
        m_mask >>= maskPos;
    }
    
    BoolRank& operator = (const BoolRank& other);
    BoolRank& operator = (const bool value);
    bool operator & (const bool value) const;
    bool operator ~ () const;
    bool operator ^ (const bool value) const;
    bool operator == (const BoolRank& other) const;
    bool operator == (const bool value) const;
    operator bool() const;
    
private:
    uint8_t* m_cell = nullptr;
    uint8_t m_mask = 1 << 7;
    
};



std::ostream& operator << (std::ostream& stream, const BoolVector& object);

std::istream& operator >> (std::istream& stream, BoolVector& object);
