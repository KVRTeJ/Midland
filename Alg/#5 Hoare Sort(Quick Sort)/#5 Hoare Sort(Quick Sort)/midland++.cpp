#include <iostream>
#include <vector>

#include "midland++.hpp"

HoareSort::HoareSort(const int& size, const int& value) {
    assert(size > 0);
    
    m_nums.resize(size);
    for(auto it = m_nums.begin(); it != m_nums.end(); ++it) {
        *it = 0;
    }
    
}

HoareSort::HoareSort(std::vector<int>& nums) {
    assert(!nums.empty());
    
    m_nums = nums;
    
}


void HoareSort::fillRandom(const int& min, const int& max) {
    assert(min < max);
    
    srand( (unsigned int) time(0) );
    for(auto it = m_nums.begin(); it != m_nums.end(); ++it) {
        *it = rand() % (max - min + 1) + min;
    }
    
}

std::istream &operator >> (std::istream& stream, HoareSort& object) {
    
    for(auto it = object.m_nums.begin(); it != object.m_nums.end(); ++it) {
        stream >> *it;
    }
    
    return stream;
}

std::ostream &operator << (std::ostream& stream, HoareSort& object) {
    
    std::cout << "[";
    
    for(auto it = object.m_nums.begin(); it != object.m_nums.end(); ++it) {
        if(it != object.m_nums.end())
            std::cout << *it << ", ";
        std::cout << *it;
    }
    
    std::cout << "]";
    
    return stream;
}

/*
bool HoareSort::readFromFile(std::string fileName);

bool HoareSort::checkIncrease();

bool HoareSort::QuickSort();
*/
