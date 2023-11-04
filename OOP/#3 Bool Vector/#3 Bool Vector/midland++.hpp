#pragma once

#include <iostream>

class BoolVector {
    friend std::ostream& operator << (std::ostream& stream, const BoolVector& object);
    friend std::istream& operator >> (std::istream& stream, BoolVector& object);
private:
    class BoolRank;
public:
    BoolVector(const int& lenth = CELL_SIZE, const bool& value = false);
    BoolVector(const char* string);
    BoolVector(const BoolVector& other);
    ~BoolVector();
    
    int weight() const;
    void print() const;
    void scan();
    
    void swap(BoolVector& other);
    void invert();
    void invert(const int& POSITION);
    void set(const int& POSITION, const bool& VALUE);
    void set(const int& POS_FROM, const int& POS_TO, const bool& VALUE);
    void set(const bool& VALUE);
    unsigned int getLenth() const {
        return m_lenght;
    }
    
    BoolRank operator [] (const int& index);
    const BoolRank operator [] (const int& index) const;
    BoolVector& operator = (const BoolVector& other);
    BoolVector operator ~ () const;
    BoolVector operator & (const BoolVector& other) const;
    BoolVector operator | (const BoolVector& other) const;
    BoolVector operator ^ (const BoolVector& other) const;
    BoolVector operator >> (const BoolVector& other) const;
    BoolVector operator << (const BoolVector& other) const;
    BoolVector& operator &= (const BoolVector& other);
    BoolVector& operator |= (const BoolVector& other);
    BoolVector& operator ^= (const BoolVector& other);
    //BoolVector& operator >>= (const int& value);//
    //BoolVector& operator <<= (const int& value);//
    
    static const uint8_t CELL_SIZE = 8;
    
private:
    void m_setInCell(const int& cellNumber, const int& position);
    void m_unSetInCell(const int& cellNumber, const int& position);
    void m_printCell(const int& cellNumber) const;
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
    BoolRank& operator = (const bool& value);
    BoolRank operator & (const bool& value);
    BoolRank operator ^ (const bool& value);
    BoolRank operator ~ () const;
    bool operator == (BoolRank other);
    bool operator == (const bool& value);
    operator bool() const;
    
private:
    uint8_t* m_cell = nullptr;
    uint8_t m_mask = 1 << 7;
    
};



inline std::ostream& operator << (std::ostream& stream, const BoolVector& object) {
    
    for(int i = 0; i < object.m_cellCount; ++i) {
        stream << "[";
        for(uint8_t j = 1 << 7; j > 0; j >>= 1) {
            if(object.m_cells[i] & j) {
                stream << "1";
                if((j >> 1) > 0)
                    stream << " ";
            }
            else {
                stream << "0";
                if((j >> 1) > 0)
                    stream << " ";
            }
        }
        stream << "] ";
    }
    stream << std::endl;
    
    return stream;
}

inline std::istream& operator >> (std::istream& stream, BoolVector& object) {//
    char* string = new char [object.m_lenght];
    for(int i = 0; i < object.m_lenght; ++i) {
        stream >> string[i];
    }
    
    for(unsigned int i = 0; i < object.m_lenght; ++i) {
        if(string[i] != '0')
            object.set(i, 1);
        else
            object.set(i, 0);
    }
    
    delete [] string;
    return stream;
}
