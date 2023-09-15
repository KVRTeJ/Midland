#pragma once

void MatrixInput(int **matrix, int column, int row);
//Ввод динамической матрицы

void MatrixPrint(int **matrix, int column, int row);
//Вывод динамической матрицы

void MatrixRandom(int **matrix, int column, int row, int min, int max);
//Заполняет матрицу случайными числами от min до max

void MatrixRandomCost(int **matrix, int column, int row, int min, int max);
//Заполняет матрицу стоимости путей(1-1 = 2-2 = 0)случайными числами от min до max

void ArrayCopy(int *arrayOriginal, int *arrayReplica, int size);
//Копирует массив из arrayOriginal в arrayReplica

void ArrayPrint(int *array, int size);
//Вывод первых 'size' элементов массива

void Swap(int &first, int &second);
//Меняет элементы местами

unsigned int Factorial(int number);
//Рекурсия, которая вычисляет факториал 'number'
