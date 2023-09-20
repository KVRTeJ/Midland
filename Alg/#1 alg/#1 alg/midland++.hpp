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

void createMatrixCopy(int** matrixOriginal, int** matrixCopy, int column, int row);
//Копирует матрицу из matrixOriginal в matrixCopy

void printArray(int *array, int size);
//Вывод первых 'size' элементов массива

void swapNumbers(int &first, int &second);
//Меняет элементы местами

unsigned int calculateFactorial(int number);
//Рекурсия, которая вычисляет факториал 'number'

int calculateWayWeight(int **matrix, int *array, int size);
//Подсчет веса пути

void calculateStraightMinimalWay(int** matrix,int* bestWay, int* worstWay,
                                 int numberOfCities, int sourceCity, int maxElement);
//Подсчет минимального пути прямым методом. Ответ записывается в "answerArray"

int findMinInTheRow(int** matrix, int size, int column, int maxElement);
//Выводит минимальный элемент в строке column размером size

bool wasInArray(int* array, int size, int number);
//Есть 2 ответа - true если number есть в массиве array и false если нету

void calculateHeuristicMinimalWay(int** priceMatrix, int* answerArray, int numberOfCities, int maxElement);
//Подсчет минимального пути эвристическим методом. Ответ записывается в "answerArray"
