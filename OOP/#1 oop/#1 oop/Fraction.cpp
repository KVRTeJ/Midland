//
//  Fraction.cpp
//  #1
//
//  Created by Dmitriy on 04.09.2023.
//
#include <iostream>

#include "Fraction.h"

Fraction::Fraction()
{
    numerator = 1;
    denomerator = 1;
}

Fraction::Fraction(int numerator, int denomerator) {// нельзя переименовывать
    //
}

void Fraction::PrintFrac() {
    std::cout << numerator << "/" << denomerator << std::endl;
}

Fraction Fraction::SumFrac(const Fraction b) {
    Fraction ans;
    ans.numerator = numerator * b.denomerator + denomerator * b.numerator;
    ans.denomerator = denomerator * b.denomerator;
    return ans;
}

Fraction Fraction::MinusFrac(const Fraction b) {
    Fraction ans;
    ans.numerator = numerator * b.denomerator - denomerator * b.numerator;
    ans.denomerator = denomerator * b.denomerator;
    return ans;
}


Fraction Fraction::DivisionFrac(const Fraction b) {
    Fraction ans; //= {0, 1};
    if(denomerator * b.numerator == 0)
        return ans;
    ans.numerator = numerator * b.denomerator;
    ans.denomerator = denomerator * b.numerator;
    return ans;
}

Fraction Fraction::MultiplicationFrac(const Fraction b) {
    Fraction ans;//= {0, 1};
    if(denomerator * b.denomerator == 0)
        return ans;
    ans.numerator = numerator * b.numerator;
    ans.denomerator = denomerator * b.denomerator;
    return ans;
}

