#ifndef ARE_TEMPLATE_ARRAY_METHODS_DEFINED
#define ARE_TEMPLATE_ARRAY_METHODS_DEFINED

#include "midland++.hpp"


template <typename Type>
Array<Type>::Array(const Type* array, int size) {
    
    assert(size != 0);
    
    if(size < 0) {
        size = -size;
        std::cerr << "void Array::Array(const int*, int size): размер не может быть отрицательным. Убран минус." << std::endl;
        std::cout << size << std::endl;
    }
    
    m_size = size;
    
    m_numbers = new Type [m_size];
    for(int i = 0; i < m_size; i++)
        m_numbers[i] = array[i];
    
}

template <typename Type>
Array<Type>::Array(const Array &array) {
    
    m_numbers = new Type [array.m_size];
    for(m_size = 0; m_size < array.m_size;
        m_size++)
        m_numbers[m_size] = array.m_numbers[m_size];
    //std::cout << "Работает конструктор копирования" << std::endl;
}

template <typename Type>
Array<Type>::Array(Array &&array) {
    
    swap(array);
    
}

template <typename Type>
Array<Type>::~Array() {
    
    delete [] m_numbers;
    //std::cout << "Работает дeструктор " << std::endl;
    
}

template<typename Type> typename
Array<Type>::Iterator Array<Type>::begin() {
    
    return Iterator(this, 0);
    
}
template <typename  Type> typename
Array<Type>::Iterator Array<Type>::end() {
    
    return Iterator(this, getSize());
    
}

template<typename Type> typename
Array<Type>::ConstIterator Array<Type>::begin() const {
    
    return ConstIterator(this, 0);
    
}
template <typename  Type> typename
Array<Type>::ConstIterator Array<Type>::end() const {
    
    return ConstIterator(this, getSize());
    
}

template <typename Type> typename
Array<Type>::Iterator Array<Type>::insertBeforeIterator(Iterator iterator, const Type value) {
    
    insert(iterator.m_pos, value);
    iterator.m_pos++;
    return iterator;
    
}

template <typename Type> typename
Array<Type>::Iterator Array<Type>::removeInRange(const Iterator begin, const Iterator end) {
    
    assert(end.m_pos >= begin.m_pos);
    
    const int newSize = m_size - (end.m_pos - begin.m_pos);
    Array temp(newSize, -1);
    TemplateIterator itTemp = temp.begin();
    
    for(auto it = this->begin(); it != this->end(); it++) {
        if(it.m_pos < begin.m_pos || it.m_pos >= end.m_pos) {
            (*itTemp) = (*this)[it.m_pos];
            itTemp++;
        }
        else {
            it += end.m_pos - begin.m_pos - 1;
        }
    }
    
    swap(temp);
    
    return itTemp;
    
}

template <typename Type>
int Array<Type>::getSize() const{
    
    return m_size;
    
}

template <typename Type>
int Array<Type>::getIndexOfElement(const Type element) const{
    
    for(int i = 0; i < m_size; i++){
        if(m_numbers[i] == element) {
            return i;
        }
    }
    
    return -1;
    
}

template <typename Type>
void Array<Type>::print() const{
    
    for(int i = 0; i < m_size; i++) {
        if(i != 0){
            std::cout << ", ";
        }
        std::cout << m_numbers[i];
    }
    std::cout << std::endl;
}

template <typename Type>
void Array<Type>::scan(int size) {
    
    if(size < 0) {
        size = -size;
        std::cerr << "void Array::scan: размер не может быть отрицательным. Убран минус." << std::endl;
        std::cout << size << std::endl;
    }
    else if(size == 0) {
        std::cout<< "void Array::scan: размер не может равен 0. Итоговый массив - {0}" << std::endl;
        return;
    }
    
    m_numbers = new Type [size];
    m_size = size;
        
    for(int i = 0; i < size; i++) {
        std::cout << "Array[" << i << "] = ";
        std::cin >> m_numbers[i];
        
    }
    
}

template <typename Type>
void Array<Type>::swap(Array &object) {
    
    std::swap(m_size, object.m_size);
    std::swap(m_numbers, object.m_numbers);
    
}

