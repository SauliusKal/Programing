#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int max (int *a, int n, int i, int j, int k) {
    int m = i;
    if (j < n && a[j] > a[m]) {
        m = j;
    }
    if (k < n && a[k] > a[m]) {
        m = k;
    }
    return m;
}

void downheap (int *a, int n, int i) {
    while (1) {
        int j = max(a, n, i, 2 * i + 1, 2 * i + 2);
        if (j == i) {
            break;
        }
        int t = a[i];
        a[i] = a[j];
        a[j] = t;
        i = j;
    }
}

void heapsort (int *a, int n) {
    int i;
    for (i = (n - 2) / 2; i >= 0; i--) {
        downheap(a, n, i);
    }
    for (i = 0; i < n; i++) {
        int t = a[n - i - 1];
        a[n - i - 1] = a[0];
        a[0] = t;
        downheap(a, n - i - 1, 0);
    }
}

int main()
{
    int *A;
    int size;
    int z,i;
    double time_spent;
    printf("Heap sort\n\n\n");
    printf("\nEnter the size of the array: ");
    scanf("%d",&size);
    A=(int*)malloc(size * sizeof(int));
    for (i=0;i<size;i++)
    {
        A[i]=rand()%1000000;
    }

    clock_t tic = clock();
    heapsort(A, size);
    clock_t toc = clock();
    printf("Elapsed: %f seconds\n", (double)(toc - tic) / CLOCKS_PER_SEC);
    printf("\n---\n\n---\n\n");
//    for (i=0;i<size;i++)
//    {
//        z=i%50;
//        if(z==0)printf("\n");
//        printf("%d, ",A[i]);
//    }
    free(A);
    return 0;
}
