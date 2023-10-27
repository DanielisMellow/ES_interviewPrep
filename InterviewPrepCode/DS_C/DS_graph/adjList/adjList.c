#include "linkedList.h"
#include "queue.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// A structure to represet a graph

struct Graph {
  int numVertices;
  node **adjList;
};

typedef struct Graph graph;

graph *createGraph(int numVertices) {
  graph *newGraph = (graph *)malloc(sizeof(graph));
  newGraph->numVertices = numVertices;

  newGraph->adjList = (node **)malloc(numVertices * sizeof(node *));

  // Initizalize the adjacency matrix to 0 (no edges)
  for (int i = 0; i < numVertices; i++) {
    newGraph->adjList[i] = NULL;
  }

  return newGraph;
}

// Add an edge to an undirected graph
void addEdge(graph *g, int src, int dest) {
  // Ad and edge from src to dest
  insert(&g->adjList[src], dest);

  // Since the graph is undirected
  // Add and edge from dest to src
  insert(&g->adjList[dest], src);
}

void printGraph(graph *g) {
  for (int i = 0; i < g->numVertices; i++) {
    printList(g->adjList[i], i);
  }
}

void freeGraph(graph *g) {
  if (g == NULL) {
    return;
  }
  for (int i = 0; i < g->numVertices; i++) {
    freeList(g->adjList[i]);
  }
  free(g->adjList);
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

    node *temp = g->adjList[currentVertex];
    while (temp != NULL) {
      int adjVertex = temp->vertex;

      if (!visited[adjVertex]) {
        visited[adjVertex] = 1;
        enqueue(&q, adjVertex);
      }
      temp = temp->next;
    }
  }

  free(visited);
  freeQueue(&q);
}

int main(int argc, char *argv[]) {
  int V = 5;

  graph *mainGraph = createGraph(V);

  addEdge(mainGraph, 0, 1);
  addEdge(mainGraph, 0, 2);
  addEdge(mainGraph, 0, 3);

  addEdge(mainGraph, 1, 2);

  addEdge(mainGraph, 2, 3);
  addEdge(mainGraph, 2, 4);

  addEdge(mainGraph, 3, 4);

  printGraph(mainGraph);

  int startVertex = 4;
  printf("\nBreadth First Search\nStarting from Vertex:%d\n", startVertex);
  BFS(mainGraph, startVertex);

  freeGraph(mainGraph);
  return EXIT_SUCCESS;
}
