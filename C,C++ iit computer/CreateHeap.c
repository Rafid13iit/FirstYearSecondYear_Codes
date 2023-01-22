#include <stdio.h>

void CreateHeap(int A[], int i, int val);
void DeleteHeap (int A[]);
void DisplayHeapTree (int A[], int i, int n);

int main ()
{
    int n, m, i, val;

    printf("How many elements in your Tree?\n");
    scanf("%d", &n);

    int A[n];

    printf("Input the Tree elements:\n");

    scanf("%d", &A[1]);

    for (i=2; i<=n; i++){
        scanf("%d", &val);
        CreateHeap(A, i, val); //MAX Heap
    }

    DisplayHeapTree (A, i, n);

    printf("How many elements you want to delete?\n");
    scanf("%d", &m);

    return 0;
}

void CreateHeap(int A[], int i, int val) //MAX Heap
{
    int temp;

    A[i] = val;

    while(i != 0){

        if (A[i/2] < A[i]){
            temp = A[i/2];
            A[i/2] = A[i];
            A[i] = temp;
        }

        i = i/2;
    }
}

void DisplayHeapTree (int A[], int i, int n)
{
    printf("The Heap is : ");

    for (i=1; i<=n; i++){
        printf("%d ", A[i]);
    }
}
