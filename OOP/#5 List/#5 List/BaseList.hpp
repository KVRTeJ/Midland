#ifndef IS_TEMPLATE_LIST_DECLARED
#define IS_TEMPLATE_LIST_DECLARED

#include <iostream>
#include <string>
#include <vector>

#include "Array.hpp"

template <typename Type>
class BaseList {
public:
    class Node;
    
public:
    class IIterator;
    template <typename IterType, typename ListType>
    class TemplateIterator;
    using Iterator = TemplateIterator<Type, BaseList>;
    using ConstIterator = TemplateIterator<const Type, const BaseList>;
    
public:
    BaseList(const int size = 0, const Type& value = Type());
    BaseList(const Array<Type>& value);
    BaseList(const BaseList& other);
    virtual ~BaseList();
    
    virtual void subscribe(IIterator* iter) const {}
    virtual void unsubscribe(IIterator* iter) const {}
    virtual void notify(Node* deleted, std::function<void(IIterator *)> action, bool eraseAfterAction = true) {}
    
    
    unsigned int getSize() const {return m_size;}
    void swap(BaseList& other);
    
    Iterator begin() {return Iterator(this, m_head->m_next);}
    Iterator end() {return Iterator(this, m_tail);}
    
    ConstIterator begin() const {return ConstIterator(this, m_head->m_next);}
    ConstIterator end() const {return ConstIterator(this, m_tail);}
    
    Iterator find(const Type& key);
    ConstIterator find(const Type& key) const;
    
    void insert(const unsigned pos, const Type& value);
    void insert(const Iterator& iter, const Type& value);
    void insertAfter(const Type& key, const Type& value);
    void push_back(const Type& value);
    void push_front(const Type& value);
    
    void erase(const unsigned pos);
    void erase(const Iterator& iter);
    void erase(const Iterator& from, const Iterator& to);
    void eraseFirst(const Type& key);
    void pop_back();
    void pop_front();
    
    Type max() const;
    Type min() const;
    bool isEmpty() const {return m_head->m_next == m_tail;}
    void clear();
    void move(Iterator at, Iterator before);
    void sort();

    
    Type& operator [] (const int index);
    const Type& operator [] (const int index) const;
    BaseList& operator = (const BaseList& other);
    bool operator == (const BaseList& other) const;
    bool operator != (const BaseList& other) const;
    BaseList operator + (const BaseList& other) const;
    BaseList& operator += (const BaseList& other);
    
private:
    void generateListBasis();
    void insertNode(const Iterator &currentNode, const Type& value);
    void removeNode(const Iterator& currentNode);
    void removeNode(Node* currentNode);
    
    Node* m_head = nullptr;
    Node* m_tail = nullptr;
    unsigned int m_size = 0;
    
};

template <typename Type>
class BaseList<Type>::Node {
    friend class BaseList;
private:
    Node(const Type& value = Type(), Node* next = nullptr, Node* prev = nullptr)
    :m_next(next), m_prev(prev)
    {
        m_value = new Type(value);
    }
    ~Node() {delete m_value;}
    
    Type* m_value = nullptr;
    Node* m_next = nullptr;
    Node* m_prev = nullptr;
    
};

template <typename Type>
class BaseList<Type>::IIterator {
public:
    virtual bool isValid() const = 0;
    virtual void invalidate() = 0;
    virtual bool pointsTo(const Node *node) const = 0;
    virtual ~IIterator() = default;
    //TODO: move to protected, IIterator -> AbstractIterator
    virtual void setList(BaseList *list) = 0;
};

template <typename Type>
template <typename IterType, typename ListType>
class BaseList<Type>::TemplateIterator : public IIterator {
    friend class BaseList;
public:
    TemplateIterator(ListType* list = nullptr, Node* node = nullptr)
    : m_list(list), m_node(node)
    {
        IIterator* a = this;
        m_list->subscribe(a);
    }
    ~TemplateIterator() override {
        if(isValid()) {
            m_list->unsubscribe(this);
        }
    }
    
    IterType& operator * () {assert(m_node != nullptr); return *m_node->m_value;}
    
    TemplateIterator& operator ++ ();
    TemplateIterator operator ++ (int);
    TemplateIterator operator + (const int value) const;
    TemplateIterator& operator += (const int value);
    
    TemplateIterator& operator -- ();
    TemplateIterator operator -- (int);
    TemplateIterator operator - (const int value) const;
    TemplateIterator& operator -= (const int value);
    
    bool operator == (const TemplateIterator& other) const ;
    bool operator != (const TemplateIterator& other) const ;
    
    bool pointsTo(const Node* node) const override {return m_node == node;}
    bool isValid() const override {return m_node != nullptr;}
    void invalidate() override {m_node = nullptr; m_list = nullptr;}
    void setList(BaseList *list) override { m_list = list;}
private:
    Node* m_node = nullptr;
    ListType* m_list = nullptr;
};

template <typename Type>
std::ostream& operator << (std::ostream& stream, const BaseList<Type>& other);

template <typename Type>
std::istream& operator >> (std::istream& stream, BaseList<Type>& other);


template <typename Type>
class List: public BaseList<Type> {
public:
    using typename BaseList<Type>::IIterator;
    using typename BaseList<Type>::Node;
public:
    List(const int size = 0, const Type& value = Type())
    : BaseList<Type>(size, value)
    {
        iterators = new BaseList<IIterator* >(0);
    }
    List(const Array<Type>& value)
    : BaseList<Type>(value)
    {
        iterators = new BaseList<IIterator* >(0);
        
    }
    List(const List<Type>& other)
    : BaseList<Type>(other)
    {
        iterators = new BaseList<IIterator* >(0);
    }
    
    ~List() {delete iterators;}
    
    void subscribe(IIterator* iter) const override {
        if(iter->isValid())
            iterators->push_back(iter);
    }
    void unsubscribe(IIterator* iter) const override {
        iterators->eraseFirst(iter);
    }
    
    void notify(Node* deleted, std::function<void(IIterator *)> action, bool eraseAfterAction = true) override {
        for(auto it = iterators->begin(); it != iterators->end();) {
            if( !(*it)->isValid() || (*it)->pointsTo(deleted)) {
                action(*it);
                
                if (eraseAfterAction)
                    iterators->erase(it++);
            } else {
                ++it;
            }
        }
        
    }
    
    List& operator = (const List& other) {
        if(&other == this)
            return *this;
        for (auto *iter : *iterators) {
            iter->invalidate();
        }
        iterators->clear();
        BaseList<Type>::operator=(other);
        return *this;
    }
    
private:
    BaseList<IIterator* > *iterators = nullptr;
};

#include "BaseList.cpp"

#endif //!IS_TEMPLATE_LIST_DECLARED
