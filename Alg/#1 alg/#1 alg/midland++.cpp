#include "midland++.hpp"
#include <iostream>
#include <time.h>

void MatrixPrint(int **matrix, int column, int row) {
    //column - столбцы
    //row - строки
    for(int c = 0; c < column; c++){
        for(int r = 0; r < row; r++)
            std::cout << matrix[c][r] << ' ';
        std::cout << std::endl;
    }
    
}

void MatrixInput(int **matrix, int column, int row) {
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

void MatrixRandom(int **matrix, int column, int row, int min, int max) {
    
    srand( (unsigned int) time(NULL));
    
    for(int c = 0; c < column; c++)
        for(int r = 0; r < row; r++)
            matrix[c][r] = rand() % (max - min + 1) + min;
}


void MatrixRandomCost(int **matrix, int column, int row, int min, int max) {
    
    srand( (unsigned int) time(NULL));
    
    for(int c = 0; c < column; c++)
        for(int r = 0; r < row; r++)
        if(c != r)
            matrix[c][r] = rand() % (max - min + 1) + min;
        else
            matrix[c][r] = 0;
}

void ArrayCopy(int *arrayOriginal, int *arrayReplica, int size) {
    for(int index = 0; index < size; index++)
        arrayReplica[index] = arrayOriginal[index];
}

void ArrayPrint(int *array, int size) {
    for(int index = 0; index < size; index++)
        std::cout << array[index] << ' ';
    std::cout << std::endl;
}

void Swap(int &first, int &second) {
    int temp = first;
    first = second;
    second = first;
}

unsigned int Factorial(int number) {
    if(number == 0)
        return 1;
    else
        return number*Factorial(number-1);
}
