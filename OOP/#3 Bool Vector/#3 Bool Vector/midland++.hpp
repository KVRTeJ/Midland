#pragma once

class BoolVector {
public:
    BoolVector(int lenth = m_CELL_SIZE, bool value = false);
    BoolVector(const char* string);
    BoolVector(const BoolVector& other);
    ~BoolVector();
    
    void print() const;
    void scan();//
    
    void twich();//
    
    void swap(BoolVector& other);//
    void set(unsigned int& position);
    void unSet(unsigned int& position);
    
    BoolVector& operator = (const BoolVector& other);//
    BoolVector& operator >>= (const int& value);///
    BoolVector& operator <<= (const int& value);///
    BoolVector operator >> (const int& value) const;//
    BoolVector operator << (const int& value) const;//
    BoolVector operator & (const BoolVector& other);//
    BoolVector& operator &= (const BoolVector& other);//
    BoolVector operator | (const BoolVector& other);//
    BoolVector& operator |= (const BoolVector& other);//
    BoolVector operator ^ (const BoolVector& other);//
    BoolVector& operator ^= (const BoolVector& other);//
    BoolVector operator ~ ();//
    
private:
    void m_setInCell(const int& cellNumber, const int& position);
    void m_unSetInCell(const int& cellNumber, const int& position);
    void m_printCell(const int& cellNumber) const;
    
    static const uint8_t m_CELL_SIZE = 8; //Размер ячейки
    unsigned char* m_cells = nullptr; //Сами ячейки
    unsigned int m_cellCount = 0; //Кол-во ячеек
    unsigned int m_lenth = 0; //Длина вектора
    uint8_t m_significantRankCount = 0; //Кол-во незначащих 0
    
};
