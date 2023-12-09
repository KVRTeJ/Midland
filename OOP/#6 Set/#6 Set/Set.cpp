#include "Set.hpp"

Set::Set(const char* string) {
    
    m_set = new BoolVector(127);
    const int size = (int) strlen(string);
    m_cardinalis = (size ? 1 : 0);
    for(int i = 0; i < size; ++i) {
        if(!m_set->operator[]((int) string[i])) {
            m_set->set((int) string[i], 1);
            m_cardinalis <<= 1;
        }
    }
    
}
