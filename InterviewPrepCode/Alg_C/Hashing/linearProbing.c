#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 10

typedef struct {
  int key;
  int value;
} HashEntry;

typedef struct {
  HashEntry table[TABLE_SIZE];
} HashTable;

HashTable *createHashTable();
int hash(int key);
void insert(HashTable *ht, int key, int value);
int search(HashTable *ht, int key);
void display(HashTable *ht);

int main() {
  HashTable *ht = createHashTable();

  insert(ht, 0, 100);
  insert(ht, 2, 200);
  insert(ht, 3, 300);
  insert(ht, 13, 1300);
  insert(ht, 10, 10000); 

  display(ht);

  printf("Key 0 has value: %d\n", search(ht , 0)); 
  printf("Key 3 has value: %d\n", search(ht, 3));
  printf("Key 13 has value: %d\n", search(ht, 13));
  printf("Key 10 has value: %d\n", search(ht, 10)); 

  free(ht);
  return 0;
}

HashTable *createHashTable() {
  HashTable *ht = (HashTable *)malloc(sizeof(HashTable));
  for (int i = 0; i < TABLE_SIZE; i++) {
    ht->table[i].key = -1; // -1 indicates an empty slot
    ht->table[i].value = -1;
  }
  return ht;
}

int hash(int key) { return key % TABLE_SIZE; }

void insert(HashTable *ht, int key, int value) {
  int index = hash(key);
  int originalIndex = index;

  while (ht->table[index].key != -1 && ht->table[index].key != key) {
    index = (index + 1) % TABLE_SIZE;
    if (index == originalIndex) {
      printf("Hash table is full, cannot insert!\n");
      return;
    }
  }
  ht->table[index].key = key;
  ht->table[index].value = value;
}

int search(HashTable *ht, int key) {
  int index = hash(key);
  int originalIndex = index;

  while (ht->table[index].key != -1) {
    if (ht->table[index].key == key) {
      return ht->table[index].value;
    }
    index = (index + 1) % TABLE_SIZE;
    if (index == originalIndex) {
      break;
    }
  }
  printf("Key %d not found!\n", key);
  return -1;
}

void display(HashTable *ht) {
  for (int i = 0; i < TABLE_SIZE; i++) {
    if (ht->table[i].key != -1) {
      printf("index %d: key = %d, value = %d\n", i, ht->table[i].key,
             ht->table[i].value);
    }
  }
}
