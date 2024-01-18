#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// Structure to represent a min heap node
typedef struct MinHeapNode {
  int vertex;
  int weight;
} MinHeapNode;

// Structure to represent a min heap
typedef struct MinHeap {
  int size;     // Number of heap nodes present currently
  int capacity; // Capacity of min heap
  int *pos;     // This is needed for decreaseKey()
  MinHeapNode **array;
} MinHeap;

// A utility function to create a new Min Heap Node
MinHeapNode *newMinHeapNode(int vertex, int weight);

// A utility function to create a Min Heap
MinHeap *createMinHeap(int capacity);

// A utility function to swap two nodes of min heap. Needed for min heapify
void swapMinHeapNode(MinHeapNode **a, MinHeapNode **b);

// Insert new nodes into min heap
void insert(MinHeap *minHeap, int vertex, int weight);

// A standard function to heapify at given idx
// This function also updates position of nodes when they are swapped.
// Position is needed for decreaseKey()
void minHeapify(MinHeap *minHeap, int idx);

// A utility function to check if a given minHeap is empty or not
int isEmpty(MinHeap *minHeap);

// Standard function to extract minimum vertex
int extractMin(MinHeap *minHeap);

// Function to decrease weight value of a given vertex vertex. This function
// uses pos[] of min heap to get the current index of node in min heap
void decreaseKey(MinHeap *minHeap, int vertex, int weight);

// A utility function to check if a given vertex 'vertex' is in min heap or
// not
bool isInMinHeap(MinHeap *minHeap, int vertex);

// Free memory allocated by minHeap
void freeMinHeap(MinHeap *minHeap);
