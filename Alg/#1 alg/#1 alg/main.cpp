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
    
    //NumberOfCities - кол-во городов, SourceCity - начальный город
    //PriseMatr - матрица стоимости
    //CurrentWay - актуальный путь, MinWay - минимальный путь
    //CurrentWeight - вес актального пути, MinWeight - вес минимального пути
    //Permuration - актуальная перестановка чисел
    
    const int min = 1, max = 9;
    
    int NumberOfCities, SourceCity,** PriseMatr, CurrentWeight, MinWeight,* MinWay,* Permutation, CounterPermutation = 0, next_i;
    
    unsigned int NumberOfPermutations;

    std::cout << "Кол-во городов - ";
    std::cin >> NumberOfCities;
    std::cout << "Стартовый город - ";
    std::cin >> SourceCity;
    
    MinWeight = max * NumberOfCities;
    
    MinWay = new int [NumberOfCities + 1];
    Permutation = new int [NumberOfCities + 1];
    //+1 для возврата в исходный город
    PriseMatr = new int * [NumberOfCities];
    for(int index = 0; index < NumberOfCities; index++) {
        PriseMatr[index] = new int [NumberOfCities];
    }
    
    //MatrixInput(PriseMatr, NumberOfCities, NumberOfCities);
    MatrixRandomCost(PriseMatr, NumberOfCities, NumberOfCities, min, max);
    
    
    std::cout << "Итоговая матрица стоимости: " << std::endl;
    MatrixPrint(PriseMatr, NumberOfCities, NumberOfCities);
    
    NumberOfPermutations = Factorial(NumberOfCities - 1);
    
    //первый путь с весом
    for(int i = 0, k = 0; i < NumberOfCities; ) {
        
        if(i == 0) {
            Permutation[i] = SourceCity - 1;
            i++;
            
        }
        
        else if(k == SourceCity - 1) {
            k++;
        }
        
        else {
            Permutation[i] = k;
            
            k++;
            i++;
        }
        
    }
    
    Permutation[NumberOfCities] = SourceCity - 1;
    
    ArrayPrint(Permutation, NumberOfCities+1);
    CurrentWeight = WayWeight(PriseMatr, Permutation, NumberOfCities);
    if(CurrentWeight < MinWeight) {
        MinWeight = CurrentWeight;
        ArrayCopy(Permutation, MinWay, NumberOfCities);
    }
    
    CounterPermutation++;
    std::cout << "Перестановка номер - " << CounterPermutation << std::endl;
    CurrentWeight = WayWeight(PriseMatr, Permutation, NumberOfCities);
    std::cout << "Вес - " << CurrentWeight << std::endl;
    std::cout << "Путь - ";
    ArrayPrint(Permutation, NumberOfCities + 1);
    
    while(NumberOfPermutations != CounterPermutation) {//пока не счетчик не = кол-ву (n-1)! перестановок
        for(int i = NumberOfCities - 2; i >= 1; i--) {
            //-1 потому что алгоритм + -1 потому что исходный не трогаем
            next_i = i + 1;
            // в самой программе меняет i -> ошибка
            if((0 < i) && (i < (NumberOfCities - 1)) && (Permutation[i] < Permutation[next_i])) {
                //пока i < n последнего элемента and P[i] < P[i+1] по алгоритму
                for(int j = (NumberOfCities-1); j > i; j--) { // j  на последний элемент
                    if((i < j) && (j <= (NumberOfCities - 1) ) && (Permutation[i] < Permutation[j])) {
                        Swap(Permutation[i], Permutation[j]); //если j <= n and P[i] < P[j] по алгоритму
                        for(int i_tail = i + 1, j_tail = (NumberOfCities - 1); i_tail <= j_tail; i_tail++, j_tail--)
                            Swap(Permutation[i_tail], Permutation[j_tail]);// инвертируем хвост по алгоритму
                        CounterPermutation++;//счетчик
                        //std::cout << "Перестановка номер: " <<//мусор
                       // CounterPermutation << std::endl;//мусор
                        //std::cout << NumberOfPermutations << std::endl;//мусор

                       // ArrayPrint(Permutation, NumberOfCities+1);//мусор
                        i = NumberOfCities-1;
                        //std::cout << "last i = " << i << std::endl;//мусор
                        
                        //Вес и минимальный маршрут
                        
                        CurrentWeight = WayWeight(PriseMatr, Permutation, NumberOfCities);
                        
                        std::cout << "Перестановка номер - " << CounterPermutation << std::endl;
                        std::cout << "Вес - " << CurrentWeight << std::endl;
                        std::cout << "Путь - ";
                        ArrayPrint(Permutation, NumberOfCities+1);
                        
                        if(CurrentWeight < MinWeight) {
                            MinWeight = CurrentWeight;
                            ArrayCopy(Permutation, MinWay, NumberOfCities+1);
                        }
                    }
                }
            }
        }
    }
    
    
    //Ответ
    
    std::cout << "Минимальный путь - ";
    ArrayPrint(MinWay, NumberOfCities+1);
    std::cout << "Минимальный вес пути - " << MinWeight << std::endl;
    
    for(int index = 0; index < NumberOfCities; index++)
        delete [] PriseMatr[index];
    delete [] PriseMatr;
    delete [] MinWay;
    
    return 0;
}
