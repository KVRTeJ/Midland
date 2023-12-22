#pragma once

#include "BoolMatrix.hpp"
#include "BaseList.hpp"

class Graph {
private:
    struct Leader;
public:
    Graph();
    Graph(const BoolMatrix& adjacencyMatrix);
    ~Graph();
    
    BoolMatrix matrix() const;
    
    void scan();
    void print() const;
    void addArc(const int from, const int to);
    void deleteArc(const int from, const int to);
    
    std::vector<int> TopologicalSort();
    
    
    
private:
    bool find(List<Leader* >::Iterator& iter, const List<Leader* >::Iterator& end, const int key) const;
    List<Leader* > m_leaders;
    
};

class Graph::Leader {
    friend class Graph;
public:
    Leader(const int key)
    : m_key(key)
    {}
private:
    void addTrailer(Leader* lead) {
        m_trailers.push_back(lead);
        ++lead->m_degree;
    }
    void deleteTrailer(Leader* lead) {
        auto target = m_trailers.find(lead);
        if(target != m_trailers.end()) {
            m_trailers.erase(target);
            --lead->m_degree;
        }
    }
    int m_key = 0;
    int m_degree = 0;
    List<Leader* > m_trailers;
};

std::vector<int> TopologicalSort(BoolMatrix& adjacencyMatrix);
