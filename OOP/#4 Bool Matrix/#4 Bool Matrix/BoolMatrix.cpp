#include "BoolMatrix.hpp"
#include "../../#3 Bool Vector/#3 Bool Vector/BoolVector.cpp"


BoolMatrix::BoolMatrix(const int columnSize, const int rowSize, const bool value) {
    assert(rowSize >= 0 && columnSize >= 0);
    
    m_rows = new BoolVector [columnSize];
    m_columnSize = columnSize;
    m_rowSize = rowSize;
    
    for(int i = 0; i < columnSize; ++i) {
        BoolVector temp(rowSize, value);
        m_rows[i] = temp;
    }
}

/*
BoolMatrix::BoolMatrix(char** matrix) { //
    const int matrixRowSize = strlen(matrix[0]);
    const int matrixColumnSize = sizeof(matrix) / sizeof(matrix[0]);
 ///????? for(i) counter = counterTemp for(j) => ++counerTemp => if(counter > strlen(matrix[0])) return counter;
    
    m_rows = new BoolVector [matrixColumnSize];
    m_rowSize = matrixRowSize;
    m_columnSize = matrixColumnSize;
    
    for(int i = 0; i < m_columnSize; ++i) {
        for(int j = 0; j < m_rowSize; ++j) {
            m_rows[i][j] = matrix[i][j];
        }
    }
    
}
*/

BoolMatrix::BoolMatrix(std::vector< std::vector<char> > matrix) {
    m_rowSize = (int) matrix[0].size();
    m_columnSize = (int) matrix.size();
    m_rows = new BoolVector [m_columnSize];
    
    BoolVector temp(m_rowSize);
    for(int i = 0; i < m_columnSize; ++i) {
            m_rows[i] = matrix[i];
        
    }
    
}

BoolMatrix::BoolMatrix(const BoolMatrix& other) {
    
    m_rows = new BoolVector [other.m_columnSize];
    m_rowSize = other.m_rowSize;
    m_columnSize = other.m_columnSize;
    for(int i = 0; i < m_columnSize; ++i) {
        m_rows[i] = other.m_rows[i];
    }
    
}

BoolMatrix::~BoolMatrix() {
    delete [] m_rows;
}

int BoolMatrix::getWeight() const {
    
    int result = 0;
    for(int i = 0; i < m_columnSize; ++i) {
        result += m_rows[i].weight();
    }
    
    return result;
}

int BoolMatrix::getRowWeight(const int rowIndex) const {
    assert(rowIndex >= 0 && rowIndex < m_rowSize);
    
    return m_rows[rowIndex].weight();
}

BoolVector BoolMatrix::getConjunctionRows() const {
    BoolVector conjunction(m_rows[0]);
    
    for(int i = 1; i < m_columnSize; ++i) {
        conjunction &= m_rows[i];
    }
    
    return conjunction;
}

BoolVector BoolMatrix::getDisjunctionRows() const {
    BoolVector conjunction(m_rows[0]);
    
    for(int i = 1; i < m_columnSize; ++i) {
        conjunction |= m_rows[i];
    }
    
    return conjunction;
}

void BoolMatrix::swap(BoolMatrix& other) {
    
    std::swap(m_rowSize, other.m_rowSize);
    std::swap(m_columnSize, other.m_columnSize);
    std::swap(m_rows, other.m_rows);
    
}

BoolVector& BoolMatrix::operator[](const int index) {
    assert(index >= 0 && index < m_columnSize);
    
    return m_rows[index];
}

BoolMatrix& BoolMatrix::operator=(const BoolMatrix& other) {
    
    if(this == &other)
        return *this;
    
    if(m_rowSize != other.m_rowSize || m_columnSize != other.m_columnSize) {
        m_rowSize = other.m_rowSize;
        m_columnSize = other.m_columnSize;
        delete [] m_rows;
        m_rows = new BoolVector [m_columnSize];
    }
    
    for(int i = 0; i < m_columnSize; ++i) {
        m_rows[i] = other.m_rows[i];
    }
    
    return *this;
}

BoolMatrix BoolMatrix::operator & (const BoolMatrix& other) {
    BoolMatrix result(*this);
    
    for(int i = 0; i < m_columnSize; ++i) {
        result.m_rows[i] &= other.m_rows[i];
    }
    
    return result;
}

BoolMatrix BoolMatrix::operator | (const BoolMatrix& other) {
    BoolMatrix result(*this);
    
    for(int i = 0; i < m_columnSize ; ++i) {
        result.m_rows[i] |= other.m_rows[i];
    }
    
    return result;
}



std::istream& operator >> (std::istream& stream, BoolMatrix& other) {
    
    for(int i = 0; i < other.getColumnSize(); ++i) {
        stream >> other[i];
    }
    
    return stream;
}

std::ostream& operator << (std::ostream& stream, BoolMatrix& other) {
    
    for(int i = 0; i < other.getColumnSize(); ++i) {
        stream << "|";
        for(int j = 0; j < other.getRowSize(); ++j) {
            stream << other[i][j] << ((j + 1) < other.getRowSize() ? " ":"");
        }
        stream << "|" << std::endl;
    }
    
    return stream;
}
