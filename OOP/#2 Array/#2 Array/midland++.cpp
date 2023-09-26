#include <iostream>

#include "midland++.hpp"

Array::Array() {
    m_size = 1;
    
    m_numbers = new int [m_size];
    m_numbers = {0};
    
}
Array::~Array() {
    
    
    
}

int Array::getArraySize() {
    
    return m_size;
    
}
