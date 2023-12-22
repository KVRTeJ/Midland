#ifndef ARE_TEMPLATE_LIST_METHODS_DEFINED
#define ARE_TEMPLATE_LIST_METHODS_DEFINED

#include "BaseList.hpp"

template <typename Type>
BaseList<Type>::BaseList(const int size, const Type& value) {

    generateListBasis();
    
    for(int i = 0; i < size; i++) {
        push_back(value);
    }
    
}

template <typename Type>
BaseList<Type>::BaseList(const Array<Type>& value) {
    
    generateListBasis();
    
    for(auto it = value.begin(); it != value.end(); ++it) {
        push_back(*it);
    }
    
}

template <typename Type>
BaseList<Type>::BaseList(const BaseList& other) {
    
    generateListBasis();
    
    Node* temp = other.m_head->m_next;
    while(temp != other.m_tail) {
        push_back(*temp->m_value);
        temp = temp->m_next;
    }
    
}

template <typename Type>
BaseList<Type>::~BaseList() {
    
    clear();
    delete m_head;
    delete m_tail;
    
}

template <typename Type>
void BaseList<Type>::swap(BaseList<Type>& other) {
    
    std::swap(m_head, other.m_head);
    std::swap(m_tail, other.m_tail);
    std::swap(m_size, other.m_size);
    
}


template <typename Type> typename
BaseList<Type>::Iterator BaseList<Type>::find(const Type& key) {
    
    auto it = begin();
    while(it != end()) {
        if(*it == key)
            break;
        ++it;
    }
    
    return it;
}

template <typename Type> typename
BaseList<Type>::ConstIterator BaseList<Type>::find(const Type& key) const {
    
    auto it = begin();
    while(it != end()) {
        if(*it == key)
            break;
        ++it;
    }
    
    return it;
}

template <typename Type>
void BaseList<Type>::insert(const unsigned pos, const Type& value) {
    assert(pos <= m_size);
    
    insertNode(begin() + pos, value);
}

template <typename Type>
void BaseList<Type>::insert(const Iterator& iter, const Type& value) {
    insertNode(iter, value);
}

template <typename Type>
void BaseList<Type>::insertAfter(const Type& key, const Type& value) {
    insertNode(find(key), value);
}


template <typename Type>
void BaseList<Type>::push_back(const Type& value) {
    insert(end(), value);
}

template <typename Type>
void BaseList<Type>::push_front(const Type& value) {
    insert(begin(), value);
}

template <typename Type>
void BaseList<Type>::erase(const unsigned pos) {
    assert(pos < m_size);
    
    removeNode(begin() + pos);
}

template <typename Type>
void BaseList<Type>::erase(const Iterator& iter) {
    removeNode(iter);
}

template <typename Type>
void BaseList<Type>::erase(const Iterator& from, const Iterator& to) {
    for(auto it = from; it != to;)
        erase(it++);
    return;
}

template <typename Type>
void BaseList<Type>::eraseFirst(const Type& key) {
    removeNode(find(key));
}

template <typename Type>
void BaseList<Type>::pop_back() {
    erase((unsigned) m_size - 1);
}

template <typename Type>
void BaseList<Type>::pop_front() {
    removeNode(begin());
}

template <typename Type>
Type BaseList<Type>::max() const {
    if(m_size <= 0)
        return 0;
    
    Type max = m_head->m_next->m_value;
    for(auto it = begin(); it != end(); ++it) {
        if(*it > max)
            max = *it;
    }
    
    return max;
}

template <typename Type>
Type BaseList<Type>::min() const {
    if(m_size <= 0)
        return 0;
    
    Type min = m_head->m_next->m_value;
    for(auto it = begin(); it != end(); ++it)
        if(*it < min)
            min = *it;
    
    return min;
}

template <typename Type>
void BaseList<Type>::clear() {
    
    while(!isEmpty()) {
        removeNode(begin());
    }
    
}

