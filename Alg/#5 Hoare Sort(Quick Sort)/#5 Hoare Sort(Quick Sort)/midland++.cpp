#include <iostream>
#include <vector>

#include "midland++.hpp"

HoareSort::HoareSort(const int& size, const int& value) {
    assert(size > 0);
    
    m_nums.resize(size);
    for(auto it = m_nums.begin(); it != m_nums.end(); ++it) {
        *it = value;
    }
    
}

HoareSort::HoareSort(std::vector<int>& nums) {
    assert(!nums.empty());
    
    m_nums = nums;
    
}


bool HoareSort::fillRandom(const int& min, const int& max) {
    assert(min < max);
    
    srand( (unsigned int) time(0) );
    for(auto it = m_nums.begin(); it != m_nums.end(); ++it) {
        *it = rand() % (max - min + 1) + min;
    }
    
    return true;
    
}


bool HoareSort::readFromFile(std::string name) {
    
    char* fileName = new char [name.length() + 1];
    std::strcpy(fileName, name.c_str());
    
    FILE *f;
    f = fopen (fileName, "r");
    assert(f != NULL);
    
    m_nums.clear();
    
    {
        int x;
        while (fscanf (f, "%d", &x) != EOF)
            m_nums.push_back(x);
    }
    
    delete [] fileName;
    fclose (f);
    
    return true;
    
}


bool HoareSort::checkIncrease() const {
    
    for(auto it = m_nums.begin(); it != (m_nums.end() - 1); ++it) {
        if(*(it) > *(it + 1) )
            assert(false);
    }
    
    return true;
    
}


void HoareSort::QuickSort() {
    
    
    
}

HoareSort &HoareSort::operator = (HoareSort& nums) {
    assert(!nums.m_nums.empty());
    
    if(m_nums == nums.m_nums)
        return *this;
    
    m_nums = nums.m_nums;
    
    return *this;
}

/* Out of class */
std::istream &operator >> (std::istream& stream, HoareSort& object) {
    
    for(auto it = object.m_nums.begin(); it != object.m_nums.end(); ++it) {
        stream >> *it;
    }
    
    return stream;
}

std::ostream &operator << (std::ostream& stream, HoareSort& object) {
    
    std::cout << "[";
    
    for(auto it = object.m_nums.begin(); it != object.m_nums.end(); ++it) {
        if(it != object.m_nums.begin())
            std::cout << ", ";
        std::cout << *it;
    }
    
    std::cout << "]";
    
    return stream;
}
