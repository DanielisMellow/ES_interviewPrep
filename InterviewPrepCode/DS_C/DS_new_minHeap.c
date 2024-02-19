#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define CAP 100

typedef struct node {
  char key;
  int value;
} node;

typedef struct min_heap {
  int size;     // number of heap nodes present
  int cap;      // mem cap of min heap
  int *pos;     // keeps track of positions
  node **nodes; // key value pairs exist here
} min_heap;

// returns parent index for any index
int parent_index(int index) { return (index - 1) / 2; }
// returns left child index for any index
int left_child_index(int index) { return (2 * index) + 1; }
// return right child index for any index
int right_child_index(int index) { return (2 * index) + 2; }
// char to integer helper func
int char_to_idx(char char_to_be_conv) { return ((int)char_to_be_conv % 65); }
// returns boolean if heap is empty or not
bool is_empty(min_heap *min_heap) { return (min_heap->size == 0); }

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

node *create_node(char key, int value) {
  node *new_node;
  if ((new_node = (node *)malloc(sizeof(node))) == NULL) {
    return NULL;
  }
  new_node->key = key;
  new_node->value = value;
  return new_node;
}

min_heap *create_heap() {
  min_heap *new_heap;
  if ((new_heap = (min_heap *)malloc(sizeof(min_heap))) == NULL) {
    return NULL;
  }
  new_heap->cap = CAP;
  new_heap->size = 0;
  if ((new_heap->pos = (int *)malloc(sizeof(int) * new_heap->cap)) == NULL) {
    return NULL;
  }
  if ((new_heap->nodes = (node **)malloc(sizeof(node) * new_heap->cap)) ==
      NULL) {
    return NULL;
  }
  return new_heap;
}

void insert_to_heap(min_heap *min_heap, char key, int value) {
  if (min_heap->size == min_heap->cap) {
    printf("Heap is full.\n");
    return;
  }

  int i = min_heap->size;
  min_heap->nodes[i] = create_node(key, value);
  min_heap->pos[char_to_idx(key)] = i;

  while (i &&
         min_heap->nodes[i]->value < min_heap->nodes[parent_index(i)]->value) {
    int start = ((int)min_heap->nodes[i]->key) % 65;
    int parent = ((int)min_heap->nodes[parent_index(i)]->key) % 65;
    swap(&min_heap->pos[start], &min_heap->pos[parent], sizeof(int));

    swap(min_heap->nodes[i], min_heap->nodes[parent_index(i)], sizeof(node));
    i = parent_index(i);
  }

  min_heap->size++;
}

void heapify(min_heap *min_heap, int index) {
  int smallest = index;
  int left = left_child_index(index);
  int right = right_child_index(index);

  if (left < min_heap->size &&
      min_heap->nodes[left]->value < min_heap->nodes[smallest]->value) {
    smallest = left;
  }
  if (right < min_heap->size &&
      min_heap->nodes[right]->value < min_heap->nodes[smallest]->value) {
    smallest = right;
  }
  if (smallest != index) {
    min_heap->pos[char_to_idx(min_heap->nodes[smallest]->key)] = index;
    min_heap->pos[char_to_idx(min_heap->nodes[index]->key)] = smallest;

    swap(min_heap->nodes[smallest], min_heap->nodes[index], sizeof(node));
    heapify(min_heap, smallest);
  }
}

char extract_min(min_heap *min_heap) {
  if (is_empty(min_heap))
    return '!';

  node *root = min_heap->nodes[0];
  node *last = min_heap->nodes[min_heap->size - 1];

  char min_key = root->key;

  min_heap->pos[char_to_idx(root->key)] = min_heap->size - 1;
  min_heap->pos[char_to_idx(last->key)] = 0;

  swap(min_heap->nodes[0], min_heap->nodes[min_heap->size - 1], sizeof(node));
  min_heap->size--;

  heapify(min_heap, 0);

  return min_key;
}

void decrease_key(min_heap *min_heap, char key, int value) {
  int i = min_heap->pos[char_to_idx(key)];
  min_heap->nodes[i]->value = value;

  while (i &&
         min_heap->nodes[i]->value < min_heap->nodes[parent_index(i)]->value) {
    min_heap->pos[char_to_idx(min_heap->nodes[i]->key)] = parent_index(i);
    min_heap->pos[char_to_idx(min_heap->nodes[parent_index(i)]->key)] = i;
    swap(min_heap->nodes[i], min_heap->nodes[parent_index(i)], sizeof(node));
    i = parent_index(i);
  }
}

void free_heap(min_heap *min_heap) {
  if (!min_heap) {
    return;
  }
  for (int i = 0; i < min_heap->cap; i++) {
    node *tmp = min_heap->nodes[i];
    free(tmp);
  }
  free(min_heap->nodes);
  free(min_heap->pos);
  free(min_heap);
}

int main(void) {

  min_heap *my_heap = create_heap();

  insert_to_heap(my_heap, 'D', 100);
  printf("Inserting key: D with value: 100\n");
  insert_to_heap(my_heap, 'B', 100);
  printf("Inserting key: B with value: 100\n");
  insert_to_heap(my_heap, 'F', 100);
  printf("Inserting key: F with value: 100\n");
  insert_to_heap(my_heap, 'E', 100);
  printf("Inserting key: E with value: 100\n");
  insert_to_heap(my_heap, 'A', 100);
  printf("Inserting key: A with value: 100\n");
  insert_to_heap(my_heap, 'C', 100);
  printf("Inserting key: C with value: 100\n");
  insert_to_heap(my_heap, 'G', 100);
  printf("Inserting key: G with value: 100\n");

  printf("\nNow in the heap...\n");
  for (int i = 0; i < 7; i++) {
    printf("Key: %c, Value: %d\n", my_heap->nodes[i]->key,
           my_heap->nodes[i]->value);
  }

  printf("\n");
  printf("pos array:\n");
  for (int i = (int)'A'; i <= (int)'G'; i++) {
    printf("%c is at index %d\n", (char)i, my_heap->pos[i % 65]);
  }

  decrease_key(my_heap, 'A', 0);
  decrease_key(my_heap, 'D', 3);
  decrease_key(my_heap, 'B', 1);
  decrease_key(my_heap, 'C', 2);
  decrease_key(my_heap, 'F', 5);
  decrease_key(my_heap, 'G', 6);
  decrease_key(my_heap, 'E', 4);

  printf("\n");
  for (int i = 0; i < 7; i++) {
    printf("Extracted min: %c\n", extract_min(my_heap));
  }

  free_heap(my_heap);
  return 0;
}
