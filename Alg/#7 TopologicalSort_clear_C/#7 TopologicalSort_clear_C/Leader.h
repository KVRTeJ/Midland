#pragma once

#include <stdio.h>
#include <stdlib.h>

struct Trailer;

struct Leader {
    int key;
    int st;
    struct Leader* next;
    struct Trailer* trailers;

};

struct Trailer {
    struct Leader* lead;
    struct Trailer* next;
};

void printGraph(struct Leader* graph);

void addArc(struct Leader* lead, const int From, const int To);
void deleteArc(struct Leader* lead, const int From, const int To);
