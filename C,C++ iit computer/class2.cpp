#include <stdio.h>
#define SIZE 100
int A[SIZE];

int BinarySearch (int A[], int first, int last, int x)
{
    if (last >= first){
        int mid = first + (last - first) / 2;

        if (A[mid] == x){
            return mid;
        }

        else if (A[mid] > x){
            return BinarySearch (A, first, mid - 1, x);
        }

        else {
            return BinarySearch (A, mid + 1, last, x);
        }
    }

    else {
        return -1;
    }
}

int main ()
{
    int n, i, x, index;

    freopen("raf.txt", "r", stdin);

    scanf("%d%d", &n, &x);

    for (i=0; i<n; i++){
        scanf("%d", &A[i]);
    }

    index = BinarySearch (A, 0, n-1, x);

    if (index < 0) {
        printf("Value not found.\n");
    }

    else {
        printf("%d found at index : %d\n", x, index + 1);
    }

    return 0;
}

