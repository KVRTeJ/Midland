#include "TopSort.hpp"

template <typename Type>
void printVector(const std::vector<Type>& vec) {
    std::cout << "[";
    for(auto it = vec.begin(); it != vec.end(); ++it) {
        std::cout << (*it) << ((it + 1) == vec.end() ? "":" ");
    }
    std::cout << "]" << std::endl;
}

int main() {
    Graph b;
    
    //b.addArc(1, 7);
    b.addArc(2, 1);
    b.addArc(4, 5);
    b.addArc(5, 1);
    b.addArc(5, 3);
    b.addArc(6, 2);
    b.addArc(6, 3);
    b.addArc(6, 5);
    b.addArc(7, 1);
    b.print();
    //std::cout << b.matrix() << std::endl;
    printVector(b.TopologicalSort());
    b.print();
    
    return -2;
    Graph a;
    a.scan();
    a.print();
    BoolMatrix temp = a.matrix();
    printVector(TopologicalSort(temp));
    //std::cout << a.matrix() << std::endl;
    return -1;
    
    const int SIZE = 7;
    std::cout << "Size = " << SIZE << std::endl;
    BoolMatrix m(SIZE, SIZE);
    std::cin >> m;
    printVector(TopologicalSort(m));
    return 0;
}


/*
case 1:
 
size = 7
0000000
1000000
0000000
0000100
1010000
0110100
1000000
 
res: 3, 5, 6, 1, 4, 2, 0
 
case 2:
 
size = 6
010000
000110
100000
000001
000100
000000

res: 2, 0, 1, 3, 4, 5
 
case 3:
 
size = 9
101010101
010101000
000110100
000001100
000000011
110110100
000101001
000011010
001001010

res: []
*/
