#pragma once

void inputMatrix(int **matrix, int column, int row);
//Ввод динамической матрицы

void printMatrix(int **matrix, int column, int row);
//Вывод динамической матрицы

void getRandomMatrix(int **matrix, int column, int row, int min, int max);
//Заполняет матрицу случайными числами от min до max

void getRandomCostMatrix(int **matrix, int column, int row, int min, int max);
//Заполняет матрицу стоимости путей(1-1 = 2-2 = 0)случайными числами от min до max

void createArrayCopy(int *arrayOriginal, int *arrayReplica, int size);
//Копирует массив из arrayOriginal в arrayReplica

void printArray(int *array, int size);
//Вывод первых 'size' элементов массива

void swapNumbers(int &first, int &second);
//Меняет элементы местами

unsigned int calculateFactorial(int number);
//Рекурсия, которая вычисляет факториал 'number'

int calculateWayWeight(int **matrix, int *array, int size);
//Подсчет веса пути
