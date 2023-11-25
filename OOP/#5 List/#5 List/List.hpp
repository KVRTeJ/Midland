#pragma once

#include <iostream>

class List {
private:
    class Node;
public:
    List();
   // ~List();
    
    Node front();//первый элемент
    Node back();//последний элемент
    
    void push_back();
    void push_front();
    
private:
    Node* m_head = nullptr;
    Node* m_tail = nullptr;
    unsigned int m_size = 0;
    
};


class List::Node {
public:
    Node(const int value = 0, Node* next = nullptr, Node* prev = nullptr)
    : m_value(value), m_next(next), m_prev(prev)
    { }
    
    int m_value = 0; //Type
    Node* m_next = nullptr;
    Node* m_prev = nullptr;
    
};
