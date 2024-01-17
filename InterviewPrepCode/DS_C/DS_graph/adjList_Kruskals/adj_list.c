#include "adj_list.h"
#include "linkd_lst.h"

Graph * create_graph(unsigned int vertex_amount) {
    Graph *new_graph = (Graph *)malloc(sizeof(Graph)); 
    if(!(new_graph)) return NULL; 
    new_graph->vertex_amount = vertex_amount; 
    new_graph->edge_amount = 0; 

    new_graph->adj_list = (node **)malloc(sizeof(node *) * vertex_amount); 
    if(!(new_graph->adj_list)) return NULL; 

    for(int i = 0; i < vertex_amount; i++) {
        new_graph->adj_list[i] = NULL; 
    }

    return new_graph; 
}

Edges * create_edge_array(int total_edges) {
    Edges *array_of_edges = (Edges *)malloc(sizeof(Edges) * total_edges); 
    if(!(array_of_edges)) return NULL; 

    return array_of_edges; 
}

void print_edge_array(Edges *edge_array, int total_edges) {
    printf("Src | Dest | Weight \n"); 
    for(int i = 0; i < total_edges; i++) {
        printf("%d  | %d   | %d \n", edge_array[i].src, edge_array[i].dest, edge_array[i].weight);
    }
}

void add_edge(Graph *graph, int src, int dest, int weight, Edges *edge_array) {
    insert(&graph->adj_list[src], dest, weight); 

    insert(&graph->adj_list[dest], src, weight); 

    edge_array[graph->edge_amount].src = src; 
    edge_array[graph->edge_amount].dest = dest; 
    edge_array[graph->edge_amount].weight = weight; 
    graph->edge_amount++; 
} 

void print_graph(Graph *graph) {
    printf("Graph with %d vertices and %d edges.\n", graph->vertex_amount, graph->edge_amount); 
    for(int i = 0; i < graph->vertex_amount; i++) {
       print_list(graph->adj_list[i], i);  
    }
}

void free_graph(Graph *graph) {
    for(int i = 0; i < graph->vertex_amount; i++) {
        free_list(graph->adj_list[i]); 
    }
    free(graph->adj_list); 
    free(graph); 
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
