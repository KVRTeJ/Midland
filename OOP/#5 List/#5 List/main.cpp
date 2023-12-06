#include "BaseList.hpp"

int main() {
    const int SIZE = 100;
    Array<int> arr(SIZE);
    for(int i = 0; i < SIZE; ++i) {
        arr[i] = i;
    }
    
    std::cout << arr;
    List<int> list(arr);
    std::cout << list  << std::endl;
    for (int i = list.getSize(); i > 0; --i) {
        int index = rand() % arr.getSize();
        int element = arr[index];
        assert(element == list[index]);
        arr.removeIndex(index);
        
        List<int>::Iterator it = list.find(element);
        assert(!list.isEmpty() && it != list.end());
        list.erase(it);
        assert(list.getSize() == arr.getSize());
    }
    return 0;
}

