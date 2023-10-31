#include <iostream>

#include "midland++.hpp"

BoolVector::BoolVector(int lenth, bool value) {
    assert(lenth >= 0);
    
    m_lenth = lenth;
    m_cellCount = lenth / 8 + (lenth % 8 ? 1:0);
    m_significantRankCount = (m_cellCount * m_CELL_SIZE) - m_lenth;
    m_cells = new unsigned char [m_cellCount];
    
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
    m_cells = new unsigned char [m_cellCount];
    
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
    m_cells = new unsigned char [other.m_cellCount];
    
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


void BoolVector::scan() {
    
    std::cout << "Булев вектор(lenth = " << m_lenth << "): ";
    char* string = new char [m_lenth];
    for(int i = 0; i < m_lenth; ++i) {
        std::cin >> string[i];
    }
    *this = string;
    
    delete [] string;
}

void twich() {
    
    // >> m_sRC
    // << m_sRC
    
}

void BoolVector::swap(BoolVector& other) {
    
    std::swap(m_lenth, other.m_lenth);
    std::swap(m_cellCount, other.m_cellCount);
    std::swap(m_significantRankCount, other.m_significantRankCount);
    std::swap(m_cells, other.m_cells);
    
}

void BoolVector::set(const int& position, const bool value) {
    assert(position >= 0 && position < m_lenth);
    
    const unsigned int currentCell = position / 8, currentPosition = position % 8;
    
    if(value) {
        m_setInCell(currentCell, currentPosition);
    }
    else {
        m_unSetInCell(currentCell, currentPosition);
    }
    
}

BoolVector& BoolVector::operator = (const BoolVector& other) {
    
    if(this != &other) {
        delete [] m_cells;
        m_lenth = other.m_lenth;
        m_cellCount = other.m_cellCount;
        m_significantRankCount = other.m_significantRankCount;
        m_cells = new unsigned char [other.m_cellCount];
        
        for(int i = 0; i < m_cellCount; ++i) {
            m_cells[i] = other.m_cells[i];
        }
    }
    
    return *this;
    
}

BoolVector& BoolVector::operator >>= (const int& value) {
    
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

