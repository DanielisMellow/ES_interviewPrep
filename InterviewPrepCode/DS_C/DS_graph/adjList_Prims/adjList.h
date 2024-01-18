#ifndef _ADJ_LIST_H
#define _ADJ_LIST_H
#include "linked_list.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct graph {
    // total number of vertices in graph
    unsigned int num_of_vertices;
    // array of heads
    node **adjList;
}Graph; 

Graph *create_graph(unsigned int num_of_vertices); 

void add_edge(Graph *g, int source, int dest, int weight); 

void print_graph(Graph *g); 

void free_graph(Graph *g); 



#endif
