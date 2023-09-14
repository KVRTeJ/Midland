#pragma once

class Fraction {
    
public:
    Fraction();
    Fraction(int numerator, int denomerator);
    ~Fraction() = default;
    void PrintFrac();
    Fraction SumFrac(const Fraction b);
    Fraction MinusFrac(const Fraction b);
    Fraction DivisionFrac(const Fraction b);
    Fraction MultiplicationFrac(const Fraction b);
    
public:
    int numerator;
    int denomerator;
};


