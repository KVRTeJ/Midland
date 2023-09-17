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
    //min, max - диапазон чисел для случайного заполнения матрицы
    
    const int min = 1, max = 9;
    
    int numberOfCities, SourceCity,** PriseMatr, CurrentWeight, MinWeight,* MinWay,* Permutation, CounterPermutation = 0;
    
    unsigned int NumberOfPermutations;

    std::cout << "Кол-во городов - ";
    std::cin >> numberOfCities;
    std::cout << "Стартовый город - ";
    std::cin >> SourceCity;
    
    MinWeight = max * numberOfCities;
    
    MinWay = new int [numberOfCities + 1];
    Permutation = new int [numberOfCities + 1]; //+1 для возврата в исходный город
    PriseMatr = new int * [numberOfCities];
    for(int index = 0; index < numberOfCities; index++) {
        PriseMatr[index] = new int [numberOfCities];
    }
    
    //Заполнение матрицы
    MatrixRandomCost(PriseMatr, numberOfCities, numberOfCities, min, max);
    //MatrixInput(PriseMatr, NumberOfCities, NumberOfCities);
    
    
    std::cout << "Итоговая матрица стоимости: " << std::endl;
    MatrixPrint(PriseMatr, numberOfCities, numberOfCities);
    
    NumberOfPermutations = Factorial(numberOfCities - 1);
    
    //Генерируем первый путь, учитывая, что начальный город - конечный
    for(int i = 0, k = 0; i < numberOfCities; ) {
        
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
    
    Permutation[numberOfCities] = SourceCity - 1;
    
    CurrentWeight = WayWeight(PriseMatr, Permutation, numberOfCities);
    CounterPermutation++; //Первая перестановка сгенерирована, прибавляем счетчик
    
    std::cout << "Перестановка номер - " << CounterPermutation << std::endl;
    CurrentWeight = WayWeight(PriseMatr, Permutation, numberOfCities);
    std::cout << "Вес - " << CurrentWeight << std::endl;
    std::cout << "Путь - ";
    ArrayPrint(Permutation, numberOfCities + 1);
    
    while(NumberOfPermutations != CounterPermutation) {//Пока счетчик != кол-ву перестановок
        for(int i = numberOfCities - 2; i >= 1; i--) {
            //-1 по алгоритму и -1 потому что исходный город не трогаем
            if((0 < i) && (i < (numberOfCities - 1)) && (Permutation[i] < Permutation[i + 1])) {
                //Пока 0 < i < n and P[i] < P[i+1] по алгоритму
                for(int j = (numberOfCities-1); j > i; j--) { // j  на последний элемент
                    if((i < j) && (j <= (numberOfCities - 1) ) && (Permutation[i] < Permutation[j])) {
                        //Eсли i < j <= n and P[i] < P[j] по алгоритму
                        Swap(Permutation[i], Permutation[j]);
                        for(int i_tail = i + 1, j_tail = (numberOfCities - 1); i_tail <= j_tail; i_tail++, j_tail--)
                            Swap(Permutation[i_tail], Permutation[j_tail]);//Инвертируем хвост
                        CounterPermutation++; //Сделана перестановка - счетчик +1
                        
                        i = numberOfCities-1;
                        //Возвращаем i на исходное место
                        
                        //Вес и минимальный маршрут
                        
                        CurrentWeight = WayWeight(PriseMatr, Permutation, numberOfCities);
                        //Текущий вес маршрута
                        
                        std::cout << "Перестановка номер - " << CounterPermutation << std::endl;
                        std::cout << "Вес - " << CurrentWeight << std::endl;
                        std::cout << "Путь - ";
                        ArrayPrint(Permutation, numberOfCities+1);
                        
                        if(CurrentWeight < MinWeight) {
                            MinWeight = CurrentWeight;
                            ArrayCopy(Permutation, MinWay, numberOfCities+1);
                        //Если текущий вес < минимального - он минимальный
                        }
                    }
                }
            }
        }
    }
    
    
    //Ответ
    
    std::cout << "Минимальный путь - ";
    ArrayPrint(MinWay, numberOfCities+1);
    std::cout << "Минимальный вес пути - " << MinWeight << std::endl;
    
    for(int index = 0; index < numberOfCities; index++)
        delete [] PriseMatr[index];
    delete [] PriseMatr;
    delete [] MinWay;
    
    return 0;
}
