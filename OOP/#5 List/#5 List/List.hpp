#ifndef ARE_TEMPLATE_LIST_DECLARED
#define ARE_TEMPLATE_LIST_DECLARED

#include <iostream>
#include <string>
#include <vector>

#include "Array.hpp"

template <typename Type>
class List {
public:
    template <typename NodeType>
    class Node;
public:
    List(const Type& value = Type(), const int size = 0);
    List(const Array<Type>& value);
    List(const List& other);
    ~List();
    
    unsigned int getSize() const {return m_size;}
    bool isEmpty() const {return m_head->m_next == m_tail;}
    
    
    void push_back(const Type& value);
    void push_front(const Type& value);
    void clear();
    
    Node<Type>& operator [] (const int index);
    
private:
    void generateListBasis();
    
    Node<Type>* m_head = nullptr;
    Node<Type>* m_tail = nullptr;
    unsigned int m_size = 0;
    
};

template <typename Type>
template <typename NodeType>
class List<Type>::Node {
    friend List<Type>;
public:
    NodeType value = 0; //Type
private:
    Node(const NodeType& value = NodeType(), Node* next = nullptr, Node* prev = nullptr)
    : value(value), m_next(next), m_prev(prev)
    { }
    
    Node<NodeType>* m_next = nullptr;
    Node<NodeType>* m_prev = nullptr;
    
};

#include "List.cpp"

#endif //!ARE_TEMPLATE_LIST_DECLARED
