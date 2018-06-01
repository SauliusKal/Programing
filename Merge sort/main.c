#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void Merge(int *A,int *L,int leftCount,int *R,int rightCount)
{
    int i,j,k;
    // i - to mark the index of left sub-array (L)
    // j - to mark the index of right sub-array (R)
    // k - to mark the index of merged sub-array (A)
    i = 0; j = 0; k =0;
    while(i<leftCount && j< rightCount)
    {
        if(L[i]  < R[j]) A[k++] = L[i++];
        else A[k++] = R[j++];
    }
    while(i < leftCount) A[k++] = L[i++];
    while(j < rightCount) A[k++] = R[j++];
}

int MergeSort(int *A,int n)
{
    int mid,i, *L, *R;
    if(n < 2)return 0;
    mid = n/2;
    L = (int*)malloc(mid*sizeof(int));
    R = (int*)malloc((n- mid)*sizeof(int));
    for(i = 0;i<mid;i++)
        L[i] = A[i];
    for(i = mid;i<n;i++)
        R[i-mid] = A[i];
    MergeSort(L,mid);
    MergeSort(R,n-mid);
    Merge(A,L,mid,R,n-mid);
    free(L);
    free(R);
    return 1;
}

int main()
{
    int *A;
    int size;
    int i,z;
    double time_spent;
    printf("Merge sort\n\n\n");
    printf("\nEnter the size of the array: ");
    scanf("%d",&size);
    A=(int*)malloc(size * sizeof(int));
    for (i=0;i<size;i++)
    {
        A[i]=rand()%100000;
    }
    clock_t tic = clock();
    MergeSort(A,size);
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
