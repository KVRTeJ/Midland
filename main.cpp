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
    
    Fraction s = a.SumFrac(b);
    s.PrintFrac();
    
    s = a.deMultiplication(b);
    s.PrintFrac();

    return 0;
}
