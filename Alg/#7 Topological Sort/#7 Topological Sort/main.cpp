#include "TopSort.hpp"

template <typename Type>
void printVector(const std::vector<Type>& vec) {
    std::cout << "[";
    for(auto it = vec.begin(); it != vec.end(); ++it) {
        std::cout << (*it) << ((it + 1) == vec.end() ? "":" ");
    }
    std::cout << "]" << std::endl;
}

int main() {
    BoolMatrix m(7, 7);
    std::cin >> m;
    printVector(TopologicalSort(m));
    return 0;
}


/*
0000000
1000000
0000000
0000100
1010000
0110100
1000000
 */
