#include "linked_list.h"

void insert(node **head, unsigned int vertex, int weight) {
    node *new_node = malloc(sizeof(node)); 
    if(!(new_node)) return; 
    new_node->vertex = vertex; 
    new_node->weight = weight; 
    new_node->next = NULL;

    // first node case
    if(*head == NULL) {
        *head = new_node; 
        return; 
    }

    // other cases
    node *curr = *head;

    while(curr->next != NULL) {
        curr = curr->next; 
    }
    curr->next = new_node;
}

void print_list(node *head, unsigned int vertex) {
    if(!head) {
        printf("[ ]\n"); 
    }
    else {
        printf("| %d | => ", vertex); 
        while(head != NULL) {
            if (head->next != NULL) {
                printf("[v: %d, w: %d] -> ", head->vertex, head->weight); 
            }
            else {
                printf("[v: %d, w: %d]", head->vertex, head->weight); 

            }
            head = head->next; 
        }
        printf("\n"); 
    }
}

node* search(node *head, unsigned int vertex) {
    while(head != NULL) {
        if(head->vertex == vertex) {
            return head; 
        } 
        head = head->next; 
    }
    //printf("Can't find that vertex\n"); 
    return NULL; 
}

void delete_node(node **head, unsigned int vertex) {
    node *succ = *head; 
    node *prev = NULL; 

    // delete first node
    if(succ != NULL && succ->vertex == vertex) {
        *head = (*head)->next; 
        free(succ); 
        return; 
    }

    while(succ != NULL && succ->next != NULL) {
        prev = succ; 
        succ = succ->next; 
        if(succ->vertex == vertex) {
            node *temp = succ; 
            prev->next = succ->next; 
            free(temp); 
            return; 
        }
    }

    printf("can't find node to delete.\n"); 
}

void free_list(node *head) {
    while(head != NULL) {
        node *curr = head; 
        head = head->next; 
        free(curr); 
    }
}

// int main(void) {
//     node *head = NULL; 
//
//     insert(&head, 10, 5); 
//     insert(&head, 15, 7); 
//     insert(&head, 20, 9); 
//
//     print_list(head, 0); 
//
//     node *found = search(head, 15); 
//     printf("Found %d, weight of %d\n", found->vertex, found->weight); 
//     delete_node(&head, 15); 
//     print_list(head, 0); 
//
//     free_list(head); 
//     return 0; 
// }
