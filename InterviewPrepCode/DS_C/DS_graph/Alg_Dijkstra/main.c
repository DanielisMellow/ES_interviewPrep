#include "adjMatrxDynamic.h"
#include "minHeap.h"
#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

void printPath(int currentV, int parent[]) {
  if (parent[currentV] == -1) {
    return;
  }

  printPath(parent[currentV], parent);

  printf("%d ", currentV);
}

void printSPset(int parent[], int distance[], int startV, graph *g) {
  if (g == NULL || parent == NULL) {
    printf("NULL");
    return;
  }

  printf("Vertex\tDistance\tPath\n");

  for (int i = 0; i < g->numVertices; i++) {
    printf("%d -> %d\t%d\t\t%d ", startV, i, distance[i], startV);
    printPath(i, parent);
    printf("\n");
  }
}

void dijkstra(graph *g, int startV) {
  MinHeap *Q = createMinHeap(g->numVertices);
  int *previous = (int *)calloc(g->numVertices, sizeof(int));
  int *distance = (int *)calloc(g->numVertices, sizeof(int));

  // Initialize single source
  for (int u = 0; u < g->numVertices; u++) {
    distance[u] = INT_MAX;
    previous[u] = -1;
    insert(Q, u, distance[u]);
  }

  decreaseKey(Q, startV, 0);
  distance[startV] = 0;

  while (!isEmpty(Q)) {

    int u = extractMin(Q);

    for (int v = 0; v < g->numVertices; v++) {

      int tempDistance = distance[u] + g->adjMatrix[u][v];

      if (g->adjMatrix[u][v] && isInMinHeap(Q, v) && distance[u] != INT_MAX &&
          tempDistance < distance[v]) {
        distance[v] = tempDistance;
        previous[v] = u;
        decreaseKey(Q, v, g->adjMatrix[u][v]);
      }
    }
  }

  printSPset(previous, distance, startV, g);

  free(previous);
  free(distance);
  free(Q);
}

// Driver program to test above functions
int main(int argc, char *argv[]) {

  /* Let us create the following graph
         2    3
     (0)--(1)--(2)
     |    / \   |
    6|  8/   \5 |7
     |  /     \ |
     (3)-------(4)
          9
  */

  int adjMatrix[5][5] = {{0, 2, 0, 6, 0},
                         {2, 0, 3, 8, 5},
                         {0, 3, 0, 0, 7},
                         {6, 8, 0, 0, 9},
                         {0, 5, 7, 9, 0}};

  int numVertices = 5;

  graph *mainGraph = createGraph(numVertices);

  for (int i = 0; i < numVertices; i++) {
    for (int j = i; j < numVertices; j++) {
      addEdge(mainGraph, i, j, adjMatrix[i][j]);
    }
  }

  printGraph(mainGraph);
  printf("\n\n");
  dijkstra(mainGraph, 0);

  freeGraph(mainGraph);

  return EXIT_SUCCESS;
}
