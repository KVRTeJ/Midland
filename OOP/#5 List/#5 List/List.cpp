#ifndef ARE_TEMPLATE_LIST_METHODS_DEFINED
#define ARE_TEMPLATE_LIST_METHODS_DEFINED

#include "List.hpp"

template <typename Type>
List<Type>::List(const Type& value, const int size) {
    assert(size >= 0);
    
    generateListBasis();
    
    for(int i = 0; i < size; i++) {
        push_back(value);
    }
    
    m_size = size;
}

template <typename Type>
List<Type>::List(const Array<Type>& value) {
    
    generateListBasis();
    
    for(auto it = value.begin(); it != value.end(); ++it) {
        push_back(*it);
    }
    
    m_size = (unsigned) value.getSize();
}

template <typename Type>
List<Type>::List(const List& other) {
    
    generateListBasis();
    
    for(Node<Type>* i = m_head; i->m_next != m_tail; i = i->m_next) {
        std::cout << i->m_value << std::endl;
    }
    
    m_size = other.m_size;
}

template <typename Type>
List<Type>::~List() {
    
    clear();
    delete m_head;
    delete m_tail;
    
}

template <typename Type>
void List<Type>::push_back(const Type& value) {
    
    Node<Type>* newNode = new Node<Type> ( Node<Type>(value, m_tail, m_tail->m_prev) );
    
    m_tail->m_prev->m_next = newNode;
    m_tail->m_prev = newNode;

    ++m_size;
}

template <typename Type>
void List<Type>::push_front(const Type& value) {
    
    Node<Type>* newNode = new Node<Type> ( Node<Type>(value, m_head->m_next, m_head) );
    
    m_head->m_next->m_prev = newNode;
    m_head->m_next = newNode;
    
    ++m_size;
}

template <typename Type>
void List<Type>::clear() {
    
    Node<Type>* temp;
    while(m_head->m_next != m_tail) {
        temp = m_head->m_next;
        m_head->m_next = temp->m_next;
        m_head->m_next->m_prev = m_head;
        delete temp;
    }
    
    m_size = 0;
}

/* private */
template <typename Type>
void List<Type>::generateListBasis() {
    if(m_head != nullptr)
        delete m_head;
    if(m_tail != nullptr)
        delete m_tail;
    
    m_head = new Node<Type> ();
    m_tail = new Node<Type> ();
    
    
    m_head->m_next = m_tail;
    m_head->m_prev = nullptr;
    m_tail->m_next = nullptr;
    m_tail->m_prev = m_head;
}


#endif //!ARE_TEMPLATE_LIST_METHODS_DEFINED
