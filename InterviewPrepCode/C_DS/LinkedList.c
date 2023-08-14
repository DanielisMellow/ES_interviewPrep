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

node *Lsearch(node *head, int key)
{
    while (head != NULL)
    {
        if (key == head->data)
            return head;
        head = head->next;
    }

    return NULL;
}

void insert(node **head_ref, int index, int value)
{
    // Check if index is Valid
    if (index < 0)
    {
        printf("Index: %d is invalid\n", index);
        return;
    }

    node *new_node = createNode(value);
    node *current = *head_ref;

    // If index is 0, inset at head_ref
    if (index == 0)
    {
        new_node->next = current;
        *head_ref = new_node;
        return;
    }

    // Move Current pointer to index
    for (int i = 0; i < (index - 1) && current != NULL; i++)
    {
        current = current->next;
    }

    if (current != NULL)
    {
        new_node->next = current->next;
        current->next = new_node;
    }
    else
    {
        // If the index is greater than the number of elements, the node is added to the end
        printf("Index %d exceeds the length of the list, appending at the end.\n", index);
        append(head_ref, value);
    }
}

void deleteNode(node **head_ref, int key)
{
    node *temp = *head_ref;
    node *prev = NULL;

    // Deleting First Node
    if (temp != NULL && temp->data == key)
    {
        *head_ref = temp->next;
        free(temp);
        return;
    }

    while (temp != NULL && temp->data != key)
    {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("Key not found in linked list\n");
        return;
    }

    prev->next = temp->next;
    free(temp);
}

/// Extra Functionality
void reverse(node **head_ref)
{
    node *prev = NULL;
    node *current = *head_ref;
    node *next = NULL;

    while (current != NULL)
    {
        // Save the next node
        next = current->next;

        // Reverse the current nodes link
        current->next = prev;

        // Slide position pointers forward
        prev = current;
        current = next;
    }
    // Change head pointer to that last node in the list
    *head_ref = prev;
}

node *search(node **head_ref, int key)
{
    node *temp = *head_ref;
    node *prev = NULL;

    while (temp != NULL)
    {
        if (key == temp->data)
        {
            prev->next = temp->next;
            temp->next = *head_ref;
            *head_ref = temp;
            return *head_ref;
        }

        prev = temp;
        temp = temp->next;
    }
    return NULL;
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

int main()
{
    node *head = NULL;

    int Arr[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    int size = sizeof(Arr) / sizeof(Arr[0]);

    for (int i = 0; i < size; i++)
    {
        append(&head, Arr[i]);
    }

    printList(head);

    node *keyLocation = NULL;
    int key = 4;
    printf("Searching for key: %d\n", key);

    keyLocation = Lsearch(head, key);

    if (keyLocation != NULL)
    {
        printf("The Key Value %d is located at memory address: 0x%llx\n", key, (long long)keyLocation);
        printList(keyLocation);
    }
    else
    {
        printf("Key Value does not exist in linked list\n");
    }

    insert(&head, 3, 420);

    printList(head);

    // Free Memory
    while (head != NULL)
    {
        node *temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}