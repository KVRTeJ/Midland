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
    const int min = 1, max = 9;
    
    //NumberOfCities - кол-во городов, SourceCity - начальный город
    //PriseMatr - матрица стоимости
    //CurrentWay - актуальный путь, MinWay - минимальный путь
    //CurrentWeight - вес актального пути, MinWeight - вес минимального пути
    //Permuration - актуальная перестановка чисел
    int NumberOfCities, SourceCity,** PriseMatr, CurrentWeight, MinWeight,* MinWay,* Permutation, CounterPermutation = 0, next_i;
    unsigned int NumberOfPermutations;

    std::cout << "Кол-во городов - ";
    std::cin >> NumberOfCities;
    std::cout << "Стартовый город - ";
    std::cin >> SourceCity;
    
    MinWeight = max*NumberOfCities;
    MinWay = new int [NumberOfCities+1];
    Permutation = new int [NumberOfCities+1];
    //+1 для возврата в исходный город
    PriseMatr = new int * [NumberOfCities];
    for(int index = 0; index < NumberOfCities; index++) {
        PriseMatr[index] = new int [NumberOfCities];
    }
    
    /*if(NumberOfCities < N)
        MatrixInput(PriseMatr, NumberOfCities, NumberOfCities);
    else
        MatrixRandomCost(PriseMatr, NumberOfCities, NumberOfCities, min, max);
    */
    MatrixRandomCost(PriseMatr, NumberOfCities, NumberOfCities, min, max);
    
    std::cout << "Итоговая матрица стоимости: " << std::endl;
    MatrixPrint(PriseMatr, NumberOfCities, NumberOfCities);
    
    //Алгоритм
    NumberOfPermutations = Factorial(NumberOfCities - 1);
    //std::cout << "NumberOfPermutations - " << NumberOfPermutations << std::endl;
    
    //1 путь с весом
    for(int i = 0; i < NumberOfCities; ) {
        //if 0 - первый город
        //NumberOfCities + 1 - последний
        
        //if i = soursecity
        //i++
        
        //elsepermutation[i] = i
        
    }
    Permutation[NumberOfCities] = SourceCity-1;
    std::cout << "l60 первый город - " << SourceCity << std::endl;
    Swap(Permutation[(SourceCity-1)], Permutation[0]);
    ArrayPrint(Permutation, NumberOfCities+1);
    CurrentWeight = WayWeight(PriseMatr, Permutation, NumberOfCities);
    if(CurrentWeight < MinWeight) {
        MinWeight = CurrentWeight;
        ArrayCopy(Permutation, MinWay, NumberOfCities);
        //std::cout << "MinWeight - " << MinWeight << std::endl;
    }
    CounterPermutation++;
    //ArrayPrint(Permutation, NumberOfCities+1);
    //Первая перестановка - исходная последовательность
    /* ArrayCopy(CurrentWay, MinWay, NumberOfCities);
    std::cout << "Min way" << std::endl;
    ArrayPrint(MinWay, NumberOfCities);
    std::cout << "Current way" << std::endl;
    ArrayPrint(CurrentWay, NumberOfCities);
    std::cout << "Permutation - ";
    ArrayPrint(Permutation, NumberOfCities+1);
    std::cout << "Counter - " << CounterPermutation << std::endl;
    */
    
    //Подробнее комментарии
    
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
                        std::cout << "Перестановка номер - " << CounterPermutation << std::endl;
                        CurrentWeight = WayWeight(PriseMatr, Permutation, NumberOfCities);
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
            /*else {
                std::cout << "Перестановок нет " << std::endl;
                std::cout << "Минимальный путь - ";
                ArrayPrint(MinWay, NumberOfCities+1);
                std::cout << "Минимальный вес пути - " << MinWeight << std::endl;
                return 9;
                
            }*/
        }
    }
    for(int index = 0; index < NumberOfCities; index++)
        delete [] PriseMatr[index];
    delete [] PriseMatr;
    
    //Ответ
    
    std::cout << "Минимальный путь - ";
    ArrayPrint(MinWay, NumberOfCities+1);
    std::cout << "Минимальный вес пути - " << MinWeight << std::endl;
    
    delete [] MinWay;
    
    return 0;
}
