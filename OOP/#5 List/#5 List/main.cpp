#include "BaseList.hpp"

int main() {
    const int SIZE = 40;
    Array<int> arr(SIZE);
    for(int i = 0; i < SIZE; ++i) {
        arr[i] = i;
    }
    
    //std::cout << arr;
    List<int> origin(arr);
    for(int i = 0; i < SIZE; ++i) {
        
        auto left = origin;
        auto right = origin;
        left = origin;
        left.erase(left.begin() + i, left.end());
        right.erase(right.begin(), right.begin() + i);
        std::cout << "left - " << left << '\n' << "right - " << right << '\n';
        std::cout << (left + right) << std::endl << std::endl;
        assert((left + right) == origin);
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
        it = list.find(element);
        assert(it == list.end());
    }
    return 0;
}

