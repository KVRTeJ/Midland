#ifndef ARE_TEMPLATE_ARRAY_DECLARED
#define ARE_TEMPLATE_ARRAY_DECLARED
#include <iostream>
#include <assert.h>
#include <time.h>
#include <vector>

template <typename Type>
class Array {
public:
    Array(int size = 1, const Type value = Type()) {
        
        if(size < 0) {
            size = -size;
            std::cerr << "void Array::Array: размер не может быть отрицательным. Убран минус." << std::endl;
            std::cerr << size << std::endl;
        }
        
        else {
            m_numbers = new Type [size];
            m_size = size;
            
            for(int i = 0; i < size; i++) {
                m_numbers[i] = value;
            }
        }
        
    }
    
    Array(const Type* array, int size);
    Array(const Array &array);
    Array(Array &&array);
    ~Array();
    
    template <typename IterType, typename ArrType>
    class TemplateIterator;
    using Iterator = TemplateIterator<Type, Array>;
    using ConstIterator = TemplateIterator<const Type, const Array>;
    
    Iterator begin();
    Iterator end();
    
    ConstIterator begin() const;
    ConstIterator end() const;
    
    Iterator insertBeforeIterator(Iterator iter, const Type value);
    Iterator removeInRange(const Iterator begin, const Iterator end);
    
    int getSize() const;
    int getIndexOfElement(const Type element) const;
    
    void print() const;
    void scan(int size);
    
    void swap(Array &object);
    
    void resize(int size);
    
    void sort() const;
    
    bool insert(const int index, const Type value);
    bool removeIndex(const int index);
    bool remove(const Type value);
    bool removeAll(const Type value);
    
    Type getMaxElement() const;
    Type getMinElement() const;
    
    void setRandomNumbers(const int min, const int max) const;
    void setRandomNumbersIncrease() const;
    void setRandomNumbersDecrease() const;
    
    Type &operator [] (const int index) const;
    Array &operator = (const Array &object);
    Array operator + (const Type value) const;
    Array &operator += (const Type value);
    Array operator + (const Array &object) const;
    Array &operator += (const Array &object);
    bool operator == (const Array object) const;
    bool operator != (const Array object) const;
    
private:
    Type* m_numbers = nullptr;
    int m_size = 0;
    
};

template <typename Type>
template <typename IterType, typename ArrType>
class Array<Type>::TemplateIterator {
public:
    friend class Array;
    
    TemplateIterator(ArrType *object = nullptr, const int pos = 0)
    : m_numbers(object), m_pos(pos)
    {}
    
    bool hasNext() const;
    int getPosition() const;
    
    IterType &operator * ();
    
    TemplateIterator &operator ++ ();
    TemplateIterator operator ++ (int);
    TemplateIterator &operator -- ();
    TemplateIterator operator -- (int);
    TemplateIterator &operator += (const int &value);
    TemplateIterator &operator -= (const int &value);
    TemplateIterator &operator = (const int &value);
    
    bool operator == (const TemplateIterator &object) const;
    bool operator != (const TemplateIterator &object) const;
    
private:
    ArrType* m_numbers = nullptr;
    int m_pos = 0;
    
};

template <typename Type>
std::ostream &operator << (std::ostream &stream, const Array<Type> &object);

template <typename Type>
std::istream &operator >> (std::istream &stream, const Array<Type> &object);

#include "midland++.cpp"

#endif //!ARE_TEMPLATE_ARRAY_DECLARED