template <typename Type>
void Array<Type>::resize(int size) {
    
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

template <typename Type>
void Array<Type>::sort() const {
    
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

template <typename Type>
bool Array<Type>::insert(const int index, const Type value) {
    
    if(index < 0 || index > m_size) {
        std::cerr << "bool Array::insert: некорректное значение index. " << std::endl;
        std::cerr << "Array::insert ended with: false" << std::endl;
        return false;
    }
    
    Type* temp = new Type [m_size + 1];
    
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

template <typename Type>
bool Array<Type>::removeIndex(const int index) {
    
    if(index < 0 || index >= m_size) {
        std::cerr << "bool Array::removeIndex: некорректное значение index. " << std::endl;
        std::cerr << "Array::insert ended with: false" << std::endl;
        return false;
    }
    
    Type* temp = new Type [m_size - 1];
    
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

template <typename Type>
bool Array<Type>::remove(const Type value) {
    
    Type* temp = new Type [m_size - 1];
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
    
    if(!isInArray) {
        delete [] temp;
        return false;
    }
    
    delete [] m_numbers;
    
    m_size--;
    m_numbers = temp;
    return true;
    
}

template <typename Type>
bool Array<Type>::removeAll(const Type value) {
    
    bool isInArray = false;
    
    for(int i = 0; i < m_size; i++) {
        if(m_numbers[i] == value) {
            isInArray = removeIndex(i);
            i--;
        }
    }
    
    if(isInArray)
        return true;
    return false;
    
}

template <typename Type>
Type Array<Type>::getMaxElement() const {
    
    assert(m_size > 0);
    
    Type max = m_numbers[0];
    
    for(int i = 0; i < m_size; i++) {
        if(m_numbers[i] > max)
            max = m_numbers[i];
    }
    
    return max;
    
}

template <typename Type>
Type Array<Type>::getMinElement() const {
    
    assert(m_size > 0);
    
    Type min = m_numbers[0];
    
    for(int i = 0; i < m_size; i++) {
        if(m_numbers[i] < min)
            min = m_numbers[i];
    }
    
    return min;
    
}

template <> inline
void Array<int>::setRandomNumbers(const int min, const int max) const {
    
    srand( (unsigned int) time(0) );
    
    for(int i = 0; i < m_size; i++) {
        m_numbers[i] = rand() % (max - min + 1) + min;
    }
    
}

template <> inline
void Array<int>::setRandomNumbersIncrease() const {
    
    srand( (unsigned int) time(0) );
    m_numbers[0] = rand() % 10;
    
    for(int i = 1; i < m_size; i++) {
        m_numbers[i] = m_numbers[i - 1] + rand() % 5 + 1;
    }
    
}

template <> inline
void Array<int>::setRandomNumbersDecrease() const {
    
    srand( (unsigned int) time(0) );
    m_numbers[m_size - 1] = rand() % 10;
    
    for(int i = m_size - 2; i >= 0; i--) {
        m_numbers[i] = m_numbers[i + 1] + rand() % 5 + 1;
    }
    
}

template <typename Type>
Type &Array<Type>::operator [] (const int index) const {
    
    assert(index >= 0 || index < m_size);
    return m_numbers[index];
    
}

template <typename Type>
Array<Type> &Array<Type>::operator = (const Array &object) {
    
    if(this == &object) {
        return *this;
    }
    
    if(m_size != object.m_size) {
        m_size = object.m_size;
        delete[] m_numbers;
        m_numbers = new Type [object.m_size];
    }
    
    for(m_size = 0; m_size < object.m_size; m_size++)
        m_numbers[m_size] = object.m_numbers[m_size];

    
    return *this;
    
}

template <typename Type>
Array<Type> Array<Type>::operator + (const Type value) const {
    
    Array temp(m_size + 1, 0);
    
    for(int i = 0; i <= m_size; i++) {
        temp.m_numbers[i] = m_numbers[i];
    }
    temp.m_numbers[m_size] = value;
    
    return temp;
    
}

template <typename Type>
Array<Type> &Array<Type>::operator += (const Type value) {
    
    *this = *this + value;
    return *this;
    
}

template <typename Type>
Array<Type> Array<Type>::operator + (const Array &object) const {
    
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

template <typename Type>
Array<Type> &Array<Type>::operator += (const Array &object) {
    
    *this = *this + object;
    
    return *this;
    
}

template <typename Type>
bool Array<Type>::operator == (const Array object) const {
    
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

template <typename Type>
bool Array<Type>::operator != (const Array object) const {
    
    return !(*this == object);
    
}

template <typename Type>
template <typename IterType, typename ArrType>
bool Array<Type>::TemplateIterator<IterType, ArrType>::hasNext() const {
    
    return (m_pos < m_numbers->getSize());
    
}

template <typename Type>
template <typename IterType, typename ArrType>
int Array<Type>::TemplateIterator<IterType, ArrType>::getPosition() const {
    
    return m_pos;
    
}


template <typename Type>
template <typename IterType, typename ArrType>
IterType &Array<Type>::TemplateIterator<IterType, ArrType>::operator * ()
{
    return m_numbers->operator [] (m_pos);
}

template <typename Type>
template <typename IterType, typename ArrType> typename
Array<Type>::template TemplateIterator<IterType, ArrType> &Array<Type>::TemplateIterator<IterType, ArrType>::operator ++ () {
    
    m_pos++;
    return *this;
    
}

template <typename Type>
template <typename IterType, typename ArrType> typename
Array<Type>::template TemplateIterator<IterType, ArrType> Array<Type>::TemplateIterator<IterType, ArrType>::operator ++ (int) {
    
    Iterator old(*this);
    m_pos++;
    return old;
    
}

template <typename Type>
template <typename IterType, typename ArrType> typename
Array<Type>::template TemplateIterator<IterType, ArrType> &Array<Type>::TemplateIterator<IterType, ArrType>::operator -- () {
    
    m_pos--;
    return *this;
    
}

template <typename Type>
template <typename IterType, typename ArrType> typename
Array<Type>:: template TemplateIterator<IterType, ArrType> Array<Type>::TemplateIterator<IterType, ArrType>::operator -- (int) {
    
    Iterator old(*this);
    m_pos--;
    return old;
    
}

template <typename Type>
template <typename IterType, typename ArrType> typename
Array<Type>::template TemplateIterator<IterType, ArrType> &Array<Type>::TemplateIterator<IterType, ArrType>::operator += (const int &value) {
    
    
    m_pos += value;
    return *this;

}

template <typename Type>
template <typename IterType, typename ArrType> typename
Array<Type>:: template TemplateIterator<IterType, ArrType> &Array<Type>::TemplateIterator<IterType, ArrType>::operator -= (const int &value) {
    
    m_pos -= value;
    return *this;

}

template <typename Type>
template <typename IterType, typename ArrType>
bool Array<Type>::TemplateIterator<IterType, ArrType>::operator == (const TemplateIterator &object) const {
    
    assert(m_numbers == object.m_numbers);
    return (m_numbers == object.m_numbers && m_pos == object.m_pos);
    
}

template <typename Type>
template <typename IterType, typename ArrType>
bool Array<Type>::TemplateIterator<IterType, ArrType>::operator != (const TemplateIterator &object) const {
    
    return !(*this == (object));
    
}

template <typename Type>
template <typename IterType, typename ArrType> typename
Array<Type>:: template TemplateIterator<IterType, ArrType> &Array<Type>::TemplateIterator<IterType, ArrType>::operator = (const int &value) {
    
    m_pos = value;
    return *this;
    
}

template <typename Type>
std::ostream &operator << (std::ostream &stream, const Array<Type> &object) {
    
    stream << "[";
    for(int i = 0; i < object.getSize(); i++) {
        if(i != 0){
            stream  << ", ";
        }
        stream << object[i];
    }
    stream << "]" << std::endl;
    
    return stream;
    
}

template <typename Type>
std::istream &operator >> (std::istream &stream, const Array<Type> &object) {
    
    for(int i = 0; i < object.getSize(); i++) {
        std::cout << "Array[" << i << "] = ";
        stream >> object[i];
    }
    
    return stream;
}

#endif
