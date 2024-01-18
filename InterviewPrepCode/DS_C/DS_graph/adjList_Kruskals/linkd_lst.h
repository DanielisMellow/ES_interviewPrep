#ifndef _LL_H
#define _LL_H
#include <stdio.h>
#include <stdlib.h>


typedef struct node {
   unsigned int vertex; 
   int weight; 
   struct node *next; 
}node; 
// insert node with weight
void insert(node **head, unsigned int vertex, int weight); 
// print list
void print_list(node *head, unsigned int vertex); 
// search for node
node* search(node *head, unsigned int vertex); 
// delete node
void delete_node(node **head, unsigned int vertex); 
// free list
void free_list(node *head); 
// returns nodes in list
int count(node *head); 
#endif
