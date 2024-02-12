#ifndef MIN_HEAP_H
#define MIN_HEAP_H
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#define CAPACITY 100

typedef struct heap_node {
    unsigned int vertex; 
    unsigned int weight;
}heap_node; 

typedef struct min_heap {
    int size;            // current nodes in graph 
    int cap;             // max capacity allowed for graph 
    int *pos;            // position array 
    heap_node **nodes;        // key value pairs
}min_heap; 
// boolean if heap is empty or not
bool is_heap_empty(min_heap *min_heap); 
// general swap function
void swap(void *a, void *b, int size); 
// creates a new min heap heap_node (to be used by create_new_heap())
heap_node * create_new_node(unsigned int vertex, unsigned int weight); 
// creates a blank heap
min_heap * create_new_heap(int capacity); 
// inserts nodes into heap and organized them as a min heap
void insert_into_heap(min_heap *min_heap, unsigned int vertex, unsigned int weight); 
// organizes nodes in the heap after extraction (to be used by extract_min()) 
void heapify(min_heap *min_heap, int index); 
// extracts from the root, which is the smallest in the heap
int extract_min(min_heap *min_heap); 
// decreases weight of a particular vertex
void decrease_key(min_heap *min_heap, unsigned int vertex, unsigned int weight);  
// returns bool if vertex is in heap
bool is_in_heap(min_heap *min_heap, unsigned int vertex);
// frees the heap
void free_heap(min_heap *min_heap); 
#endif
