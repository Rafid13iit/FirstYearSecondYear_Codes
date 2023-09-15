#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
// #include <sys/wait.h>

#define MAX 100
int A[MAX][MAX], B[MAX][MAX];

void initializeMatrix(int rows, int cols, int matrix[rows][cols]);
void displayMatrix(int rows, int cols, int matrix[rows][cols]);
void multiplyMatrices(int startRow, int endRow, int N, int M, int K, int A[N][M], int B[M][K], int C[N][K]);

int main ()
{
    int a, b, c, d;

    while(1){
        printf("Enter the dimension for matrix A : ");
        scanf("%d%d", &a, &b);
        printf("Enter the dimension for matrix B : ");
        scanf("%d%d", &c, &d);

        if (b == c) break;
        else printf("Can not multiply matrix A with matrix B!\nMatrix A's column is not equal to matrix B's row\nEnter the matrix dimensions again...\n\n");
    }

    printf("Enter matrix A elements :\n");
    initializeMatrix(a, b, A);
    printf("\n");
    printf("Enter matrix B elements :\n");
    initializeMatrix(c, d, B);

    printf("Matrix A is :\n");
    displayMatrix(a, b, A);
    printf("\n");
    printf("Matrix B is :\n");
    displayMatrix(c, d, B);

    




}

void initializeMatrix(int rows, int cols, int matrix[rows][cols]) 
{
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < cols; j++){
            scanf("%d", &matrix[rows][cols]);
        }
    }
}

void displayMatrix(int rows, int cols, int matrix[rows][cols])
{
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < cols; j++){
            printf("%d ", matrix[rows][cols]);
        }
        printf("\n");
    }
}

// Function to perform matrix multiplication for a portion of the matrix
void multiplyMatrices(int startRow, int endRow, int N, int M, int K, int A[N][M], int B[M][K], int C[N][K]) {
    // Implement matrix multiplication logic here
}