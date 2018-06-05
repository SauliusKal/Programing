#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void inserrtsion_sort(int*A,long size)
{
    long i, j, tmp;
    for(i=i; i<size; i++)
    {
        j=i;
        while(j>0 && (A[j-1]>A[j]))
          {
              tmp=A[j];
              A[j]=A[j-1];
              A[j-1]=tmp;
              j--;
          }
    }
    printf("Done\n");
}

long main()
{
    long *A;
    long size;
    long i,z;
    double time_spent;
    printf("Insertion sort (plz not a milion)\n\n\n");
    printf("\nEnter the size of the array: ");
    scanf("%d",&size);
    A=(int*)malloc(size * sizeof(int));
    for (i=0;i<size;i++)
    {
        A[i]=rand()%1000000;
    }
    clock_t tic = clock();
    inserrtsion_sort(A, size);
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
