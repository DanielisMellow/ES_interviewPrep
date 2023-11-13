#include "disjointSet.h"
#include "graph.h"
#include <stdio.h>
#include <stdlib.h>

// Compare two edges according to their weights. Used in qsort() for sorting an
// array of edges
int myComp(const void *a, const void *b) {
  edge *a1 = (edge *)a;
  edge *b1 = (edge *)b;
  return (a1->weight - b1->weight);
}

// The main function to construct MST using Kruskal's algorithm
void KruskalMST(graph *g) {
  int V = g->amountV;
  edge result[V]; // Tnis will store the resultant MST
  int e = 0;      // An index variable, used for result[]
  int i = 0;      // An index variable, used for sorted edges

  DisjointSet *subsets = makeSet(V);

  // Step 1:  Sort all the edges in non-decreasing order of their weight
  qsort(g->edges, g->amountE, sizeof(g->edges[0]), myComp);
  // printGraphTable(g);

  // Number of edges to be taken is equal to V-1
  while (e < V - 1 && i < g->amountE) {
    // Step 2: Pick the smallest edge. And increment the index for next
    // iteration
    edge next_edge = g->edges[i++];

    // If including this edge does't cause cycle, include it in result and
    // increment the index of result for next edge
    if (!isSameSet(subsets, next_edge.src, next_edge.dest)) {
      result[e++] = next_edge;
      unionSet(subsets, next_edge.src, next_edge.dest);
    }
    // Else discard the next_edge
  }

  // print the contents of result[] to display the built MST
  printf("Following are the edges in the constructed MST\n");
  for (i = 0; i < e; ++i)
    printf("%d -- %d == %d\n", result[i].src, result[i].dest, result[i].weight);

  freeSet(subsets);
}

// The main program to test the above functions
int main() {
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
  int numEdges = 7;

  graph *mainGraphTable = createGraph(numVertices, numEdges);

  int edgeCount = 0;
  for (int i = 0; i < numVertices; i++) {
    for (int j = i; j < numVertices; j++) {
      if (adjMatrix[i][j] != 0) {

        addEdge(mainGraphTable, i, j, adjMatrix[i][j], edgeCount);
        edgeCount++;
      }
    }
  }

  printGraphTable(mainGraphTable);

  KruskalMST(mainGraphTable);

  freeGraph(mainGraphTable);
  return 0;
}
