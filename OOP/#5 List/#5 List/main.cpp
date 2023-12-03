#include "BaseList.hpp"

int main() {
    Array<int> arr(9, 56);
    arr.setRandomNumbers(1, 10);
    List<int> a(arr);
    List<int>::Iterator it1 = a.begin();
    List<int>::Iterator it2 = a.begin() + 2;
    {
        List<int>::Iterator it3 = it2 + 1;
        a.erase(it1, it3);
    }
    std::cout << a << std::endl;
    return 0;
}

