#include "List.hpp"

int main() {
    Array<int> array(5);
    array.setRandomNumbersIncrease();
    array.print();
    List<int> a(array);
    List<int>::Iterator it = a.begin();
    it++;
    ++it;
    std::cout << *(++it) << std::endl;
    
    return 0;
}
