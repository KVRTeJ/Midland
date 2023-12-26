#include "Leader.h"

_Bool isEdge(struct Leader* graph, const int from, const int to) {
    
    struct Leader* ptrFrom = NULL;
    struct Leader* ptrTo = NULL;
    for(ptrFrom = graph; ptrFrom; ptrFrom = ptrFrom->next) {
        if(ptrFrom->key == from)
            break;
    }
    for(ptrTo = graph; ptrTo; ptrTo = ptrTo->next) {
        if(ptrTo->key == to)
            break;
    }
    if(ptrFrom && ptrFrom->trailers && ptrTo) {
        struct Trailer* tempTp = NULL;
        for(tempTp = ptrFrom->trailers; tempTp; tempTp = tempTp->next) {
            if(tempTp->lead == ptrTo)
                break;
        }
        
        return tempTp;
    }
        
    return 0;
}

void print(struct Leader* graph) {
    if(!graph) {
        printf("Graph is empty\n");
    }
    
    for(struct Leader* it = graph; it; it = it->next) {
        if(!it->key)
            continue;
        printf("%d -> ", it->key);
        for(struct Trailer* itTrailer = it->trailers; itTrailer; itTrailer = itTrailer->next){
            printf("%d ", itTrailer->lead->key);
        }
        printf("\n");
    }
}


void scan(struct Leader** graph) {
    printf("To stop scan enter -0 0\n");
    
    int a = -1, b = -1;
    while(a != 0 || b != 0) {
        scanf("%d %d", &a, &b);
        addArc(graph, a, b);
    }
    
}

void addArc(struct Leader** graph, const int From, const int To) {
    if(From == To) {
        printf("%d cannot be included by inself\n", From);
        return;
    }
    
    struct Leader* ptrFrom = NULL;
    struct Leader* ptrTo = NULL;
    
    for(ptrFrom = *graph; ptrFrom; ptrFrom = ptrFrom->next) {
        if(ptrFrom->key == From)
            break;
    }
    for(ptrTo = *graph; ptrTo; ptrTo = ptrTo->next) {
        if(ptrTo->key == To)
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
            ptrFrom->next = *graph;
            *graph = ptrFrom;
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
            ptrTo->next = *graph;
            *graph = ptrTo;
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
    
    return;
}


void excludeArc(struct Leader** graph, const int From, const int To) { //FIXME: fixme
    
    struct Leader* ptrFrom = NULL;
    struct Leader* ptrTo = NULL;
    for(ptrFrom = (*graph); ptrFrom; ptrFrom = ptrFrom->next) {
        if(ptrFrom->key == From)
            break;
    }
    for(ptrTo = (*graph); ptrTo; ptrTo = ptrTo->next) {
        if(ptrTo->key == To)
            break;
    }
    
    if(ptrFrom && ptrFrom->trailers && ptrTo) {
        if(ptrFrom->trailers->lead == ptrTo) {
            --ptrTo->st;
            struct Trailer* delTr = ptrFrom->trailers;
            ptrFrom->trailers = ptrFrom->trailers->next;
            free(delTr);
        } else {
            struct Trailer* tempTr;
            for(tempTr = ptrFrom->trailers; tempTr; tempTr = tempTr->next) {
                if(tempTr->lead == ptrTo) {
                    --ptrTo->st;
                    tempTr->next = tempTr->next->next;
                }
            }
        }
        
    }
    
}

void deleteGraph(struct Leader** graph) {
    
    while(*graph) {
        while((*graph)->trailers) {
            struct Trailer* deletedTr = (*graph)->trailers;
            (*graph)->trailers = (*graph)->trailers->next;
            free(deletedTr);
        }
        struct Leader* deleted = *graph;
        *graph = (*graph)->next;
        free(deleted);
    }
}
