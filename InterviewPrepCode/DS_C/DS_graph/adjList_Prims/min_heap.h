#ifndef _MIN_HEAP_H
#define _MIN_HEAP_H
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX_CAP 100

// represents min heap node
typedef struct MinHeapNode {
    unsigned int vertex; 
    int weight; 
}MinHeapNode; 

// represents the whole min heap
typedef struct Min_Heap {
    int size; 
    int capacity; 
    int *pos; 
    MinHeapNode **array;
}Min_Heap; 

// see if heap is empty
bool is_empty(Min_Heap *heap); 

// create new min heap node
MinHeapNode* new_node(unsigned int vertex, int weight); 

// returns a min heap
Min_Heap* create_min_heap(int capacity); 

// swaps two nodes in the min heap
void swap_nodes(MinHeapNode **a, MinHeapNode **b); 

// inserts into min heap
void insert_to_heap(Min_Heap *heap, unsigned int vertex, int weight); 

// free heap
void free_heap(Min_Heap *heap); 

void min_heapify(Min_Heap *heap, int index); 

int extract_min(Min_Heap *heap); 

void decrease_key(Min_Heap *heap, int vertex, int weight);  

bool is_in_heap(Min_Heap *heap, int vertex);  
#endif
