#pragma once

class Fraction {
    
public:
    
    Fraction() = default;
    Fraction(int numerator, int denomerator);
    ~Fraction() = default;
    
    void print() const;
    
    Fraction sum(const Fraction b);
    Fraction minus(const Fraction b);
    Fraction division(const Fraction b);
    Fraction multiplication(const Fraction b);
    
    void reduce(); //сокращение дроби
    
    int getNumerator();
    int getDenomirator();
    
    void setNumerator(int value);
    void setDenomirator(int value);
    
private:
    
    int m_numerator = 1; //Вторая очередь инициализации
    int m_denominator = 1; //Вторая очередь инициализации
    
private:
    
    int m_test;
    
};


