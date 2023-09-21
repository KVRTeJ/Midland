#include <iostream>

#include "Fraction.h"

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


Fraction Fraction::sum(const Fraction b) {
    
    Fraction ans;
    ans.m_numerator = m_numerator * b.m_denominator + m_denominator * b.m_numerator;
    ans.m_denominator = m_denominator * b.m_denominator;
    
    return ans;
    
}

Fraction Fraction::minus(const Fraction b) {
    
    Fraction ans;
    
    ans.m_numerator = m_numerator * b.m_denominator - m_denominator * b.m_numerator;
    ans.m_denominator = m_denominator * b.m_denominator;
    
    return ans;
    
}


Fraction Fraction::division(const Fraction b) {
    
    Fraction ans; //= {0, 1};
    
    if(m_denominator * b.m_numerator == 0)
        return ans;
    
    ans.m_numerator = m_numerator * b.m_denominator;
    ans.m_denominator = m_denominator * b.m_numerator;
    
    return ans;
    
}

Fraction Fraction::multiplication(const Fraction b) {
    
    Fraction ans; //= {0, 1};
    
    if(m_denominator * b.m_denominator == 0)
        return ans;
    
    ans.m_numerator = m_numerator * b.m_numerator;
    ans.m_denominator = m_denominator * b.m_denominator;
    
    return ans;
    
}


 void reduce() {
 
 }


int Fraction::getNumerator() {
    
    return m_numerator;
    
}

int Fraction::getDenomirator() {
    
    return m_denominator;
    
}

void Fraction::setNumerator(int value) {
    
    m_numerator = value;
    return;
    
}

void Fraction::setDenomirator(int value) {
    
    m_denominator = value;
    return;
    
}

