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

void createMatrixCopy(int** matrixOriginal, int** matrixCopy, int column, int row) {
    
    for (int i = 0; i < column; i++) {
        
            for (int j = 0; j < row; j++) {
                
                matrixCopy[i][j] = matrixOriginal[i][j];
                
            }
        
        }
    
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

void calculateStraightMinimalWay(int** priceMatrix, int* bestWay, int* worstWay,
                                 int numberOfCities, int sourceCity,
                                 int maxElement) {
    
    //numberOfCities - кол-во городов, SourceCity - начальный город
    //priceMatrix - матрица стоимости
    //currentWay - актуальный путь, MinWay - минимальный путь
    //currentWeight - вес актального пути, MinWeight - вес минимального пути
    //permuration - актуальная перестановка чисел
    //maxElement - диапазон чисел для случайного заполнения матрицы
    
    //Обработка исключений
    if((sourceCity - 1) < 0 || (sourceCity - 1) > numberOfCities) {
        std::cout << "calculateStraightMinimalWay -> Ошибка в значении sourceCity" << std::endl;
        return;
    }
    
    //Ввод данных
    int* permutation, currentWeight, minWeight = (numberOfCities * maxElement),
    maxWeight = 0, counterPermutation = 0;
    
    
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
    createArrayCopy(permutation, bestWay, numberOfCities+1);
    counterPermutation++;
    //Первая перестановка сгенерирована, прибавляем счетчик
    
    /*
    //Вывод первого пути
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
                    
                    /*
                    //Текущий вес маршрута. Вывод
                    std::cout << "Перестановка номер - " << counterPermutation << std::endl;
                    std::cout << "Вес - " << currentWeight << std::endl;
                    std::cout << "Путь - ";
                    printArray(permutation, numberOfCities+1);
                    */
                    
                    if(currentWeight < minWeight) {
                        minWeight = currentWeight;
                        createArrayCopy(permutation, bestWay, numberOfCities+1);
                        //Если текущий вес < минимального - он минимальный
                    }
                    
                    else if(currentWeight > maxWeight) {
                        maxWeight = currentWeight;
                        createArrayCopy(permutation, worstWay, numberOfCities+1);
                        //Если текущий вес > максимального - он максимальный
                    }
                    
                }
            }
        }
    }
    
    delete [] permutation;
    
    return;
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

void calculateHeuristicMinimalWay(int** priceMatrix, int* answerArray, int numberOfCities, int maxElement) {
    
    int minElement_NextRow = 1;
    
    
    int** priceMatrixCopy = new int * [numberOfCities];
    for(int i = 0; i < numberOfCities; i++)
        priceMatrixCopy[i] = new int [numberOfCities];
    
    createMatrixCopy(priceMatrix, priceMatrixCopy, numberOfCities, numberOfCities);
    //Создаем копию матрицы, чтобы не менять исходную
    
    for(int i = 0; i < numberOfCities + 1; i++) {
        if(i == 0) {
            answerArray[i] = 1;
        }
        answerArray[i] = 0;
        
    }
    
    answerArray[numberOfCities + 1] = 0;
    //Готовим массив для минимального пути
    //Так как алгоритм расчитан на то, что мы всегда стартуем из 1 города, нет необходимости строить путь с определенным исходным городом
    
    {
    //Сделано, чтобы переменная currentColumn и i удалились сразу же после цикла
        
        int currentColumn = 0, i = 1; // currentColumn - текущий номер строки i - счетчик
        
        while(i < numberOfCities) {
            //Пока не прошли по всем городам
            
            minElement_NextRow = findMinInTheRow(priceMatrixCopy, numberOfCities, currentColumn, maxElement);
            //minElement_NextRow - сейчас индекс минимального элемента - а дальше номер следующей строки
            
            if(wasInArray(answerArray, numberOfCities, minElement_NextRow) == true) {
                
                priceMatrixCopy[currentColumn][minElement_NextRow] = 0;
                minElement_NextRow = findMinInTheRow(priceMatrixCopy, numberOfCities, currentColumn, maxElement);
                
            }
            //Проверка на цикл - если город уже есть в массиве перестановок, то анулируем его путь и снова ищем minElement_NextRow
            
            for(int k = 0; k < numberOfCities; k++) {
                
                priceMatrixCopy[currentColumn][k] = 0;
                priceMatrixCopy[k][minElement_NextRow] = 0;
                
            }
            
            priceMatrixCopy[currentColumn][minElement_NextRow] = 0;
            //По алгоритму: зануляем строку и столбец, с которыми работали, а также обратный путь
            
            /*
            std::cout << "-------" << std::endl;
            printMatrix(priceMatrixCopy, numberOfCities, numberOfCities);
            //Вывод шагов
            */
            
            answerArray[i] = minElement_NextRow;
            currentColumn = minElement_NextRow;
            i++;
            //После проверки на цикл и зануления, записываем город в массив перестановок, а также ставим номер следующей строки, прибавляем счетчик
            
            
        }
        
    }
    
    for(int i = 0; i < numberOfCities; i++)
        delete [] priceMatrixCopy[i];
    delete [] priceMatrixCopy;
    
    return;
    
}

