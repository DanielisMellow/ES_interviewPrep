#include "queue.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// A structure to represet a graph

struct Graph {
  int numVertices;
  int **adjMatrix;
};

typedef struct Graph graph;

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

void freeGraph(graph *g) {
  for (int i = 0; i < g->numVertices; i++) {
    free(g->adjMatrix[i]);
  }
  free(g->adjMatrix);
  free(g);
}

void BFS(graph *g, int startVertex) {

  queue q;
  createQueue(&q, g->numVertices);
  bool *visited = (bool *)calloc(g->numVertices, sizeof(bool));

  visited[startVertex] = true;
  enqueue(&q, startVertex);

  while (!isEmpty(&q)) {
    int currentVertex = dequeue(&q);

    printf("Visited: %d\n", currentVertex);

    // Visit all the neighbors of the current vertex
    for (int i = 0; i < g->numVertices; i++) {
      if (g->adjMatrix[currentVertex][i] == 1 && !visited[i]) {
        visited[i] = 1;
        enqueue(&q, i);
      }
    }
  }
  freeQueue(&q);
  free(visited);
}

void DFS(graph *g, int vertex, bool visited[]) {
  visited[vertex] = 1;
  printf("Visited: %d\n", vertex);

  for (int i = 0; i < g->numVertices; i++) {
    if (g->adjMatrix[vertex][i] == 1 && !visited[i]) {
      DFS(g, i, visited);
    }
  }
}

void startDFS(graph *g, int startVertex) {
  // Keep track of the visited vertices
  bool *visited = (bool *)calloc(g->numVertices, sizeof(bool));

  DFS(g, startVertex, visited);

  free(visited);
}

int main(int argc, char *argv[]) {
  int V = 5;

  graph *mainGraph = createGraph(V);

  /* addEdge(mainGraph, 0, 1);
  addEdge(mainGraph, 0, 2);
  addEdge(mainGraph, 0, 3);

  addEdge(mainGraph, 1, 2);
  addEdge(mainGraph, 1, 0);

  addEdge(mainGraph, 2, 0);
  addEdge(mainGraph, 2, 1);

  addEdge(mainGraph, 3, 0);
 */

  addEdge(mainGraph, 0, 1);
  addEdge(mainGraph, 0, 2);
  addEdge(mainGraph, 0, 3);

  addEdge(mainGraph, 1, 0);
  addEdge(mainGraph, 1, 2);

  addEdge(mainGraph, 2, 0);
  addEdge(mainGraph, 2, 1);
  addEdge(mainGraph, 2, 3);
  addEdge(mainGraph, 2, 4);

  addEdge(mainGraph, 3, 0);
  addEdge(mainGraph, 3, 2);
  addEdge(mainGraph, 3, 4);

  addEdge(mainGraph, 4, 2);
  addEdge(mainGraph, 4, 3);

  printGraph(mainGraph);

  printf("\nBreadth First Search\n");
  BFS(mainGraph, 4);

  printf("\nDepth First Search\n");
  startDFS(mainGraph, 4);

  freeGraph(mainGraph);

  return EXIT_SUCCESS;
}
