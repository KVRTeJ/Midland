#include <iostream>
#include <vector>

#include "midland++.hpp"

int maxBit(const int MAX_NUMBER) {
    switch (MAX_NUMBER) {
        case 10:
            return 3;
            break;
        case 1000:
            return 9;
            break;
        case 100000:
            return 16;
            break;
        default:
            std::cerr << "maxBit: default ended with: 31" << std::endl;
            return 30;
    }
}

int main() {
    const int MAX = 100000;
    std::vector<int> temp(10);
    fillRandom(temp, 0, MAX);
    printVector(temp);
    std::cout << maxBit(MAX) << std::endl;
    BitSort(temp, 0, temp.size() - 1, maxBit(MAX));
    printVector(temp);
    assert(checkIncrease(temp));
    return 0;
}
