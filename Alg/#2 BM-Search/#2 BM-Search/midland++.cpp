#include <iostream>
#include <string>
#include <vector>

#include "midland++.hpp"

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

int bmSearchCorrected(const std::string string, const std::string subString) {
    
    const int start = 0, stop = (int) string.size(); //Размер строки
    
    int answer  = bmSearchOccurrencesInDiapason(string, subString, start, stop)[0];
    return answer;
    
}

std::vector<int> bmSearchAllOccurrencesCorrected(const std::string string,const std::string subString) {
    
    const int start = 0, stop = (int) string.size();
    
    return bmSearchOccurrencesInDiapason(string, subString, start, stop);
    
}

void printVector(const std::vector<int> nums) {
    
    for(auto it = nums.begin(); it != nums.end(); it++) {
        
        if(it != nums.begin())
            std::cout << ", ";
        
        std::cout << *it;
        
    }
    
    std::cout << std::endl;
    
}
