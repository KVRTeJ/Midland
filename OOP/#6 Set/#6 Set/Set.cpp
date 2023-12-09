#include "Set.hpp"

Set::Set(const char* string) {
    
    m_set = new BoolVector(MAX_CARDINALIS);
    const int size = (int) strlen(string);
    for(int i = 0; i < size; ++i) {
        if(!m_set->operator[]((int) string[i])) {
            m_set->set((int) string[i], 1);
        }
    }
    
}

Set::Set(const Set& other) {
    
    m_set = new BoolVector(MAX_CARDINALIS);
    for(int i = 0; i < MAX_CARDINALIS; ++i) {
        if(other.contains((char) i)) {
            *this += (char) i;
        }
    }
    
}

char Set::max() const {
    for(int i = MAX_CARDINALIS - 1; i >= 0; --i)
        if(m_set->operator[](i))
            return (char) i;
    return (char) 0;
}

char Set::min() const {
    for(int i = 0; i < MAX_CARDINALIS; ++i)
        if(m_set->operator[](i))
            return (char) i;
    return (char) 0;
}

Set& Set::operator = (const Set& other) {
    
    if(this != &other) {
        delete m_set;
        m_set = new BoolVector(MAX_CARDINALIS);
        for(int i = 0; i < MAX_CARDINALIS; ++i) {
            if(other.contains((char) i)) {
                *this += (char) i;
            }
        }
    }
    
    return *this;
}

Set Set::operator | (const Set& other) const {
    
    Set result(*this);
    result |= other;
    
    return result;
}

Set Set::operator & (const Set& other) const {
    
    Set result(*this);
    result &= other;
    
    return result;
}

Set& Set::operator /= (const Set& other) {
    *m_set &= ~*other.m_set;
    return *this;
}

Set Set::operator / (const Set& other) const {
    
    Set result(*this);
    result /= other;
    
    return result;
}

Set& Set::operator += (const char value) {
    
    if(!m_set->operator[]((int) value)) {
        m_set->operator[]((int) value) = true;
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
    }
    
    return *this;
}

Set Set::operator - (const char value) const {
    
    Set result(*this);
    result -= value;
    
    return result;
}

Set Set::operator ~ () const {
    
    Set result(*this);
    result.m_set->invert();
    
    return result;
}



std::ostream& operator << (std::ostream& stream, const Set& other) {
    
    stream << "{";
    bool wasOutput = false;
    for(int i = 0; i < other.MAX_CARDINALIS; ++i) {
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
    other -= (char) 0;
    while(true) {
        stream >> scan;
        if(other.contains(scan))
            return stream;
        other += scan;
    }
    
 return stream;
}

