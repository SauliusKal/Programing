#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int selection_sort(int *A, int size)
{
    int i,j;
    if(size<=1)return 0;
    for(i=0;i<size-1;i++)
    {
        int ismallest=i;
        for(j=i+1; j<size; j++)
        {
            if(A[ismallest]>A[j])
                ismallest=j;
        }
        int tmp = A[ismallest];
        A[ismallest]=A[i];
        A[i]=tmp;

    }
    printf("done");
}

int main()
{
    int *A;
    int size;
    int i,z;
    double time_spent;
    printf("Selection sort\n\n\n");
    printf("\nEnter the size of the array: ");
    scanf("%d",&size);
    A=(int*)malloc(size * sizeof(int));
    for (i=0;i<size;i++)
    {
        A[i]=rand()%100;
    }

    clock_t tic = clock();
    selection_sort(A,size);
    clock_t toc = clock();
    printf("Elapsed: %f seconds\n", (double)(toc - tic) / CLOCKS_PER_SEC);
//    printf("\n---\n\n---\n\n");
//    for (i=0;i<size;i++)
//    {
//        z=i%20;
//        if(z==0)printf("\n");
//        printf("%d, ",A[i]);
//    }
    free(A);
    return 0;
}
