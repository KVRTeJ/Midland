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
    
//private:
    List<Leader* > leaders;
    
};

struct Graph::Leader {
    Leader(const int key, const int degree = 0)
    : key(key),
    degree(degree)
    {}
    
    int key = 0;
    int degree = 0;
    List<Leader* > trailers();
};

std::vector<int> TopologicalSort(BoolMatrix& adjacencyMatrix);
