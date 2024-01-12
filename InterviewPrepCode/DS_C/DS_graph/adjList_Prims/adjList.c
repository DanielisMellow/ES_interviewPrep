#include "adjList.h"
#include "linked_list.h"

Graph *create_graph(unsigned int num_of_vertices) {
    Graph *new_graph = malloc(sizeof(Graph)); 
    new_graph->num_of_vertices = num_of_vertices; 
    new_graph->adjList = malloc(num_of_vertices * sizeof(node *)); 

    // Initialize the graph to have no edges
    for(int i = 0; i < num_of_vertices; i++) {
        new_graph->adjList[i] = NULL; 
    }
    return new_graph; 
}

void add_edge(Graph *g, int source, int dest, int weight) {
    // add edge from source to dest
    insert(&g->adjList[source], dest, weight); 
    // because graph is undirected
    // Add edge from dest to source too
    insert(&g->adjList[dest], source, weight); 
}

void print_graph(Graph *g) {
    for (int i = 0; i < g->num_of_vertices; i++) {
        print_list(g->adjList[i], i); 
    }
}

void free_graph(Graph *g) {
    for (int i = 0; i < g->num_of_vertices; i++) {
        free_list(g->adjList[i]); 
    }
    free(g->adjList); 
    free(g); 
}

// int main(void) {
//
//     Graph *graph = create_graph(5); 
//     
//     add_edge(graph, 0, 1, 5); 
//     add_edge(graph, 3, 4, 9); 
//     add_edge(graph, 2, 4, 2); 
//
//     print_graph(graph); 
//
//     free_graph(graph); 
//
//     return 0; 
// }
