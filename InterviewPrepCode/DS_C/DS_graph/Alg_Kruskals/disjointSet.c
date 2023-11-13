#include <stdio.h>
#include <stdlib.h>

typedef struct DisjointSet {
  int *parent;
  int *rank;
  int n;

} DisjointSet;

// Create a disjoint set with 'n' elements
DisjointSet *makeSet(int n) {
  DisjointSet *set = (DisjointSet *)malloc(sizeof(DisjointSet));
  if (set == NULL) {
    printf("Failed To allocated Mem for DisjointSet\n");
    return NULL;
  }

  // Initialize all the elements to zero;
  set->parent = (int *)malloc(n * sizeof(int));
  set->rank = (int *)malloc(n * sizeof(int));
  set->n = n;

  for (int i = 0; i < set->n; i++) {
    set->parent[i] = i;
    set->rank[i] = 0;
  }
  return set;
}

// Find the parents of 'u' with path compression
int findSet(DisjointSet *set, int u) {
  if (set->parent[u] != u) {
    set->parent[u] = findSet(set, set->parent[u]);
  }

  return set->parent[u];
}

// Union by rank of 'u' and 'v'
void unionSet(DisjointSet *set, int u, int v) {
  int parentU = findSet(set, u);
  int parentV = findSet(set, v);

  if (parentU != parentV) {
    // Union by rank
    if (set->rank[parentU] < set->rank[parentV]) {
      set->parent[parentU] = parentV;
    } else if (set->rank[parentV] < set->rank[parentU]) {
      set->parent[parentV] = parentU;
    } else {
      // If ranks are same, then make one as root and increment its rank by one
      set->parent[parentV] = parentU;
      set->rank[parentU]++;
    }
  }
}

// A function to check if two elements 'u' and 'v' are in the same set
int isSameSet(DisjointSet *set, int u, int v) {
  return findSet(set, u) == findSet(set, v);
}

void freeSet(DisjointSet *set) {
  free(set->parent);
  free(set->rank);
  free(set);
}

// Main function to demonstrate the Disjoint Set operations
/*
int main() {
  int n = 5; // Example with 5 elements
  DisjointSet *set = makeSet(n);

  unionSet(set, 0, 2);
  unionSet(set, 4, 2);
  unionSet(set, 3, 1);

  if (isSameSet(set, 0, 4))
    printf("Yes, 0 and 4 are in the same set.\n");
  else
    printf("No, 0 and 4 are not in the same set.\n");

  if (isSameSet(set, 1, 0))
    printf("Yes, 1 and 0 are in the same set.\n");
  else
    printf("No, 1 and 0 are not in the same set.\n");

  freeSet(set);
  return 0;
} */
