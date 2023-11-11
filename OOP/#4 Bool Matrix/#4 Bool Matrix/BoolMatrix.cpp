#include "BoolMatrix.hpp"
#include "../../#3 Bool Vector/#3 Bool Vector/BoolVector.cpp"


BoolMatrix::BoolMatrix(const int rowSize, const int columnSize, const bool value) {
    assert(rowSize >= 0 && columnSize >= 0);
    
    m_rows = new BoolVector [columnSize];
    m_columnSize = columnSize;
    m_rowSize = rowSize;
    
    for(int i = 0; i < columnSize; ++i) {
        BoolVector temp(rowSize, value);
        m_rows[i] = temp;
    }
}

BoolMatrix::BoolMatrix(char** matrix) { //
    const int matrixRowSize = strlen(matrix[0]);
    const int matrixColumnSize = sizeof(matrix) / matrixRowSize;
    
    m_rows = new BoolVector [matrixColumnSize];
    m_rowSize = matrixRowSize;
    m_columnSize = matrixColumnSize;
    
    for(int i = 0; i < m_columnSize; ++i) {
        for(int j = 0; j < m_rowSize; ++j) {
            m_rows[i][j] = matrix[i][j];
        }
    }
    
}

BoolMatrix::~BoolMatrix() {
    delete [] m_rows;
}

BoolVector& BoolMatrix::operator[](const int index) {
    assert(index >= 0 && index < m_columnSize);
    
    return m_rows[index];
}

std::istream& operator >> (std::istream& stream, BoolMatrix& other) {
    
    for(int i = 0; i < other.getColumnSize(); ++i) {
        stream >> other[i];
    }
    
    return stream;
}

std::ostream& operator << (std::ostream& stream, BoolMatrix& other) {
    
    for(int i = 0; i < other.getColumnSize(); ++i) {
        stream << other[i];
    }
    
    return stream;
}
