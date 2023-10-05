#include <iostream>
#include <assert.h>
#include <time.h>
#include <vector>

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
    
}

Array::Array(const Array &array) {
    
    m_numbers = new int [array.m_size];
    for(m_size = 0; m_size < array.m_size;
        m_size++)
        m_numbers[m_size] = array.m_numbers[m_size];
    //std::cout << "Работает конструктор копирования" << std::endl;
}

Array::Array(Array &&array) {
    
    swap(array);
    
}


Array::~Array() {
    
    delete [] m_numbers;
    //std::cout << "Работает дeструктор " << std::endl;
    
}

Array::Iterator Array::begin() {
    
    return Iterator(this, 0);
    
}

Array::Iterator Array::end() {
    
    return Iterator(this, getSize());
    
}

Array::Iterator Array::insertBeforeIterator(Iterator iterator, const int value) {
    
    insert(iterator.m_pos, value);
    iterator.m_pos++;
    return iterator;
    
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
        std::cout<< "void Array::scan: размер не может равен 0. Итоговый массив - {0}" << std::endl;
        return;
    }
    
    m_numbers = new int [size];
    m_size = size;
        
    for(int i = 0; i < size; i++) {
        std::cout << "Array[" << i << "] = ";
        std::cin >> m_numbers[i];
        
    }
    
}

void Array::swap(Array &object) {
    
    std::swap(m_size, object.m_size);
    std::swap(m_numbers, object.m_numbers);
    
}

void Array::resize(int size) {
    
    if(size < 0) {
        std::cerr << "Array::resize size = -size" << std::endl;
        size = -size;
    }
    
    Array resized(size);
    size = std::min(m_size, size);
    
    for(int i = 0; i < size; i++) {
        resized.m_numbers[i] = m_numbers[i];
    }
    
    swap(resized);
}

