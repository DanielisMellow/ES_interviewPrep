#include "adjList.h" 
#include "linked_list.h"
#include "min_heap.h"

void print_MST(int parent[], Graph *g) {
    if(g == NULL || parent == NULL) {
        printf("NULL\n"); 
        return; 
    }

    printf("Edge\tWeight\n"); 
    for(int i = 1; i < g->num_of_vertices; i++) {
        while(g->adjList[i] != NULL) {
            if(g->adjList[i]->vertex == parent[i]) {
                printf("%d - %d\t%d\n", parent[i], i, g->adjList[i]->weight); 
                break; 
            }
            g->adjList[i] = g->adjList[i]->next;  
        }
    }
}

void prim_MST(Graph *g) {
    if(g == NULL) {
        return; 
    }

    // To represent the set of vertices not yet included in the MST
    Min_Heap *heap = create_min_heap(g->num_of_vertices); 
    // Array to store the constructed MST
    int *parent = calloc(g->num_of_vertices, sizeof(int)); 
    // cost values used to pick the minimum edge weight
    int *cost = calloc(g->num_of_vertices, sizeof(int)); 

    for(int u = 0; u < g->num_of_vertices; u++) {
        cost[u] = INT32_MAX; 
        parent[u] = -1; 
        insert_to_heap(heap, u, cost[u]); 
    }

    decrease_key(heap, 0, 0); 

    while(!is_empty(heap)) {
        // Extract the verte4x with minimum key value
        // store the extracted vertex number
        int u = extract_min(heap); 

        // traverse through all ajacent vertices of u and update their values
        for(int v = 0; v < g->num_of_vertices; v++) {
            // if v is not yet included in MST and the weight of uv is less
            // than the weight of v, then update the key and parent of v

            node *temp = search(g->adjList[u], v); 
            if(temp && is_in_heap(heap, v) && temp->weight < cost[v]) {
                cost[v] = temp->weight; 
                parent[v] = u; 
                decrease_key(heap, v, temp->weight); 
            }
        }
    }

    print_MST(parent, g); 

    free(parent); 
    free(cost); 
    free_heap(heap); 
}


int main(void) {
  /* Let us create the following graph
         2    3
     (0)--(1)--(2)
     |    / \   |
    6|  8/   \5 |7
     |  /     \ |
     (3)-------(4)
          9
  */
    Graph *_main = create_graph(5); 

    add_edge(_main, 0, 1, 2);
    add_edge(_main, 0, 3, 6);
    add_edge(_main, 1, 3, 8);
    add_edge(_main, 1, 4, 5);
    add_edge(_main, 1, 2, 3);
    add_edge(_main, 2, 4, 7);
    add_edge(_main, 3, 4, 9);

    print_graph(_main); 

    printf("\n\n"); 
    prim_MST(_main); 

    free_graph(_main); 





    return 0; 
}
