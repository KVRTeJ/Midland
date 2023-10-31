#pragma once

class BoolVector {
public:
    BoolVector(int lenth = m_size, bool value = false);
    BoolVector(const char* string);//
    BoolVector(BoolVector& other);//
    ~BoolVector();
    
    void print() const;
    void scan();
    
    void twich();
    
    void set(unsigned int& position);
    void unSet(unsigned int& position);
    
    BoolVector& operator = (const BoolVector& other);//
    BoolVector& operator >>= (const int& value);
    BoolVector& operator <<= (const int& value);
    BoolVector operator >> (const int& value) const;//
    BoolVector operator << (const int& value) const;//
    
private:
    void m_setInCell(const int& cellNumber, const int& position);
    void m_unSetInCell(const int& cellNumber, const int& position);
    void m_printCell(const int& cellNumber) const;
    
    static const uint8_t m_size = 8; //Размер ячейки
    unsigned char* m_cells; //Сами ячейки
    unsigned int m_cellCount; //Кол-во ячеек
    unsigned int m_lenth; //Длина вектора
    uint8_t m_significantRankCount; //Кол-во незначащих 0
    
};
