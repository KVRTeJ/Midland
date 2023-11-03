#pragma once

#include <iostream>

class BoolVector {
private:
    class BoolRank;
public:
    BoolVector(const int& lenth = m_CELL_SIZE, const bool& value = false);
    BoolVector(const char* string);
    BoolVector(const BoolVector& other);
    ~BoolVector();
    
    int weight() const;
    void print() const;
    void scan();
    
    void swap(BoolVector& other);
    void invert();//исправить
    void invert(const int& position);
    void set(const int& position, const bool& value);
    unsigned int getLenth() const {
        return m_lenght;
    }
    
    BoolRank operator [] (const int& index);
    const BoolRank operator [] (const int& index) const;
    BoolVector& operator = (const BoolVector& other);
    BoolVector operator ~ () const;// переделать
    BoolVector operator & (const BoolVector& other) const; //проверить
    BoolVector operator | (const BoolVector& other) const;
    BoolVector operator ^ (const BoolVector& other) const;
    //BoolVector& operator >>= (const int& value);//
    //BoolVector& operator <<= (const int& value);//
    
    static const uint8_t m_CELL_SIZE = 8;
    
private:
    void m_setInCell(const int& cellNumber, const int& position);
    void m_unSetInCell(const int& cellNumber, const int& position);
    void m_printCell(const int& cellNumber) const;
    void m_twich();
    
    uint8_t* m_cells = nullptr; //Сами ячейки
    unsigned int m_cellCount = 0; //Кол-во ячеек
    unsigned int m_lenght = 0; //Длина вектора
    uint8_t m_unsignificantRankCount = 0; //Кол-во незначащих 0
    
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
    
    //char -> uint8_t ??
    BoolRank& operator = (const BoolRank& other); // BV& op=(bool vale)
    BoolRank& operator = (const bool& value);
    BoolRank operator & (const bool& value);
    BoolRank operator ^ (const bool& value);//
    BoolRank operator ~ () const;
    bool operator == (const BoolRank& other);//
    bool operator == (const bool& value);// (char) -> (uint8_t) => BR == BR
    operator bool() const;//
    
private:
    uint8_t* m_cell = nullptr;
    uint8_t m_mask = 1 << 7;
    
};

//переписать 
inline std::ostream& operator << (std::ostream& stream, const BoolVector& object) {//
    object.print();
    return stream;
}

inline std::istream& operator >> (std::istream& stream, BoolVector& object) {//
    object.scan();
    return stream;
}
