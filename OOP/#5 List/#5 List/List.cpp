#ifndef ARE_TEMPLATE_LIST_METHODS_DEFINED
#define ARE_TEMPLATE_LIST_METHODS_DEFINED

#include "List.hpp"

template <typename Type>
List<Type>::List() {
    
    m_size = 0;
    m_head = new Node<Type> ();
    m_tail = new Node<Type> ();
    
    
    m_head->m_next = m_tail;
    m_head->m_prev = nullptr;
    m_tail->m_next = nullptr;
    m_tail->m_prev = m_head;
    
}

template <typename Type>
List<Type>::List(const Array<Type>& value) {
    
    m_head = new Node<Type> ();
    m_tail = new Node<Type> ();
    
    
    m_head->m_next = m_tail;
    m_head->m_prev = nullptr;
    m_tail->m_next = nullptr;
    m_tail->m_prev = m_head;
    
    for(auto it = value.begin(); it != value.end(); ++it) {
        push_back(*it);
    }
    
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



#endif //!ARE_TEMPLATE_LIST_METHODS_DEFINED
