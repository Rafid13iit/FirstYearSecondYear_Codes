#include <stdio.h>

void QuickSort (int A[], int first, int last);
int partition (int A[], int first, int last);

int main ()
{
	int n, i;

	printf("Enter element numbers : ");
	scanf("%d", &n);

	int A[n];

	printf("Enter the array below :\n");
	for (i=1; i<=n; i++){
		scanf("%d", &A[i]);
	}

	int first = 1, last = n;

	QuickSort (A, first, last);

	printf("The quick sorted array is :\n");
	for (i=1; i<=n; i++){
        printf("%d ", A[i]);
    }

    return 0;
}

void QuickSort (int A[], int first, int last)
{
	if (first < last){
		int q = partition (A, first, last);
		QuickSort (A, first, q-1);
		QuickSort (A, q+1, last);
	}
}

int partition (int A[], int first, int last)
{
	int j, temp = 0, pivot = A[last];
	int i = first - 1;

	for (j=first; j<=last-1; j++){
		if (A[j] <= pivot){
			i++;
			temp = A[i];
			A[i] = A[j];
			A[j] = temp;
		}
	}

	temp = A[i+1];
	A[i+1] = A[last];
	A[last] = temp;

	return i + 1;
}
