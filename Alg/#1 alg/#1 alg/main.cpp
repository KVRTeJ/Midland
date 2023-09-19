#include <iostream>
#include <time.h>

#include "midland++.hpp"

int main() {
    
    //numberOfCities - кол-во городов, SourceCity - начальный город
    //priseMatr - матрица стоимости
    //MIN, MAX - диапазон чисел для случайного заполнения матрицы
    //minWay - массив для записи ответа с функций
    
    const int MIN = 1, MAX = 9;
    
    int** priceMatrix, * minWay, numberOfCities, sourceCity;
    
    double seconds;
    
    std::cout << "Кол-во городов - ";
    std::cin >> numberOfCities;
    std::cout << "Стартовый город - ";
    std::cin >> sourceCity;
    
    minWay = new int [numberOfCities + 1];
    priceMatrix = new int * [numberOfCities];
    for(int i = 0; i < numberOfCities; i++) {
        priceMatrix[i] = new int [numberOfCities];
    }
    
    //Заполнение матрицы
    getRandomCostMatrix(priceMatrix, numberOfCities, numberOfCities, MIN, MAX); //Случайно
    //inputMatrix(PriseMatr, NumberOfCities, NumberOfCities); //Вручную
    
    std::cout << "Итоговая матрица стоимости: " << std::endl;
    printMatrix(priceMatrix, numberOfCities, numberOfCities);

    /*
    //Точный алгоритм
    clock_t start = clock();
    calculateStraightMinimalWay(priceMatrix, minWay, numberOfCities, sourceCity, MAX);
    clock_t end = clock();
    
    seconds = (double)(end - start) / CLOCKS_PER_SEC;
    
    std::cout << "Минимальный маршрут - ";
    printArray(minWay, numberOfCities + 1);
    std::cout << "Вес маршрута - " << calculateWayWeight(priceMatrix, minWay, numberOfCities + 1) << std::endl;
    std::cout << "Затраченое время - " << seconds << "s" << std::endl;
    */
    
    //Эвристический алгоритм #3
    //Выбираем исходящую дугу минимальной стоимости из текущей вершины, начиная с первой.

    int temp = -1;
    
    int* permutations = new int [numberOfCities + 1];
    //int* wasArray = new int [numberOfCities];
    
    for(int i = 0; i < numberOfCities; i++) {
        
        permutations[i] = i;
        
    }
    
    permutations[numberOfCities + 1] = 0;
    
    printArray(permutations, numberOfCities + 1);
    
    
    for(int j = 0; j < numberOfCities; j++) {
        /*
        if(wasInArray(permutations, numberOfCities, j) == true) {
            priceMatrix[temp][j] = 0;
            j--;
        }
        //проверка на цикл и откат на шаг назад
        */
        temp = findMinInTheRow(priceMatrix, numberOfCities, j, MAX);
        //wasArray[temp] = 1;
        //std::cout << "temp = " << temp << " Element - " << priceMatrix[j][temp] << std::endl;
        
        
    }
    
    
    //printArray(wasArray, numberOfCities);
    //delete [] wasArray;
    
    for(int i = 0; i < numberOfCities; i++)
        delete [] priceMatrix[i];
    delete [] priceMatrix;
    delete [] minWay;
    
    return 0;
}
