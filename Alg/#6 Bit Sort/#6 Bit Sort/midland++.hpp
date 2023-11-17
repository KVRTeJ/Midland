#pragma once

void printVector(const std::vector<int>& nums);

bool fillRandom(std::vector<int>& nums, const int& min, const int& max);

bool readFromFile(const std::string& name, std::vector<int>& nums);

bool checkIncrease(const std::vector<int> nums);

void BitSortPositive(std::vector<int>& nums, int left, int right, int k);

bool checkNegative(const int& num);

void BitSort(std::vector<int>& nums, int maxNum);
