#include "List.hpp"

int main() {
    
    Array<int> a(998);
    a.setRandomNumbers(0, 1000);
    List<int> l(a);
    
    return 0;
}
