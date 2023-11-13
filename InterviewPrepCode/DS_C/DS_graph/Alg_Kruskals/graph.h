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

graph *createGraph(int numVertices, int numEdges);

// Add an edge to the graph
void addEdge(graph *g, int src, int dest, int weight, int edgeCount);

void printGraphTable(graph *g);

void freeGraph(graph *g);
