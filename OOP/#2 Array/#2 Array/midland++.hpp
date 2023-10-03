#pragma once

class Array {
public:
    Array(int size = 1, const int value = -1) {
        
        if(size < 0) {
            size = -size;
            std::cerr << "void Array::scan: размер не может быть отрицательным. Убран минус." << std::endl;
            std::cout << size << std::endl;
        }
        
        m_numbers = new int [size];
        m_size = size;
        
        for(int i = 0; i < size; i++) {
            m_numbers[i] = value;
        }
        
    }
    
    Array(const int* array, const int size);
    Array(const Array &array);
    ~Array();
    
    int getSize() const;
    int getIndexOfElement(const int element) const;
    
    void print() const;
    void scan(int size);
    
    void sort() const;
    
    bool insert(const int index, const int value);
    bool removeIndex(const int index);
    bool remove(const int value);
    bool removeAll(const int value);
    
    int getMaxElement() const;
    int getMinElement() const;
    
    void setRandomNumbers(const int min, const int max) const;
    void setRandomNumbersIncrease() const;
    void setRandomNumbersDecrease() const;
    
    int &operator [] (const int index) const;
    Array &operator = (const Array &object);
    Array operator + (const int value) const;
    Array &operator += (const int value);
    Array operator + (const Array &object) const;
    Array &operator += (const Array &object);
    bool operator == (const Array object) const;
    bool operator != (const Array object) const;
    
private:
    int* m_numbers = nullptr;
    int m_size = 0;
};
