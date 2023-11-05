#include "adjMatrxDynamic.h"
#include "minHeap.h"
#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

void printMST(int parent[], graph *g) {
  if (g == NULL || parent == NULL) {
    printf("NULL");
    return;
  }
  printf("Edge\tWeight\n");
  for (int i = 1; i < g->numVertices; i++) {
    printf("%d - %d\t%d\n", parent[i], i, g->adjMatrix[i][parent[i]]);
  }
}

void primMST(graph *g) {
  if (g == NULL) {
    return;
  }
  // To represent the set of vertices no yet included in the MST
  MinHeap *minHeap = createMinHeap(g->numVertices);

  // Array To store the constructed MST
  int *parent = (int *)calloc(g->numVertices, sizeof(int));

  // key values used to pick the the minimum edge weight
  int *weight = (int *)calloc(g->numVertices, sizeof(int));

  for (int u = 0; u < g->numVertices; u++) {
    weight[u] = INT_MAX;
    parent[u] = -1;
    insert(minHeap, u, weight[u]);
  }

  decreaseKey(minHeap, 0, 0);

  while (!isEmpty(minHeap)) {
    // Extract The vertex with minumum key value
    // Store the extracted vertex number
    int u = extractMin(minHeap);

    // Travere through all adjacence vertices of u and update their values
    for (int v = 0; v < g->numVertices; v++) {
      // If v is not yet included in MST and the weight of u-v is less than
      // weight value of v, then update the key and parent of v
      if (g->adjMatrix[u][v] && isInMinHeap(minHeap, v) &&
          g->adjMatrix[u][v] < weight[v]) {

        weight[v] = g->adjMatrix[u][v];
        parent[v] = u;
        decreaseKey(minHeap, v, g->adjMatrix[u][v]);
      }
    }
  }

  printMST(parent, g);

  free(parent);
  free(weight);
  freeMinHeap(minHeap);
}

// Driver program to test above functions
int main(int argc, char *argv[]) {

  /* Let us create the following graph
     2    3
     (0)--(1)--(2)
     |    / \   |
     6|  8/   \5 |7
     |  /      \ |
     (3)-------(4)
     9          */
  int adjMatrix[5][5] = {{0, 2, 0, 6, 0},
                         {2, 0, 3, 8, 5},
                         {0, 3, 0, 0, 7},
                         {6, 8, 0, 0, 9},
                         {0, 5, 7, 9, 0}};

  int numVertices = 5;

  graph *mainGraph = createGraph(numVertices);

  for (int i = 0; i < numVertices; i++) {
    for (int j = 0; j < numVertices; j++) {
      addEdge(mainGraph, i, j, adjMatrix[i][j]);
    }
  }

  printGraph(mainGraph);
  printf("\n\n");
  primMST(mainGraph);

  freeGraph(mainGraph);

  return EXIT_SUCCESS;
}
