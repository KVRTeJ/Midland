#include <iostream>
#include <vector>
#include <string>

#include "midland++.hpp"

int main() {
    
    
    std::vector <int> occurrences; //вхождения
    
    std::string string = "abbagbsds",
                subString = "gbs";
    
    std::cout << "string = " << string << std::endl;
    std::cout << "subString = " << subString << std::endl;
        
    int ans = bmSearch(string, subString);

    std::cout << "ans - " << ans << std::endl;
    
    return 0;
}
