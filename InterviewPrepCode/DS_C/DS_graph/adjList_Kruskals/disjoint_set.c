#include "disjoint_set.h"

Disjoint_Set * make_set(int elem) {
    Disjoint_Set * new_set = (Disjoint_Set *)malloc(sizeof(Disjoint_Set)); 
    if(!(new_set)) return NULL; 

    new_set->parent = (int *)malloc(sizeof(int) * elem); 
    new_set->rank = (int *)malloc(sizeof(int) * elem);
    if(!(new_set->parent) || !(new_set->rank)) return NULL; 

    new_set->elem = elem; 

    // Initialize parent and rank array
    for(int i = 0; i < elem; i++) {
        new_set->parent[i] = i; 
        new_set->rank[i] = 0; 
        // parent[] = 0, 1, 2, 3, 4, 5...
        // rank[] = 0, 0, 0, 0, 0...
    }

    return new_set; 
} 

int find_set(Disjoint_Set* set, int u) {
    if(set->parent[u] != u) {
        set->parent[u] = find_set(set, set->parent[u]); 
    } 
    return set->parent[u]; 
}

void union_set(Disjoint_Set *set, int u, int v) {
    int parent_u = find_set(set, u); 
    int parent_v = find_set(set, v); 

    if(parent_u != parent_v) {
        
        if(set->rank[parent_u] < set->rank[parent_v]) {
            set->parent[parent_u] = parent_v; 
        }
        else if(set->rank[parent_u] > set->rank[parent_v]) {
            set->parent[parent_v] = parent_u; 
        }
        else {
            set->parent[parent_v] = parent_u; 
            set->rank[parent_u]++; 
        }
    }
}

bool same_set(Disjoint_Set *set, int u, int v) {
    return find_set(set, u) == find_set(set, v); 
}

void free_set(Disjoint_Set *set) {
    free(set->parent); 
    free(set->rank); 
    free(set); 
}


// int main(void) {
//     
//     Disjoint_Set *set = make_set(6);
//
//     union_set(set, 1, 3); 
//     union_set(set, 1, 5); 
//     union_set(set, 4, 2); 
//
//     if(same_set(set, 3, 1)) {
//         printf("3 and 1 are of same set\n"); 
//     }
//     else {
//         printf("3 and 1 are not of same set\n"); 
//     }
//
//     if(same_set(set, 3, 4)) {
//         printf("3 and 4 are of same set\n"); 
//     }
//     else {
//         printf("3 and 4 are not of same set\n"); 
//     }
//
//     for(int i = 0; i < 6; i++) {
//         printf("%d,", set->parent[i]); 
//     }
//     printf("\n"); 
//     for(int i = 0; i < 6; i++) {
//         printf("%d,", set->rank[i]); 
//     }
//     printf("\n"); 
//
//     union_set(set, 1, 2);
//
//     for(int i = 0; i < 6; i++) {
//         printf("%d,", set->parent[i]); 
//     }
//     printf("\n"); 
//     for(int i = 0; i < 6; i++) {
//         printf("%d,", set->rank[i]); 
//     }
//     printf("\n"); 
//
//
//     return 0; 
// }
