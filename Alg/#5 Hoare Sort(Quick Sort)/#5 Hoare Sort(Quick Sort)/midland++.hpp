#pragma once

class HoareSort {
    friend std::istream &operator >> (std::istream& stream, HoareSort& object);
    friend std::ostream &operator << (std::ostream& stream, HoareSort& object);
    
public:
    HoareSort(const int& size = 9, const int& value = 0);
    HoareSort(std::vector<int>& nums);
    
    bool fillRandom(const int& max = 1, const int& min = 10);
    bool readFromFile(std::string name);
    bool checkIncrease() const;
    
    void QuickSort();
    
    HoareSort &operator = (HoareSort& nums);
    
private:
    std::vector<int> m_nums;
    std::vector<int> m_sortedNums;
    int min, max;
};

std::istream &operator >> (std::istream& stream, HoareSort& object);
std::ostream &operator << (std::istream& stream, HoareSort& object);

