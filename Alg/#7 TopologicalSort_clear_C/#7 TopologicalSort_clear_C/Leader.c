#include "Leader.h"

void printGraph(struct Leader* graph) {
    
    for(struct Leader* it = graph; it; it = it->next) {
        printf("%d -> ", it->key);
        for(struct Trailer* itTrailer = it->trailers; itTrailer; itTrailer = itTrailer->next){
            printf("%d ", itTrailer->lead->key);
        }
        printf("\n");
    }
}

void addArc(struct Leader* graph, const int From, const int To) {
    struct Leader* ptrFrom = NULL;
    struct Leader* ptrTo = NULL;
    
    for(ptrFrom = graph; ptrFrom; ptrFrom = ptrFrom->next) {
        if(ptrFrom->key == From)
            break;
    }
    for(ptrTo = graph; ptrTo; ptrTo = ptrTo->next) {
        if(ptrTo->key == From)
            break;
    }
    
    _Bool needSet = 1;
    
    if(ptrFrom && ptrTo) {
        for(struct Trailer* it = ptrFrom->trailers; it; it = it->next) {
            if(it->lead == ptrTo)
                needSet = 0;
        }
    } else {
        if(!ptrFrom) {
            ptrFrom = malloc(1*sizeof(struct Leader));
            if(!ptrFrom) {
                printf("addArc: allocation ptrFrom faled\n");
                return;
            }
            
            ptrFrom->key = From;
            ptrFrom->st = 0;
            ptrFrom->next = graph;
            graph = ptrFrom;
            ptrFrom->trailers = NULL;
        }
        if(!ptrTo) {
            ptrTo = malloc(1*sizeof(struct Leader));
            if(!ptrTo) {
                printf("addArc: allocation ptrTo faled\n");
                return;
            }
            
            ptrTo->key = To;
            ptrTo->st = 0;
            ptrTo->next = graph;
            graph = ptrTo;
            ptrTo->trailers = NULL;
        }
    }
    
    if(needSet) {
        ++ptrTo->st;
        struct Trailer* newTrailer = malloc(1*sizeof(struct Trailer));
        if(!newTrailer) {
            printf("addArc: allocation ptrFrom->trailers faled\n");
            return;
        }
        
        newTrailer->lead = ptrTo;
        newTrailer->next = ptrFrom->trailers;
        ptrFrom->trailers = newTrailer;
    }
    
    ptrTo = NULL;
    ptrFrom = NULL;
    
}
