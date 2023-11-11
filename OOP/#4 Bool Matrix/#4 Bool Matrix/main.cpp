#include <iostream>

#include "BoolMatrix.hpp"

void printMatrix(char** matrix, const int n, const int m) {
    for(int i = 0; i < n; ++i) {
        std::cout << "|";
        for(int j = 0; j < m; ++j) {
            std::cout << matrix[i][j] << ((j + 1) < m ? " ":"");
        }
        std::cout << "|";
        std::cout << std::endl;
    }
}

int main() {
    BoolMatrix j(3, 3, 1), k(3, 3, 1), t;
    t = j & k;
    std::cout << t;
    
    return 0;
}
