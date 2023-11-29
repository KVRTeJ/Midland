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
List<Type>::Iterator List<Type>::find(const Type& key) {
    
    auto it = begin();
    while(it != end()) {
        if(*it == key)
            break;
        ++it;
    }
    
    return it;
}

template <typename Type>
void List<Type>::insert(const unsigned pos, const Type& value) {
    assert(pos <= m_size);
    
    insertNode(begin() + pos, value);
}

template <typename Type>
void List<Type>::insert(Iterator iter, const Type& value) {
    insertNode(iter, value);
}

template <typename Type>
void List<Type>::insertAfter(const Type& key, const Type& value) {
    insertNode(find(key), value);
}


template <typename Type>
void List<Type>::push_back(const Type& value) {
    insert((unsigned) m_size, value);
}

template <typename Type>
void List<Type>::push_front(const Type& value) {
    insert((unsigned) 0, value);
}

template <typename Type>
void List<Type>::erase(const unsigned pos) {
    assert(pos < m_size);
    
    removeNode(begin() + pos);
}

template <typename Type>
void List<Type>::erase(Iterator iter) {
    removeNode(iter);
}

template <typename Type>
void List<Type>::erase(Iterator from, Iterator to) { 
    //FIXME
    if(from == to)
        return;
    erase(to);
    erase(from, to--);
}

template <typename Type>
void List<Type>::eraseFirst(const Type& key) {
    removeNode(find(key));
}

template <typename Type>
void List<Type>::pop_back() {
    erase((unsigned) m_size - 1);
}

template <typename Type>
void List<Type>::pop_front() {
    erase((unsigned) 0);
}

template <typename Type>
void List<Type>::clear() {
    
    while(!isEmpty()) {
        removeNode(begin());
    }
    
}

template <typename Type>
Type List<Type>::max() const {
    if(m_size < 0)
        return 0;
    
    Type max = m_head->m_next->m_value;
    for(auto it = begin(); it != end(); ++it) {
        if(*it > max)
            max = *it;
    }
    
    return max;
}

template <typename Type>
Type List<Type>::min() const {
    if(m_size < 0)
        return 0;
    
    Type min = m_head->m_next->m_value;
    for(auto it = begin(); it != end(); ++it)
        if(*it < min)
            min = *it;
    
    return min;
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
void List<Type>::insertNode(Iterator currentNode, const Type& value) {
    if(currentNode.isNullptr()) {
        alertNodeNullptr("insertNode()");
        return;
    }
    
    Node<Type>* newNode = new Node<Type> ( Node<Type>(value, currentNode.m_node, currentNode.m_node->m_prev) );
    
    currentNode.m_node->m_prev->m_next = newNode;
    currentNode.m_node->m_prev = newNode;
    
    ++m_size;
}

template <typename Type>
void List<Type>::removeNode(Iterator currentNode) {
    if(currentNode.isNullptr()) {
        alertNodeNullptr("removeNode()");
        return;
    }
    
    currentNode.m_node->m_next->m_prev = currentNode.m_node->m_prev;
    currentNode.m_node->m_prev->m_next = currentNode.m_node->m_next;
    delete currentNode.m_node;
    
    assert(m_size > 0);
    --m_size;
}

/* Iterator */
template <typename Type>
template <typename IterType, typename ListType> typename
List<Type>::template TemplateIterator<IterType, ListType>& List<Type>::TemplateIterator<IterType, ListType>::operator ++ () {
    m_node = m_node->m_next;
    return *this;
}

template <typename Type>
template <typename IterType, typename ListType>
typename List<Type>::template TemplateIterator<IterType, ListType> List<Type>::TemplateIterator<IterType, ListType>::operator ++ (int) const {
    return TemplateIterator(m_list, m_node->m_next);
}

template <typename Type>
template <typename IterType, typename ListType>
typename List<Type>::template TemplateIterator<IterType, ListType> List<Type>::TemplateIterator<IterType, ListType>::operator + (const int value) const {
    assert(value <= m_list->getSize());
    
    TemplateIterator result(m_list, m_node);
    for(int i = 0; i < value; ++i) {
        ++result;
    }
    
    return result;
}

template <typename Type>
template <typename IterType, typename ListType>
typename List<Type>::template TemplateIterator<IterType, ListType>& List<Type>::TemplateIterator<IterType, ListType>::operator += (const int value){
    *this = *this + value;
    return *this;
}

template <typename Type>
template <typename IterType, typename ListType>
typename List<Type>::template TemplateIterator<IterType, ListType>& List<Type>::TemplateIterator<IterType, ListType>::operator -- () {
    m_node = m_node->m_prev;
    return *this;
}

template <typename Type>
template <typename IterType, typename ListType>
typename List<Type>::template TemplateIterator<IterType, ListType> List<Type>::TemplateIterator<IterType, ListType>::operator -- (int) const {
    return TemplateIterator(m_list, m_node->m_prev);
}

template <typename Type>
template <typename IterType, typename ListType>
typename List<Type>::template TemplateIterator<IterType, ListType> List<Type>::TemplateIterator<IterType, ListType>::operator - (const int value) const {
    assert(value <= m_list->getSize());
    
    TemplateIterator result(m_list, m_node);
    for(int i = value; i > 0; --i) {
        --result;
    }
    
    return result;
}

template <typename Type>
template <typename IterType, typename ListType>
typename List<Type>::template TemplateIterator<IterType, ListType>& List<Type>::TemplateIterator<IterType, ListType>::operator -= (const int value){
    *this = *this - value;
    return *this;
}
 
template <typename Type>
template <typename IterType, typename ListType>
bool List<Type>::TemplateIterator<IterType, ListType>::operator == (TemplateIterator& other) const {
    return (m_node == other.m_node) && (m_list == other.m_list);
}

template <typename Type>
template <typename IterType, typename ListType>
bool List<Type>::TemplateIterator<IterType, ListType>::operator != (TemplateIterator& other) const {
    return !((m_node == other.m_node) && (m_list == other.m_list));
}

template <typename Type>
std::ostream& operator << (std::ostream& stream, const List<Type>& other) {
    
    stream << "[";
    for(auto it = other.begin(); it != other.end(); ++it) {
        stream << *it << (it != (other.end()--) ? ", ":"");
    }
    stream << "]";
    
    return stream;
}

template  <typename Type>
std::istream& operator >> (std::istream& stream, List<Type>& other) {
    
    for(auto it = other.begin(); it != other.end(); ++it) {
        stream >> *it;
    }
    
    return stream;
}

#endif //!ARE_TEMPLATE_LIST_METHODS_DEFINED
