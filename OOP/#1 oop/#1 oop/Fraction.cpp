#include <iostream>

#include "Fraction.h"


unsigned int calculateGreatestCommonDivisor(const unsigned int a,
                                            const unsigned int b) {
    
    if (a % b == 0)
        return b;
    
     if (b % a == 0)
        return a;
    
    if (a > b)
        return calculateGreatestCommonDivisor(a % b, b);
    
    return calculateGreatestCommonDivisor(a, b % a);
    
}

Fraction::Fraction(const int numerator, const int denomerator) {
    
    this -> m_numerator = numerator;
    
    if(denomerator != 0) {
        
        this -> m_denominator = denomerator;
        
    }
    
    else {
        
        std::cerr << "Fraction::Fraction - Ошибка: denominator = 0" << std::endl;
        std::cerr << "denominator исправлен на 1" << std::endl;
        this -> m_denominator = 1;
        
    }
    
}

void Fraction::print() const {
    
    std::cout << m_numerator << "/" << m_denominator << std::endl;
    
}

void Fraction::scan() {
    
    std::cout << "Введите числитель - ";
    std::cin >> m_numerator;
    
    std::cout << "Введите знаменатель - ";
    std::cin >> m_denominator;
    
    while(m_denominator == 0) {
        
        std::cout << "Введите знаменатель - ";
        std::cin >> m_denominator;
        
    }
    
}


Fraction Fraction::sum(const Fraction b) const {
    
    Fraction ans;
    ans.m_numerator = m_numerator * b.m_denominator + m_denominator * b.m_numerator;
    ans.m_denominator = m_denominator * b.m_denominator;
    
    return ans;
    
}

Fraction Fraction::minus(const Fraction b) const {
    
    Fraction ans;
    
    ans.m_numerator = m_numerator * b.m_denominator - m_denominator * b.m_numerator;
    ans.m_denominator = m_denominator * b.m_denominator;
    
    return ans;
    
}


Fraction Fraction::division(const Fraction b) const {
    
    Fraction ans;
    
    if(m_denominator * b.m_numerator == 0)
        return ans;
    
    ans.m_numerator = m_numerator * b.m_denominator;
    ans.m_denominator = m_denominator * b.m_numerator;
    
    return ans;
    
}

Fraction Fraction::multiplication(const Fraction b) const {
    
    Fraction ans; //= {0, 1};
    
    if(m_denominator * b.m_denominator == 0)
        return ans;
    
    ans.m_numerator = m_numerator * b.m_numerator;
    ans.m_denominator = m_denominator * b.m_denominator;
    
    return ans;
    
}

int Fraction::getNumerator() const {
    
    return m_numerator;
    
}

int Fraction::getDenomirator() const {
    
    return m_denominator;
    
}

void Fraction::setNumerator(const int value) {
    
    m_numerator = value;
    return;
    
}

void Fraction::setDenomirator(const int value) {
    
    m_denominator = value;
    return;
    
}

bool Fraction::operator == (const Fraction other) {
    
    return ((m_numerator == other.m_numerator) && (m_denominator == other.m_denominator));
    
}

bool Fraction::operator != (const Fraction other) {
    
    return ( !(operator == (other) ) );
    
}

bool Fraction::operator < (const Fraction other) {
    
    return ( (m_numerator * other.m_denominator) <
            (other.m_numerator * m_denominator) );
    
}

bool Fraction::operator > (const Fraction other) {
    
    return ( !(operator < (other) ) ) ;
    
}

Fraction Fraction::operator + (const Fraction other) {
    
    return sum(other);
    
}


Fraction Fraction::operator - (const Fraction other) {
 
 return minus(other);
    
}


Fraction Fraction::operator * (const Fraction other) {
    
    return multiplication(other);
    
}


Fraction Fraction::operator / (const Fraction other) {
    
    return division(other);
    
}


void Fraction::reduce() {
    
    int greatestCommonDivisor = calculateGreatestCommonDivisor(m_numerator, m_denominator);
    
    m_numerator /= greatestCommonDivisor;
    m_denominator /= greatestCommonDivisor;
    
    return;
    
}
