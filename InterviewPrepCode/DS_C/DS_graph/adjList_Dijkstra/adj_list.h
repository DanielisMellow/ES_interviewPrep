#ifndef ADJ_LIST_H
#define ADJ_LIST_H
#include "list.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct graph {
    unsigned int vertex_amount; 
    unsigned int edge_amount; 
    node **adj_list; 
}graph;  

// creates a blank graph
graph * create_graph(unsigned int vertex_amount); 
// adds an edge to the graph and edge array
void add_edge(graph *graph, int src, int dest, int weight); 
// prints graph
void print_graph(graph *graph); 
// frees mem used by graph
void free_graph(graph *graph); 




#endif
