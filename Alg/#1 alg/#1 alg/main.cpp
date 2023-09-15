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
    
    //numberCities - кол-во городов, SourceCity - начальный город
    //priseMatr - матрица стоимости
    int NumberOfCities, SourceCity, **PriseMatr;

    std::cout << "Кол-во городов - ";
    std::cin >> NumberOfCities;
    std::cout << "Стартовый город - ";
    std::cin >> SourceCity;
    
    PriseMatr = new int * [NumberOfCities];
    for(int index = 0; index < NumberOfCities; index++) {
        PriseMatr[index] = new int [NumberOfCities];
    }
    
    if(NumberOfCities < 5)
        InputMatrix(PriseMatr, NumberOfCities, NumberOfCities);
    else
        RandomCostMatrix(PriseMatr, NumberOfCities, NumberOfCities, 1, 9);
    
    std::cout << "Итоговая матрица стоимости: " << std::endl;
    PrintMatrix(PriseMatr, NumberOfCities, NumberOfCities);
    
    
    
    for(int index = 0; index < NumberOfCities; index++)
        delete [] PriseMatr[index];
    delete [] PriseMatr;
    
    return 0;
}
