#include "min_heap.h"
#include <stdint.h>
#include <string.h>
// returns parent index of any index
int parent_index(int index) { return (index - 1) / 2; }
// returns the left child index of an index
int left_child_index(int index) { return (2 * index) + 1; }
// returns right child of any index
int right_child_index(int index) { return (2 * index) + 2; }
// returns a bool if heap is empty or not
bool is_heap_empty(min_heap *min_heap) { return (min_heap->size == 0); }

void swap(void *a, void *b, int size) {
  void *tmp;
  if ((tmp = malloc(sizeof(size))) == NULL) {
    return;
  }
  memcpy(tmp, a, size);
  memcpy(a, b, size);
  memcpy(b, tmp, size);
  free(tmp);
}

heap_node *create_new_node(unsigned int vertex, unsigned int weight) {
  heap_node *new_node;
  if ((new_node = (heap_node *)malloc(sizeof(heap_node))) == NULL) {
    return NULL;
  }
  new_node->vertex = vertex;
  new_node->weight = weight;
  return new_node;
}

min_heap *create_new_heap(int capacity) {
  min_heap *new_heap;
  if ((new_heap = (min_heap *)malloc(sizeof(min_heap))) == NULL) {
    return NULL;
  }
  new_heap->cap = capacity;
  new_heap->size = 0;
  if ((new_heap->pos = (int *)malloc(sizeof(int) * new_heap->cap)) == NULL) {
    return NULL;
  }
  if ((new_heap->nodes =
           (heap_node **)malloc(sizeof(heap_node) * new_heap->cap)) == NULL) {
    return NULL;
  }
  return new_heap;
}

void insert_into_heap(min_heap *min_heap, unsigned int vertex,
                      unsigned int weight) {
  if (min_heap->size == min_heap->cap) {
    printf("Heap is full.\n");
  }

  int index = min_heap->size;
  min_heap->nodes[index] = create_new_node(vertex, weight);
  min_heap->pos[vertex] = index;

  while (index && min_heap->nodes[index]->weight <
                      min_heap->nodes[parent_index(index)]->weight) {
    int start = min_heap->nodes[index]->vertex;
    int parent = min_heap->nodes[parent_index(index)]->vertex;
    swap(&min_heap->pos[start], &min_heap->pos[parent], sizeof(int));
    swap(min_heap->nodes[start], min_heap->nodes[parent_index(index)],
         sizeof(heap_node));
    index = parent_index(index);
  }
  min_heap->size++;
}

void heapify(min_heap *min_heap, int index) {
  int smallest = index;
  int left = left_child_index(index);
  int right = right_child_index(index);

  if (left < min_heap->size &&
      min_heap->nodes[left]->weight < min_heap->nodes[smallest]->weight) {
    smallest = left;
  }
  if (right < min_heap->size &&
      min_heap->nodes[right]->weight < min_heap->nodes[smallest]->weight) {
    smallest = right;
  }
  if (smallest != index) {
    min_heap->pos[min_heap->nodes[smallest]->vertex] = index;
    min_heap->pos[min_heap->nodes[index]->vertex] = smallest;

    swap(min_heap->nodes[smallest], min_heap->nodes[index], sizeof(heap_node));
    heapify(min_heap, smallest);
  }
}

int extract_min(min_heap *min_heap) {
  if (is_heap_empty(min_heap)) {
    return INT32_MIN;
  }

  heap_node *root = min_heap->nodes[0];
  heap_node *last = min_heap->nodes[min_heap->size - 1];

  int min_to_return = root->vertex;

  min_heap->pos[root->vertex] = min_heap->size - 1;
  min_heap->pos[last->vertex] = 0;

  swap(min_heap->nodes[0], min_heap->nodes[min_heap->size - 1],
       sizeof(heap_node));
  min_heap->size--;

  heapify(min_heap, 0);

  return min_to_return;
}

void decrease_key(min_heap *min_heap, unsigned int vertex,
                  unsigned int weight) {
  int i = min_heap->pos[vertex];
  min_heap->nodes[i]->weight = weight;

  while (i && min_heap->nodes[i]->weight <
                  min_heap->nodes[parent_index(i)]->weight) {
    int child = min_heap->nodes[i]->vertex;
    int parent = min_heap->nodes[parent_index(i)]->vertex;
    swap(&min_heap->pos[child], &min_heap->pos[parent], sizeof(int));
    swap(min_heap->nodes[i], min_heap->nodes[parent_index(i)],
         sizeof(heap_node));
    i = parent_index(i);
  }
}

bool is_in_heap(min_heap *min_heap, unsigned int vertex) {
  return (min_heap->pos[vertex] < min_heap->size);
}

void free_heap(min_heap *min_heap) {
  if (!(min_heap)) {
    return;
  }
  for (int i = 0; i < min_heap->cap; i++) {
    void *tmp = min_heap->nodes[i];
    free(tmp);
  }
  free(min_heap->nodes);
  free(min_heap->pos);
  free(min_heap);
}

// int main(void) {
//
//     min_heap *my_heap = create_new_heap(CAPACITY);
//
//     insert_into_heap(my_heap, 'D', 100);
//     printf("Inserting key: D with value: 100\n");
//     insert_into_heap(my_heap, 'B', 100);
//     printf("Inserting key: B with value: 100\n");
//     insert_into_heap(my_heap, 'F', 100);
//     printf("Inserting key: F with value: 100\n");
//     insert_into_heap(my_heap, 'E', 100);
//     printf("Inserting key: E with value: 100\n");
//     insert_into_heap(my_heap, 'A', 100);
//     printf("Inserting key: A with value: 100\n");
//     insert_into_heap(my_heap, 'C', 100);
//     printf("Inserting key: C with value: 100\n");
//     insert_into_heap(my_heap, 'G', 100);
//     printf("Inserting key: G with value: 100\n");
//
//     printf("\nNow in the heap...\n");
//     for(int i = 0; i < 7; i++) {
//        printf("Key: %c, Value: %d\n", my_heap->nodes[i]->vertex,
//        my_heap->nodes[i]->weight);
//     }
//
//     printf("\n");
//     printf("pos array:\n");
//     for(int i = (int)'A'; i <= (int)'G'; i++) {
//         printf("%c is at index %d\n", (char)i, my_heap->pos[i % 65]);
//     }
//
//     decrease_key(my_heap, 'A', 0);
//     decrease_key(my_heap, 'D', 3);
//     decrease_key(my_heap, 'B', 1);
//     decrease_key(my_heap, 'C', 2);
//     decrease_key(my_heap, 'F', 5);
//     decrease_key(my_heap, 'G', 6);
//     decrease_key(my_heap, 'E', 4);
//
//     printf("\n");
//     for(int i = 0; i < 7; i++) {
//         printf("Extracted min: %c\n", extract_min(my_heap));
//     }
//
//     free_heap(my_heap);
//     return 0;
// }
//
