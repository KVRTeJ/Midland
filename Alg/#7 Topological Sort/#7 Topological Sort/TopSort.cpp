#include "TopSort.hpp"

Graph::Graph() {
    m_leaders.push_back(new Leader(1));
}

Graph::Graph(const BoolMatrix& adjacencyMatrix) {
    if(adjacencyMatrix.getRowCount() != adjacencyMatrix.getColumnCount()) {
        std::cerr << "Graph::Graph(const BoolMatrix& adjacencyMatrix) - exit with code: -1\n";
        m_leaders.push_back(new Leader(1));
        return;
    }
    
    int size = adjacencyMatrix.getRowCount();
    for(int i = 0; i < size; ++i)
        for(int j = 0; j < size; ++j)
            if(adjacencyMatrix[i][j])
                addArc(i + 1, j + 1);
    
}

Graph::~Graph() {
    for(auto it = m_leaders.begin(); it != m_leaders.end();)
        delete *(it++);
}

BoolMatrix Graph::matrix() const {
    const int MAX_SIZE = m_leaders.getSize();
    BoolMatrix matrix(MAX_SIZE, MAX_SIZE);
    
    int leadKey = -1, trailKey = -1;
    for(auto itLead = m_leaders.begin(); itLead != m_leaders.end(); ++itLead) {
        for(auto itTrail = (*itLead)->m_trailers.begin();
            itTrail != (*itLead)->m_trailers.end(); ++itTrail) {
            if( (*itLead)->m_key > MAX_SIZE)
                leadKey = MAX_SIZE - 1;
            else
                leadKey = (*itLead)->m_key - 1;
            
            if( (*itTrail)->m_key > MAX_SIZE)
                trailKey = MAX_SIZE - 1;
            else
                trailKey = (*itTrail)->m_key - 1;
            
            matrix.set(leadKey, trailKey, true);
        }
    }
            
    return matrix;
}

void Graph::scan() {
    m_leaders.clear();
    m_leaders.push_back(new Leader(1));
    std::cout << "Input Graph\nExample -1 2\n";
    std::cout << "To stop input push -0 0" << std::endl;
    
    int from = 1, to = 1;
    while(true) {
        std::cout << "-";
        scanf("%d%d", &from, &to);
        if(from == 0 || to == 0)
            return;
        else if(from < 0 || to < 0) {
            std::cout << "from and to can't be < 0" << std::endl;
            continue;
        }
        addArc(from, to);
        //std::cout << "a - " << a << " b - " << b << std::endl;
    }
}

void Graph::print() const {
    
    for(auto itLead = m_leaders.begin(); itLead != m_leaders.end(); ++itLead) {
        for(auto itTrail = (*itLead)->m_trailers.begin();
            itTrail != (*itLead)->m_trailers.end(); ++itTrail) {
            
            std::cout << "{" << (*itLead)->m_key << ", "
            << (*itTrail)->m_key << "}"
            << ((itTrail + 1) == (*itLead)->m_trailers.end() ? "\n":", ");
            
        }
    }
    std::cout << std::endl;
    
}

void Graph::addArc(const int from, const int to) {
    const auto END = m_leaders.end();
    
    auto iterFrom = m_leaders.begin();
    auto iterTo = m_leaders.begin();

    if(!find(iterFrom, END, from)) {
        auto newLead = new Leader(from);
        m_leaders.push_back(newLead);
        iterFrom = m_leaders.find(newLead);
    }
    
    if(!find(iterTo, END, to)) {
        auto newLead = new Leader(to);
        m_leaders.push_back(newLead);
        iterTo = m_leaders.find(newLead);
    }
    
    for(auto it = (*iterFrom)->m_trailers.begin(); it != (*iterFrom)->m_trailers.end(); ++it) {
        if((*it)->m_key == (*iterTo)->m_key)
           return; //already has arc
    }
    
    (*iterFrom)->addTrailer(*iterTo);
}

void Graph::deleteArc(const int from, const int to) {
    const auto END = m_leaders.end();
    
    auto iterFrom = m_leaders.begin();
    auto iterTo = m_leaders.begin();
    if(find(iterFrom, END, from) && find(iterTo, END, to)) {
        std::cout << "From - " << (*iterFrom)->m_key << " To - " << (*iterTo)->m_key << std::endl;
        (*iterFrom)->deleteTrailer(*iterTo);
    }
    
}

std::vector<int> Graph::TopologicalSort() {
    std::vector<int> result;
    BoolMatrix reserve = matrix();
    
    List<Leader* > newLead;
    do {
        for(auto it = m_leaders.begin(); it != m_leaders.end();) {
            if( (*it)->m_degree == 0) {
                result.push_back((*it)->m_key);
                m_leaders.move(it++, newLead.begin());
            }
            else
                ++it;
        }
        if(newLead.isEmpty())
            break;
        
        auto p = *(newLead.begin());
        auto temp = p->m_trailers.begin();
        while(!p->m_trailers.isEmpty()) {
            --(*temp)->m_degree;
            assert( (*temp)->m_degree >= 0);
            if( (*temp)->m_degree == 0)
                newLead.push_front(*temp);
            p->m_trailers.pop_front();
            temp = p->m_trailers.begin();
        }
        newLead.pop_front();
    }
    while(!newLead.isEmpty());
    
    int size = reserve.getRowCount();
    for(int i = 0; i < size; ++i)
        for(int j = 0; j < size; ++j)
            if(reserve[i][j])
                addArc(i + 1, j + 1);
    
    
    return result;
}

/*private*/
bool Graph::find(List<Leader* >::Iterator& iter, const List<Leader* >::Iterator& end, const int key) const {
    
    while(iter != end) {
        if((*iter)->m_key == key) {
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

