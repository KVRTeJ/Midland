#include "midland++.hpp"
#include <iostream>
#include <time.h>

void PrintMatrix(int **matrix, int column, int row) {
    //column - столбцы
    //row - строки
    for(int i = 0; i < column; i++){
        for(int j = 0; j < row; j++)
            std::cout << matrix[i][j] << ' ';
        std::cout << std::endl;
    }
    
}

void InputMatrix(int **matrix, int column, int row) {
    //column - столбцы
    //row - строки
    for(int c = 0; c < column; c++)
        for(int r = 0; r < row; r++) {
            if(c != r) {
                std::cout << "Введите стоимость путь из города " << c + 1 << " до города " << r + 1 << std::endl;
                std::cin >> matrix[c][r];
            }
            else
                matrix[c][r] = 0;
        }
    
}

void RandomMatrix(int **matrix, int column, int row, int min, int max) {
    
    srand( (unsigned int) time(NULL));
    
    for(int c = 0; c < column; c++)
        for(int r = 0; r < row; r++)
            matrix[c][r] = rand() % (max - min + 1) + min;
}


void RandomCostMatrix(int **matrix, int column, int row, int min, int max) {
    
    srand( (unsigned int) time(NULL));
    
    for(int c = 0; c < column; c++)
        for(int r = 0; r < row; r++)
        if(c != r)
            matrix[c][r] = rand() % (max - min + 1) + min;
        else
            matrix[c][r] = 0;
}