template <typename Type>
void BaseList<Type>::move(Iterator at, Iterator before) {
    if(at.m_list->getSize() == 0)
        return;
    
    at.m_node->m_prev->m_next = at.m_node->m_next;
    at.m_node->m_next->m_prev = at.m_node->m_prev;
    --at.m_list->m_size;
    
    at.m_list->notify(at.m_node, [&before](IIterator *it){
        it->setList(before.m_list);
        before.m_list->subscribe(it);
    });
    
    at.m_node->m_next = before.m_node;
    at.m_node->m_prev = before.m_node->m_prev;
    before.m_node->m_prev->m_next = at.m_node;
    before.m_node->m_prev = at.m_node;
    ++before.m_list->m_size;
    
}

template <typename Type>
void BaseList<Type>::sort() {
    
    for(auto it = begin(); it != end(); it++)
        for(auto jt = begin(); jt != end(); jt++)
            if(*it < *jt)
                std::swap(it.m_node->m_value, jt.m_node->m_value);
    
}

template <typename Type>
Type& BaseList<Type>::operator [] (const int index) {
    assert(index < m_size);
    
    Node* temp = m_head->m_next;
    
    for(int i = 0; i < index; ++i) {
        temp = temp->m_next;
    }
    
    return *temp->m_value;
}

template <typename Type>
const Type& BaseList<Type>::operator [] (const int index) const {
    assert(index < m_size);
    
    Node* temp = m_head->m_next;
    
    for(int i = 0; i < index; ++i) {
        temp = temp->m_next;
    }
    
    return temp->m_value;
}

template <typename Type>
BaseList<Type>& BaseList<Type>::operator = (const BaseList<Type>& other) {
    
    if(m_head != other.m_head) {
        clear();
        
        for (const Type &value : other) {
            push_back(value);
        }
        
    }
    
    return *this;
}

template <typename Type>
bool BaseList<Type>::operator == (const BaseList<Type>& other) const {
    if(m_size != other.m_size)
        return false;
    if(m_head == other.m_head)
        return true;
    
    auto it = begin();
    auto otherIt = other.begin();
    auto itEnd = end();
    while(it != itEnd) {
        if(*it != *otherIt) {
            return false;
        }
        
        ++it;
        ++otherIt;
    }
    
    return true;
}

template <typename Type>
bool BaseList<Type>::operator != (const BaseList<Type>& other) const {
    return !(*this==other);
}

template <typename Type>
BaseList<Type> BaseList<Type>::operator + (const BaseList<Type>& other) const {
    
    BaseList<Type> result(*this);
    result += other;
    return result;
}

template <typename Type>
BaseList<Type>& BaseList<Type>::operator += (const BaseList<Type>& other) {
    
    for(auto it = other.begin(); it != other.end(); ++it) {
        this->push_back(*it);
    }
    
    return *this;
}


/* private */
template <typename Type>
void BaseList<Type>::generateListBasis() {
    if(m_head != nullptr)
        delete m_head;
    if(m_tail != nullptr)
        delete m_tail;
    
    m_head = new Node ();
    m_tail = new Node ();
    
    
    m_head->m_next = m_tail;
    m_head->m_prev = nullptr;
    m_tail->m_next = nullptr;
    m_tail->m_prev = m_head;
}

template <typename Type>
void BaseList<Type>::insertNode(const Iterator &currentNode, const Type& value) {
    if(!currentNode.isValid()) {
        return;
    }
    
    Node* newNode = new Node ( Node(value, currentNode.m_node, currentNode.m_node->m_prev) );
    
    currentNode.m_node->m_prev->m_next = newNode;
    currentNode.m_node->m_prev = newNode;
    
    ++m_size;
}

template <typename Type>
void BaseList<Type>::removeNode(const Iterator& currentNode) {
    if(!(currentNode.isValid())) {
        return;
    }
    
    removeNode(currentNode.m_node);
    
}

template <typename Type>
void BaseList<Type>::removeNode(Node* currentNode) {
    if(currentNode == nullptr || currentNode->m_next == nullptr)
        return;
    
    assert(m_size > 0);
    
    notify(currentNode, [](IIterator *it) {
        it->invalidate();
    });
    currentNode->m_next->m_prev = currentNode->m_prev;
    currentNode->m_prev->m_next = currentNode->m_next;
    delete currentNode;
    --m_size;
}

