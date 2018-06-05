#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void Shellsort(int A[],int size)
{
    int gap,i,j,temp;

    for(gap=size/2;gap>0;gap/=2)
        for(i=gap;i<size;i++)
            for(j=i-gap;j>=0&&A[j]>A[j+gap];j-=gap)
    {
        temp=A[j];
        A[j]=A[j+gap];
        A[j+gap]=temp;
    }
    printf("\ndone\n");
}

int main()
{
    int *A;
    int size;
    int i,z;
    double time_spent;
    printf("Shell sort\n\n\n");
    printf("\nEnter the size of the array: ");
    scanf("%d",&size);
    A=(int*)malloc(size * sizeof(int));
    for (i=0;i<size;i++)
    {
        A[i]=rand()%1000000;
    }

    clock_t tic = clock();
    Shellsort(A,size);
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
