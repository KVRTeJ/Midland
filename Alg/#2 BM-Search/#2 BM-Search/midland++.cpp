#include <iostream>
#include <string>
#include <vector>

#include "midland++.hpp"

int bmSearch(const std::string string, const std::string subString) {
    
    const int sizeString = (int) string.size(), //Размер строки
              sizeSubString = (int) subString.size(); //Размер подстроки
    int tab[256] = {0}; //Таблица символов
    
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

std::vector<int> bmSearchAllOccurrences(const std::string string,const std::string subString) {
    
    std::vector<int> occurrences; // вхождения
    
    const int sizeString = (int) string.size(), //Размер строки
              sizeSubString = (int) subString.size(); //Размер подстроки
    int tab[256] = {0}; //Таблица символов
    
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
        int i = sizeSubString - 1,
            j = sizeSubString - 1,
            k = i;
        
        bool flag = false,
             a = true;
        
        while(a) {
            if(i >= 0 && i < sizeString) {
                if(j >= 0) {
                    
                    if(string[k] == subString[j]) {
                        
                        k--;
                        j--;
                        
                        if(j <= 0)
                            flag = true;
                        
                    }
                    
                    else {
                        
                        if(flag)
                            occurrences.push_back(i + 1 - sizeSubString);
                        flag = false;
                        
                        i += tab[string[i]];
                        j = sizeSubString - 1;
                        k = i;
                        
                    }
                    
                }
                else
                    j = sizeSubString - 1;
                    //j >= 0 - false
                
            }
            else
                a = false;
                //i < sizeString - false
        }
        
    }
    
    return occurrences;
}


std::vector<int> bmSearchOccurrencesInDiapason(const std::string string, const std::string subString,
                                               const int start, const int stop) {
    
    std::vector<int> occurrences; // вхождения
    
    const int sizeSubString = (int) subString.size(); //Размер подстроки
    int tab[256] = {0}; //Таблица символов
    
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
        int i = sizeSubString - 1 + start, //
            j = sizeSubString - 1,
            k = i;
        
        bool flag = false,
             a = true;
        
        while(a) {
            if( i >= 0 && i < (stop + 1) ) {
                if(j >= 0) {
                    if(string[k] == subString[j]) {
                        
                        k--;
                        j--;
                        
                        if(j <= 0)
                            flag = true;
                        
                    }
                    
                    else {
                        
                        if(flag)
                            occurrences.push_back(i + 1 - sizeSubString);
                        flag = false;
                        
                        i += tab[string[i]];
                        j = sizeSubString - 1;
                        k = i;
                        
                    }
                    
                }
                else
                    j = sizeSubString - 1;
                    //j >= 0 - false
            }
            else
                a = false;
                //i < sizeString - false
        }
    }
    return occurrences;
}

void printVector(const std::vector<int> nums) {
    
    for(auto it = nums.begin(); it != nums.end(); it++) {
        
        if(it != nums.begin())
            std::cout << ", ";
        
        std::cout << *it;
        
    }
    
    std::cout << std::endl;
    
}

