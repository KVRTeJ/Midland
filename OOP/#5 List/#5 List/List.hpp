#ifndef ARE_TEMPLATE_LIST_DECLARED
#define ARE_TEMPLATE_LIST_DECLARED

#include <iostream>
#include <string>
#include <vector>

#include "Array.hpp"

// List : public {List->BaseList}

template <typename Type>
class List {
public:
    template <typename NodeType>
    class Node;
    
public:
    template <typename IterType, typename ListType>
    class TemplateIterator;
    using Iterator = TemplateIterator<Type, List>;
    using ConstIterator = TemplateIterator<const Type, const List>;
    
public:
    List(const Type& value = Type(), const int size = 0);
    List(const Array<Type>& value);
    List(const List& other);
    ~List();
    
    
    unsigned int getSize() const {return m_size;}
    void swap(List& other);
    
    Iterator begin() {return Iterator(this, m_head->m_next);}
    Iterator end() {return Iterator(this, m_tail);}
    
    ConstIterator begin() const {return ConstIterator(this, m_head->m_next);}
    ConstIterator end() const {return ConstIterator(this, m_tail);}
    
    Iterator find(const Type& key); //? const
    
    //Type = unsigned int?
    void insert(const unsigned pos, const Type& value);
    void insert(Iterator iter, const Type& value);
    void insertAfter(const Type& key, const Type& value);
    void push_back(const Type& value);
    void push_front(const Type& value);
    
    void erase(const unsigned pos);
    void erase(Iterator iter);
    void erase(Iterator from, Iterator to);//FIXME
    void eraseFirst(const Type& key);
    void pop_back();
    void pop_front();
    
    Type max() const;
    Type min() const;
    bool isEmpty() const {return m_head->m_next == m_tail;}
    void clear();
    void sort();
    
    Type& operator [] (const int index);
    const Type& operator [] (const int index) const;
    List& operator = (const List& other);
    bool operator == (const List& other) const;
    bool operator != (const List& other) const;
    List operator + (const List& other) const;
    List& operator += (const List& other);
    
private:
    void generateListBasis();
    void insertNode(Iterator currentNode, const Type& value);
    void removeNode(Iterator currentNode);
    
    Node<Type>* m_head = nullptr;
    Node<Type>* m_tail = nullptr;
    unsigned int m_size = 0;
    
};

template <typename Type>
template <typename NodeType>
class List<Type>::Node {
    friend class List;
private:
    Node(const NodeType& value = NodeType(), Node* next = nullptr, Node* prev = nullptr)
    : m_value(value), m_next(next), m_prev(prev)
    { }
    
    NodeType m_value = nullptr; ///NoteType* m_value
    Node<NodeType>* m_next = nullptr;
    Node<NodeType>* m_prev = nullptr;
    
};

template <typename Type>
template <typename IterType, typename ListType>
class List<Type>::TemplateIterator {
    friend class List;
public:
    TemplateIterator(ListType* list = nullptr, Node<Type>* node = nullptr)
    : m_list(list), m_node(node)
    {}
    //Iterator(const Iterator&) - ?
    
    IterType& operator * () {return m_node->m_value;}
    
    TemplateIterator& operator ++ ();
    TemplateIterator operator ++ (int) const;
    TemplateIterator operator + (const int value) const;
    TemplateIterator& operator += (const int value);
    
    TemplateIterator& operator -- ();
    TemplateIterator operator -- (int) const;
    TemplateIterator operator - (const int value) const;
    TemplateIterator& operator -= (const int value);
    
    bool operator == (TemplateIterator& other) const ;
    bool operator != (TemplateIterator& other) const ;
    
    bool isNullptr() const { return m_node == nullptr;}
private:
    Node<Type>* m_node = nullptr;
    ListType* m_list = nullptr;
};

template <typename Type>
std::ostream& operator << (std::ostream& stream, const List<Type>& other);

template <typename Type>
std::istream& operator >> (std::istream& stream, List<Type>& other);

#include "List.cpp"

#endif //!ARE_TEMPLATE_LIST_DECLARED
