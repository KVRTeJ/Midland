#pragma once

class Array {
public:
    Array(int size, const int value) {
        
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
    
    int getArraySize() const;
    int getIndexOfElement(const int element) const;
    
    void print() const;
    void scan(int size);
    
    void sort();
    
    int &operator [] (const int index);
    Array &operator = (const Array &object);
    
    
private:
    int* m_numbers;
    int m_size;
};
