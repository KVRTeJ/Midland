#include "List.hpp"

List::List() {
    
    m_size = 0;
    m_head = new Node (sizeof(Node) * 1);
    m_tail = new Node (sizeof(Node) * 1);
    
    m_head->m_next = m_tail;
    m_head->m_prev = nullptr;
    m_tail->m_next = nullptr;
    m_tail->m_prev = m_head;
    
}
