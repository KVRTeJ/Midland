#include <iostream>
#include <vector>
#include <string>

#include "midland++.hpp"

int main() {
    //для проверки 3 функции bmSearchOccurrencesInDiapason
    const int start = 0, stop = 92,
              start1 = 17, stop1 = 92,
              start2 = 28, stop2 = 36;
    
    const std::string string = "std::move_iterator is an iterator adaptor which behaves exactly like the underlying iterator",
                subString = "tor";
    
    std::vector<int> occurrences;
    
    std::cout << "string = " << string << std::endl;
    std::cout << "subString = " << subString << std::endl;
    
    std::cout << std::endl;
    
    int firstOccurrences = bmSearch(string, subString);
    std::cout << "1) First occurrences - " << firstOccurrences << std::endl;
    
    std::cout << std::endl;
    
    occurrences = bmSearchAllOccurrences(string, subString);
    std::cout << "2) All occurrences - ";
    printVector(occurrences);
    
    std::cout << std::endl;
    
    occurrences = bmSearchOccurrencesInDiapason(string, subString, start, stop);
    std::cout << "3) Occurrences in diapason [" << start << ", " << stop << "] - ";
    printVector(occurrences);
    
    occurrences = bmSearchOccurrencesInDiapason(string, subString, start1, stop1);
    std::cout << "   Occurrences in diapason [" << start1 << ", " << stop1 << "] - ";
    printVector(occurrences);
    
    occurrences = bmSearchOccurrencesInDiapason(string, subString, start2, stop2);
    std::cout << "   Occurrences in diapason [" << start2 << ", " << stop2 << "] - ";
    printVector(occurrences);
    
    std::cout << std::endl;
    
    return 0;
}
