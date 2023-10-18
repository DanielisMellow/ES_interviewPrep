#include "chain.h"
#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 10

typedef struct HashTable {
  node *table[TABLE_SIZE];
} HashTable;

HashTable *createHashtable() {
  HashTable *newTable = (HashTable *)malloc(sizeof(HashTable));

  if (newTable == NULL) {
    return NULL;
  }

  for (int i = 0; i < TABLE_SIZE; i++) {
    newTable->table[i] = NULL;
  }

  return newTable;
}

unsigned int hashFunction(unsigned int key) { return key % TABLE_SIZE; }

void insert(HashTable *ht, unsigned int key, const char *value) {
  unsigned int index = hashFunction(key);
  sortedInsert(&ht->table[index], key, value);
}

char *searchTable(HashTable *ht, unsigned int key) {
  unsigned int index = hashFunction(key);
  node *temp = search(ht->table[index], key);
  return temp->value;
}

void deleteKey(HashTable *ht, unsigned int key) {
  unsigned int index = hashFunction(key);
  deleteNode(&ht->table[index], key);
}

void printHashTable(HashTable *ht) {

  if (!ht) {
    printf("Hash table is NULL.\n");
    return;
  }
  for (int i = 0; i < TABLE_SIZE; i++) {
    printList(ht->table[i]);
  }
}

void freeHashTable(HashTable *ht) {
  for (int i = 0; i < TABLE_SIZE; i++) {
    freeList(ht->table[i]);
  }

  free(ht);
}

int main(int argc, char *argv[]) {
  HashTable *table = createHashtable();

  char ch = 'A';
  char str[2] = {ch, '\0'};

  for (int i = 0; i < 26; i += 2) {
    sprintf(str, "%c", ch);
    insert(table, i, str);
    ch++;
  }

  printHashTable(table);

  freeHashTable(table);

  return EXIT_SUCCESS;
}
