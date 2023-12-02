#ifndef IS_TEMPLATE_LIST_DECLARED
#define IS_TEMPLATE_LIST_DECLARED

#include <iostream>
#include <string>
#include <vector>

#include "Array.hpp"

template <typename Type>
class BaseList {
public:
    template <typename NodeType>
    class Node;
    
public:
    template <typename IterType, typename ListType>
    class TemplateIterator;
    using Iterator = TemplateIterator<Type, BaseList>;
    using ConstIterator = TemplateIterator<const Type, const BaseList>;
    
public:
    BaseList(const int size = 0, const Type& value = Type());
    BaseList(const Array<Type>& value);
    BaseList(const BaseList& other);
    ~BaseList();
    
    virtual void subscribe(Iterator& iter) {}
    virtual void subscribe(ConstIterator iter) const {}
    virtual void unsubscribe(Iterator& iter) {}
    virtual void unsubscribe(ConstIterator iter) const {}
    virtual void notify() {}
    
    
    unsigned int getSize() const {return m_size;}
    void swap(BaseList& other);
    
    Iterator begin() {return Iterator(this, m_head->m_next);}
    Iterator end() {return Iterator(this, m_tail);}
    
    ConstIterator begin() const {return ConstIterator(this, m_head->m_next);}
    ConstIterator end() const {return ConstIterator(this, m_tail);}
    
    Iterator find(const Type& key); //? const
    ConstIterator find(const Type& key) const;
    
    void insert(const unsigned pos, const Type& value);
    void insert(Iterator iter, const Type& value);
    void insertAfter(const Type& key, const Type& value);
    void push_back(const Type& value);
    void push_front(const Type& value);
    
    void erase(const unsigned pos);
    void erase(Iterator iter);
    void erase(Iterator from, Iterator to);
    void eraseFirst(const Type& key);
    void pop_back();
    void pop_front();
    
    Type max() const;
    Type min() const;
    bool isEmpty() const {return m_head->m_next == m_tail;}
    void clear();
    void move(Iterator at, Iterator before);
    void bubbleSort();

    
    Type& operator [] (const int index);
    const Type& operator [] (const int index) const;
    BaseList& operator = (const BaseList& other);
    bool operator == (const BaseList& other) const;
    bool operator != (const BaseList& other) const;
    BaseList operator + (const BaseList& other) const;
    BaseList& operator += (const BaseList& other);
    
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
class BaseList<Type>::Node {
    friend class BaseList;
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
class BaseList<Type>::TemplateIterator {
    friend class BaseList;
public:
    TemplateIterator(ListType* list = nullptr, Node<Type>* node = nullptr)
    : m_list(list), m_node(node)
    {m_list->subscribe(*this);}
    ~TemplateIterator() {std::cout << "~iter\n";}//m_list->unsubscribe(*this);invalidate();}
    //Iterator(const Iterator&) - ?
    
    IterType& operator * () {return m_node->m_value;}
    
    TemplateIterator& operator ++ ();
    TemplateIterator operator ++ (int);
    TemplateIterator operator + (const int value) const;
    TemplateIterator& operator += (const int value);
    
    TemplateIterator& operator -- ();
    TemplateIterator operator -- (int);
    TemplateIterator operator - (const int value) const;
    TemplateIterator& operator -= (const int value);
    
    bool operator == (TemplateIterator& other) const ;
    bool operator != (TemplateIterator& other) const ;
    
    bool isValidate() const {return !(m_node == nullptr);}
    void invalidate() {m_node = nullptr; m_list = nullptr;}
private:
    Node<Type>* m_node = nullptr;
    ListType* m_list = nullptr;
};

template <typename Type>
std::ostream& operator << (std::ostream& stream, const BaseList<Type>& other);

template <typename Type>
std::istream& operator >> (std::istream& stream, BaseList<Type>& other);


template <typename Type>
class List: public BaseList<Type> {
public:
    void subscribe(typename BaseList<Type>::Iterator& iter) override {iterators.push_back(&iter);}
    void unsubscribe(typename BaseList<Type>::Iterator& iter) override {iterators.pop_front();}
    void notify() override {
        for(auto it = iterators.begin(); it != iterators.end(); ++it)
            if((*it)->isValidate()) {
                unsubscribe(**it);
            }
    }
    
//private:
    BaseList<typename BaseList<Type>::Iterator* > iterators;
};

#include "BaseList.cpp"

#endif //!IS_TEMPLATE_LIST_DECLARED
