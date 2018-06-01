#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int partition (int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = (low - 1),j;

    for (j = low; j <= high- 1; j++)
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
    int i,z;
    double time_spent;
    printf("Quick sort\n\n\n");
    printf("\nEnter the size of the array: ");
    scanf("%d",&size);
    A=(int*)malloc(size * sizeof(int));
    for (i=0;i<size;i++)
    {
        A[i]=rand()%1000000;
    }
    clock_t tic = clock();
    quickSort(A, 0, size-1);
    clock_t toc = clock();
    printf("Elapsed: %f seconds\n", (double)(toc - tic) / CLOCKS_PER_SEC);
    printf("\n---\n\n---\n\n");
    for (i=0;i<size;i++)
    {
        z=i%20;
        if(z==0)printf("\n");
        printf("%d, ",A[i]);
    }
    free(A);
    return 0;
}
