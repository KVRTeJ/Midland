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
    int NumberOfCities, SourceCity, **PriseMatr, CurrentWeight, *CurrentWay, MinWeight, *MinWay, *Permutation, CounterPermutation = 0;
    unsigned int NumberOfPermutations;

    std::cout << "Кол-во городов - ";
    std::cin >> NumberOfCities;
    std::cout << "Стартовый город - ";
    std::cin >> SourceCity;
    
    CurrentWay = new int [NumberOfCities];
    MinWay = new int [NumberOfCities];
    Permutation = new int [NumberOfCities+1];
    //+1 для возврата в исходный город
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
    
    CounterPermutation++;
    
    //Подробнее комментарии
    while (NumberOfPermutations != CounterPermutation) {//пока не счетчик не = кол-ву (n-1)! перестановок
        for(int i = NumberOfCities - 2; i >= 1; i--) {
            //-1 потому что алгоритм + -1 потому что исходный не трогаем
            int next_i = i + 1;
            // в самой программе меняет i -> ошибка
            if ((i < (NumberOfCities - 1)) && (Permutation[i] < Permutation[next_i])) {
                //пока i < n последнего элемента and P[i] < P[i+1] по алгоритму
                for(int j = (NumberOfCities-1); j > i; j--) { // j  на последний элемент
                    if(( j <= (NumberOfCities - 1) ) && (Permutation[i] < Permutation[j])) {
                        Swap(Permutation[i], Permutation[j]); //если j <= n and P[i] < P[j] по алгоритму
                        for(int i_tail = i + 1, j_tail = (NumberOfCities - 1); i_tail <= j_tail; i_tail++, j_tail--)
                            Swap(Permutation[i_tail], Permutation[j_tail]);// инвертируем хвост по алгоритму
                        CounterPermutation++;//счетчик
                        std::cout << "Перестановка номер: " <<//мусор
                        CounterPermutation << std::endl;//мусор
                        std::cout << NumberOfPermutations << std::endl;//мусор

                        ArrayPrint(Permutation, NumberOfCities+1);//мусор
                        i = NumberOfCities-1;
                        std::cout << "last i = " << i << std::endl;//мусор
                        
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
