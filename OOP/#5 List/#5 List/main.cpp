#include "BaseList.hpp"

int main() {
    
    List<const char> a;
    a.push_back('1');
    a.push_back('2');
    a.push_back('0');
    a.push_back('6');
    a.sort();
    std::cout << a << std::endl;
    //a.pop_front();
    List<const char>::Iterator it = a.begin();
    List<const char>::Iterator it1 = a.begin() + 2;
    List<const char>::Iterator it3 = a.end();
    List<const char>::Iterator it4 = a.end() - 1;
    std::cout << a.iterators << std::endl;
    std::cout << a.iterators + 1 << std::endl;
    std::cout << a.iterators + 2 << std::endl;
    std::cout << a.iterators + 3 << std::endl;
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

