#pragma once

class HoareSort {
public:
    friend std::istream &operator >> (std::istream& stream, HoareSort& object);
    friend std::ostream &operator << (std::ostream& stream, HoareSort& object);
    
    HoareSort(const int& size = 9, const int& value = 0);
    HoareSort(std::vector<int>& nums);
    
    void fillRandom(const int& max = 1, const int& min = 10);
    bool readFromFile(std::string& fileName);
    
    bool checkIncrease() const;
    
    bool QuickSort();
    
private:
    std::vector<int> m_nums;
    std::vector<int> m_sortedNums;
};

std::istream &operator >> (std::istream& stream, HoareSort& object);
std::ostream &operator << (std::istream& stream, HoareSort& object);

