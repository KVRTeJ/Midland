#pragma once

#include <iostream>

class BoolVector {
public:
    class BoolRank;
public:
    BoolVector(const int& lenth = m_CELL_SIZE, const bool& value = false);
    BoolVector(const char* string);
    BoolVector(const BoolVector& other);
    ~BoolVector();
    
    int weight() const;
    void print() const;
    void scan();
    
    void twich();
    
    void swap(BoolVector& other);
    void invert();
    void invert(const int& position);
    void set(const int& position, const bool& value);
    unsigned int getLenth() {
        return m_lenth;
    }
    
    BoolRank operator [] (const int& index);
    BoolVector& operator = (const BoolVector& other);
    BoolVector& operator ~ ();
    BoolVector operator & (const BoolVector& other);
    BoolVector operator | (const BoolVector& other);
    BoolVector operator ^ (const BoolVector& other);
    //BoolVector& operator >>= (const int& value);//
    //BoolVector& operator <<= (const int& value);//
    
private:
    void m_setInCell(const int& cellNumber, const int& position);
    void m_unSetInCell(const int& cellNumber, const int& position);
    void m_printCell(const int& cellNumber) const;
    
    static const uint8_t m_CELL_SIZE = 8; //Размер ячейки
    uint8_t* m_cells = nullptr; //Сами ячейки
    unsigned int m_cellCount = 0; //Кол-во ячеек
    unsigned int m_lenth = 0; //Длина вектора
    uint8_t m_significantRankCount = 0; //Кол-во незначащих 0
    
};

/**
 перегрузки стандартных операций (присваивание, битовое сложение, умножение, инверсия, исключающее ИЛИ. Рекомендуется также определить операции сравнения и присваивание, как между объектами класса BoolRank, так и с одним из базовых типов (int/bool/char), а также конвертацию типа Rank в один из базовых типов.
 **/

class BoolVector::BoolRank {
public:
    BoolRank(uint8_t* cell, const int& maskPos) {
        m_cell = cell;
        m_mask >>= maskPos;
    }
    
    BoolRank& operator = (const bool& value);
    BoolRank& operator ~ ();
    BoolRank operator & ();
    
private:
    uint8_t* m_cell = nullptr;
    uint8_t m_mask = 1 << 7;
    
};

inline std::ostream& operator << (std::ostream& stream, const BoolVector& object) {
    object.print();
    return stream;
}

inline std::istream& operator >> (std::istream& stream, BoolVector& object) {
    object.scan();
    return stream;
}
