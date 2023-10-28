#pragma once

class HoareSort {
    friend std::istream &operator >> (std::istream& stream, HoareSort& object);
    friend std::ostream &operator << (std::ostream& stream, HoareSort& object);
    
public:
    HoareSort(const int& size = 9, const int& value = 0);
    HoareSort(std::vector<int>& nums);
    
    unsigned int getSize() {
        return m_nums.size();
    }
    
    bool fillRandom(const int& min, const int& max);
    bool readFromFile(std::string name);
    bool checkIncrease() const;
    
    int partition(int left, int right);
    void QuickSort(int left, int right);
    
    HoareSort &operator = (HoareSort& nums);
    
private:
    std::vector<int> m_nums;
    std::vector<int> m_sortedNums;
};

std::istream &operator >> (std::istream& stream, HoareSort& object);
std::ostream &operator << (std::istream& stream, HoareSort& object);

