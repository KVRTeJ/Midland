#include "midland++.hpp"

unsigned int greatestCommonDivisor(unsigned int a, unsigned int b) {
    
    if (a % b == 0)
        return b;
    
    if (b % a == 0)
        return a;
    
    if (a > b)
        return greatestCommonDivisor(a % b, b);
    
    return greatestCommonDivisor(a, b % a);
    
}
