#include <iostream>
#include <vector>
#include <string>

#include "midland++.hpp"

int main() {
    
    const int N = 256;
    
    std::vector <int> occurrences; //вхождения
    
    
    std::string string = "Hello world!",
                subString = "world";

    getline(std::cin, string);
    
    int sizeString = (int) string.size(), //размер строки
        sizeSubString = (int) subString.size(), //размер подстроки
        tab[N]; //таблица символов
    
    for(int i = 0; i < sizeSubString - 1; i++) {
        
        tab[subString[i]] = sizeSubString - 1 - i;
        
    }
    
    printArray(tab, N);
    
    std::cout << "size s = " << sizeString << std::endl;
    std::cout << string << std::endl;
    
    
    
    
    //for(int i = 0; i < sizeSubString - 1; i++) {
        
        
        
   // }
    
    
    return 0;
}
