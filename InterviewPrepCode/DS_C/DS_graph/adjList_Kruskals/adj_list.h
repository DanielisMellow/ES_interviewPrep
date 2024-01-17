#ifndef _ADJ_LIST_H
#define _ADJ_LIST_H
#include "linkd_lst.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct graph {
    unsigned int vertex_amount; 
    unsigned int edge_amount; 
    node **adj_list; 
}Graph; 

typedef struct edges {
    int src, dest, weight; 
}Edges; 

// Creates a graph with vertex_amount of vertices
Graph * create_graph(unsigned int vertex_amount); 

// Creates an array of edges
Edges * create_edge_array(int total_edges);

// Prints edge array
void print_edge_array(Edges *edge_array, int total_edges); 

// adds an edge to the graph from src to des, and des to src (undirected)
void add_edge(Graph *graph, int src, int dest, int weight, Edges * edge_array); 

// prints graph
void print_graph(Graph *graph); 

// fress graph
void free_graph(Graph *graph); 


#endif
