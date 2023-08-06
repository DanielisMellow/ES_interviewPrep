#include <stdio.h>

// Function to swap two elements
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Partition the array using the last element as the pivot
int partition(int arr[], int low, int high)
{
    // Choosing the pivot
    int pivot = arr[high];

    int partitionIndex = low; // Set Partition Index as low initially

    for (int i = low; i < high; i++)
    {
        if (arr[i] < pivot)
        {
            // Swap current element if it is less than pivot
            swap(&arr[partitionIndex], &arr[i]);
            partitionIndex++; // Increment partition Index
        }
    }
    swap(&arr[partitionIndex], &arr[high]);
    return partitionIndex;
}

// The main function that implements QuickSort
// arr[] --> Array to be sorted,
// low --> Starting index,
// high --> Ending index
void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {

        // pi is partitioning index, arr[p]
        // is now at right place
        int pi = partition(arr, low, high);

        // Separately sort elements before
        // partition and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main()
{

    int A[] = {7, 2, 1, 6, 8, 5, 3, 4};
    // int A[] = {2, 0, 2, 1, 1, 0};
    int size = sizeof(A) / sizeof(A[0]);

    for (int i = 0; i < size; i++)
        printf("%d ", A[i]);

    printf("\n");
    quickSort(A, 0, size - 1);

    for (int i = 0; i < size; i++)
        printf("%d ", A[i]);
}