#include <iostream>

#include "BoolMatrix.hpp"

void inputMatrix(std::vector< std::vector<char> >& matrix, const int n, const int m) {
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            std::cin >> matrix[i][j];
        }
    }
}

void printMatrix(const std::vector< std::vector<char> >& matrix, const int n, const int m) {
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
    std::vector< std::vector<char> > matrix;
    matrix.resize(3);
    for(int i = 0; i < 3; ++i) {
        matrix[i].resize(3);
    }
    
    inputMatrix(matrix, 3, 3);
    //printMatrix(matrix, 3, 3);
    std::cout << "BoolMatrix:" << std::endl;
    BoolMatrix foo(matrix), boo(foo), foo1(3, 3, 1), foo0(3, 3, 0);
    boo &= foo1;
    std::cout << boo;
    boo &= foo0;
    std::cout << boo;
    std::cout << "weight - " << boo.getWeight(1) << std::endl;
    
    
    
    return 0;
}

