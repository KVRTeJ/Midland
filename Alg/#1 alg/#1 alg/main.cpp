#include <iostream>

#include "midland++.hpp"

int main() {
    
    //numberOfCities - кол-во городов, SourceCity - начальный город
    //priseMatr - матрица стоимости
    //currentWay - актуальный путь, MinWay - минимальный путь
    //currentWeight - вес актального пути, MinWeight - вес минимального пути
    //permuration - актуальная перестановка чисел
    //MIN, MAX - диапазон чисел для случайного заполнения матрицы
    
    const int MIN = 1, MAX = 9;
    
    int numberOfCities, sourceCity,** priseMatr, currentWeight, minWeight,
    * minWay,* permutation, counterPermutation = 0;
    
    std::cout << "Кол-во городов - ";
    std::cin >> numberOfCities;
    std::cout << "Стартовый город - ";
    std::cin >> sourceCity;
    
    minWeight = MAX * numberOfCities;
    
    minWay = new int [numberOfCities + 1];
    permutation = new int [numberOfCities + 1]; //+1 для возврата в исходный город
    priseMatr = new int * [numberOfCities];
    for(int index = 0; index < numberOfCities; index++) {
        priseMatr[index] = new int [numberOfCities];
    }
    
    //Заполнение матрицы
    getRandomCostMatrix(priseMatr, numberOfCities, numberOfCities, MIN, MAX);
    //inputMatrix(PriseMatr, NumberOfCities, NumberOfCities);
    
    
    std::cout << "Итоговая матрица стоимости: " << std::endl;
    printMatrix(priseMatr, numberOfCities, numberOfCities);
    
    //Генерируем первый путь, учитывая, что начальный город - конечный
    for(int i = 0, j = 0; i < numberOfCities; ) {
        
        if(i == 0) {
            permutation[i] = sourceCity - 1;
            i++;
        }
        
        else if(j == sourceCity - 1) {
            j++;
        }
        
        else {
            permutation[i] = j;
            j++;
            i++;
        }
        
    }
    
    permutation[numberOfCities] = sourceCity - 1;
    
    currentWeight = calculateWayWeight(priseMatr, permutation, numberOfCities);
    counterPermutation++;
    //Первая перестановка сгенерирована, прибавляем счетчик
    
    std::cout << "Перестановка номер - " << counterPermutation << std::endl;
    currentWeight = calculateWayWeight(priseMatr, permutation, numberOfCities);
    std::cout << "Вес - " << currentWeight << std::endl;
    std::cout << "Путь - ";
    printArray(permutation, numberOfCities + 1);
    
    for(int i = numberOfCities - 2; i >= 1; i--) {
        //-1 по алгоритму и -1 потому что исходный город не трогаем
        
        if((0 < i) && (i < (numberOfCities - 1)) && (permutation[i] < permutation[i + 1])) {
            //Пока 0 < i < n and P[i] < P[i+1] по алгоритму
            
            for(int j = (numberOfCities-1); j > i; j--) {
                // j  на последний элемент
                
                if((i < j) && (j <= (numberOfCities - 1) ) && (permutation[i] < permutation[j])) {
                    //Eсли i < j <= n and P[i] < P[j] по алгоритму
                    
                    swapNumbers(permutation[i], permutation[j]);
                    for(int i_tail = i + 1, j_tail = (numberOfCities - 1);
                        i_tail <= j_tail; i_tail++, j_tail--)
                        swapNumbers(permutation[i_tail], permutation[j_tail]);//Инвертируем хвост
                    
                    counterPermutation++; //Сделана перестановка - счетчик +1
                    
                    i = numberOfCities-1;
                    //Возвращаем i на исходное место
                    
                    currentWeight = calculateWayWeight(priseMatr, permutation, numberOfCities);
                    //Текущий вес маршрута
                    
                    std::cout << "Перестановка номер - " << counterPermutation << std::endl;
                    std::cout << "Вес - " << currentWeight << std::endl;
                    std::cout << "Путь - ";
                    printArray(permutation, numberOfCities+1);
                    
                    if(currentWeight < minWeight) {
                        minWeight = currentWeight;
                        createArrayCopy(permutation, minWay, numberOfCities+1);
                        //Если текущий вес < минимального - он минимальный
                    }
                }
            }
        }
    }
    
    
    //Ответ
    
    std::cout << "Минимальный путь - ";
    printArray(minWay, numberOfCities+1);
    std::cout << "Минимальный вес пути - " << minWeight << std::endl;
    
    for(int index = 0; index < numberOfCities; index++)
        delete [] priseMatr[index];
    delete [] priseMatr;
    delete [] minWay;
    
    return 0;
}
