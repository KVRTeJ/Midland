#include <iostream>
#include <assert.h>

#include "midland++.hpp"

Array::Array(const int* array, int size) {
    
    assert(size != 0);
    
    if(size < 0) {
        size = -size;
        std::cerr << "void Array::scan: размер не может быть отрицательным. Убран минус." << std::endl;
        std::cout << size << std::endl;
    }
    
    m_size = size;
    
    m_numbers = new int [m_size];
    for(int i = 0; i < m_size; i++)
        m_numbers[i] = array[i];
    //std::cout << "Сработал контруктор с аргументом m_numbers - ";
    print();
    
    
}

Array::Array(const Array &array) {
    
    m_numbers = new int [array.m_size];
    for(m_size = 0; m_size < array.m_size;
        m_size++)
        m_numbers[m_size] = array.m_numbers[m_size];
    //std::cout << "Работает конструктор копирования" << std::endl;
}


Array::~Array() {
    
    delete [] m_numbers;
    //std::cout << "Работает дeструктор " << std::endl;
    
}

int Array::getSize() const{
    
    return m_size;
    
}

int Array::getIndexOfElement(int element) const{
    
    for(int i = 0; i < m_size; i++){
        if(m_numbers[i] == element) {
            return i;
        }
    }
    
    return -1;
    
}


void Array::print() const{
    
    for(int i = 0; i < m_size; i++) {
        if(i != 0){
            std::cout << ", ";
        }
        std::cout << m_numbers[i];
    }
    std::cout << std::endl;
}

void Array::scan(int size) {
    
    if(size < 0) {
        size = -size;
        std::cerr << "void Array::scan: размер не может быть отрицательным. Убран минус." << std::endl;
        std::cout << size << std::endl;
    }
    else if(size == 0) {
        std::cerr << "void Array::scan: размер не может равен 0. Итоговый массив - {0}" << std::endl;
        return;
    }
    
    m_numbers = new int [size];
    m_size = size;
        
    for(int i = 0; i < size; i++) {
        std::cout << "Array[" << i << "] = ";
        std::cin >> m_numbers[i];
        
    }
    
}

void Array::sort() {
    
    int forSwap;
    for(int i = 0; i < m_size; i++)
        for(int j = 0; j < m_size; j++) {
            
            if(m_numbers[i] < m_numbers[j]) {
                
                forSwap = m_numbers[i];
                m_numbers[i] = m_numbers[j];
                m_numbers[j] = forSwap;
                
            }
            
        }
    
}

bool Array::insert(int index, int value) {
    
    if(index < 0 || index > m_size) {
        std::cerr << "bool Array::insert: некорректное значение index. " << std::endl;
        std::cerr << "Array::insert ended with: false" << std::endl;
        return false;
    }
    
    int* temp = new int [m_size + 1];
    
    for(int i = 0, j = 0; i < m_size + 1; i++, j++) {
        if(i != index) {
            temp[i] = m_numbers[j];
        }
        else {
            temp[i] = value;
            j--;
        }
    }
    delete [] m_numbers;
    
    m_size++;
    m_numbers = new int [m_size];
    
    for(int i = 0; i < m_size + 1; i++) {
        m_numbers[i] = temp[i];
    }
        
    return true;
    
}

bool Array::remove(int index, int value) {
    
    return false;
    
}

int &Array::operator [] (const int index) {
    
    assert(index >= 0 || index < m_size);
    return m_numbers[index];
    
}

Array &Array::operator = (const Array &object) {
    
    if(this == &object) {
        return *this;
    }
    
    if(m_size != object.m_size) {
        m_size = object.m_size;
        delete[] m_numbers;
        m_numbers = new int[object.m_size];
    }
    
    for(m_size = 0; m_size < object.m_size; m_size++)
        m_numbers[m_size] = object.m_numbers[m_size];
    
    return *this;
    
}


