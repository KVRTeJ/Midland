#pragma once

#include "BoolMatrix.hpp"
#include "BaseList.hpp"

class Graph {
public:
    struct Leader;
public:
    Graph();
    
    BoolMatrix matrix() const;
    /*
     А что если отнаследоваться(или агрегировать) от(по) BoolMatrix, (Для примера можно назвать AdjacencyMatrix)
     добавить приведение типа к Graph и обратно, добавить метод топологической сортировки,
     и сделать этот класс полем для класса Graph?
    */
    
    void scan();
    void print() const;
    void addVertex(const int from, const int to);
    void deleteVertex(const int from, const int to);
    
    
    std::vector<int> TopologicalSort();
    
private:
    bool shiftIterator(auto& iter, const auto& end, const int key) const;
    List<Leader* > m_leaders;
    
};

struct Graph::Leader {
    Leader(const int key)
    : key(key)
    {}
    
    void addTrailer(Leader* lead) {
        trailers.push_back(lead);
        ++lead->degree;
    }
    void deleteTrailer(Leader* lead) {
        auto target = trailers.find(lead);
        if(target != trailers.end()) {
            trailers.erase(target);
            --lead->degree;
        }
    }
    int key = 0;
    int degree = 0;
    List<Leader* > trailers;
};

std::vector<int> TopologicalSort(BoolMatrix& adjacencyMatrix);
