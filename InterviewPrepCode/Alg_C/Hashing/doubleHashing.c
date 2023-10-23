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
int hash1(int key);
int hash2(int key);
void insert(HashTable *ht, int key, int value);
int search(HashTable *ht, int key);
void display(HashTable *ht);

int main() {
  HashTable *ht = createHashTable();

  insert(ht, 5, 100);
  insert(ht, 25, 200);
  insert(ht, 15, 200);
  insert(ht, 35, 300);
  insert(ht, 95, 1300);

  display(ht);

  printf("Key 5 has value: %d\n", search(ht, 5));
  printf("Key 3 has value: %d\n", search(ht, 3));

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

int hash1(int key) { return key % TABLE_SIZE; }

int hash2(int key) { return (7 - (key % 7)); }

void insert(HashTable *ht, int key, int value) {
  int index = hash1(key);
  int originalIndex = index;
  int i = 1;

  while (ht->table[index].key != -1 && ht->table[index].key != key) {
    index = (index + (i * hash2(key))) % TABLE_SIZE;
    if (index == originalIndex) {
      printf("Hash table is full, cannot insert!\n");
      return;
    }
    i++;
  }
  ht->table[index].key = key;
  ht->table[index].value = value;
}

int search(HashTable *ht, int key) {
  int index = hash1(key);
  int originalIndex = index;
  int i = 1;
  while (ht->table[index].key != -1) {
    if (ht->table[index].key == key) {
      return ht->table[index].value;
    }

    index = (index + (i * hash2(key))) % TABLE_SIZE;
    if (index == originalIndex) {
      break;
    }
    i++;
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
