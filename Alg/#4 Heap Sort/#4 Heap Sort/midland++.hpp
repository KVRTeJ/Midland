#pragma once

void readFileToVector(const char *name, std::vector<int>& nums);

bool printVectorInt(const std::vector<int>& nums);

bool fillRandomNums(std::vector<int>& vector, const long int size = 5,
                    const int min = 1, const int max = 10);

bool checkIncrease(const std::vector<int> nums);