/* Iterator */
template <typename Type>
template <typename IterType, typename ListType>
typename BaseList<Type>::template
TemplateIterator<IterType, ListType>& BaseList<Type>::TemplateIterator<IterType, ListType>::operator ++ () {
    if (!isValid()) {
        return *this;
    }
    
    m_node = m_node->m_next;
    if (this->m_node->m_prev == m_list->m_tail) {
        invalidate();
    }
    
    return *this;
}

template <typename Type>
template <typename IterType, typename ListType>
typename BaseList<Type>::template
TemplateIterator<IterType, ListType> BaseList<Type>::TemplateIterator<IterType, ListType>::operator ++ (int) {
    
    TemplateIterator old(m_list, m_node);
    ++(*this);
    return old;
    
}

template <typename Type>
template <typename IterType, typename ListType>
typename BaseList<Type>::template
TemplateIterator<IterType, ListType> BaseList<Type>::TemplateIterator<IterType, ListType>::operator + (const int value) const {
    assert(value <= m_list->getSize());
    
    TemplateIterator result(m_list, m_node);
    for(int i = 0; i < value; ++i) {
        ++result;
    }
    
    return result;
}

template <typename Type>
template <typename IterType, typename ListType>
typename BaseList<Type>::template
TemplateIterator<IterType, ListType>& BaseList<Type>::TemplateIterator<IterType, ListType>::operator += (const int value){
    *this = *this + value;
    return *this;
}

template <typename Type>
template <typename IterType, typename ListType>
typename BaseList<Type>::template
TemplateIterator<IterType, ListType>& BaseList<Type>::TemplateIterator<IterType, ListType>::operator -- () {
    if (!isValid()) {
        return *this;
    }
    
    m_node = m_node->m_prev;
    if (this->m_node == m_list->m_head)
        invalidate();
    
    return *this;
}

template <typename Type>
template <typename IterType, typename ListType>
typename BaseList<Type>::template
TemplateIterator<IterType, ListType> BaseList<Type>::TemplateIterator<IterType, ListType>::operator -- (int) {
    TemplateIterator old(m_list, m_node);
    --(*this);
    return old;
}

template <typename Type>
template <typename IterType, typename ListType>
typename BaseList<Type>::template
TemplateIterator<IterType, ListType> BaseList<Type>::TemplateIterator<IterType, ListType>::operator - (const int value) const {
    assert(value <= m_list->getSize());
    
    TemplateIterator result(m_list, m_node);
    for(int i = value; i > 0; --i) {
        --result;
    }
    
    return result;
}

template <typename Type>
template <typename IterType, typename ListType>
typename BaseList<Type>::template
TemplateIterator<IterType, ListType>& BaseList<Type>::TemplateIterator<IterType, ListType>::operator -= (const int value){
    *this = *this - value;
    return *this;
}
 
template <typename Type>
template <typename IterType, typename ListType>
bool BaseList<Type>::TemplateIterator<IterType, ListType>::operator == (const TemplateIterator& other) const {
    return (m_node == other.m_node) && (m_list == other.m_list);
}

template <typename Type>
template <typename IterType, typename ListType>
bool BaseList<Type>::TemplateIterator<IterType, ListType>::operator != (const TemplateIterator& other) const {
    return !(*this == other);
}

template <typename Type>
std::ostream& operator << (std::ostream& stream, const BaseList<Type>& other) {
    stream << "[";
    for(auto it = other.begin(); it != other.end(); it++) {
        stream << *it << (it != (other.end() - 1) ? ", ":"");
    }
    stream << "]";
    
    return stream;
}

template  <typename Type>
std::istream& operator >> (std::istream& stream, BaseList<Type>& other) {
    
    for(auto it = other.begin(); it != other.end(); ++it) {
        stream >> *it;
    }
    
    return stream;
}

#endif //!ARE_TEMPLATE_LIST_METHODS_DEFINED
