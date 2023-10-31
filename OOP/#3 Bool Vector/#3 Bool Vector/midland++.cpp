#include <iostream>

#include "midland++.hpp"

BoolVector::BoolVector(int lenth, bool value) {
    assert(lenth >= 0);
    
    m_lenth = lenth;
    m_cellCount = lenth / 8 + (lenth % 2 ? 1:0);
    m_significantRankCount = (m_cellCount * m_size) - m_lenth;
    m_cells = new unsigned char [m_cellCount];
    
    if(value) {
        for(unsigned int i = 0; i < m_lenth; ++i) {
            set(i);
        }
    }
    else
        for(unsigned int i = 0; i < m_lenth; ++i) {
            unSet(i);
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


void BoolVector::scan() {
    
    /****/
    
}

void twich() {
    
    // >> m_sRC
    // << m_sRC
    
}

void BoolVector::set(unsigned int& position) {
    assert(position >= 0 && position < m_lenth);
    
    const unsigned int currentCell = position / 8, currentPosition = position % 8;
    
    m_setInCell(currentCell, currentPosition);
    
}

void BoolVector::unSet(unsigned int& position) {
    assert(position >= 0 && position < m_lenth);
    
    const unsigned int currentCell = position / 8, currentPosition = position % 8;
    
    m_unSetInCell(currentCell, currentPosition);
    
}

BoolVector& BoolVector::operator >>= (const int& value) {
    
    for(int i = 0; i < m_cellCount; ++i) {
        m_cells[i] >>= value;
    }
    
    return *this;
}

BoolVector& BoolVector::operator <<= (const int& value) {
    
    for(int i = 0; i < m_cellCount; ++i) {
        m_cells[i] >>= value;
    }
    
    return *this;
}


/* private */
void BoolVector::m_setInCell(const int& cellNumber, const int& position) {
    assert(cellNumber >= 0 && cellNumber < m_cellCount);
    assert(position >= 0 && position < m_size);
    
    uint8_t mask = 1;
    mask <<= 7 - position;
    m_cells[cellNumber] |= mask;
    
}

void BoolVector::m_unSetInCell(const int& cellNumber, const int& position) {
    assert(cellNumber >= 0 && cellNumber < m_cellCount);
    assert(position >= 0 && position < m_size);
    
    uint8_t mask = 1;
    mask <<= 7 - position;
    m_setInCell(cellNumber, position);
    m_cells[cellNumber] ^= mask;

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

