#include <iostream>
#include <vector>
#include <string>

#include "midland++.hpp"

int main() {
    
    std::string string = "abbagbsds",
                subString = "ba";
    
    std::vector<int> occurrences;
    
    std::cout << "string = " << string << std::endl;
    std::cout << "subString = " << subString << std::endl;
    
    
    int answer = bmSearch(string, subString);
    std::cout << "first - " << answer << std::endl;
    
    std::cout << "-=-=-=-=-=-=-=-=-" << std::endl;
    
    occurrences = bmSearchAllOccurrences(string, subString);
    
    printVector(occurrences);
    
    
    return 0;
}
