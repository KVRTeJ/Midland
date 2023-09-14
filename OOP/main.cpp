//
//  main.cpp
//  #1
//
//  Created by Dmitriy on 04.09.2023.
//

#include <iostream>

#include "Fraction.h"


int main() {
    
    Fraction a;
    a.numerator = 1;
    a.denomerator = 3;
    
    Fraction b;
    b.numerator = 1;
    b.denomerator = 2;
    
    
    std::cout << "Sum - ";
    Fraction temp = a.SumFrac(b);
    temp.PrintFrac();
    
    std::cout << "Minus - ";
    temp = a.MinusFrac(b);
    temp.PrintFrac();
    
    std::cout << "Division - ";
    temp = a.DivisionFrac(b);
    temp.PrintFrac();
    
    std::cout << "Multiplication - ";
    temp = a.MultiplicationFrac(b);
    temp.PrintFrac();
    
    return 0;
}
