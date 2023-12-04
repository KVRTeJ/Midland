#include "TopSort.hpp"

#define forever for(;;)
void appendVertex(std::vector<int>& result, BoolVector& vertexes) {
    int i = 0;
    unsigned resSize = (unsigned) vertexes.getLenth();
    
    forever {
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
    BoolVector finishedVertex(size), noEnteringVertex, forResult;
    
    while(result.size() != size) { //пока А не пусто ??
        noEnteringVertex = adjacencyMatrix.getDisjunctionRows();
        if(noEnteringVertex.weight() != size) {
            noEnteringVertex = ~noEnteringVertex;
                std::cout << "noEntVer - " << noEnteringVertex;
            
            forResult = noEnteringVertex & ~finishedVertex;
                std::cout << "  resVertex - " << forResult;
            
            finishedVertex |= forResult;
                std::cout << "    finVer - " << finishedVertex;
            
            appendVertex(result, forResult);
            //зануление строк
        } else {
            result.clear();
            break;
        }
    }
    
    return result;
}
