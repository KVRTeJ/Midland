#include <iostream>
#include <vector>
#include <string>

#include "midland++.hpp"

int main() {
    
    std::string string = "babagbabas",
                subString = "bab";
    
    std::vector<int> occurrences;
    
    std::cout << "string = " << string << std::endl;
    std::cout << "subString = " << subString << std::endl;
    
    
    int answer = bmSearch(string, subString);
    std::cout << "First occurrences - " << answer << std::endl;
    
    occurrences = bmSearchAllOccurrences(string, subString);
    std::cout << "All occurrences - ";
    printVector(occurrences);
    
    
    return 0;
}
