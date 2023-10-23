#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define CAPACITY 100 // initial capacity

typedef struct {
  int size;
  int *data;
  int capacity;
} min_heap;

min_heap *createHeap() {
  min_heap *heap = (min_heap *)malloc(sizeof(min_heap));
  if (heap == NULL) {
    printf("Unable to allocate mem for heap\n");
    return NULL;
  }

  heap->data = (int *)malloc(sizeof(int) * CAPACITY);
  if (heap->data == NULL) {
    printf("Unable to allocate mem for heap\n");
    return NULL;
  }

  heap->size = 0;
  heap->capacity = CAPACITY;

  return heap;
}

int isEmpty(min_heap *heap) { return heap->size == 0; }

int parentIndx(int i) { return (i - 1) / 2; }

int leftChildInx(int i) { return (2 * i) + 1; }

int rightChildIndx(int i) { return (2 * i) + 2; }

void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

void insert(min_heap *heap, int value) {
  if (heap->size == heap->capacity) {
    // Double the capacity if full
    heap->capacity *= 2;
    heap->data = realloc(heap->data, heap->capacity * sizeof(int));
  }

  int i = heap->size;
  heap->data[i] = value;

  while (i != 0 && heap->data[parentIndx(i)] > heap->data[i]) {
    swap(&heap->data[i], &heap->data[parentIndx(i)]);
    i = parentIndx(i);
  }
  heap->size++;
}
// Method to remove minimum element (or root) form min heap
int extractMin(min_heap *heap) {
  if (isEmpty(heap)) {
    printf("\nHeap is empty!\n");
    return -1; // error code, could also exit or throw exception
  }
  // You can only remove the root node from the heap
  int root = heap->data[0];
  // store the minimum value and remove it from heap decrease size of heap
  heap->data[0] = heap->data[(heap->size - 1)];
  heap->size--;

  int i = 0;
  while (true) {
    int l = leftChildInx(i);
    int r = rightChildIndx(i);
    int smallest = i;

    if (l < heap->size && heap->data[l] < heap->data[smallest])
      smallest = l;
    if (r < heap->size && heap->data[r] < heap->data[smallest])
      smallest = r;

    if (smallest != i) {
      swap(&heap->data[i], &heap->data[smallest]);
      i = smallest;
    } else {
      break;
    }
  }

  return root;
}

void freeHeap(min_heap *heap) {
  free(heap->data);
  free(heap);
}

int main(int argc, char *argv[]) {
  min_heap *heap = createHeap();

  int A[] = {35, 15, 30, 5, 10, 25};

  int size = sizeof(A) / sizeof(A[0]);

  printf("Inserting: ");

  for (int i = 0; i < size; i++) {
    insert(heap, A[i]);
    printf("%d ", A[i]);
  }
  printf("\n\n\n");
  printf("Items after insert: ");

  for (int i = 0; i < heap->size; i++) {
    printf("%d ", heap->data[i]);
  }
  printf("\n\n");

  printf("Deleting from heap: ");
  for (int i = 0; i < size; i++) {
    /*  printf("%d ", heap->data[i]); */

    printf("%d ", extractMin(heap));
  }
  printf("\n");

  freeHeap(heap);

  return EXIT_SUCCESS;
}
