#include "Set.hpp"

namespace {
    bool find(const std::string& string, const std::string& substring, const int start) {
        if(start + substring.size() > string.size())
            return false;
        
        const int subStrSize = (int) substring.size();
        for(int i = start, j = 0; i < start + subStrSize && j < subStrSize; ++i, ++j) {
            if(string[i] != substring[j]) {
                return false;
            }
        }
        
        return true;
        
    }
}

const int Set::MAX_CARDINALIS = 127;

const std::vector<std::string> Set::NOT_ENTERED_CHARAPTERS = {
    "/NULL", "/SOH", "/STX", "/ETX", "/EOT", "/ENQ", "/ACK", "/BEL", "/BS", "/HT", "/LF",
    "/VT", "/FF", "/CR", "/SO", "/SI", "/DLE", "/DC1", "/DC2", "/DC3", "/DC4", "/NAK",
    "/SYN", "/ETB", "/CAN", "/EM", "/SUB", "/ESC", "/FS", "/GS", "/RS", "/US", "/SPACE"
};


Set::Set(const char* str)
: BoolVector(MAX_CARDINALIS)
{
    
    for(int i = 0; str[i] != '\0'; ++i) {
        *this += str[i];
    }

}

Set::Set(const std::string& str) 
: Set(str.c_str())
{}


Set::Set(const Set& other)
: BoolVector(other)
{}

char Set::max() const {
    for(int i = MAX_CARDINALIS - 1; i >= 0; --i)
        if(operator[](i))
            return (char) i;
    return (char) 0;
}

char Set::min() const {
    for(int i = 0; i < MAX_CARDINALIS; ++i)
        if(operator[](i))
            return (char) i;
    return (char) 0;
}

Set& Set::operator = (const Set& other) {
    BoolVector::operator=(other);
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
    BoolVector::operator&=(~other);
    return *this;
}

Set Set::operator / (const Set& other) const {
    
    Set result(*this);
    result /= other;
    
    return result;
}

Set& Set::operator += (const char value) {
    
    if(value >= 0 && value < MAX_CARDINALIS) {
        if(!operator[]((int) value)) {
            operator[]((int) value) = true;
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
        if(operator[]((int) value)) {
            operator[]((int) value) = false;
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
    result.invert();
    
    return result;
}



std::ostream& operator << (std::ostream& stream, const Set& other) {
    
    stream << "{";
    
    bool wasOutput = false;
    for(int i = 0; i < Set::MAX_CARDINALIS; ++i) {
        if(other.contains((char) i)) {
            stream << (wasOutput ? ", " : "");
            if(i < Set::NOT_ENTERED_CHARAPTERS.size()) { //Нелья засунуть в тернарный оператор :(
                stream << Set::NOT_ENTERED_CHARAPTERS[i];
            } else {
                stream << static_cast<char> (i);
            }
            wasOutput = true;
        }
        
    }
    
    stream << "}";
    
    return stream;
}

std::istream& operator >> (std::istream& stream, Set& other) {
    other.clear();
    
    std::string c;
    std::getline(stream, c);
    std::cout << c << std::endl;
    for(int i = 0; i < c.size(); ++i) {
        if(c[i] == '/') {
            if(c[i + 1] >= 'A' && c[i + 1] <= 'Z') {
                for(int j = 0; j < Set::NOT_ENTERED_CHARAPTERS.size(); ++j) {
                    if(find(c, Set::NOT_ENTERED_CHARAPTERS[j], i)) {
                        other += (char) j;
                        i += Set::NOT_ENTERED_CHARAPTERS[j].size();
                        continue;
                    }
                }
                other += c[i];
            } else {
                if(c[i] != (char) 0)
                    other += c[i];
            }
        } else
            c[i] += '/';
    }
    
    return stream;
}
    
