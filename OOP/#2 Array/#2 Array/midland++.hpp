#pragma once

class Array {
public:
    Array();
    Array(int* array);
    Array(Array &array);
    ~Array();
    
    int getArraySize();
    int getIndexOfElement(int element);
    
    void print();
    void scan(int size);
    
private:
    int* m_numbers;
    int m_size;
};
