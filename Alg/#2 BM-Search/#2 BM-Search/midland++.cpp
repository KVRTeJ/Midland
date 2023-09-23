#include <iostream>
#include <string>
#include <vector>

#include "midland++.hpp"

int bmSearch(std::string string, std::string subString) {
    
    int sizeString = (int) string.size(), //Размер строки
        sizeSubString = (int) subString.size(), //Размер подстроки
        tab[256] = {0}; //Таблица символов
    
    /*
    std::cout << "size s " << sizeString << std::endl;
    std::cout << "size ss " << sizeSubString << std::endl;
    */
    
    //Генерируем таблицу
    for(int i = 0; i < sizeSubString - 1; i++) {
        
        tab[subString[i]] = sizeSubString - 1 - i;
        
    }
    
    for(int i = 0; i < 256; i++) {
        
        if(!(tab[i])) {
            
            tab[i] = sizeSubString;
            
        }
        
    }
    
    {
        int i = sizeSubString - 1;
        int j = sizeSubString - 1;
        int k = i;
        
        bool a = true;
        
        while(a) {
            
            if(i < sizeString) {
                
                if(j >= 0) {
                    
                    if(string[k] == subString[j]) {
                        
                        k--;
                        j--;
                        
                    }
                    
                    else {
                        
                        i += tab[string[i]];
                        j = sizeSubString - 1;
                        k = i;
                        
                    }
                    
                }
                
                else {
                    
                    return i + 1 - sizeSubString;
                    
                }
                
            }
            
            else
                return -1;
            
        }
        
    }
    
    return -1;
}

std::vector<int> bmSearchAllOccurrences(std::string string, std::string subString) {
    
    std::vector<int> occurrences; // вхождения
    
    int sizeString = (int) string.size(), //Размер строки
        sizeSubString = (int) subString.size(), //Размер подстроки
        tab[256] = {0}; //Таблица символов
    
    /*
    std::cout << "size s " << sizeString << std::endl;
    std::cout << "size ss " << sizeSubString << std::endl;
    */
    
    //Генерируем таблицу
    for(int i = 0; i < sizeSubString - 1; i++) {
        
        tab[subString[i]] = sizeSubString - 1 - i;
        
    }
    
    for(int i = 0; i < 256; i++) {
        
        if(!(tab[i])) {
            
            tab[i] = sizeSubString;
            
        }
        
    }
    
    {
        int i = sizeSubString - 1;
        int j = sizeSubString - 1;
        int k = i;
        
        bool flag = false;
        bool a = true;
        
        while(a) {
            
            if(i < sizeString) {
                
                if(j >= 0) {
                    
                    if(string[k] == subString[j]) {
                        
                        k--;
                        j--;
                        
                        if(j == 0)
                            flag = true;
                        
                    }
                    
                    else {
                        
                        if(flag)
                            occurrences.push_back(i + 1 - sizeSubString);
                        
                        i += tab[string[i]];
                        j = sizeSubString - 1;
                        k = i;
                        
                    }
                    
                }
                
                //j >= 0 - false
                
            }
            
            //i < sizeString - false
            
        }
        
    }
    
    return occurrences;
}


void printVector(std::vector<int> nums) {
    
    for(auto it = nums.begin(); it != nums.end(); it++) {
        
        if(it != nums.begin())
            std::cout << ", ";
        
        std::cout << *it;
        
    }
    
    std::cout << std::endl;
    
}

