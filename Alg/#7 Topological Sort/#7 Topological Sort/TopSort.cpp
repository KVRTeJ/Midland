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
    
    const auto END = leaders.end();
    
    auto iterFrom = leaders.begin();
    bool isFrom = shiftIterator(iterFrom, END, from);
    
    auto iterTo = leaders.begin();
    bool isTo = shiftIterator(iterTo, END, to);

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
    
}

void Graph::deleteVertex(const int from, const int to) {
    if(from == 0 || to == 0)
        return;
    if(from == to)
        return;
    
    const auto END = leaders.end();
    
    auto iterFrom = leaders.begin();
    auto iterTo = leaders.begin();
    if(shiftIterator(iterFrom, END, from) && shiftIterator(iterTo, END, to)) {
        std::cout << "From - " << (*iterFrom)->key << " To - " << (*iterTo)->key << std::endl;
        (*iterFrom)->deleteTrailer(*iterTo);
    }
    
    
}

/*private*/
bool Graph::shiftIterator(auto& iter, const auto& end, const int key) const {
    while(iter != end) {
        if((*iter)->key == key) {
            return true;
        }
        ++iter;
    }
    return false;
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

