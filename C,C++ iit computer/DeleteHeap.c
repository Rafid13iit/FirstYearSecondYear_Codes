#include <stdio.h>

int n, m, i, val;

void CreateHeap(int A[], int j);
void DeleteHeapElement (int A[], int m, int n);
void DisplayHeapTree (int A[], int j, int n);

int main ()
{

    printf("How many elements in your Tree?\n");
    scanf("%d", &n);

    int A[n];

    printf("Input the Tree elements:\n");

    scanf("%d", &A[1]);

    for (i=2; i<=n; i++){
        scanf("%d", &val);
        A[i] = val;
        CreateHeap(A, i); //MAX Heap
    }

    DisplayHeapTree (A, i, n);

    printf("How many elements do you want to delete?\n");
    scanf("%d", &m);

    DeleteHeapElement(A, m, n);
    n = n - m;

    printf("After deletetion, ");
    DisplayHeapTree (A, i, n);

    return 0;
}

void CreateHeap(int A[], int j) //MAX Heap
{
    int temp;

    while(j != 0){

        if (A[j/2] < A[j]){
            temp = A[j/2];
            A[j/2] = A[j];
            A[j] = temp;
        }

        j = j/2;
    }
}

void DisplayHeapTree (int A[], int j, int n)
{
    printf("The Heap is : ");

    for (j=1; j<=n; j++){
        printf("%d ", A[j]);
    }

    printf("\n");
}

void DeleteHeapElement (int A[], int m, int n)
{
    int temp, j = 0;

    while(j != m){
        temp = A[1];
        A[1] = A[n];
        A[n] = temp;
        n = n - 1;

        j++;

        for (i=n; i>=1; i--){
            CreateHeap(A, i);
        }
    }
}

// 10 20 15 30 25
