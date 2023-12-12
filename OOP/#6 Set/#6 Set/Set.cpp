#include "Set.hpp"

Set::Set(const char* string) {
    
    m_set = new BoolVector(MAX_CARDINALIS);
    const int size = (int) strlen(string);
    for(int i = 0; i < size; ++i) {
        if(!m_set->operator[]((string[i]) - NEEDLESS_TABLE)) {
            m_set->set((int) string[i] - NEEDLESS_TABLE, 1);
        }
    }
    
}

Set::Set(const Set& other) {
    
    m_set = new BoolVector(MAX_CARDINALIS);
    *m_set |= *other.m_set;
    
}

char Set::max() const {
    for(int i = MAX_CARDINALIS - 1; i >= 0; --i)
        if(m_set->operator[](i))
            return (char) i + NEEDLESS_TABLE;
    return (char) 0;
}

char Set::min() const {
    for(int i = 0; i < MAX_CARDINALIS; ++i)
        if(m_set->operator[](i))
            return (char) i + NEEDLESS_TABLE;
    return (char) 0;
}

Set& Set::operator = (const Set& other) {
    
    if(this != &other) {
        delete m_set;
        m_set = new BoolVector(MAX_CARDINALIS);
        *m_set |= *other.m_set;
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
    
    if(value - NEEDLESS_TABLE >= 0 && value - NEEDLESS_TABLE < MAX_CARDINALIS) {
        if(!m_set->operator[]((int) value - NEEDLESS_TABLE)) {
            m_set->operator[]((int) value - NEEDLESS_TABLE) = true;
        }
    }
    
    return *this;
}

Set Set::operator + (const char value) const  {
    
    Set result(*this);
    result += value;
    
    return result;
}


Set& Set::operator -= (const char value) {
    
    if(value - NEEDLESS_TABLE >= 0 && value - NEEDLESS_TABLE < MAX_CARDINALIS) {
        if(m_set->operator[]((int) value - NEEDLESS_TABLE)) {
            m_set->operator[]((int) value - NEEDLESS_TABLE) = false;
        }
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
            
            stream << (wasOutput ? ", " : "") << static_cast<char> (i + 32);
            wasOutput = true;
        }
        
    }
    stream << "}";
    
    return stream;
}


std::istream& operator >> (std::istream& stream, Set& other) {
    
    std::string string;
    char c = 0;
    while(c != '\n') {
        stream >> std::noskipws >> c;
        if((int) c - 32 >= 0 && (int) c - 32 < Set::MAX_CARDINALIS) {
            other += c;
        }
        string += c;
    }
    std::cout << "string = " << string;
    
 return stream;
}

