#pragma once

class Fraction {
    
public:
    
    //расставить const там где this не меняется
    
    Fraction() = default;
    Fraction(const int numerator, const int denomerator);
    ~Fraction() = default;
    
    void print() const;
    
    Fraction sum(const Fraction b);
    Fraction minus(const Fraction b);
    Fraction division(const Fraction b);
    Fraction multiplication(const Fraction b);
    
    int getNumerator() const;
    int getDenomirator() const;
    
    void setNumerator(const int value);
    void setDenomirator(const int value);
    
    bool operator == (const Fraction other);
    bool operator != (const Fraction other);
    bool operator < (const Fraction other);
    bool operator > (const Fraction other);
    
    Fraction operator + (const Fraction other);
    Fraction operator - (const Fraction other);
    Fraction operator * (const Fraction other);
    Fraction operator / (const Fraction other);
    
    //Fraction operator ++ //свой метод
    
    void reduce(); //сокращение дроби
    
private:
    
    int m_numerator = 1; //Вторая очередь инициализации
    int m_denominator = 1; //Вторая очередь инициализации
    
};


