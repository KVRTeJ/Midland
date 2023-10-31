#pragma once

using Cell = uint8_t;

class BoolVector {
public:
    BoolVector(int lenth = m_size, bool value = false);
    BoolVector(const char* string);
    BoolVector(BoolVector& other);
    ~BoolVector();
    
    void print() const;
    void scan(const unsigned int& lenth);
    
    void set(unsigned int& position); // pos/m_size + (ternar) => setInCell
    void unSet(unsigned int& position);
    
    BoolVector &operator = (const BoolVector& other);
    
private:
    void setInCell(const int& cellNumber, const int& position);
    void unSetInCell(const int& cellNumber, const int& position);
    void printCell(const int& cellNumber) const;
    void scanCell(const int& cellNumber);
    
    static const Cell m_size = 8; //Размер ячейки
    unsigned char* m_cells; //Сами ячейки
    unsigned int m_cellCount; //Кол-во ячеек
    unsigned int m_lenth; //Длина вектора
    uint8_t m_significantRankCount; //Кол-во незначащих 0
    
};
