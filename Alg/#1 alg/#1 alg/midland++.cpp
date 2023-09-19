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

int calculateWayWeight(int **matrix, int *array, int size) {
    int answer = 0;
    for(int index = 0; index < size; index++) {
        answer += matrix[array[index]][array[index + 1]];
    }
    return answer;
}

int calculateStraightMinimalWay(int** priceMatrix, int* answerArray,
                                 int numberOfCities, int sourceCity,
                                 int maxElement) {
    
    //numberOfCities - кол-во городов, SourceCity - начальный город
    //priseMatr - матрица стоимости
    //currentWay - актуальный путь, MinWay - минимальный путь
    //currentWeight - вес актального пути, MinWeight - вес минимального пути
    //permuration - актуальная перестановка чисел
    //maxElement - диапазон чисел для случайного заполнения матрицы
    
    //Обработка исключений
    if((sourceCity - 1) < 0 || (sourceCity - 1) > numberOfCities) {
        std::cout << "calculateStraightMinimalWay -> Ошибка в значении sourceCity" << std::endl;
        return -1;
    }
    
    //Ввод данных
    int* permutation, currentWeight, minWeight = (numberOfCities * maxElement), counterPermutation = 0;
    
    
    permutation = new int [numberOfCities + 1];
    
    
    
    //Генерируем первый путь, учитывая, что начальный город - конечный
    for(int i = 0, j = 0; i < numberOfCities; ) {
        
        if(i == 0) {
            permutation[i] = sourceCity - 1;
            i++;
        }
        
        else if(j == sourceCity - 1) {
            j++;
        }
        
        else {
            permutation[i] = j;
            j++;
            i++;
        }
        
    }
    
    permutation[numberOfCities] = sourceCity - 1;
    
    currentWeight = calculateWayWeight(priceMatrix, permutation, numberOfCities);
    createArrayCopy(permutation, answerArray, numberOfCities+1);
    counterPermutation++;
    //Первая перестановка сгенерирована, прибавляем счетчик
    /*
    std::cout << "Перестановка номер - " << counterPermutation << std::endl;
    currentWeight = calculateWayWeight(priceMatrix, permutation, numberOfCities);
    std::cout << "Вес - " << currentWeight << std::endl;
    std::cout << "Путь - ";
    printArray(permutation, numberOfCities + 1);
    */
    for(int i = numberOfCities - 2; i > 0; i--) {
        //-1 по алгоритму и -1 потому что исходный город не трогаем
        
        if((0 < i) && (i < (numberOfCities - 1)) && (permutation[i] < permutation[i + 1])) {
            //Пока 0 < i < n and P[i] < P[i+1] по алгоритму
            
            for(int j = (numberOfCities-1); j > i; j--) {
                // j  на последний элемент
                
                if((i < j) && (j <= (numberOfCities - 1) ) && (permutation[i] < permutation[j])) {
                    //Eсли i < j <= n and P[i] < P[j] по алгоритму
                    
                    swapNumbers(permutation[i], permutation[j]);
                    for(int i_tail = i + 1, j_tail = (numberOfCities - 1);
                        i_tail <= j_tail; i_tail++, j_tail--)
                        swapNumbers(permutation[i_tail], permutation[j_tail]);//Инвертируем хвост
                    
                    counterPermutation++; //Сделана перестановка - счетчик +1
                    
                    i = numberOfCities-1;
                    //Возвращаем i на исходное место
                    
                    currentWeight = calculateWayWeight(priceMatrix, permutation, numberOfCities);
                    //Текущий вес маршрута
                    /*
                    std::cout << "Перестановка номер - " << counterPermutation << std::endl;
                    std::cout << "Вес - " << currentWeight << std::endl;
                    std::cout << "Путь - ";
                    printArray(permutation, numberOfCities+1);
                    */
                    if(currentWeight < minWeight) {
                        minWeight = currentWeight;
                        createArrayCopy(permutation, answerArray, numberOfCities+1);
                        //Если текущий вес < минимального - он минимальный
                    }
                }
            }
        }
    }
    
    delete [] permutation;
    
    return 0;
}

int findMinInTheRow(int** matrix, int size, int column, int maxElement) {
    
    int minNumber = maxElement, minIndex = 0;
    
    for(int i = 0; i < size; i++) {
        
        if(matrix[column][i] != 0) {
            
            if(matrix[column][i] < minNumber) {
                
                minNumber = matrix[column][i];
                minIndex = i;
                
            }
            
        }
        
    }
    
    return minIndex;
}

bool wasInArray(int* array, int size, int number) {
    
    for(int i = 0; i < size; i++) {
        
        if(array[i] == number) {
            return true;
        }
        
    }
    
    return false;
}
