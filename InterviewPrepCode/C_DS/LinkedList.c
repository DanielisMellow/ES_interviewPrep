#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};
typedef struct node node;

// Function To Create a new node
node *createNode(int data)
{
    node *newNode = (node *)malloc(sizeof(node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void append(node **head_ref, int new_data)
{
    node *new_node = createNode(new_data);
    node *last_node = *head_ref;

    // To Deal if it is the first node in the linked list
    if (*head_ref == NULL)
    {
        *head_ref = new_node;
        return;
    }

    while (last_node->next != NULL)
    {
        last_node = last_node->next;
    }
    last_node->next = new_node;
}

void printList(node *head)
{

    while (head != NULL)
    {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

void displayR(node *head)
{
    if (head != NULL)
    {
        displayR(head->next);
        printf("%d -> ", head->data);
    }
}

int add(node *head)
{
    int sum = 0;
    while (head != NULL)
    {
        sum += head->data;
        head = head->next;
    }

    return sum;
}
int count(node *head)
{
    int count = 0;
    while (head != NULL)
    {
        count++;
        head = head->next;
    }

    return count;
}

int max(node *head)
{
    int max = INT_MIN;

    while (head != NULL)
    {
        if (head->data > max)
        {
            max = head->data;
        }

        head = head->next;
    }

    return max;
}

int min(node *head)
{
    int min = INT_MAX;
    while (head != NULL)
    {
        if (head->data < min)
        {
            min = head->data;
        }

        head = head->next;
    }

    return min;
}

node *search(node *head, int key)
{
    while (head != NULL)
    {
        if (key == head->data)
            return head;
        head = head->next;
    }

    return NULL;
}

int main()
{
    node *head = NULL;

    int Arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int size = sizeof(Arr) / sizeof(Arr[0]);

    for (int i = 0; i < size; i++)
    {
        append(&head, Arr[i]);
    }

    printList(head);

    printf("The Sum of Data in LinkedList %d\n", add(head));
    printf("Number of nodes in linked list: %d\n", count(head));
    printf("Max: %d\n", max(head));
    printf("Min: %d\n", min(head));

    node *location = NULL;
    int key = 4;
    printf("Searching for key: %d\n", key);

    location = search(head, key);

    if (location != NULL)
    {
        printf("The Key Value %d is located at memory address: 0x%llx\n", key, (long long)location);
        printList(location);
    }
    else
    {
        printf("Key Value does not exist in linked list\n");
    }

    // Free Memory
    node *temp;
    while (head != NULL)
    {
        temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}