#include "disjoint_set.h"
#include "adj_list.h"
#include <stdlib.h>

int compare_val(const void *a, const void *b) {
    Edges *a1 = (Edges *)a; 
    Edges *b1 = (Edges *)b; 
    return (a1->weight - b1->weight); 
}

void kruskal_mst(Graph *graph, Edges *edge_array) {
    int total_vertices = graph->vertex_amount; 
    Edges result[total_vertices];
    int r = 0; 
    int i = 0; 

    Disjoint_Set *sub_set = make_set(total_vertices); 

    // Step 1: Sort the edges
    qsort(edge_array, graph->edge_amount, sizeof(edge_array[0]), compare_val); 
    // print_edge_array(edge_array, graph->edge_amount); 

    while(r < total_vertices - 1 && i < graph->edge_amount) {
        // Step 2: pick the smallest edge (the first one by default) 
        Edges next_edge = edge_array[i++]; 

        // If it doesn't form a cycle, add it to subset
        if(!(same_set(sub_set, next_edge.src, next_edge.dest))) {
            result[r++] = next_edge;   
            union_set(sub_set, next_edge.src, next_edge.dest); 
        }

        // Step 3: repeat until total edges is vertices - 1
    }

    printf("The following is the MST using Kruskal's Alg.\n"); 

    for(int i = 0; i < r; i++) {
        printf("%d -- %d = %d \n", result[i].src, result[i].dest, result[i].weight); 
    }

    free(sub_set); 
}
int main(void) {
    int vertices = 5; 
    int edges = 7; 

    Graph *my_graph = create_graph(vertices); 
    Edges *edge_array = create_edge_array(edges); 
    
    add_edge(my_graph, 0, 1, 2, edge_array);
    add_edge(my_graph, 0, 3, 6, edge_array);
    add_edge(my_graph, 1, 3, 8, edge_array);
    add_edge(my_graph, 1, 4, 5, edge_array);
    add_edge(my_graph, 1, 2, 3, edge_array);
    add_edge(my_graph, 2, 4, 7, edge_array);
    add_edge(my_graph, 3, 4, 9, edge_array);

    print_graph(my_graph); 

    kruskal_mst(my_graph, edge_array); 

    free_graph(my_graph); 
    free(edge_array); 


   return 0; 
}
