#include <stdio.h>
#include <stdlib.h>
#define TABLE_SIZE 10

typedef struct {
    int key; 
    char value; 
}HashEntry; 

typedef struct {
    HashEntry table[TABLE_SIZE]; 
}HashTable; 

int power(int base, int pow) {
    if(pow == 0) return 1;
    return base * power(base, pow - 1); 
}

HashTable* create_hash_table() {
    HashTable *new_table = malloc(sizeof(HashTable)); 
    if(!(new_table)) {
        printf("Error allocating space to create Hash Table.\n"); 
        return NULL; 
    }
    for(int i = 0; i < TABLE_SIZE; i++) {
        new_table->table[i].key = -1; 
        new_table->table[i].value = '*'; 
    }
    return new_table; 
}

int hash(int key) { return key % TABLE_SIZE; }

void insert(HashTable *hash_table, int key, char value) {
    if(!(hash_table)) {
        printf("No hash table to insert to.\n"); 
        return; 
    }
    int index = hash(key); 
    int org_index = index; 
    int i = 1;  
    // printf("About to enter while loop...\n"); 
    while(hash_table->table[index].key != -1 && hash_table->table[index].key != key) {
        // printf("\tindex: %d, \torg_index: %d\n", index, org_index); 
        index = (org_index + power(i, 2)) % TABLE_SIZE;  
        // printf("\tUpdated index: %d, \torg_index: %d\n", index, org_index); 
        if(index == org_index) {
            printf("Table is full, cannot insert.\n");
            return; 
        }
        i++; 
    }
    hash_table->table[index].key = key; 
    hash_table->table[index].value = value; 
} 

char search_for(HashTable *hash_table, int key) {
    if(!(hash_table)) {
        printf("No hash table to search in...\n"); 
        return '?'; 
    }
    int index = hash(key); 
    int org_index = index; 
    int i = 1;
    while(1) {
        if(i == TABLE_SIZE - 1) {
            break; 
        }
        if(hash_table->table[index].key == key) {
            return hash_table->table[index].value; 
        }
        index = (org_index + power(i, 2)) % TABLE_SIZE; 
        i++; 
    }
    printf("Could not find value for that key in table.\n"); 
    return '?'; 
}

void print_hash_table(HashTable *hash_table) {
    if(!(hash_table)) return; 
    for(int i = 0; i < TABLE_SIZE; i++) {
        printf("[%d] -> %c\n", hash_table->table[i].key, hash_table->table[i].value);
    }
}

int main(void) {

    HashTable *table = create_hash_table(); 
    HashTable *rogue = NULL; 
    
    insert(table, 0, 'A'); 
    insert(table, 10, 'B'); 
    insert(table, 20, 'C'); 
    insert(table, 30, 'D'); 
    insert(table, 40, 'E'); 
    insert(table, 50, 'F'); 
    insert(table, 60, 'G'); 
    print_hash_table(table); 

    printf("Searching for 50...\n"); 
    printf("%c\n", search_for(table, 50)); 
    printf("Searching for 40...\n"); 
    printf("%c\n", search_for(table, 40)); 
    printf("Searching for 20...\n"); 
    printf("%c\n", search_for(table, 20)); 
    printf("Searching for 100...\n"); 
    printf("%c\n", search_for(table, 100)); 

    insert(rogue, 20, 'A'); 
    search_for(rogue, 20); 
    print_hash_table(rogue); 
    free(table); 
    return 0; 
}
