#ifndef ARE_TEMPLATE_LIST_DECLARED
#define ARE_TEMPLATE_LIST_DECLARED

#include <iostream>
#include <string>
#include <vector>

#include "Array.hpp"

template <typename Type>
class List {
public: // Node* find else private
    template <typename NodeType>
    class Node;
public:
    List(const Type& value = Type(), const int size = 0);
    List(const Array<Type>& value);
    List(const List& other);
    ~List();
    
    unsigned int getSize() const {return m_size;}
    void swap(List& other);
    
    Node<Type>* find(const Type& key) const;// Node* or Node->m_value ?
    
    void push(const unsigned pos, const Type& value);
    void push(const Type& key, const Type& value);
    void push_back(const Type& value);
    void push_front(const Type& value);
    void pop(const unsigned pos);
    void pop(const Type& key);
    void pop_back();
    void pop_front();
    
    Type max() const;//
    Type min() const;//
    bool isEmpty() const {return m_head->m_next == m_tail;}
    void clear();
    
    Type& operator [] (const int index);
    const Type& operator [] (const int index) const;
    List& operator = (const List& other);
    bool operator == (const List& other) const;
    bool operator != (const List& other) const;
    List operator + (const List& other) const;
    List& operator += (const List& other);
    
private:
    void generateListBasis();
    void insertNode(Node<Type>* currentNode, const Type& value);
    void removeNode(Node<Type>* currentNode);
    
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
    
    NodeType m_value = NodeType();
    Node<NodeType>* m_next = nullptr;
    Node<NodeType>* m_prev = nullptr;
    
};

template <typename Type>
std::ostream& operator << (std::ostream& stream, const List<Type>& other);

template <typename Type>
std::istream& operator >> (std::istream& stream, List<Type>& other);

#include "List.cpp"

#endif //!ARE_TEMPLATE_LIST_DECLARED
