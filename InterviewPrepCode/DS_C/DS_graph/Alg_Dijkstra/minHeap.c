#include "minHeap.h"
#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CAPACITY 100 // initial capacity

int parentIndx(int i) { return (i - 1) / 2; }

int leftChildInx(int i) { return (2 * i) + 1; }

int rightChildIndx(int i) { return (2 * i) + 2; }

// A utility function to create a new Min Heap Node
MinHeapNode *newMinHeapNode(int vertex, int weight) {
  MinHeapNode *minHeapNode = (MinHeapNode *)malloc(sizeof(MinHeapNode));
  minHeapNode->vertex = vertex;
  minHeapNode->weight = weight;
  return minHeapNode;
}

// A utility function to create a Min Heap
MinHeap *createMinHeap(int capacity) {
  MinHeap *minHeap = (MinHeap *)malloc(sizeof(MinHeap));
  minHeap->pos = (int *)malloc(capacity * sizeof(int));
  minHeap->size = 0;
  minHeap->capacity = capacity;
  minHeap->array = (MinHeapNode **)malloc(capacity * sizeof(MinHeapNode *));
  return minHeap;
}

void freeMinHeap(MinHeap *minHeap) {

  if (minHeap == NULL) {
    return;
  }

  for (int i = 0; i < minHeap->capacity; i++) {
    MinHeapNode *temp = minHeap->array[i];
    free(temp);
  }

  free(minHeap->array);
  free(minHeap->pos);
  free(minHeap);
}

// =============================================================
// A utility function to swap two nodes of min heap. Needed for min heapify

void swapMinHeapNode(MinHeapNode **a, MinHeapNode **b) {
  MinHeapNode *t = *a;
  *a = *b;
  *b = t;
}

// Insert new keys into the minheap
void insert(MinHeap *minHeap, int vertex, int weight) {
  if (minHeap->size == minHeap->capacity) {
    printf("HEAP IS FULL\n");
    return;
  }
  // insert the new node at the end
  int i = minHeap->size;
  minHeap->array[i] = newMinHeapNode(vertex, weight);
  minHeap->pos[vertex] = i;

  while (i != 0 &&
         minHeap->array[i]->weight < minHeap->array[parentIndx(i)]->weight) {

    // swap position in pos[]
    int start = minHeap->array[i]->vertex;
    int parent = minHeap->array[parentIndx(i)]->vertex;

    minHeap->pos[start] = parent;
    minHeap->pos[parent] = start;

    // Swap the nodes
    swapMinHeapNode(&minHeap->array[parentIndx(i)], &minHeap->array[i]);
    // update index to parent
    i = parentIndx(i);
  }

  // Increment the size of the heap
  minHeap->size++;
}
// A standard function to heapify at given idx
// This function also updates position of nodes when they are swapped.
// Position is needed for decreaseKey()
void minHeapify(MinHeap *minHeap, int idx) {
  int smallest, left, right;
  smallest = idx;
  left = 2 * idx + 1;
  right = 2 * idx + 2;

  if (left < minHeap->size &&
      minHeap->array[left]->weight < minHeap->array[smallest]->weight)
    smallest = left;

  if (right < minHeap->size &&
      minHeap->array[right]->weight < minHeap->array[smallest]->weight)
    smallest = right;

  if (smallest != idx) {
    // The nodes to be swapped in min heap
    MinHeapNode *smallestNode = minHeap->array[smallest];
    MinHeapNode *idxNode = minHeap->array[idx];

    // Swap positions
    minHeap->pos[smallestNode->vertex] = idx;
    minHeap->pos[idxNode->vertex] = smallest;

    // Swap nodes
    swapMinHeapNode(&minHeap->array[smallest], &minHeap->array[idx]);

    minHeapify(minHeap, smallest);
  }
}

// A utility function to check if a given minHeap is empty or not
int isEmpty(MinHeap *minHeap) { return minHeap->size == 0; }

// Standard function to extract minimum vertex from heap
int extractMin(MinHeap *minHeap) {
  if (isEmpty(minHeap))
    return INT_MIN;

  // Store the root node and last node
  MinHeapNode *root = minHeap->array[0];
  MinHeapNode *lastNode = minHeap->array[minHeap->size - 1];

  // Store the root node vertex
  int rootV = root->vertex;

  // Swap postions of root node and last node
  minHeap->pos[root->vertex] = minHeap->size - 1;
  minHeap->pos[lastNode->vertex] = 0;

  swapMinHeapNode(&minHeap->array[0], &minHeap->array[minHeap->size - 1]);

  // Reduce heap size and heapify root
  --minHeap->size;
  minHeapify(minHeap, 0);

  return rootV;
}

// Function to decrease weight value of a given vertex vertex. This function
// uses pos[] of min heap to get the current index of node in min heap
void decreaseKey(MinHeap *minHeap, int vertex, int weight) {
  // Get the index of vertex in heap array
  int i = minHeap->pos[vertex];

  // Get the node and update its weight value
  minHeap->array[i]->weight = weight;

  // Travel up while the complete tree is not heapified.
  // This is a O(Logn) loop
  while (i &&
         minHeap->array[i]->weight < minHeap->array[parentIndx(i)]->weight) {
    // Swap this node with its parent
    minHeap->pos[minHeap->array[i]->vertex] = parentIndx(i);
    minHeap->pos[minHeap->array[parentIndx(i)]->vertex] = i;
    swapMinHeapNode(&minHeap->array[i], &minHeap->array[parentIndx(i)]);

    // move to parent index
    i = parentIndx(i);
  }
}

// A utility function to check if a given vertex 'vertex' is in min heap or not
bool isInMinHeap(MinHeap *minHeap, int vertex) {
  return minHeap->pos[vertex] < minHeap->size;
}
