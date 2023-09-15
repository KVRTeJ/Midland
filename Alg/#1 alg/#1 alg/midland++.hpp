#pragma once

void InputMatrix(int **matrix, int column, int row);
//Ввод динамической матрицы

void PrintMatrix(int **matrix, int column, int row);
//Вывод динамической матрицы

void RandomMatrix(int **matrix, int column, int row, int min, int max);
//Заполняет матрицу случайными числами от min до max

void RandomCostMatrix(int **matrix, int column, int row, int min, int max);
//Заполняет матрицу стоимости путей(1-1 = 2-2 = 0)случайными числами от min до max
