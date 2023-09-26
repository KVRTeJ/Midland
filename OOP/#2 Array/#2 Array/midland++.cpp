#include <iostream>

#include "midland++.hpp"

Array::Array() {
    m_size = 1;
    
    m_numbers = new int [m_size];
    m_numbers[m_size - 1] = m_size - 1;
    std::cout << "Работает конструктор по умолчанию" << std::endl;
    
}

Array::Array(int* array) {
    
    m_size = sizeof(array)/sizeof(array[0]) + 1; //выводит на 1 элемент меньше ??????
    //sizeof (array)' will return the size of the pointer, not the array itself
    std::cout << "m_size - " << m_size << std::endl;
    
    m_numbers = new int [m_size];
    for(int i = 0; i < m_size; i++)
        m_numbers[i] = array[i];
    std::cout << "Сработал контруктор с аргументом m_numbers - ";
    printArray();
    
    
}

Array::Array(Array &array) {
    
    m_numbers = new int [array.m_size];
    for(m_size = 0; m_size < array.m_size;
        m_size++)
        m_numbers[m_size] = array.m_numbers[m_size];
    std::cout << "Работает конструктор копирования" << std::endl;
}


Array::~Array() {
    
    delete [] m_numbers;
    std::cout << "Работает дeструктор" << std::endl;
    
}

void Array::printArray() {
    
    for(int i = 0; i < m_size; i++) {
        if(i != 0){
            std::cout << ", ";
        }
        std::cout << m_numbers[i];
    }
    std::cout << std::endl;
}

int Array::getArraySize() {
    
    return m_size;
    
}
