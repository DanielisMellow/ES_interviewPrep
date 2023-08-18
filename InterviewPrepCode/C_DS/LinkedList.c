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

// This function checks if all elements in list1 can be found in list2
int isSubsetGPT(node *list1, node *list2)
{

    // If both linked lists are empty, return true
    if (list1 == NULL && list2 == NULL)
        return 1;

    // Else If one is empty and other is not return
    // false
    if (list1 == NULL ||
        (list1 != NULL && list2 == NULL))
        return 0;

    node *ptr1 = list1;
    node *ptr2 = list2;
    // Iterate through all elements of list1
    while (ptr1 != NULL)
    {
        ptr2 = list2;
        while (ptr2 != NULL)
        {
            if (ptr1->data == ptr2->data)
            {
                break; // Element found in list2
            }
            ptr2 = ptr2->next;
        }

        // If element of list1 is not found in list2
        if (ptr2 == NULL)
        {
            return 0; // list1 is not a subset of list2
        }

        ptr1 = ptr1->next;
    }

    return 1; // list1 is a subset of list2
}

void concatenate(node **head_ref, node *head2)
{
    if (head_ref == NULL)
    {
        *head_ref = head2;
        return;
    }
    if (head2 == NULL)
    {
        return;
    }

    node *lastNode = *head_ref;
    while (lastNode->next != NULL)
    {
        lastNode = lastNode->next;
    }
    lastNode->next = head2;
}

node *mergeSortedList(node *head1, node *head2)
{
    if (head1 == NULL)
        return head2;
    if (head2 == NULL)
        return head1;

    node *mergedHead = NULL;

    // Chose the smaller head node to be the new head
    if (head1->data < head2->data)
    {
        mergedHead = head1;
        head1 = head1->next;
    }
    else
    {
        mergedHead = head2;
        head2 = head2->next;
    }

    node *current = mergedHead;

    while (head1 != NULL && head2 != NULL)
    {
        if (head1->data < head2->data)
        {
            current->next = head1;
            head1 = head1->next;
        }
        else
        {
            current->next = head2;
            head2 = head2->next;
        }

        current = current->next;
    }

    if (head1 != NULL)
    {
        current->next = head1;
    }

    if (head2 != NULL)
    {
        current->next = head2;
    }

    return mergedHead;
}

int main()
{
    node *head = NULL;
    int Arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};

    int size = sizeof(Arr) / sizeof(Arr[0]);
    for (int i = 0; i < size / 2; i++)
    {
        append(&head, Arr[(size - 1 - i)]);
    }
    printList(head);

    // Creating second Linked List
    node *head2 = NULL;
    for (int i = 0; i < size + 1; i++)
        append(&head2, i);

    printList(head2);

    (isSubsetGPT(head, head2)) ? printf("List 1 is Subset of list 2\n") : printf("Lists are not subsets\n");

    node *keyLocation = NULL;
    int key = 4;
    printf("Searching for key: %d\n", key);

    keyLocation = Lsearch(head, key);

    if (keyLocation != NULL)
    {
        printf("The Key Value %d is located at memory address: 0x%llx\n", key, (long long)keyLocation);
        // printList(keyLocation);
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