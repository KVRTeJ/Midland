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

void inputMatrix(char** matrix, const int n, const int m) {
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            std::cin >> matrix[i][j];
        }
    }
}

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
    const int n = 3, m = 3;
    
    char** foo = new char* [n];
    for(int i = 0; i < n; ++i)
        foo[i] = new char [m];
    
    inputMatrix(foo, n, m);
    printMatrix(foo, n, m);
    
    BoolMatrix boo(foo, n, m);
    boo.invert(0, 0, 0);
    std::cout << "boo:" << std::endl;
    std::cout << boo;
    
    for(int i = 0; i < n; ++i)
        delete [] foo[i];
    delete [] foo;
    
    return 0;
    /*
    std::vector<std::vector<char>> a = { {'1', '1', '1'},{'1', '1', '1'},{'1', '1', '1'} };
    
    BoolMatrix ap(a);
    ap.invert(0, 0, 2);
    ap.invert(1, 1);
    std::cout << ap;
    
    return 0;
    std::vector< std::vector<char> > matrix;
    matrix.resize(3);
    for(int i = 0; i < 3; ++i) {
        matrix[i].resize(3);
    }
    
    inputMatrix(matrix, 3, 3);
    printMatrix(matrix, 3, 3);
    std::cout << "BoolMatrix:" << std::endl;
    BoolMatrix foo(matrix), boo(foo), foo1(3, 3, 1), foo0(3, 3, 1);
    foo1 = ~boo;
    std::cout << foo1;
    foo1 ^= foo0;
    std::cout << foo1;
    std::cout << "weight - " << boo.getWeight(1) << std::endl;
    
    
    
    return 0;
     */
}

