#include <iostream>
#include <vector>
#include <string>

#include "midland++.hpp"

int main() {
    
    const int N = 256;
    
    std::vector <int> occurrences; //вхождения
    
    
    std::string string = "Hello world!",
    subString = "";
    
    int sizeString = (int) string.size(), //размер строки
    sizeSubString = (int) subString.size(), //размер подстроки
    tab[N] = {0}; //таблица символов
    
    //Формируем таблицу
    
    for(int i = 0; i < sizeSubString - 1; i++) {
        
        tab[subString[i]] = sizeSubString - 1 - i;
        
    }
    
    for(int i = 0; i < N; i++) {
        
        if(!(tab[i])) {
            
            tab[i] = sizeSubString;
            
        }
        
    }
    
    /*
     for(int i = 0; i < sizeSubString; i++) {
     
     std::cout << subString[i] << " = " << tab[subString[i]] << std::endl;
     
     }
     */
    
    std::cout << "string = " << string << std::endl;
    std::cout << "subString = " << subString << std::endl;
        
    int temp = 0;
    int i = sizeSubString - 1;
    int j = sizeSubString - 1;
    int k = 0;
    
    while(temp <= sizeString - sizeSubString) {
        
        if(i < sizeString) {
            
            if(j >= 0) {
                
                k = i;
                j = sizeSubString - 1;
                
                if(j >= 0) {
                    
                    if(string[k] == subString[j]) {
                        
                        k--;
                        j--;
                        
                    }
                    
                    else {
                        
                        temp = temp + tab[string[i]];
                        i += tab[string[i]];
                        j = sizeSubString - 1;
                        
                    }
                    
                }
                
            }
            
        }
        
        else if(j >= 0) {
            
            return -1;
            
        }
        
        else {
            
            return i + 1 - sizeSubString;
            
        }
        
    }
    
    std::cout << "i = " << i << std::endl;
    std::cout << "j = " << j << std::endl;
    std::cout << "k = " << k << std::endl;
    
    return 0;
}
