#include "BaseList.hpp"

int main() {
    
    List<char> a;
    a.push_back('1');
    a.push_back('2');
    a.push_back('0');
    a.push_back('6');
    a.sort();
    std::cout << a << std::endl;
    //a.pop_front();
    List<char>::Iterator it = a.begin();
    List<char>::Iterator it1 = a.begin();
    List<char>::Iterator it2 = a.begin();
    std::cout << a<< std::endl;
    //a.notify();
    std::cout << a.iterators << std::endl;
    /*
    Array<int> array(10);
    array.setRandomNumbers(-1, 10);
    array.print();
    BaseList<int> a(array);
   // a.push_back(10);
    std::cout << a << std::endl;
    a.pop_back();
    std::cout << a << std::endl;
    
    a.sort();
    std::cout << a << std::endl;
    */
    return 0;
}

