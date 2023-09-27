#include <iostream>
#include <string>
#include <vector>

#include "midland++.hpp"

void printVector(const std::vector<int> nums) {
    
    for(auto it = nums.begin(); it != nums.end(); it++) {
        
        if(it != nums.begin())
            std::cout << ", ";
        
        std::cout << *it;
        
    }
    
    std::cout << std::endl;
    
}

void fillAsciiTab(int* tab, std::string subString){
    
    const int sizeSubString = (int) subString.size();
    
    for(int i = 0; i < sizeSubString - 1; i++) {
        tab[subString[i]] = sizeSubString - 1 - i;
    }
    
    for(int i = 0; i < 256; i++) {
        if(!(tab[i])) {
            tab[i] = sizeSubString;
        }
    }
    
}

void getOccurrences(std::vector<int> &answer,const std::string string,
                    const std::string subString, int* tab, const int start, const int stop) {
    
    if(subString.size() == 0)
        return;
    
    const int sizeSubString = (int) subString.size(); //Размер подстроки
    
    {
        int i = sizeSubString - 1 + start,
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
                            answer.push_back(i + 1 - sizeSubString);
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
    return;
}

int bmSearch(const std::string string, const std::string subString) {
    
    int start = 0,
        stop = (int) subString.size();
    
    int tab[256] = {0};
    
    fillAsciiTab(tab, subString);
    
    std::vector<int> answer;
    
    while(answer.size() < 1 && stop < string.size() && stop != 0) {
        getOccurrences(answer, string, subString, tab, start, stop);
        start = stop;
        stop += stop;
    }
    
    if(!answer.empty())
        return answer[0];
    return -1;
}

std::vector<int> bmSearchAllOccurrences(const std::string string,const std::string subString) {
    
    const int start = 0, stop = (int) string.size();
    
    int tab[256] = {0};
    
    fillAsciiTab(tab, subString);
    
    std::vector<int> answer;
    getOccurrences(answer, string, subString, tab, start, stop);
    return answer;
    
}

std::vector<int> bmSearchOccurrencesInRange(const std::string string, const std::string subString,
                                            const int start, const int stop) {
    
    int tab[256] = {0};
    
    fillAsciiTab(tab, subString);
    
    std::vector<int> answer;
    getOccurrences(answer, string, subString, tab, start, stop);
    return answer;
    
}

