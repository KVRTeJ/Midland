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

void print(struct Leader* graph);
void scan(struct Leader** graph);
_Bool isEdge(struct Leader* graph, const int from, const int to);

void addArc(struct Leader** graph, const int From, const int To);
void excludeArc(struct Leader** graph, const int From, const int To);

void deleteGraph(struct Leader** graph);
