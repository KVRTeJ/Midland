#pragma once

#include <iostream>

class List {
public:
    List() { std::cout << "Hello World! " << std::endl;}
    ~List() { std::cout << "Bye World! " << std::endl;}
    
private:
    bool isList = true;
};
