#include "TopSort.hpp"

Graph::Graph() {
    leaders.push_back(new Leader(1));
}


void Graph::addVertex(const int from, const int to) {
    if(from == 0 || to == 0)
        return;
    if(from == to) {
        std::cerr << from << " cannot be included by itself" << std::endl;
        return;
    }
    
    bool isFrom = false, isTo = false;
    const auto END = leaders.end();
    
    auto iterFrom = leaders.begin();
    while(iterFrom != END) {
        if((*iterFrom)->key == from) {
            isFrom = true;
            break;
        }
        ++iterFrom;
    }
    
    auto iterTo = leaders.begin();
    while(iterTo != END) {
        if((*iterTo)->key == to) {
            isTo = true;
            break;
        }
        ++iterTo;
    }
    
    if(!isFrom) {
        auto newLead = new Leader(from);
        leaders.push_back(newLead);
        iterFrom = leaders.find(newLead);
    }
    
    if(!isTo) {
        auto newLead = new Leader(to);
        leaders.push_back(newLead);
        iterTo = leaders.find(newLead);
    }
    
    for(auto it = (*iterFrom)->trailers.begin(); it != (*iterFrom)->trailers.end(); ++it) {
        if((*it)->key == (*iterTo)->key)
           return;
    }
    (*iterFrom)->addTrailer(*iterTo);
    //std::cout << "From - " << (*iterFrom)->key << "\nTo - " << (*iterTo)->key << std::endl;
}


#define forever for(;;)
void appendVertex(std::vector<int>& result, BoolVector vertexes) {
    int i = 0;
    unsigned resSize = (unsigned) vertexes.getLenth();
    
    forever { //TODO: убрать forever => (i >= resSize)
        while(vertexes[i] != true) {
            if(i >= resSize - 1)
                return;
            ++i;
        }
        vertexes[i] = 0;
        result.push_back(i);
    }
    
}

std::vector<int> TopologicalSort(BoolMatrix& adjacencyMatrix) {
    
    std::vector<int> result;
    const int size = adjacencyMatrix.getColumnCount();
    BoolVector finishedVertex(size), noEnteringVertex, newVertexes;
    
    std::vector<int> forClear;
    do {
        noEnteringVertex = ~adjacencyMatrix.getDisjunctionRows();
        if(noEnteringVertex.weight() == 0) {
            break;
        }
        
        newVertexes = noEnteringVertex & ~finishedVertex;
        finishedVertex |= newVertexes;
        appendVertex(result, newVertexes);
        appendVertex(forClear, newVertexes);
        
        while(!forClear.empty()) {
            adjacencyMatrix.set(forClear[0], 0, size - 1, 0);
            forClear.erase(forClear.begin());
        }
        
    }
    while((~finishedVertex).weight() != 0);
    
    return result;
}

