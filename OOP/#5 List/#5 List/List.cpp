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
    
    Node<Type>* temp = other.m_head->m_next;
    while(temp != other.m_tail) {
        push_back(temp->m_value);
        temp = temp->m_next;
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
void List<Type>::swap(List<Type>& other) {
    
    std::swap(m_head, other.m_head);
    std::swap(m_tail, other.m_tail);
    std::swap(m_size, other.m_size);
    
}

template <typename Type>
void List<Type>::push_back(const Type& value) {
    assert(m_head != nullptr && m_tail != nullptr);
    
    Node<Type>* newNode = new Node<Type> ( Node<Type>(value, m_tail, m_tail->m_prev) );
    
    m_tail->m_prev->m_next = newNode;
    m_tail->m_prev = newNode;

    ++m_size;
}

template <typename Type>
void List<Type>::push_front(const Type& value) {
    assert(m_head != nullptr && m_tail != nullptr);
    
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

template <typename Type>
Type& List<Type>::operator [] (const int index) {
    assert(index < m_size);
    
    Node<Type>* temp = m_head->m_next;
    
    for(int i = 0; i < index; ++i) {
        temp = temp->m_next;
    }
    
    return temp->m_value;
}

template <typename Type>
const Type& List<Type>::operator [] (const int index) const {
    assert(index < m_size);
    
    Node<Type>* temp = m_head->m_next;
    
    for(int i = 0; i < index; ++i) {
        temp = temp->m_next;
    }
    
    return temp->m_value;
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

template <typename Type>
std::ostream& operator << (std::ostream& stream, const List<Type>& other) {
    
    stream << "[";
    for(int i = 0; i < other.getSize(); ++i) {
        stream << other[i] << ((i + 1) < other.getSize() ? ", ":"");
    }
    stream << "]";
    
    return stream;
}

template  <typename Type>
std::istream& operator >> (std::istream& stream, List<Type>& other) {
    
    for(int i = 0; i < other.getSize(); ++i) {
        stream >> other[i];
    }
    
    return stream;
}

#endif //!ARE_TEMPLATE_LIST_METHODS_DEFINED
