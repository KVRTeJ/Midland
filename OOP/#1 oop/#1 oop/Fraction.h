#pragma once

class Fraction {
    
public:
    
    Fraction() = default;
    Fraction(const int numerator, const int denomerator);
    ~Fraction() = default;
    
    void print() const;
    void scan();
    
    Fraction sum(const Fraction b) const;
    Fraction minus(const Fraction b) const;
    Fraction division(const Fraction b) const;
    Fraction multiplication(const Fraction b) const;
    
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
    
    void reduce();
    
    //Свои методы
    
    Fraction operator -- (int);
    Fraction & operator ++ ();
    Fraction operator ++ (int);
    Fraction & operator -- ();
    
private:
    
    int m_numerator = 1; //Вторая очередь инициализации
    int m_denominator = 1; //Вторая очередь инициализации
    
};


