#pragma once

class Array {
public:
    Array();
    Array(int* array);
    Array(Array &array);
    ~Array();
    
    int getArraySize();
    void printArray();
    
private:
    int* m_numbers;
    int m_size;
};
