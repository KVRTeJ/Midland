#include "BoolMatrix.hpp"

BoolMatrix::BoolMatrix(const int colCount, const int rowCount, const bool value) {
    assert(rowCount > 0 && colCount > 0);
    
    m_rows = new BoolVector [colCount];
    m_rowCount = colCount;
    m_columnCount = rowCount;
    
    BoolVector temp(rowCount, value);
    for(int i = 0; i < colCount; ++i) {
        m_rows[i] = temp;
    }
}

BoolMatrix::BoolMatrix(const std::vector< std::vector<char> >& matrix) {
    assert((int) matrix[0].size() > 0 && (int) matrix.size() > 0);
    
    m_columnCount = (int) matrix[0].size();
    m_rowCount = (int) matrix.size();
    m_rows = new BoolVector [m_rowCount];
    
    for(int i = 0; i < m_rowCount; ++i) {
            m_rows[i] = matrix[i];
        
    }
    
}

BoolMatrix::BoolMatrix(char** matrix, const int colCount, const int rowCount) {
    assert(colCount > 0 && rowCount > 0);
    
    m_columnCount = rowCount;
    m_rowCount = colCount;
    m_rows = new BoolVector [m_rowCount];
    
    for(int i = 0; i < m_rowCount; ++i) {
        m_rows[i] = matrix[i];
    }
    
}

BoolMatrix::BoolMatrix(const BoolMatrix& other) {
    
    m_rows = new BoolVector [other.m_rowCount];
    m_columnCount = other.m_columnCount;
    m_rowCount = other.m_rowCount;
    
    for(int i = 0; i < m_rowCount; ++i) {
        m_rows[i] = other.m_rows[i];
    }
    
}

BoolMatrix::~BoolMatrix() {
    delete [] m_rows;
}

int BoolMatrix::getWeight() const {
    
    int result = 0;
    for(int i = 0; i < m_rowCount; ++i) {
        result += m_rows[i].weight();
    }
    
    return result;
}

int BoolMatrix::getWeight(const int row) const {
    assert(row >= 0 && row < m_rowCount);
    
    return m_rows[row].weight();
}

BoolVector BoolMatrix::getConjunctionRows() const {
    BoolVector conjunction(m_rows[0]);
    
    for(int i = 1; i < m_rowCount; ++i) {
        conjunction &= m_rows[i];
    }
    
    return conjunction;
}

BoolVector BoolMatrix::getDisjunctionRows() const {
    BoolVector conjunction(m_rows[0]);
    
    for(int i = 1; i < m_rowCount; ++i) {
        conjunction |= m_rows[i];
    }
    
    return conjunction;
}

void BoolMatrix::set(const int row, const int col, const bool value) {
    assert(row >= 0 && row < m_rowCount);
    
    m_rows[row].set(col, value);
}

void BoolMatrix::set(const int row, const int from, const int to, const bool value) {
    assert(row >= 0 && row < m_rowCount);
    
    m_rows[row].set(from, to, value);
}

void BoolMatrix::invert(const int row, const int col) {
    assert(row >= 0 && row < m_rowCount);
    
    m_rows[row].invert(col);
}

void BoolMatrix::invert(const int row, const int from, const int to) {
    assert(row >= 0 && row < m_rowCount);
    
    for(int i = from; i <= to; ++i) {
        m_rows[row].invert(i);
    }
}

void BoolMatrix::swap(BoolMatrix& other) {
    
    std::swap(m_columnCount, other.m_columnCount);
    std::swap(m_rowCount, other.m_rowCount);
    std::swap(m_rows, other.m_rows);
    
}

BoolVector& BoolMatrix::operator[](const int index) {
    assert(index >= 0 && index < m_rowCount);
    
    return m_rows[index];
}

const BoolVector& BoolMatrix::operator[](const int index) const {
    assert(index >= 0 && index < m_rowCount);
    
    return m_rows[index];
}

BoolMatrix& BoolMatrix::operator=(const BoolMatrix& other) {
    
    if(this == &other)
        return *this;
    
    if(m_rowCount != other.m_rowCount) {
        m_rowCount = other.m_rowCount;
        delete [] m_rows;
        m_rows = new BoolVector [m_rowCount];
    }
    
    m_columnCount = other.m_columnCount;
    for(int i = 0; i < m_rowCount; ++i) {
        m_rows[i] = other.m_rows[i];
    }
    
    return *this;
}

BoolMatrix BoolMatrix::operator & (const BoolMatrix& other) const {
    BoolMatrix result(*this);
    
    for(int i = 0; i < m_rowCount; ++i) {
        result.m_rows[i] &= other.m_rows[i];
    }
    
    return result;
}

BoolMatrix BoolMatrix::operator | (const BoolMatrix& other) const {
    BoolMatrix result(*this);
    
    for(int i = 0; i < m_rowCount ; ++i) {
        result.m_rows[i] |= other.m_rows[i];
    }
    
    return result;
}

BoolMatrix BoolMatrix::operator ^ (const BoolMatrix& other) const {
    BoolMatrix result(*this);
    
    for(int i = 0; i < m_rowCount ; ++i) {
        result.m_rows[i] ^= other.m_rows[i];
    }
    
    return result;
}

BoolMatrix& BoolMatrix::operator &= (const BoolMatrix& other) {
    (*this) = *this & other;
    return *this;
}

BoolMatrix& BoolMatrix::operator |= (const BoolMatrix& other) {
    (*this) = *this | other;
    return *this;
}

BoolMatrix& BoolMatrix::operator ^= (const BoolMatrix& other) {
    (*this) = *this ^ other;
    return *this;
}

BoolMatrix BoolMatrix::operator ~ () const {
    BoolMatrix result(*this);
    for(int i = 0; i < m_rowCount; ++i) {
        result.m_rows[i].invert();
    }
    
    return result;
}



std::istream& operator >> (std::istream& stream, BoolMatrix& other)  {
    
    for(int i = 0; i < other.getColumnCount(); ++i) {
        stream >> other[i];
    }
    
    return stream;
}

std::ostream& operator << (std::ostream& stream, const BoolMatrix& other) {
    
    for(int i = 0; i < other.getColumnCount(); ++i) {
        stream << "|";
        for(int j = 0; j < other.getRowCount(); ++j) {
            stream << other[i][j] << ((j + 1) < other.getRowCount() ? " ":"");
        }
        stream << "|" << std::endl;
    }
    
    return stream;
}