void Array::sort() const {
    
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

bool Array::insert(const int index, const int value) {
    
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
    m_numbers = temp;
    return true;
    
}

bool Array::removeIndex(const int index) {
    
    if(index < 0 || index >= m_size) {
        std::cerr << "bool Array::insert: некорректное значение index. " << std::endl;
        std::cerr << "Array::insert ended with: false" << std::endl;
        return false;
    }
    
    int* temp = new int [m_size - 1];
    
    {
        int i = 0, j = 0;
        while(i < m_size){
            if(i != index) {
                temp[j] = m_numbers[i];
                i++;
                j++;
            }
            else {
                i++;
            }
        }
    }
    
    delete [] m_numbers;
    
    m_size--;
    m_numbers = temp;
    return true;
    
}

bool Array::remove(const int value) {
    
    int* temp = new int [m_size - 1];
    bool isInArray = false;
    
    for(int i = 0, j = 0; i < m_size; i++, j++) {
        if(m_numbers[j] == value && isInArray == false) {
            isInArray = true;
            i--;
        }
        else {
            temp[i] = m_numbers[j];
        }
    }
    
    if(!isInArray)
        return false;
    
    delete [] m_numbers;
    
    m_size--;
    m_numbers = temp;
    return true;
    
}

bool Array::removeAll(const int value) {
    
    bool isInArray = false;
    
    for(int i = 0; i < m_size; i++) {
        if(m_numbers[i] == value) {
            isInArray = remove(value);
            i--;
        }
    }
    
    if(isInArray)
        return true;
    return false;
    
}

int Array::getMaxElement() const {
    
    assert(m_size > 0);
    
    int max = m_numbers[0];
    
    for(int i = 0; i < m_size; i++) {
        if(m_numbers[i] > max)
            max = m_numbers[i];
    }
    
    return max;
    
}

int Array::getMinElement() const {
    
    assert(m_size > 0);
    
    int min = m_numbers[0];
    
    for(int i = 0; i < m_size; i++) {
        if(m_numbers[i] < min)
            min = m_numbers[i];
    }
    
    return min;
    
}

void Array::setRandomNumbers(const int min, const int max) const {
    
    srand( (unsigned int) time(0) );
    
    for(int i = 0; i < m_size; i++) {
        m_numbers[i] = rand() % (max - min + 1) + min;
    }
    
}

void Array::setRandomNumbersIncrease() const {
    
    srand( (unsigned int) time(0) );
    m_numbers[0] = rand() % 10;
    
    for(int i = 1; i < m_size; i++) {
        m_numbers[i] = m_numbers[i - 1] + rand() % 5 + 1;
    }
    
    
}

void Array::setRandomNumbersDecrease() const {
    
    srand( (unsigned int) time(0) );
    m_numbers[m_size - 1] = rand() % 10;
    
    for(int i = m_size - 2; i >= 0; i--) {
        m_numbers[i] = m_numbers[i + 1] + rand() % 5 + 1;
    }
    
}

int &Array::operator [] (const int index) const {
    
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

Array Array::operator + (const int value) const {
    
    Array temp(m_size + 1, 0);
    
    for(int i = 0; i <= m_size; i++) {
        temp.m_numbers[i] = m_numbers[i];
    }
    temp.m_numbers[m_size] = value;
    
    return temp;
    
}

Array &Array::operator += (const int value) {
    
    *this = *this + value;
    return *this;
    
}


Array Array::operator + (const Array &object) const {
    
    int sizeOfTwoObj = m_size + object.m_size;
    Array temp(sizeOfTwoObj, 0);
    
    for(int i = 0, j = 0; i < temp.m_size; i++) {
        if(i < m_size) {
            temp[i] = m_numbers[i];
        }
        else {
            temp[i] = object.m_numbers[j];
            j++;
        }
    }
    
    return temp;
    
}

Array &Array::operator += (const Array &object) {
    
    *this = *this + object;
    
    return *this;
    
}

bool Array::operator == (const Array object) const {
    
    if(m_size != object.m_size) {
        return false;
    }
    
    {
        
        int i = 0;
        while(i < m_size) {
            if(m_numbers[i] != object.m_numbers[i]) {
                return false;
            }
            else {
                i++;
            }
        }
        
    }
    
    return true;
    
}

bool Array::operator != (const Array object) const {
    
    return !(*this == object);
    
}

bool Array::Iterator::hasNext() const {
    
    return (m_pos < m_numbers->getSize());
    
}

int Array::Iterator::getPosition() const {
    
    return m_pos;
    
}

int &Array::Iterator::operator * () const {
    
    return (*m_numbers)[m_pos];
    
}


Array::Iterator &Array::Iterator::operator ++ () {
    
    m_pos++;
    return *this;
    
}

Array::Iterator Array::Iterator::operator ++ (int) {
    
    Iterator old(*this);
    m_pos++;
    return old;
    
}

Array::Iterator &Array::Iterator::operator -- () {
    
    m_pos--;
    return *this;
    
}

Array::Iterator Array::Iterator::operator -- (int) {
    
    Iterator old(*this);
    m_pos--;
    return old;
    
}

Array::Iterator &Array::Iterator::operator += (const int &value) {
    
    m_pos += value;
    return *this;

}

Array::Iterator &Array::Iterator::operator -= (const int &value) {
    
    m_pos -= value;
    return *this;

}

bool Array::Iterator::operator == (const Iterator &object) const {
    
    assert(m_numbers == object.m_numbers);
    return (m_numbers == object.m_numbers && m_pos == object.m_pos);
    
}

bool Array::Iterator::operator != (const Iterator &object) const {
    
    return !(object==(object));
    
}


/*
std::ostream &Array::operator << (std::ostream &stream, const Array &object) {
    
    stream << "[";
    for(int i = 0; i < object.getSize(); i++) {
        if(i != 0){
            stream  << ", ";
        }
        stream << m_numbers[i];
    }
    stream << std::endl;
    
    return stream;
    
}

//std::istream &operator >> (std::istream &stream, const Array &object);
*/
