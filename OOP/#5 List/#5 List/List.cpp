#ifndef ARE_TEMPLATE_LIST_METHODS_DEFINED
#define ARE_TEMPLATE_LIST_METHODS_DEFINED

#include "List.hpp"

template <typename Type>
List<Type>::List(const Type& value, const int size) {

    generateListBasis();
    
    for(int i = 0; i < size; i++) {
        push_back(value);
    }
    
}

template <typename Type>
List<Type>::List(const Array<Type>& value) {
    
    generateListBasis();
    
    for(auto it = value.begin(); it != value.end(); ++it) {
        push_back(*it);
    }
    
}

template <typename Type>
List<Type>::List(const List& other) {
    
    generateListBasis();
    
    Node<Type>* temp = other.m_head->m_next;
    while(temp != other.m_tail) {
        push_back(temp->m_value);
        temp = temp->m_next;
    }
    
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


template <typename Type> typename
List<Type>::template Node<Type>* List<Type>::find(const Type& key) const {
    
    Node<Type>* temp = m_head->m_next;
    while(temp != m_tail) {
        if(temp->m_value == key)
            return temp;
        temp = temp->m_next;
    }
    
    return nullptr;
}

template <typename Type>
void List<Type>::push(const unsigned pos, const Type& value) {
    assert(pos <= m_size);
    
    Node<Type>* temp = m_head->m_next;
    for(int i = 0; i < pos; ++i) {
        temp = temp->m_next;
    }
    
    insertNode(temp, value);
}


template <typename Type>
void List<Type>::push(const Type& key, const Type& value) {
    insertNode(find(key), value);
}


template <typename Type>
void List<Type>::push_back(const Type& value) {
    push((unsigned) m_size, value);
}

template <typename Type>
void List<Type>::push_front(const Type& value) {
    push((unsigned) 0, value);
}

template <typename Type>
void List<Type>::pop(const unsigned pos) {
    assert(pos < m_size);
    
    Node<Type>* temp = m_head->m_next;
    for(int i = 0; i < pos; ++i) {
        temp = temp->m_next;
    }
    
    removeNode(temp);
}

template <typename Type>
void List<Type>::pop(const Type& key) {
    removeNode(find(key));
}

template <typename Type>
void List<Type>::pop_back() {
    pop((unsigned) m_size - 1);
}

template <typename Type>
void List<Type>::pop_front() {
    pop((unsigned) 0);
}

template <typename Type>
void List<Type>::clear() {
    
    while(!isEmpty()) {
        removeNode(m_head->m_next);
    }
    
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

template <typename Type>
List<Type>& List<Type>::operator = (const List<Type>& other) {
    
    if(m_head != other.m_head || m_tail != other.m_tail) {
        clear();
        
        generateListBasis();
        
        Node<Type>* temp = other.m_head->m_next;
        while(temp != other.m_tail) {
            push_back(temp->m_value);
            temp = temp->m_next;
        }
        
        m_size = other.m_size;
    }
    
    return *this;
}

template <typename Type>
bool List<Type>::operator == (const List<Type>& other) const {
    return (m_head == other.m_head && m_tail == other.m_tail &&
            m_size == other.m_size);
}

template <typename Type>
bool List<Type>::operator != (const List<Type>& other) const {
    return !(this==other);
}

template <typename Type>
List<Type> List<Type>::operator + (const List<Type>& other) const {
    
    List<Type> result(*this);
    Node<Type>* temp = other.m_head->m_next;
    while(temp != other.m_tail) {
        result.push_back(temp->m_value);
        temp = temp->m_next;
    }
    
    return result;
}

template <typename Type>
List<Type>& List<Type>::operator += (const List<Type>& other) {
    
    *this = *this + other;
    
    return *this;
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

inline void alertNodeNullptr(const std::string name) {
    std::cerr << name + ": currentNode == nullptr";
    std::cerr << std::endl;
}

template <typename Type>
void List<Type>::insertNode(Node<Type>* currentNode, const Type& value) {
    if(currentNode == nullptr) {
        alertNodeNullptr("insertNode(Node<Type>*, const Type&)");
        return;
    }
    
    Node<Type>* newNode = new Node<Type> ( Node<Type>(value, currentNode, currentNode->m_prev) );
    
    currentNode->m_prev->m_next = newNode;
    currentNode->m_prev = newNode;
    
    ++m_size;
}

template <typename Type>
void List<Type>::removeNode(Node<Type>* currentNode) {
    if(currentNode == nullptr) {
        alertNodeNullptr("removeNode(Node<Type>*)");
        return;
    }
    
    currentNode->m_next->m_prev = currentNode->m_prev;
    currentNode->m_prev->m_next = currentNode->m_next;
    delete currentNode;
    
    --m_size;
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
