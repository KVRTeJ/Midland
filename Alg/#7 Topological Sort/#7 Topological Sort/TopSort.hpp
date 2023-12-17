#pragma once

#include "BoolMatrix.hpp"
#include "BaseList.hpp"

class Graph {
public:
    struct Leader;
public:
    Graph();
    void scan();
    void print() const;
    void addVertex(const int from, const int to);
    void deleteVertex(const int from, const int to);
    
    std::vector<int> TopologicalSort(Graph& adjacencyMatrix);
    
private:
    void shiftIterator();
    List<Leader* > leaders;
    
};

struct Graph::Leader {
    Leader(const int key)
    : key(key)
    {}
    
    void addTrailer(Leader* lead) {
        trailers.push_back(lead);
        ++lead->degree;
    }
    
    int key = 0;
    int degree = 0;
    List<Leader* > trailers;
};

std::vector<int> TopologicalSort(BoolMatrix& adjacencyMatrix);
