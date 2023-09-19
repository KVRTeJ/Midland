#include <iostream>
#include <time.h>

#include "midland++.hpp"

int main() {
    
    //numberOfCities - кол-во городов, SourceCity - начальный город
    //priceMatrix - матрица стоимости
    //MIN, MAX - диапазон чисел для случайного заполнения матрицы
    //minWay - массив для записи ответа с функций
    
    const int MIN = 1, MAX = 99, bigNumber = 70, sourceCity = 1;
    
    int** priceMatrix, * minWay, numberOfCities, minWeight;
    
    double seconds;
    
    std::cout << "Кол-во городов - ";
    std::cin >> numberOfCities;
    //std::cout << "Стартовый город - ";
    //std::cin >> sourceCity;
    
    minWay = new int [numberOfCities + 1];
    priceMatrix = new int * [numberOfCities];
    for(int i = 0; i < numberOfCities; i++) {
        priceMatrix[i] = new int [numberOfCities];
    }
    
    //Заполнение матрицы
    getRandomCostMatrix(priceMatrix, numberOfCities, numberOfCities, MIN, MAX); //Случайно
    //inputMatrix(priceMatrix, numberOfCities, numberOfCities); //Вручную
    
    if(numberOfCities < bigNumber) {
        
        std::cout << "Итоговая матрица стоимости: " << std::endl;
        printMatrix(priceMatrix, numberOfCities, numberOfCities);
        
    }
    
    //Точный алгоритм
    //Генерируем каждую перестановку алгоритмом Дейкстры
    clock_t start = clock();
    calculateStraightMinimalWay(priceMatrix, minWay, numberOfCities, sourceCity, MAX);
    clock_t end = clock();
    
    seconds = (double)(end - start) / CLOCKS_PER_SEC;
    
    std::cout << "1) Точный алгоритм " << std::endl;
    std::cout << "Минимальный маршрут - ";
    printArray(minWay, numberOfCities + 1);
    minWeight = calculateWayWeight(priceMatrix, minWay, numberOfCities + 1);
    std::cout << "Вес маршрута - " << minWeight << std::endl;
    std::cout << "Затраченое время - " << seconds << "s" << std::endl;
    
    
    //Эвристический алгоритм #3
    //Выбираем исходящую дугу минимальной стоимости из текущей вершины, начиная с первой.
    
    start = clock();
    calculateHeuristicMinimalWay(priceMatrix, minWay, numberOfCities, MAX);
    end = clock();
    
    seconds = (double)(end - start) / CLOCKS_PER_SEC;
    
    std::cout << std::endl;
    
    std::cout << "2) Эвристический алгоритм " << std::endl;
    std::cout << "Минимальный маршрут - ";
    printArray(minWay, numberOfCities + 1);
    minWeight = calculateWayWeight(priceMatrix, minWay, numberOfCities + 1);
    std::cout << "Вес маршрута - " << minWeight << std::endl;
    std::cout << "Затраченое время - " << seconds << "s" << std::endl;

    
    for(int i = 0; i < numberOfCities; i++)
        delete [] priceMatrix[i];
    delete [] priceMatrix;
    delete [] minWay;
    
    return 0;
}
