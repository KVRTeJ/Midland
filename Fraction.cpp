//
//  Fraction.cpp
//  #1
//
//  Created by Dmitriy on 04.09.2023.
//
#include <iostream>

#include "Fraction.h"

void Fraction::PrintFrac() {
    std::cout << numerator << '/' << denomerator << std::endl;
}

Fraction Fraction::SumFrac(const Fraction b) {
    Fraction ans;
    ans.numerator = numerator * b.denomerator + denomerator * b.numerator;
    ans.denomerator = denomerator * b.denomerator;
    return ans;
}

Fraction Fraction::deMultiplication(const Fraction b) {
    if(denomerator*b.numerator == 0)
        exit(-1);
    Fraction ans;
    ans.numerator = numerator * b.denomerator;
    ans.denomerator = denomerator * b.numerator;
    return ans;
}
