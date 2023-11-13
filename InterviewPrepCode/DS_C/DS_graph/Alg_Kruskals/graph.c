#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// A structure to represent a weighted edge in the graph
struct Edge {
  int src, dest, weight;
};
typedef struct Edge edge;

// A structure to represent a connected, undirected, and weighted graph
struct Graph {
  int amountV, amountE;
  struct Edge *edges;
};
typedef struct Graph graph;

graph *createGraph(int numVertices, int numEdges) {
  graph *g = (graph *)malloc(sizeof(graph));
  if (g == NULL) {
    printf("Failed mem allocation\n");
    return NULL;
  }
  g->amountV = numVertices;
  g->amountE = numEdges;
  g->edges = (edge *)malloc(g->amountE * sizeof(edge));
  if (g->edges == NULL) {
    printf("Failed mem allocation\n");
    return NULL;
  }

  return g;
}

// Add an edge to the graph
void addEdge(graph *g, int src, int dest, int weight, int edgeCount) {
  if (g == NULL) {
    printf("Unable to add edge\n");
    return;
  }

  // Add edge from src to dest
  g->edges[edgeCount].src = src;
  g->edges[edgeCount].dest = dest;
  g->edges[edgeCount].weight = weight;
}

void printGraphTable(graph *g) {
  if (g == NULL) {
    return;
  }
  printf("\nSrc | Dest | Weight\n");

  for (int i = 0; i < g->amountE; i++) {
    printf("%d   |  %d   | %d\n", g->edges[i].src, g->edges[i].dest,
           g->edges[i].weight);
  }
}

void freeGraph(graph *g) {
  free(g->edges);
  free(g);
}

/* int main(int argc, char *argv[]) {

  int adjMatrix[5][5] = {{0, 2, 0, 6, 0},
                         {2, 0, 3, 8, 5},
                         {0, 3, 0, 0, 7},
                         {6, 8, 0, 0, 9},
                         {0, 5, 7, 9, 0}};

  int numVertices = 5;
  int numEdges = 7;

  graph *mainGraph = createGraph(numVertices, numEdges);

  int edgeCount = 0;
  for (int i = 0; i < numVertices; i++) {
    for (int j = i; j < numVertices; j++) {
      if (adjMatrix[i][j] != 0) {

        addEdge(mainGraph, i, j, adjMatrix[i][j], edgeCount);
        edgeCount++;
      }
    }
  }

  printGraphTable(mainGraph);

  return EXIT_SUCCESS;
} */
