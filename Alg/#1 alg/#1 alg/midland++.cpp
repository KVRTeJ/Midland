#include <iostream>
#include <time.h>

#include "midland++.hpp"

void printMatrix(int **matrix, int column, int row) {
    //column - столбцы
    //row - строки
    for(int i = 0; i < column; i++){
        for(int j = 0; j < row; j++)
            std::cout << matrix[i][j] << ' ';
        std::cout << std::endl;
    }
    
}

void inputMatrix(int **matrix, int column, int row) {
    //column - столбцы
    //row - строки
    for(int i = 0; i < column; i++)
        for(int j = 0; j < row; j++) {
            if(i != j) {
                std::cout << "Введите стоимость путь из города " << i + 1 << " до города " << j + 1 << std::endl;
                std::cin >> matrix[i][j];
            }
            else
                matrix[i][j] = 0;
        }
    
}

void getRandomMatrix(int **matrix, int column, int row, int min, int max) {
    
    srand( (unsigned int) time(0));
    
    for(int i = 0; i < column; i++)
        for(int j = 0; j < row; j++)
            matrix[i][j] = rand() % (max - min + 1) + min;
}


void getRandomCostMatrix(int **matrix, int column, int row, int min, int max) {
    
    srand( (unsigned int) time(0));
    
    for(int i = 0; i < column; i++)
        for(int j = 0; j < row; j++)
        if(i != j)
            matrix[i][j] = rand() % (max - min + 1) + min;
        else
            matrix[i][j] = 0;
}

void createArrayCopy(int *arrayOriginal, int *arrayReplica, int size) {
    for(int i = 0; i < size; i++)
        arrayReplica[i] = arrayOriginal[i];
}

void printArray(int *array, int size) {
    for(int i = 0; i < size; i++)
        std::cout << array[i] << ' ';
    std::cout << std::endl;
}

void swapNumbers(int &first, int &second) {
    int temp = first;
    first = second;
    second = temp;
}

unsigned int calculateFactorial(int number) {
    if(number == 0)
        return 1;
    else
        return number * calculateFactorial(number - 1);
}

int calculateWayWeight(int **matrix, int *array, int size) {
    int answer = 0;
    for(int index = 0; index < size; index++) {
        answer += matrix[array[index]][array[index + 1]];
    }
    return answer;
}
