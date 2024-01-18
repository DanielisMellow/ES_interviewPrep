#ifndef _DSJOINT_H
#define _DSJOINT_H
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct disjoint_set {
    int *parent; // <- parent array, says the parent of an index
    int *rank;   // <- rank array, kind of like the size of each sub-set
    int elem;// <- number of elements in the set (to be used by each array) 
}Disjoint_Set; 

// Creates a fresh disjoint set
// Makes each index its own parent in the parent array
// Makes each index rank 0 in the rank array 
Disjoint_Set * make_set(int elem);

// Returns the parent value of u from the parent array
int find_set(Disjoint_Set* set, int u); 

// Joins two subsets (of u and v) by rank
// If v's rank is less than u's, then v becomes part of u's subset
void union_set(Disjoint_Set* set, int u, int v); 

// Returns true or false if the parent of u and v are the same
// False otherwise
bool same_set(Disjoint_Set* set, int u, int v); 

// Frees mem allocated
void free_set(Disjoint_Set* set); 

#endif
