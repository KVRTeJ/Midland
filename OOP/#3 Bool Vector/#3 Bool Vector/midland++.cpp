#include <iostream>

#include "midland++.hpp"

BoolVector::BoolVector(const int& lenght, const bool& value) {
    assert(lenght >= 0);
    
    m_lenght = lenght;
    m_cellCount = lenght / CELL_SIZE + (lenght % CELL_SIZE ? 1:0);
    m_unsignificantRankCount = (m_cellCount * CELL_SIZE) - m_lenght;
    m_cells = new uint8_t [m_cellCount];
    
    if(value) {
        for(unsigned int i = 0; i < m_cellCount; ++i) {
            m_cells[i] = 255;
        }
    }
    else
        for(unsigned int i = 0; i < m_cellCount; ++i) {
            m_cells[i] = 0;
        }
    m_twich();
}

BoolVector::BoolVector(const char* string) {
    assert(strlen(string) >= 0);
    
    m_lenght = (unsigned int) strlen(string);
    m_cellCount = m_lenght / CELL_SIZE + (m_lenght % CELL_SIZE ? 1:0);
    m_unsignificantRankCount = (m_cellCount * CELL_SIZE) - m_lenght;
    m_cells = new uint8_t [m_cellCount];
    
    for(unsigned int i = 0; i < m_lenght; ++i) {
        if(string[i] != '0')
            set(i, 1);
        else
            set(i, 0);
    }
    
}


BoolVector::BoolVector(const BoolVector& other) {
    
    m_lenght = other.m_lenght;
    m_cellCount = other.m_cellCount;
    m_unsignificantRankCount = other.m_unsignificantRankCount;
    m_cells = new uint8_t [other.m_cellCount];
    
    for(int i = 0; i < m_cellCount; ++i) {
        m_cells[i] = other.m_cells[i];
    }
    
}

BoolVector::~BoolVector() {
    delete m_cells;
}

void BoolVector::print() const {
    
    for(int i = 0; i < m_cellCount; ++i) {
        std::cout << "[";
        m_printCell(i);
        std::cout << "] ";
    }
    std::cout << std::endl;
    
}

int BoolVector::weight() const {
    int weight = 0;
    
    for(int i = 0; i < m_cellCount; ++i) {
        for(uint8_t mask = 1 << 7; mask != 0; mask >>= 1) {
            if(m_cells[i] & mask)
                ++weight;
        }
    }
    
    return weight;
}

void BoolVector::scan() {
    
    std::cout << "Булев вектор(lenth = " << m_lenght << "): ";
    char* string = new char [m_lenght];
    for(int i = 0; i < m_lenght; ++i) {
        std::cin >> string[i];
    }
    
    for(unsigned int i = 0; i < m_lenght; ++i) {
        if(string[i] != '0')
            set(i, 1);
        else
            set(i, 0);
    }
    
    delete [] string;
}

void BoolVector::swap(BoolVector& other) {
    
    std::swap(m_lenght, other.m_lenght);
    std::swap(m_cellCount, other.m_cellCount);
    std::swap(m_unsignificantRankCount, other.m_unsignificantRankCount);
    std::swap(m_cells, other.m_cells);
    
}

void BoolVector::invert() {
    *this = ~(*this);
    m_twich();
}

void BoolVector::invert(const int& POSITION) {
    assert(POSITION >= 0 && POSITION < m_lenght);
    (*this)[POSITION] = ~(*this)[POSITION];
}

void BoolVector::set(const int& POSITION, const bool& VALUE) {
    assert(POSITION >= 0 && POSITION < m_lenght);
    
    const unsigned int CURRENT_CELL = POSITION / CELL_SIZE, CURRENT_POS = POSITION % CELL_SIZE;
    
    if(VALUE) {
        m_setInCell(CURRENT_CELL, CURRENT_POS);
    }
    else {
        m_unSetInCell(CURRENT_CELL, CURRENT_POS);
    }
    
}

void BoolVector::set(const int& POS_FROM, const int& POS_TO, const bool& VALUE) {
    assert(POS_FROM >= 0 && POS_TO < m_lenght);
    assert(POS_FROM <= POS_TO);
    
    for(int i = POS_FROM; i <= POS_TO; ++i) {
        (*this)[i] = VALUE;
    }
    
}

void BoolVector::set(const bool& VALUE) {
    for(int i = 0; i < m_cellCount; ++i) {
        if(VALUE)
            m_cells[i] = 255;
        else
            m_cells[i] = 0;
    }
    m_twich();
}

BoolVector::BoolRank BoolVector::operator [] (const int& index) {
    assert(index >= 0 && index < m_lenght);
    
    return BoolRank(m_cells + index / CELL_SIZE, index % CELL_SIZE);
}

const BoolVector::BoolRank BoolVector::operator [] (const int& index) const {
    assert(index >= 0 && index < m_lenght);
    
    return BoolRank(m_cells + index / CELL_SIZE, index % CELL_SIZE);
}

BoolVector& BoolVector::operator = (const BoolVector& other) {
    
    if(this != &other) {
        delete [] m_cells;
        m_lenght = other.m_lenght;
        m_cellCount = other.m_cellCount;
        m_unsignificantRankCount = other.m_unsignificantRankCount;
        m_cells = new uint8_t [other.m_cellCount];
        
        for(int i = 0; i < m_cellCount; ++i) {
            m_cells[i] = other.m_cells[i];
        }
    }
    
    return *this;
    
}

