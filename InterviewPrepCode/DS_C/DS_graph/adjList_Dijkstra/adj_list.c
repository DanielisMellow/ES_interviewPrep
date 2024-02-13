#include "adj_list.h"
#include "list.h"

graph * create_graph(unsigned int vertex_amount) {
    graph *new_graph; 
    if((new_graph = (graph*)malloc(sizeof(graph))) == NULL) {
        return NULL; 
    }
    new_graph->vertex_amount = vertex_amount; 
    new_graph->edge_amount = 0;

    if((new_graph->adj_list = (node**)malloc(sizeof(node) * vertex_amount)) == NULL) {
        return NULL;  
    }

    for(int i = 0; i < new_graph->vertex_amount; i++) {
        new_graph->adj_list[i] = NULL;
    }
    return new_graph; 
}

void add_edge(graph *graph, int src, int dest, int weight) {
    insert_new_node(&graph->adj_list[src], dest, weight); 
    insert_new_node(&graph->adj_list[dest], src, weight); 

    graph->edge_amount++; 
}

void print_graph(graph *graph) {
    printf("Graph with %d vertices and %d edges.\n", graph->vertex_amount, graph->edge_amount); 
    for(int i = 0; i < graph->vertex_amount; i++) {
        print_list(graph->adj_list[i], i); 
    }
} 

void free_graph(graph *graph) {
    for(int i = 0; i < graph->vertex_amount; i++) {
        free_list(graph->adj_list[i]); 
    }
    free(graph->adj_list); 
    free(graph); 
}

// int main(void) {
//     
//     graph *graph = create_graph(5); 
//     
//     add_edge(graph, 0, 1, 5); 
//     add_edge(graph, 3, 4, 9); 
//     add_edge(graph, 2, 4, 2); 
//
//     print_graph(graph); 
//
//     free_mem(graph); 
//
//     return 0; 
// }
