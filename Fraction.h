//
//  Fruction.h
//  #1
//
//  Created by Dmitriy on 04.09.2023.
//

#pragma once

class Fraction {
    public:
    void PrintFrac();
    Fraction SumFrac(const Fraction b);
    Fraction MinusFrac(const Fraction b);
    Fraction DivisionFrac(const Fraction b);
    Fraction MultiplicationFrac(const Fraction b);
    
    int numerator;
    int denomerator;
};


