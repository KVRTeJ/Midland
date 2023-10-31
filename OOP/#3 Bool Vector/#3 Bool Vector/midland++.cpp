#include <iostream>

#include "midland++.hpp"

BoolVector::BoolVector(int lenth, bool value) {
    assert(lenth >= 0);
    
    m_lenth = lenth;
    m_cellCount = lenth / 8 + (lenth % 2 ? 1:0);
    //std::cout << m_cellCount << std::endl;
    m_significantRankCount = (m_cellCount * m_size) - m_lenth;
    m_cells = new unsigned char [m_cellCount];
}

BoolVector::~BoolVector() {
    delete m_cells;
}

void BoolVector::print() const {
    
    for(int i = 0; i < m_cellCount; ++i) {
        std::cout << "[";
        printCell(i);
        std::cout << "] ";
    }
    std::cout << std::endl;
    
}

/*
void BoolVector::scan(const unsigned int& lenth) {
    
    scanCell(0);
    
}

void BoolVector::setInCell(const int& cellNumber, const int& position) {
    assert(cellNumber >= 0 && cellNumber < m_cellCount);
    
    uint8_t mask = 1;
    mask << 7;
    
    
}

void BoolVector::unSetInCell(const int& cellNumber, const int& position) {
    assert(cellNumber >= 0 && cellNumber < m_cellCount);
    
    
    
}
*/

void BoolVector::printCell(const int& cellNumber) const {
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


void BoolVector::scanCell(const int& cellNumber) {
    assert(cellNumber >= 0 && cellNumber < m_cellCount);
    
    //set
    
}

