#include "Set.hpp"

const int Set::MAX_CARDINALIS = 127;

const std::vector<std::string> Set::NOT_ENTERED_CHARAPTERS = {
    "NULL", "SOH", "STX", "ETX", "EOT", "ENQ", "ACK", "BEL", "BS", "HT", "LF",
    "VT", "FF", "CR", "SO", "SI", "DLE", "DC1", "DC2", "DC3", "DC4", "NAK",
    "SYN", "ETB", "CAN", "EM", "SUB", "ESC", "FS", "GS", "RS", "US", "SPACE"
};

Set::Set(const char* string) {
    
    m_set = new BoolVector(MAX_CARDINALIS);
    const int size = (int) strlen(string);
    for(int i = 0; i < size; ++i) {
        if(!m_set->operator[]((string[i]))) {
            m_set->set((int) string[i], 1);
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
    
    if(value >= 0 && value < MAX_CARDINALIS) {
        if(!m_set->operator[]((int) value)) {
            m_set->operator[]((int) value) = true;
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
    
    if(value >= 0 && value < MAX_CARDINALIS) {
        if(m_set->operator[]((int) value)) {
            m_set->operator[]((int) value) = false;
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
    for(int i = 0; i < Set::MAX_CARDINALIS; ++i) {
        if(other.contains((char) i)) {
            stream << (wasOutput ? ", " : "");
            if(i < Set::NOT_ENTERED_CHARAPTERS.size()) { //Нелья засунуть в тернарный оператор :(
                std::cout << Set::NOT_ENTERED_CHARAPTERS[i];
            } else {
                std::cout << static_cast<char> (i);
            }
            wasOutput = true;
        }
        
    }
    stream << "}";
    
    return stream;
}



std::istream& operator >> (std::istream& stream, Set& other) { //FIXME: fixme
    
    std::string c = "";
    std::getline(stream, c);
    for(int i = 0; i < c.size(); ++i)
        if(c[i] >= 'A' && c[i] <= 'Z') {
            for(int j = 0; j < Set::NOT_ENTERED_CHARAPTERS.size(); ++j) {
                if(!bmSearchOccurrencesInRange(c, Set::NOT_ENTERED_CHARAPTERS[j], i,
                    i + Set::NOT_ENTERED_CHARAPTERS[j].size()).empty()) { //FIXME: fixme
                    other += (char) j;
                    i += Set::NOT_ENTERED_CHARAPTERS[j].size();
                    break;
                }
            }
            other += c[i];
        } else {
            other += c[i];
        }
     
 return stream;
}

