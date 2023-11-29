#include "List.hpp"

int main() {
    Array<int> array(5);
    array.setRandomNumbersIncrease();
    array.print();
    const List<int> a(array);
    for(auto it = a.begin(); it != a.end(); ++it)
        std::cout << *it << std::endl;
    
    std::cout << a << std::endl;
    List<int> b(10, 10);
    std::cin >> b;
    std::cout << b << std::endl;
    return 0;
}
