#include "Set.hpp"

Set::Set(const char* string) {
    
    m_set = new BoolVector(N);
    const int size = (int) strlen(string);
    m_cardinalis = 1;
    for(int i = 0; i < size; ++i) {
        if(!m_set->operator[]((int) string[i])) {
            m_set->set((int) string[i], 1);
            m_cardinalis <<= 1;
        }
    }
    
}

Set::Set(const Set& other) {
    
    m_set = new BoolVector(N);
    m_cardinalis = 1;
    for(int i = 0; i < N; ++i) {
        if(other.contains((char) i)) {
            *this += (char) i;
        }
    }
    
}

Set& Set::operator = (const Set& other) {
    
    if(this != &other) {
        delete m_set;
        m_set = new BoolVector(N);
        m_cardinalis = 1;
        for(int i = 0; i < N; ++i) {
            if(other.contains((char) i)) {
                *this += (char) i;
            }
        }
    }
    
    return *this;
}

Set& Set::operator += (const char value) {
    
    if(!m_set->operator[]((int) value)) {
        m_set->operator[]((int) value) = true;
        m_cardinalis <<= 1;
    }
    
    return *this;
}

Set Set::operator + (const char value) const  {
    
    Set result(*this);
    result += value;
    
    return result;
}


Set& Set::operator -= (const char value) {
    
    if(m_set->operator[]((int) value)) {
        m_set->operator[]((int) value) = false;
        m_cardinalis >>= 1;
    }
    
    return *this;
}

Set Set::operator - (const char value) const {
    
    Set result(*this);
    result -= value;
    
    return result;
}



std::ostream& operator << (std::ostream& stream, const Set& other) {
    
    stream << "{";
    bool wasOutput = false;
    for(int i = 0; i < other.N; ++i) {
        if(other.contains((char) i)) {
            
            stream << (wasOutput ? ", " : "") << (char) i;
            wasOutput = true;
        }
    }
    stream << "}";
    
    return stream;
}


std::istream& operator >> (std::istream& stream, Set& other) {
    
    std::cout << "To stop input push a repetitive char" << std::endl;
    char scan;
    other -= (int) 0;
    while(true) {
        stream >> scan;
        if(other.contains(scan))
            return stream;
        other += scan;
    }
    
 return stream;
}

