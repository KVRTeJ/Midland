#include <iostream>

#include "BoolVector.hpp"

BoolVector::BoolVector(const int lenght, const bool value) {
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

BoolVector::BoolVector(const std::vector<char>& string) {
    
    m_lenght = (unsigned int) string.size();
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

void BoolVector::invert(const int position) {
    assert(position >= 0 && position < m_lenght);
    
    (*this)[position] = ~(*this)[position];
}

void BoolVector::set(const int position, const bool value) {
    assert(position >= 0 && position < m_lenght);
    
    const unsigned int CURRENT_CELL = position / CELL_SIZE, CURRENT_POS = position % CELL_SIZE;
    
    if(value) {
        m_setInCell(CURRENT_CELL, CURRENT_POS);
    }
    else {
        m_unSetInCell(CURRENT_CELL, CURRENT_POS);
    }
    
}

void BoolVector::set(const int posFrom, const int posTo, const bool value) {
    assert(posFrom >= 0 && posTo < m_lenght);
    assert(posFrom <= posTo);
    
    for(int i = posFrom; i <= posTo; ++i) {
        (*this)[i] = value;
    }
    
}

void BoolVector::set(const bool value) {
    for(int i = 0; i < m_cellCount; ++i) {
        if(value)
            m_cells[i] = 255;
        else
            m_cells[i] = 0;
    }
    m_twich();
}

BoolVector::BoolRank BoolVector::operator [] (const int index) {
    assert(index >= 0 && index < m_lenght);
    
    return BoolRank(m_cells + index / CELL_SIZE, index % CELL_SIZE);
}

const BoolVector::BoolRank BoolVector::operator [] (const int index) const {
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
    
    for(int i = 0; i < m_cellCount; ++i) {
        returned.m_cells[i] = ~returned.m_cells[i];
    }
    
    returned.m_twich();
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

BoolVector BoolVector::operator >> (const int value) const {
    BoolVector result(*this);
    result >>= value;
    return result;
}

BoolVector BoolVector::operator << (const int value) const {
    BoolVector result(*this);
    result <<= value;
    return result;
     
}

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


BoolVector& BoolVector::operator >>= (int value) {
    assert(value >= 0 && value <= m_lenght);
    
    if (value >= CELL_SIZE) {
        for(int i = m_cellCount - 1; i >= 1; --i) {
            m_cells[i] = m_cells[i - value / CELL_SIZE];
        }
        for(int i = 0; i < value / CELL_SIZE; ++i) {
            m_cells[i] = 0;
        }
        value = value % CELL_SIZE;
    }
    
    if (value > 0) {
        uint8_t mask;
        for(int i = m_cellCount - 1; i >= 0; --i) {
            m_cells[i] >>= value;
            mask = m_cells[i - 1];
            mask <<= (CELL_SIZE - value);
            m_cells[i] |= mask;
        }
    }

    m_twich();
    return *this;
}

BoolVector& BoolVector::operator <<= (int value) {
    assert(value >= 0 && value <= m_lenght);
    
    if (value >= CELL_SIZE) {
        for(int i = 0; i < m_cellCount - value / CELL_SIZE; ++i) {
            m_cells[i] = m_cells[i + value / CELL_SIZE];
        }
        for(int i = 1; i <= value / CELL_SIZE; ++i) {
            m_cells[m_cellCount - i] = 0;
        }
        value = value % CELL_SIZE;
    }
    
    if (value == 0) {
        return *this;
    }
    
    if(value > 0) {
        uint8_t mask;
        for(int i = 0; i < m_cellCount; ++i) {
            m_cells[i] <<= value;
            mask = m_cells[i + 1];
            mask >>= (CELL_SIZE - value);
            m_cells[i] |= mask;
        }
    }
    return *this;
}


/* private */
void BoolVector::m_setInCell(const int cellNumber, const int position) {
    assert(cellNumber >= 0 && cellNumber < m_cellCount);
    assert(position >= 0 && position < CELL_SIZE);
    
    uint8_t mask = 1;
    mask <<= 7 - position;
    m_cells[cellNumber] |= mask;
    
}

void BoolVector::m_unSetInCell(const int cellNumber, const int position) {
    assert(cellNumber >= 0 && cellNumber < m_cellCount);
    assert(position >= 0 && position < CELL_SIZE);
    
    uint8_t mask = 1;
    mask <<= 7 - position;
    m_cells[cellNumber] = m_cells[cellNumber] & ~mask;

}


void BoolVector::m_printCell(const int cellNumber) const {
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
    if(m_cellCount == 0) {
        return;
    }
    
    m_cells[m_cellCount - 1] >>= m_unsignificantRankCount;
    m_cells[m_cellCount - 1] <<= m_unsignificantRankCount;
    
}


/*BoolRank*/
BoolVector::BoolRank& BoolVector::BoolRank::operator = (const BoolVector::BoolRank& other) {
    return *this = ((bool) other);
}

BoolVector::BoolRank& BoolVector::BoolRank::operator = (const bool value) {
    if(value)
        (*m_cell) |= m_mask;
    else
        (*m_cell) &= ~m_mask;
    
    return *this;
}

bool BoolVector::BoolRank::operator & (const bool value) const {
    if(!value)
        return false;
    return (bool) (*m_cell) & m_mask;
}

bool BoolVector::BoolRank::operator ~ () const {
    return !this->operator bool();
}

bool BoolVector::BoolRank::operator ^ (const bool value) const {
    return (bool) (*this) ^ value;
}


bool BoolVector::BoolRank::operator == (const BoolVector::BoolRank& other) const {
    return (*this == ((bool) other));
}


bool BoolVector::BoolRank::operator == (const bool value) const {
    return (bool) *this == value;
}


BoolVector::BoolRank::operator bool() const {
    
    if(m_mask & (*m_cell))
        return true;
    
    return false;
}

std::ostream& operator << (std::ostream& stream, const BoolVector& object) {
    
    for(int i = 0; i < object.m_cellCount; ++i) {
        stream << "[";
        for(uint8_t j = 1 << 7; j > 0; j >>= 1) {
            if(object.m_cells[i] & j) {
                stream << "1";
                if((j >> 1) > 0)
                    stream << " ";
            }
            else {
                stream << "0";
                if((j >> 1) > 0)
                    stream << " ";
            }
        }
        stream << "] ";
    }
    stream << std::endl;
    
    return stream;
}

std::istream& operator >> (std::istream& stream, BoolVector& object) {
    char* string = new char [object.m_lenght];
    for(int i = 0; i < object.m_lenght; ++i) {
        stream >> string[i];
    }
    
    for(unsigned int i = 0; i < object.m_lenght; ++i) {
        if(string[i] != '0')
            object.set(i, 1);
        else
            object.set(i, 0);
    }
    
    delete [] string;
    return stream;
}
