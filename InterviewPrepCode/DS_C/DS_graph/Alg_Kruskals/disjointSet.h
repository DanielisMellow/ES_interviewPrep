#include <stdio.h>
#include <stdlib.h>

typedef struct DisjointSet {
  int *parent;
  int *rank;
  int n;

} DisjointSet;

// Create a disjoint set with 'n' elements
DisjointSet *makeSet(int n);

// Find the parents of 'u' with path compression
int findSet(DisjointSet *set, int u);

// Union by rank of 'u' and 'v'
void unionSet(DisjointSet *set, int u, int v);

// A function to check if two elements 'u' and 'v' are in the same set
int isSameSet(DisjointSet *set, int u, int v);

void freeSet(DisjointSet *set);
