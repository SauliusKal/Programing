#include <stdio.h>
#include <stdlib.h>
#include <time.h>


    // A utility function to swap two elements
void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int partition (int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high- 1; j++)
    {
        if (arr[j] <= pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main()
{
    int *A;
    int size;
    int i;
    double time_spent;
    printf("\nEnter the size of the array: ");
    scanf("%d",&size);
    A=(int*)malloc(size * sizeof(int));
    for (i=0;i<size;i++)
    {
        A[i]=rand()%100000;
    }
    clock_t tic = clock();
    quickSort(A, 0, size-1);
    clock_t toc = clock();
    printf("Elapsed: %f seconds\n", (double)(toc - tic) / CLOCKS_PER_SEC);




    return 0;
}
