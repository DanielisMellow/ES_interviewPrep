#include "min_heap.h"

// get parent index
int parent_index(int i) { return (i - 1) / 2; }
// get left child index
int left_child_index(int i) { return (2 * i) + 1; }
// get right child index
int right_child_index(int i) { return (2 * i) + 2; }
bool is_empty(Min_Heap *heap) { return heap->size == 0; }

MinHeapNode* new_node(unsigned int vertex, int weight) {
    MinHeapNode *new_node = malloc(sizeof(MinHeapNode)); 
    if(!(new_node)) return NULL; 
    new_node->vertex = vertex; 
    new_node->weight = weight; 
    return new_node; 
}

Min_Heap* create_min_heap(int capacity) {
    Min_Heap *min_heap = malloc(sizeof(Min_Heap)); 
    if(!(min_heap)) return NULL; 
    min_heap->pos = malloc(capacity * sizeof(int)); 
    min_heap->size = 0; 
    min_heap->capacity = capacity; 
    min_heap->array = malloc(capacity * sizeof(MinHeapNode *)); 
    return min_heap; 
} 

void swap_nodes(MinHeapNode **a, MinHeapNode **b) {
    MinHeapNode *t = *a; 
    *a = *b; 
    *b = t; 
}

void insert_to_heap(Min_Heap *heap, unsigned int vertex, int weight) {
    if(heap->size == heap->capacity) {
        printf("Heap is full.\n"); 
        return; 
    }

    // add node at the end
    int i = heap->size; 
    heap->array[i] = new_node(vertex, weight); 
    heap->pos[vertex] = i; 

    // find corrent position for new node
    while(i != 0 && heap->array[i]->weight < heap->array[parent_index(i)]->weight) {
       heap->pos[i] = parent_index(i); 
       heap->pos[parent_index(i)] = i; 

       swap_nodes(&heap->array[parent_index(i)], &heap->array[i]); 

       i = parent_index(i); 
    }

    // increment heap size
    heap->size++; 
}

void free_heap(Min_Heap *heap) {
    for(int i = 0; i < heap->capacity; i++) {
        free(heap->array[i]); 
    }
    free(heap->array); 
    free(heap->pos); 
    free(heap); 
}

// not sure what this functiond does
void min_heapify(Min_Heap *heap, int index) {
    int smallest, left, right; 
    smallest = index; 
    left = 2 * index + 1; 
    right = 2 * index + 2; 


    if(left < heap->size && heap->array[left]->weight < heap->array[smallest]->weight) {
        smallest = left; 
    }

    if(right < heap->size && heap->array[right]->weight < heap->array[smallest]->weight) {
        smallest = right; 
    }

    if(smallest != index) {
        // nodes to be swapped
        MinHeapNode *smallest_node = heap->array[smallest]; 
        MinHeapNode *index_node = heap->array[index]; 

        //swap positions
        heap->pos[smallest_node->vertex] = index; 
        heap->pos[index_node->vertex] = smallest; 

        // swap nodes
        swap_nodes(&heap->array[smallest], &heap->array[index]); 

        min_heapify(heap, smallest); 
    }
}

// function to extract the minimum vertex from heap
int extract_min(Min_Heap *heap) {
    if(is_empty(heap)) { return INT32_MIN; }

    // store the root node and last node
    MinHeapNode *root = heap->array[0]; 
    MinHeapNode *last_node = heap->array[heap->size - 1]; 

    // store the root node vertex
    int root_vertex = root->vertex; 

    // swap positions of root node and last node
    heap->pos[root->vertex] = heap->size - 1; 
    heap->pos[last_node->vertex] = 0; 

    swap_nodes(&heap->array[0], &heap->array[heap->size - 1]); 

    // reduce heap size and heapify root
    --heap->size;
    min_heapify(heap, 0); 

    return root_vertex; 
}

// decreases weight of given vertex. 
void decrease_key(Min_Heap *heap, int vertex, int weight) {
    // Get the index of vertex in heap array
    int i = heap->pos[vertex]; 

    // get the node and update its weight value
    heap->array[i]->weight = weight; 

    // Travel up while the complete tree is not heapified 
    while(i && heap->array[i]->weight < heap->array[(i - 1) / 2]->weight) {
        // swap this node with its parent
        heap->pos[heap->array[i]->vertex] = (i - 1) / 2; 
        heap->pos[heap->array[(i - 1) / 2]->vertex] = i; 
        swap_nodes(&heap->array[i], &heap->array[(i - 1) / 2]); 

        // move to parent index
        i = (i - 1) / 2; 
    }
}

// function to check if given vertex is in heap or not
bool is_in_heap(Min_Heap *heap, int vertex) {
    return heap->pos[vertex] < heap->size; 
}
