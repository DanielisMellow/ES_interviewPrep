#ifndef LIST_H
#define LIST_H
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

typedef struct node {
    unsigned int vertex; 
    int weight; 
    struct node *next;
}node; 

// inserts node into linked list
void insert_new_node(node **head, unsigned int vertex, int weight); 
// searches for node and returns it
node * search_for_node(node *head, unsigned int vertex); 
// deletes node from the list
void delete_node(node **head, unsigned int vertex); 
// prints list
void print_list(node *head, unsigned int vertex); 
// frees mem used by the list
void free_list(node *head); 





#endif
