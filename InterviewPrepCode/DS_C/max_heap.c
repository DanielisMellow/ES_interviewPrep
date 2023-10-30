#include <limits.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#define MAX_CAPACITY 100

typedef struct {
    // current elements
    int size; 
    // actual data
    int *data; 
    // capacity that can be filled
    int capacity;
}max_heap; 

void swap(int *a, int *b) {
    (*a) ^= (*b);   
    (*b) ^= (*a); 
    (*a) ^= (*b); 
}

max_heap * create_heap() {
    max_heap *new_heap = (max_heap*)malloc(sizeof(max_heap)); 
    if(!new_heap) return NULL; 

    new_heap->data = (int*)malloc(sizeof(int) * MAX_CAPACITY); 
    if(!new_heap->data) return NULL; 
    new_heap->size = 0; 
    new_heap->capacity = MAX_CAPACITY; 

    return new_heap; 
}

bool is_empty(max_heap *heap) { return heap->size == 0; }
int parent_index(int index) { return ((index - 1) / 2); }
int left_child(int index) { return 2 * index + 1; }
int right_child(int index) { return 2 * index + 2; }

void insert(max_heap *heap, int value) {
    // Reallocate more memory if heap is full
    if(heap->size == heap->capacity) {
        heap->capacity *= 2; 
        heap->data = realloc(heap->data, heap->capacity * sizeof(int)); 
    }

    int i = heap->size; 
    heap->data[i] = value; 
    // keep swapping as long as the parent is smaller than the inserted data
    while(i != 0 && heap->data[parent_index(i)] < heap->data[i])
    {
        swap(&heap->data[parent_index(i)], &heap->data[i]); 
        i = parent_index(i); 
    }
    heap->size++; 
}

int max_extract(max_heap *heap) {
    if(is_empty(heap)) return INT_MIN; 
    // copy root, to return it later
    int root = heap->data[0]; 
    // copy the last added value into root's place
    heap->data[0] = heap->data[heap->size - 1];  
    int i = 0; 
    heap->size--; 

    while(1) {
        int left = left_child(i); 
        int right = right_child(i); 
        int greater = i; 

        if(left < heap->size && heap->data[left] > heap->data[greater]) {
            greater = left; 
        }
        if(right < heap->size && heap->data[right] > heap->data[greater]) {
            greater = right; 
        }
        if(greater != i) {
            swap(&heap->data[greater], &heap->data[i]); 
            i = greater; 
        }
        else break;
    }
    return root; 
}

void print_heap(max_heap *heap) {
    int i = 0; 
    if(!(is_empty(heap))) {
        while(i <= heap->size - 1) {
            printf("[%d], ", heap->data[i]); 
            i++; 
        }
        printf("\n"); 
    }
    else {
        printf("Heap is empty.\n"); 
    }
}

void free_heap(max_heap *heap) {
    free(heap->data); 
    free(heap); 
}

int main(void)
{
    max_heap *my_heap = create_heap(); 
    int members[] = {10, 64, 23, 43, 32, 51, 5}; 
    int size = sizeof(members) / sizeof(members[0]); 

    for(int i = 0; i < size; i++)
    {
        printf("Attemtping to insert: %d\n", members[i]); 
        insert(my_heap, members[i]); 
    }

    print_heap(my_heap); 

    printf("Sorted Items(deletion): \n"); 
    for(int i = 0; i < size; i++)
    {
        printf("[%d], ", max_extract(my_heap)); 
    }
    printf("\n"); 
    print_heap(my_heap); 

    return 0;
}
