#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 10

// A structure to represet a graph

struct Graph {
  int numVertices;
  int adjMatrix[MAX_VERTICES][MAX_VERTICES];
};

typedef struct Graph graph;

graph *createGraph(int numVertices) {
  graph *newGraph = (graph *)malloc(sizeof(graph));
  newGraph->numVertices = numVertices;

  // Initizalize the adjacency matrix to 0 (no edges)
  for (int i = 0; i < numVertices; i++) {
    for (int j = 0; j < numVertices; j++) {
      newGraph->adjMatrix[i][j] = 0;
    }
  }

  return newGraph;
}

// Add an edge to the graph
void addEdge(graph *g, int src, int dest) {
  // Add edge from src to dest
  g->adjMatrix[src][dest] = 1;

  // Add edge from dest to src if Undirected Graph
  g->adjMatrix[dest][src] = 1;
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

void freeGraph(graph *g) { free(g); }

int main(int argc, char *argv[]) {
  int V = 4;

  graph *mainGraph = createGraph(V);

  addEdge(mainGraph, 0, 1);
  addEdge(mainGraph, 0, 2);
  addEdge(mainGraph, 0, 3);

  addEdge(mainGraph, 1, 2);
  addEdge(mainGraph, 1, 0);

  addEdge(mainGraph, 2, 0);
  addEdge(mainGraph, 2, 1);

  addEdge(mainGraph, 3, 0);

  printGraph(mainGraph);

  freeGraph(mainGraph);
  /*
    bool *visited = (bool *)calloc(V, sizeof(bool));

    for (int i = 0; i < V; i++) {
      printf("%d\t", visited[i]);
    }
    free(visited);
   */
  return EXIT_SUCCESS;
}
