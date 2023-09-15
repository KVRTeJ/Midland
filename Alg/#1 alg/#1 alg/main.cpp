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
    //Permuration - актуальная перестановка чисел
    int NumberOfCities, SourceCity, **PriseMatr, CurrentWeight, *CurrentWay, MinWeight, *MinWay, *Permutation, CounterPermutation = 1;
    unsigned int NumberOfPermutations;

    std::cout << "Кол-во городов - ";
    std::cin >> NumberOfCities;
    std::cout << "Стартовый город - ";
    std::cin >> SourceCity;
    
    CurrentWay = new int [NumberOfCities];
    MinWay = new int [NumberOfCities];
    Permutation = new int [NumberOfCities+1];
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
    
    for(int index = 0; index < NumberOfCities; index++) {
        MinWay[index] = max;
        Permutation[index] = index;
    }
    
    //Алгоритм
    Permutation[-1] = SourceCity;
    NumberOfPermutations = Factorial(NumberOfCities - 1);
    std::cout << "NumberOfPermutations - " << NumberOfPermutations << std::endl;
    
    //1 путь с весом
    
    while (NumberOfPermutations != CounterPermutation) {
        for(int i = NumberOfCities - 2; i >= 1; i--) {
            int next_index = i+1;
            if ((i < (NumberOfCities-1))&&(Permutation[i] < Permutation[next_index])) {
                for(int j = (NumberOfCities-1); j > i; j--) {
                    if(( j <= (NumberOfCities - 1) ) && (Permutation[i] < Permutation[j])) {
                        Swap(Permutation[i], Permutation[j]);
                        for(int i_tail = i + 1, j_tail = (NumberOfCities - 1); i_tail <= j_tail; i_tail++, j_tail--)
                            Swap(Permutation[i_tail], Permutation[j_tail]);
                        CounterPermutation++;
                        std::cout << "Перестановка номер: " <<
                        CounterPermutation << std::endl;
                        std::cout << NumberOfPermutations << std::endl;

                        ArrayPrint(Permutation, NumberOfCities+1);
                        i = NumberOfCities-1;
                        std::cout << "last i = " << i << std::endl;
                        
                        //Вес и минимальный маршрут
                    }
                }
            }
        }
    }
    for(int index = 0; index < NumberOfCities; index++)
        delete [] PriseMatr[index];
    delete [] PriseMatr;
    delete [] CurrentWay;
    
    //Ответ
    
    ArrayPrint(MinWay, NumberOfCities);
    
    delete [] MinWay;
    
    return 0;
}
