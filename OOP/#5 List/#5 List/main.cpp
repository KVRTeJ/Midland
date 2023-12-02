#include "BaseList.hpp"

int main() {
    
    List<char> a;
    a.push_back('1');
    a.push_back('1');
    a.push_back('1');
    a.push_back('1');
    std::cout << a.iterators;
    /*
    Array<int> array(10);
    array.setRandomNumbers(-1, 10);
    array.print();
    BaseList<int> a(array);
   // a.push_back(10);
    std::cout << a << std::endl;
    a.pop_back();
    std::cout << a << std::endl;
    
    a.bubbleSort();
    std::cout << a << std::endl;
    */
    return 0;
}

