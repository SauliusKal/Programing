#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void radixsort(int *A, int n)
{
    int i,exp=1,m=0,*bucket,*temp;
    bucket=(int*)malloc(sizeof(int)*n);
    temp=(int*)malloc(sizeof(int)*n);
    for(i = 0; i < n; i++)
        {
        if(A[i] > m)
        {
            m = A[i];
        }
}
while((m/exp) > 0) {
    for (i = 0; i < n; i++) {
        bucket[i] = 0;
    }
    for(i = 0; i < n; i++) {
        bucket[(A[i] / exp) % 10]++;
    }
    for(i = 1; i < n; i++) {
        bucket[i] += bucket[i-1];
    }
    for(i = (n - 1); i >= 0; i--) {
        temp[--bucket[(A[i] / exp) % 10]] = A[i];
    }
    for(i = 0; i < n; i++) {
        A[i] = temp[i];
    }
    exp *= 10;
    }
    free(bucket);
    free(temp);
}

int main()
{
    int *A;
    int size;
    int i,z;
    double time_spent;
    printf("Radix sort\n\n\n");
    printf("\nEnter the size of the array: ");
    scanf("%d",&size);
    A=(int*)malloc(size*sizeof(int));
    for (i=0;i<size;i++)
    {
        A[i]=rand()%1000000;
    }
    clock_t tic = clock();
    radixsort(A,size);
    clock_t toc = clock();
    printf("Elapsed: %f seconds\n", (double)(toc - tic) / CLOCKS_PER_SEC);
    printf("\n---\n\n---\n\n");
//    for (i=0;i<size;i++)
//    {
//        z=i%40;
//        if(z==0)printf("\n");
//        printf("%d, ",A[i]);
//    }
    free(A);
    return 0;
}
