#include <iostream>
#include <vector>
#include <string>
#include <time.h>

#include "midland++.hpp"

int main() {
    //для проверки 3 функции bmSearchOccurrencesInDiapason
    const int start = 0, stop = 91,
              start1 = 17, stop1 = 91,
              start2 = 28, stop2 = 36;
    
    const std::string string = "std::move_iterator is an iterator adaptor which behaves exactly like the underlying iterator",
                      subString = "tor";
    
    std::vector<int> occurrences;
    
    std::cout << std::endl;
    
    occurrences.push_back(bmSearch(string, subString));
    std::cout << "1) First occurrences - ";
    printVector(occurrences);
    
    std::cout << std::endl;
    
    occurrences = bmSearchAllOccurrences(string, subString);
    std::cout << "2) All occurrences - ";
    printVector(occurrences);
    
    std::cout << std::endl;
    
    
    occurrences = bmSearchOccurrencesInRange(string, subString, start, stop);
    std::cout << "3) Occurrences in diapason [" << start << ", " << stop << "] - ";
    printVector(occurrences);
    
    occurrences = bmSearchOccurrencesInRange(string, subString, start1, stop1);
    std::cout << "   Occurrences in diapason [" << start1 << ", " << stop1 << "] - ";
    printVector(occurrences);
    
    occurrences = bmSearchOccurrencesInRange(string, subString, start2, stop2);
    std::cout << "   Occurrences in diapason [" << start2 << ", " << stop2 << "] - ";
    printVector(occurrences);
    
    std::cout << std::endl;
    
    return 0;
    
}
