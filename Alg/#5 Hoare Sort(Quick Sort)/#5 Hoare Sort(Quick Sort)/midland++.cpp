#include <iostream>

#include "midland++.hpp"

HelloWorld::HelloWorld() {
    std::cout << "Hello World!" << std::endl;
    this->m_helloWorld = true;
}

HelloWorld::~HelloWorld() {
    if(this->m_helloWorld) {
        std::cout << "Bye World!" << std::endl;
        return;
    }
}
