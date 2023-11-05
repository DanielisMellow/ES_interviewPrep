#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// A structure to represet a graph

struct Graph {
  int numVertices;
  int **adjMatrix;
};

typedef struct Graph graph;

graph *createGraph(int numVertices);

// Add an edge to the graph
void addEdge(graph *g, int src, int dest, int weight);

void printGraph(graph *g);
void freeGraph(graph *g);
