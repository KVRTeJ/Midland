#ifndef ARE_TEMPLATE_LIST_DECLARED
#define ARE_TEMPLATE_LIST_DECLARED

#include <iostream>
#include <string>
#include <vector>

#include "Array.hpp"

template <typename Type>
class List {
private:
    template <typename NodeType>
    class Node;
public:
    List();
    List(const Array<Type>& value);
    ~List() = default;
    
    Node<Type> front();//первый элемент
    Node<Type> back();//последний элемент
    
    void push_back(const Type& value);
    void push_front(const Type& value);//
    
private:
    Node<Type>* m_head = nullptr;
    Node<Type>* m_tail = nullptr;
    unsigned int m_size = 0;
    
};

template <typename Type>
template <typename NodeType>
class List<Type>::Node {
public:
    Node(const NodeType& value = NodeType(), Node* next = nullptr, Node* prev = nullptr)
    : m_value(value), m_next(next), m_prev(prev)
    { }
    
    NodeType m_value = 0; //Type
    Node<NodeType>* m_next = nullptr;
    Node<NodeType>* m_prev = nullptr;
    
};

#include "List.cpp"

#endif //!ARE_TEMPLATE_LIST_DECLARED
