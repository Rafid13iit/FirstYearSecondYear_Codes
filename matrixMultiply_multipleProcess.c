#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
// #include <sys/wait.h>

#define MAX 100
int A[MAX][MAX], B[MAX][MAX], result[MAX][MAX];

void initializeMatrix(int rows, int cols, int matrix[rows][cols]);
void displayMatrix(int rows, int cols, int matrix[rows][cols]);
void multiplyMatrixPortion(int startCol, int a, int d);

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
    printf("Enter matrix B elements :\n");
    initializeMatrix(c, d, B);

    printf("Matrix A is :\n");
    displayMatrix(a, b, A);
    printf("Matrix B is :\n");
    displayMatrix(c, d, B);

    pid_t child_pids[MAX];

    for (int i = 0; i < a; i++){
        pid_t child_pid = fork();

        if (child_pid == 0){
            // Child process
            multiplyMatrixPortion(i, a, d);
            exit(0);
        }
        else if (child_pid > 0) {
            // Parent process
            child_pids[i] = child_pid;
        }
        else {
            perror("Fork failed");
            exit(1);
        }
    }

    // Parent process waits for all child processes to finish
    for (int i = 0; i < a; i++) {
        waitpid(child_pids[i], NULL, 0);
    }


    printf("Result matrix after Multiplication is :\n");
    displayMatrix(a, d, result);

    return 0;
}

// Function to initialize matrix
void initializeMatrix(int rows, int cols, int matrix[rows][cols]) 
{
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < cols; j++){
            scanf("%d", &matrix[rows][cols]);
        }
    }
    printf("\n");
}

// Function to display matrix
void displayMatrix(int rows, int cols, int matrix[rows][cols])
{
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < cols; j++){
            printf("%d ", matrix[rows][cols]);
        }
        printf("\n");
    }
    printf("\n");
}

// Function to perform matrix multiplication for a portion of the matrix
void multiplyMatrixPortion(int startCol, int a, int d) {
    for (int j = 0; j < a; j++){
        result[startCol][j] = 0;
        for (int k = 0; k < d; k++){
            result[startCol][j] += A[startCol][k] * B[k][j];
        }
    }
}