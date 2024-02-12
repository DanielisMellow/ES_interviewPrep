#include "list.h"

void insert_new_node(node **head, unsigned int vertex, int weight) {  
    node *new_node; 
    node *head_ref = *head; 
    if((new_node = (node *)malloc(sizeof(node))) == NULL) { return; }

    new_node->vertex = vertex; 
    new_node->weight = weight; 
    new_node->next = NULL; 
    if(!(head_ref)) {
        // can't change the head using head_ref variable, ruins the entire list
        *head = new_node; 
        return; 
    }

    while(head_ref->next != NULL) {
        head_ref = head_ref->next; 
    }
    head_ref->next = new_node; 
}

void delete_node(node **head, unsigned int vertex) {
    if(!(*head)) { return; }
    node *succ = *head; 
    node *prev = NULL; 
    if(succ->vertex == vertex) {
        (*head) = (*head)->next; 
        free(succ); 
        return; 
    }
    while(succ->next != NULL) {
        prev = succ; 
        succ = succ->next;
        if(succ->vertex == vertex) {
            prev->next = succ->next; 
            free(succ);
            return; 
        }
    }
}

node * search_for_node(node *head, unsigned int vertex) {
    if(!(head)) { return NULL; }
    while(head != NULL) {
        if(head->vertex == vertex) {
            return head; 
        }
        head = head->next; 
    }
    return NULL; 
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

void free_list(node *head) {
    while(head != NULL) {
        node *curr = head; 
        head = head->next; 
        free(curr); 
    }
}

// int main(void) {
//
//     // always initialize your head to NULL first
//     node *head = NULL; 
//     insert_new_node(&head, 1, 10); 
//     insert_new_node(&head, 2, 10); 
//     insert_new_node(&head, 3, 10); 
//     insert_new_node(&head, 4, 10); 
//
//     print_list(head, 0); 
//
//     delete_node(&head, 3); 
//
//     print_list(head, 0); 
//
//     printf("Attempting to find 4 in list...\n"); 
//     node *node_found = search_for_node(head, 4); 
//     printf("vertex: %d and weight: %d\n", node_found->vertex, node_found->weight); 
//     print_list(head, 0); 
//     return 0; 
// }
