#include <iostream>
#include <string>

#include "midland++.hpp"

int bmSearch(std::string string, std::string subString) {
    
    int sizeString = (int) string.size(), //размер строки
        sizeSubString = (int) subString.size(), //размер подстроки
        tab[256] = {0}; //таблица символов
    
    
    //Генерируем таблицу
    for(int i = 0; i < sizeSubString - 1; i++) {
        
        tab[subString[i]] = sizeSubString - 1 - i;
        
    }
    
    for(int i = 0; i < 256; i++) {
        
        if(!(tab[i])) {
            
            tab[i] = sizeSubString;
            
        }
        
    }
    
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
    
    
    
    return 0;
}
