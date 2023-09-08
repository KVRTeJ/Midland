//
//  main.cpp
//  #1
//
//  Created by Dmitriy on 04.09.2023.
//

#include <iostream>

#include "Fraction.h"


int main() {
    
    /*int an, ad, bn, bd;
    std::cout << "a numerator - ";
    std::cin >> an;
    std::cout << "a denumerator - ";
    std::cin >> ad;
    
    std::cout << "a = " << an << "/" << ad << std::endl;
    */
    
    Fraction a;
    a.numerator = 1;
    a.denomerator = 2;
    
    Fraction b;
    b.numerator = 1;
    b.denomerator = 2;
    
    
    std::cout << "Sum - ";
    Fraction temp = a.SumFrac(b); //breakpoint - ???
    temp.PrintFrac();
    
    std::cout << "Minus - ";
    temp = a.MinusFrac(b);
    temp.PrintFrac();
    
    std::cout << "Division - ";
    temp = a.DivisionFrac(b);
    temp.PrintFrac();
    //a.PrintFrac(a.DivisionFrac(b)); // <- expected 0 arguments - ???
    
    std::cout << "Multiplication - ";
    temp = a.MultiplicationFrac(b);
    temp.PrintFrac();
    
    return 0;
}
