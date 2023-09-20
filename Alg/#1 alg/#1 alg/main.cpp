#include <iostream>
#include <time.h>

#include "midland++.hpp"

int main() {
    
    //numberOfCities - кол-во городов, SourceCity - начальный город
    //priceMatrix - матрица стоимости
    //MIN, MAX - диапазон чисел для случайного заполнения матрицы
    //minWay - массив для записи ответа с функций
    
    const int MIN = 1, MAX = 99, bigNumber = 70, sourceCity = 1;
    
    int** priceMatrix, * minWay, * maxWay, numberOfCities, minWeight, maxWeight, minWeightHeuristic;
    float relativeQuality;
    
    double secondsStraight, secondsHeuristic, relativeSpeed;
    
    std::cout << "Кол-во городов - ";
    std::cin >> numberOfCities;
    //std::cout << "Стартовый город - ";
    //std::cin >> sourceCity;
    
    minWay = new int [numberOfCities + 1];
    maxWay = new int [numberOfCities + 1];
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
    calculateStraightMinimalWay(priceMatrix, minWay, maxWay, numberOfCities, sourceCity, MAX);
    clock_t end = clock();
    
    secondsStraight = (double)(end - start) / CLOCKS_PER_SEC;
    
    std::cout << std::endl;
    
    std::cout << "1) Точный алгоритм " << std::endl;
    
    std::cout << "Лучший маршрут - ";
    printArray(minWay, numberOfCities + 1);
    
    minWeight = calculateWayWeight(priceMatrix, minWay, numberOfCities);
    maxWeight = calculateWayWeight(priceMatrix, maxWay, numberOfCities);
    
    std::cout << "Вес лучшего маршрута - " << minWeight << std::endl;
    
    std::cout << "Худший маршрут - ";
    printArray(maxWay, numberOfCities + 1);
    
    std::cout << "Вес худшего маршрута - " << maxWeight << std::endl;
    std::cout << "Затраченое время - " << secondsStraight << "s" << std::endl;
    
    
    //Эвристический алгоритм #3
    //Выбираем исходящую дугу минимальной стоимости из текущей вершины, начиная с первой.
    
    start = clock();
    calculateHeuristicMinimalWay(priceMatrix, minWay, numberOfCities, MAX);
    end = clock();
    
    secondsHeuristic = (double)(end - start) / CLOCKS_PER_SEC;
    
    std::cout << std::endl;
    
    std::cout << "2) Эвристический алгоритм " << std::endl;
    std::cout << "Лучший маршрут - ";
    printArray(minWay, numberOfCities + 1);
    minWeightHeuristic = calculateWayWeight(priceMatrix, minWay, numberOfCities);
    std::cout << "Вес лучшего маршрута - " << minWeightHeuristic << std::endl;
    std::cout << "Затраченое время - " << secondsHeuristic << "s" << std::endl;

    std::cout << std::endl;
    
    //Отчет
    
    //Качество
    relativeQuality = ( (float) (minWeightHeuristic - minWeight) / (float) (maxWeight - minWeightHeuristic) ) * 100;
    relativeQuality = 100 - relativeQuality;
    std::cout << "Качество решения эвристического алгоритма - " << relativeQuality << "%" << std::endl;
    
    //Время
    relativeSpeed = ( (secondsHeuristic - secondsStraight) / secondsHeuristic ) * 100;
    std::cout << "Процент, характеризующий скорость работы эвристического алгоритма в сравнении с точным - " << relativeSpeed << "%" << std::endl;
    std::cout << "//Если это значение положительное, то прямой алгоритм выполняется быстрее эвристического." << std::endl;
    std::cout << "//Значение отражает разницу в процентах между временем выполнения двух алгоритмов." << std::endl;
    
    for(int i = 0; i < numberOfCities; i++)
        delete [] priceMatrix[i];
    delete [] priceMatrix;
    delete [] maxWay;
    delete [] minWay;
    
    return 0;
}
