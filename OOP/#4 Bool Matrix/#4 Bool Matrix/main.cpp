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
    const char t[3][3] = { {1, 0, 0}, {1, 1, 0}, {1, 1, 1} };
    
    int n = 3, m = 3;
    char** foo = new char* [n];
    for(int i = 0; i < n; ++i) {
        foo[i] = new char [m];
    }
    
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            foo[i][j] = 'a';
        }
    }
    
    printMatrix(foo, n, m);
    
    int length = sizeof(foo) / sizeof(foo[0]);
    std::cout << "sizeof - " << length << std::endl;
    int length1 = 0;
    for(int i = 0; i < n; ++i) {
        for(int j = 0; i < m; ++j) {
            if(foo[i][j] == '1' || foo[i][j] == '0') {
                length1++;
            }
        }
    }
    
    std::cout << "strlen - " << length1 << std::endl;
    
    BoolMatrix boo(foo);
    std::cout << boo;
    
    return 0;
}
