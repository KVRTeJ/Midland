//
//  main.cpp
//  #1 alg
//
//  Created by Dmitriy on 14.09.2023.
//

//#1 Задача Комивояджера

#include <iostream>

void PrintMatr(int(&a)[5][5], int c, int b)
{
    for(int i = 0; i < c; i++) {
        for(int j = 0; j < b; j++)
            std::cout << a[i][j];
        std::cout << std::endl;
    }
}

int main() {
    
    //numberCities - кол-во городов, startCity - начальный город
    //priseMatr - матрица стоимости
    int NumberOfCities, StartingCity, **PriseMatr;

    std::cout << "Кол-во городов - ";
    std::cin >> NumberOfCities;
    std::cout << "Стартовый город - ";
    std::cin >> StartingCity;
    
    **priseMatr = new int*[NumberOfCities*NumberOfCities];
    
    return 0;
}
