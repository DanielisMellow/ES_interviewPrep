#include "adjMatrxDynamic.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// A structure to represet a graph
graph *createGraph(int numVertices) {
  graph *newGraph = (graph *)malloc(sizeof(graph));
  newGraph->numVertices = numVertices;

  newGraph->adjMatrix = (int **)malloc(numVertices * sizeof(int *));

  // Initizalize the adjacency matrix to 0 (no edges)
  for (int i = 0; i < numVertices; i++) {
    newGraph->adjMatrix[i] = (int *)calloc(numVertices, sizeof(int));
  }

  return newGraph;
}

// Add an edge to the graph
void addEdge(graph *g, int src, int dest, int weight) {
  // Add edge from src to dest
  g->adjMatrix[src][dest] = weight;

  // Add edge from dest to src if Undirected Graph
  g->adjMatrix[dest][src] = weight;
}

void printGraph(graph *g) {
  for (int i = 0; i < g->numVertices; i++) {
    printf("\n");
    for (int j = 0; j < g->numVertices; j++) {
      printf("%d ", g->adjMatrix[i][j]);
    }
  }
  printf("\n");
}
void freeGraph(graph *g) {
  for (int i = 0; i < g->numVertices; i++) {
    free(g->adjMatrix[i]);
  }
  free(g->adjMatrix);
  free(g);
}
