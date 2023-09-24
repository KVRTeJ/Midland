#include <iostream>
#include <vector>
#include <string>

#include "midland++.hpp"

int main() {
    int start = 0, stop = 91;
    
    std::string string = "std::move_iterator is an iterator adaptor which behaves exactly like the underlying iterator",
                subString = "tor";
    
    std::vector<int> occurrences;
    
    std::cout << "string = " << string << std::endl;
    std::cout << "subString = " << subString << std::endl;
    
    
    int firstOccurrences = bmSearch(string, subString);
    std::cout << "First occurrences - " << firstOccurrences << std::endl;
    
    occurrences = bmSearchAllOccurrences(string, subString);
    std::cout << "All occurrences - ";
    printVector(occurrences);
    
    occurrences = bmSearchOccurrencesInDiapason(string, subString, start, stop);
    std::cout << "Occurrences from " << start << " to " << stop << std::endl;
    printVector(occurrences);
    
    
    return 0;
}
