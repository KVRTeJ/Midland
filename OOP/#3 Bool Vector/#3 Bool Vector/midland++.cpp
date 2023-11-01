#include <iostream>

#include "midland++.hpp"

BoolVector::BoolVector(const int& lenth, const bool& value) {
    assert(lenth >= 0);
    
    m_lenth = lenth;
    m_cellCount = lenth / 8 + (lenth % 8 ? 1:0);
    m_significantRankCount = (m_cellCount * m_CELL_SIZE) - m_lenth;
    m_cells = new uint8_t [m_cellCount];
    
    if(value) {
        for(unsigned int i = 0; i < m_lenth; ++i) {
            set(i, value);
        }
    }
    else
        for(unsigned int i = 0; i < m_lenth; ++i) {
            set(i, value);
        }
}

BoolVector::BoolVector(const char* string) {
    assert(strlen(string) >= 0);
    
    m_lenth = (unsigned int) strlen(string);
    m_cellCount = m_lenth / 8 + (m_lenth % 8 ? 1:0);
    m_significantRankCount = (m_cellCount * m_CELL_SIZE) - m_lenth;
    m_cells = new uint8_t [m_cellCount];
    
    for(unsigned int i = 0; i < m_lenth; ++i) {
        if(string[i] != '0')
            set(i, 1);
        else
            set(i, 0);
    }
    
}


BoolVector::BoolVector(const BoolVector& other) {
    
    m_lenth = other.m_lenth;
    m_cellCount = other.m_cellCount;
    m_significantRankCount = other.m_significantRankCount;
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
    
    std::cout << "Булев вектор(lenth = " << m_lenth << "): ";
    char* string = new char [m_lenth];
    for(int i = 0; i < m_lenth; ++i) {
        std::cin >> string[i];
    }
    
    for(unsigned int i = 0; i < m_lenth; ++i) {
        if(string[i] != '0')
            set(i, 1);
        else
            set(i, 0);
    }
    
    delete [] string;
}

void BoolVector::twich() {
    
    m_cells[m_cellCount - 1] >>= m_significantRankCount;
    m_cells[m_cellCount - 1] <<= m_significantRankCount;
    
}

void BoolVector::swap(BoolVector& other) {
    
    std::swap(m_lenth, other.m_lenth);
    std::swap(m_cellCount, other.m_cellCount);
    std::swap(m_significantRankCount, other.m_significantRankCount);
    std::swap(m_cells, other.m_cells);
    
}

void BoolVector::invert() {
    ~(*this);
    twich();
}

void BoolVector::invert(const int& position) {
    assert(position >= 0 && position < m_lenth);
    ~(*this)[position];
}

void BoolVector::set(const int& position, const bool& value) {
    assert(position >= 0 && position < m_lenth);
    
    const unsigned int currentCell = position / 8, currentPosition = position % 8;
    
    if(value) {
        m_setInCell(currentCell, currentPosition);
    }
    else {
        m_unSetInCell(currentCell, currentPosition);
    }
    
}

BoolVector::BoolRank BoolVector::operator [] (const int& index) {
    assert(index >= 0 && index < m_lenth);
    
    return BoolRank(m_cells + index / 8, index % 8);
    
}

BoolVector& BoolVector::operator = (const BoolVector& other) {
    
    if(this != &other) {
        delete [] m_cells;
        m_lenth = other.m_lenth;
        m_cellCount = other.m_cellCount;
        m_significantRankCount = other.m_significantRankCount;
        m_cells = new uint8_t [other.m_cellCount];
        
        for(int i = 0; i < m_cellCount; ++i) {
            m_cells[i] = other.m_cells[i];
        }
    }
    
    return *this;
    
}

BoolVector& BoolVector::operator ~ () {
    
    for(int i = 0; i < m_cellCount; ++i) {
        m_cells[i] = ~m_cells[i];
    }
    twich();
    
    return *this;
}

BoolVector BoolVector::operator & (const BoolVector& other) {
    assert(m_lenth == other.m_lenth);
    
    BoolVector temp(other);
    
    for(int i = 0; i < m_cellCount; ++i) {
        temp.m_cells[i] = m_cells[i] & other.m_cells[i];
    }
    
    return temp;
}

BoolVector BoolVector::operator | (const BoolVector& other) {
    assert(m_lenth == other.m_lenth);
    
    BoolVector temp(other);
    
    for(int i = 0; i < m_cellCount; ++i) {
        temp.m_cells[i] = m_cells[i] | other.m_cells[i];
    }
    
    return temp;
}

BoolVector BoolVector::operator ^ (const BoolVector& other) {
    assert(m_lenth == other.m_lenth);
    
    BoolVector temp(other);
    
    for(int i = 0; i < m_cellCount; ++i) {
        temp.m_cells[i] = m_cells[i] ^ other.m_cells[i];
    }
    
    return temp;
}

/*
BoolVector& BoolVector::operator >>= (const int& value) {
    
    const int targetCell = value / 8;
    std::cout << targetCell << std::endl;
    unsigned char temp;
    
    for(int i = 0; i < targetCell - 1; ++i) {
        temp = m_cells[i + 1];
        m_cells[i] = m_cells[i + 1];
        m_cells[i] >>= m_CELL_SIZE;
        
    }
    m_cells[targetCell] >>= value % 8;
    
    // a >>= 1;
    //[0 1 1 1 1 0 0 0] [1 1 1 1 0 0 0 0] - current
    //[0 1 1 1 1 0 0 0] [0 1 1 1 1 0 0 0] - target
    
        
    
    for(int i = 0; i < m_cellCount; ++i) {
        m_cells[i] >>= value;
    }
    
    return *this;
}


BoolVector& BoolVector::operator <<= (const int& value) {
    
    for(int i = 0; i < m_cellCount; ++i) {
        m_cells[i] <<= value;
    }
    
    return *this;
}
*/


/* private */
void BoolVector::m_setInCell(const int& cellNumber, const int& position) {
    assert(cellNumber >= 0 && cellNumber < m_cellCount);
    assert(position >= 0 && position < m_CELL_SIZE);
    
    uint8_t mask = 1;
    mask <<= 7 - position;
    m_cells[cellNumber] |= mask;
    
}

void BoolVector::m_unSetInCell(const int& cellNumber, const int& position) {
    assert(cellNumber >= 0 && cellNumber < m_cellCount);
    assert(position >= 0 && position < m_CELL_SIZE);
    
    uint8_t mask = 1;
    mask <<= 7 - position;
    m_cells[cellNumber] = m_cells[cellNumber] & ~mask;

}


void BoolVector::m_printCell(const int& cellNumber) const {
    assert(cellNumber >= 0 && cellNumber < m_cellCount);
    
    for(uint8_t i = 128; i > 0; i >>= 1) {
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

/*BoolRank*/
BoolVector::BoolRank& BoolVector::BoolRank::operator = (const bool& value) {
    if(value)
        (*m_cell) |= m_mask;
    else
        (*m_cell) &= ~m_mask;
    
    return *this;
}

BoolVector::BoolRank& BoolVector::BoolRank::operator ~ () {
    
    (*m_cell) ^= m_mask;
    
    return *this;
}
