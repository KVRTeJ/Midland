//
//  main.cpp
//  #1 alg
//
//  Created by Dmitriy on 14.09.2023.
//

//#1 Задача Комивояджера

#include <iostream>
#include "midland++.hpp"

int main() {
    const int min = 1, max = 9, N = 5;
    
    //NumberOfCities - кол-во городов, SourceCity - начальный город
    //PriseMatr - матрица стоимости
    //CurrentWay - актуальный путь, MinWay - минимальный путь
    //CurrentWeight - вес актального пути, MinWeight - вес минимального пути
    int NumberOfCities, SourceCity, **PriseMatr, CurrentWeight, *CurrentWay, MinWeight, *MinWay;

    std::cout << "Кол-во городов - ";
    std::cin >> NumberOfCities;
    std::cout << "Стартовый город - ";
    std::cin >> SourceCity;
    
    CurrentWay = new int [NumberOfCities];
    MinWay = new int [NumberOfCities];
    PriseMatr = new int * [NumberOfCities];
    for(int index = 0; index < NumberOfCities; index++) {
        PriseMatr[index] = new int [NumberOfCities];
    }
    
    if(NumberOfCities < N)
        MatrixInput(PriseMatr, NumberOfCities, NumberOfCities);
    else
        MatrixRandomCost(PriseMatr, NumberOfCities, NumberOfCities, min, max);
    
    std::cout << "Итоговая матрица стоимости: " << std::endl;
    MatrixPrint(PriseMatr, NumberOfCities, NumberOfCities);
    
    for(int index = 0; index < NumberOfCities; index++)
        MinWay[index] = max;
    
    //Алгоритм
    
    for(int index = 0; index < NumberOfCities; index++)
        delete [] PriseMatr[index];
    delete [] PriseMatr;
    delete [] CurrentWay;
    
    //Ответ
    
    //ArrayPrint(MinWay, NumberOfCities);
    
    delete [] MinWay;
    
    return 0;
}
