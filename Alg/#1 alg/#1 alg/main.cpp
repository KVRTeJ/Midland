#include <iostream>
#include <time.h>

#include "midland++.hpp"

int main() {
    
    //numberOfCities - кол-во городов, SourceCity - начальный город
    //priseMatr - матрица стоимости
    //MIN, MAX - диапазон чисел для случайного заполнения матрицы
    //minWay - массив для записи ответа с функций
    
    const int MIN = 1, MAX = 99;
    
    int** priceMatrix, * minWay, numberOfCities, sourceCity;
    
    double seconds;
    
    std::cout << "Кол-во городов - ";
    std::cin >> numberOfCities;
    std::cout << "Стартовый город - ";
    std::cin >> sourceCity;
    
    minWay = new int [numberOfCities + 1];
    priceMatrix = new int * [numberOfCities];
    for(int index = 0; index < numberOfCities; index++) {
        priceMatrix[index] = new int [numberOfCities];
    }
    
    //Заполнение матрицы
    getRandomCostMatrix(priceMatrix, numberOfCities, numberOfCities, MIN, MAX); //Случайно
    //inputMatrix(PriseMatr, NumberOfCities, NumberOfCities); //Вручную
    
    std::cout << "Итоговая матрица стоимости: " << std::endl;
    printMatrix(priceMatrix, numberOfCities, numberOfCities);

    
    //Точный алгоритм
    clock_t start = clock();
    calculateStraightMinimalWay(priceMatrix, minWay, numberOfCities, sourceCity, MAX);
    clock_t end = clock();
    
    seconds = (double)(end - start) / CLOCKS_PER_SEC;
    
    std::cout << "Минимальный маршрут - ";
    printArray(minWay, numberOfCities + 1);
    std::cout << "Вес маршрута - " << calculateWayWeight(priceMatrix, minWay, numberOfCities + 1) << std::endl;
    std::cout << "Затраченое время - " << seconds << "s" << std::endl;

    
    //Эвристический алгоритм
    
    {
    
    }
    
    for(int index = 0; index < numberOfCities; index++)
        delete [] priceMatrix[index];
    delete [] priceMatrix;
    delete [] minWay;
    
    return 0;
}