BoolVector BoolVector::operator ~ () const {
    
    BoolVector returned(*this);
    
    for(int i = 0; i < m_lenght; ++i) {
        returned[i] = ~returned[i];
    }
    
    return returned;
}

BoolVector BoolVector::operator & (const BoolVector& other) const {
    assert(m_lenght == other.m_lenght);
    
    BoolVector returned(*this);
    
    
    for(int i = 0; i < m_cellCount; ++i) {
        returned.m_cells[i] = m_cells[i] & other.m_cells[i];
    }
    
    
    return returned;
}

BoolVector BoolVector::operator | (const BoolVector& other) const {
    assert(m_lenght == other.m_lenght);
    
    BoolVector returned(other);
    
    for(int i = 0; i < m_cellCount; ++i) {
        returned.m_cells[i] = m_cells[i] | other.m_cells[i];
    }
    
    return returned;
}

BoolVector BoolVector::operator ^ (const BoolVector& other) const {
    assert(m_lenght == other.m_lenght);
    
    BoolVector returned(other);
    
    for(int i = 0; i < m_cellCount; ++i) {
        returned.m_cells[i] = m_cells[i] ^ other.m_cells[i];
    }
    
    return returned;
}

BoolVector BoolVector::operator >> (const BoolVector& other) const {
    assert(m_lenght == other.m_lenght);
    
    BoolVector returned(other);
    
    
    
    return returned;
}

/*
BoolVector BoolVector::operator >> (const BoolVector& other) const {
    
}
*/

BoolVector& BoolVector::operator &= (const BoolVector& other) {
    *this = *this & other;
    
    return *this;
}

BoolVector& BoolVector::operator |= (const BoolVector& other) {
    *this = *this | other;
    
    return *this;
}

BoolVector& BoolVector::operator ^= (const BoolVector& other) {
    *this = *this ^ other;
    
    return *this;
}


/* private */
void BoolVector::m_setInCell(const int& cellNumber, const int& position) {
    assert(cellNumber >= 0 && cellNumber < m_cellCount);
    assert(position >= 0 && position < CELL_SIZE);
    
    uint8_t mask = 1;
    mask <<= 7 - position;
    m_cells[cellNumber] |= mask;
    
}

void BoolVector::m_unSetInCell(const int& cellNumber, const int& position) {
    assert(cellNumber >= 0 && cellNumber < m_cellCount);
    assert(position >= 0 && position < CELL_SIZE);
    
    uint8_t mask = 1;
    mask <<= 7 - position;
    m_cells[cellNumber] = m_cells[cellNumber] & ~mask;

}


void BoolVector::m_printCell(const int& cellNumber) const {
    assert(cellNumber >= 0 && cellNumber < m_cellCount);
    
    for(uint8_t i = 1 << 7; i > 0; i >>= 1) {
        if(m_cells[cellNumber] & i) {
            std::cout << "1";
            if((i >> 1) > 0)
                std::cout << " ";
        }
        else {
            std::cout << "0";
            if((i >> 1) > 0)
                std::cout << " ";
        }
    }
    //std::cout << std::endl;
    
}

void BoolVector::m_twich() {
    
    m_cells[m_cellCount - 1] >>= m_unsignificantRankCount;
    m_cells[m_cellCount - 1] <<= m_unsignificantRankCount;
    
}


/*BoolRank*/
BoolVector::BoolRank& BoolVector::BoolRank::operator = (const BoolVector::BoolRank& other) {
    return *this = ((bool) other);
}

BoolVector::BoolRank& BoolVector::BoolRank::operator = (const bool& value) {
    if(value)
        (*m_cell) |= m_mask;
    else
        (*m_cell) &= ~m_mask;
    
    return *this;
}


BoolVector::BoolRank BoolVector::BoolRank::operator ~ () const {
    
    BoolRank temp(nullptr, 0);
    temp.m_cell = new uint8_t;
    temp.m_mask = m_mask;
    
    (*temp.m_cell) = (*m_cell) ^ m_mask;
    
    return temp;
}

BoolVector::BoolRank BoolVector::BoolRank::operator & (const bool& value) {
    
    BoolRank temp(nullptr, 0);
    temp.m_cell = new uint8_t;
    temp.m_mask = m_mask;
    
    if(!value)
        (*temp.m_cell) &= ~temp.m_mask;
    
    return temp;
}

BoolVector::BoolRank BoolVector::BoolRank::operator ^ (const bool& value) {
    
    BoolRank temp(nullptr, 0);
    temp.m_cell = new uint8_t;
    temp.m_mask = m_mask;
    
    if(value) {
        (*temp.m_cell) = (*m_cell) ^ temp.m_mask;
    }
    
    return temp;
}

bool BoolVector::BoolRank::operator == (BoolVector::BoolRank other) {
    return (*this == ((bool) other));
}

bool BoolVector::BoolRank::operator == (const bool& value) {
    
    if((bool) *this & value)
        return true;
    
    return false;
}

BoolVector::BoolRank::operator bool() const {
    
    if(m_mask & (*m_cell))
        return true;
    
    return false;
}
