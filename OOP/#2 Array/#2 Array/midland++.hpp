#pragma once

class Array {
public:
    Array();
    Array(int* array);
    ~Array();
    
    int getArraySize();
    
private:
    int* m_numbers;
    int m_size;
};
