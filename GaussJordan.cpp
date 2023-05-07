#include <stdio.h>

#define N 3 // number of equations and unknowns

int main() {
    float A[N][N+1], x[N]; // A is the augmented matrix, x is the solution vector
    int i, j, k;

    // Read in the coefficients of the linear equations
    printf("Enter the coefficients of the linear equations:\n");
    for (i = 0; i < N; i++) {
        for (j = 0; j < N+1; j++) {
            scanf("%f", &A[i][j]);
        }
    }

    // Apply Gauss-Jordan elimination
    for (i = 0; i < N; i++) {
        float pivot = A[i][i];
        for (j = 0; j < N+1; j++) {
            A[i][j] /= pivot;
        }
        for (j = 0; j < N; j++) {
            if (i != j) {
                float factor = A[j][i];
                for (k = 0; k < N+1; k++) {
                    A[j][k] -= factor * A[i][k];
                }
            }
        }
    }

    // Extract the solution from the augmented matrix
    for (i = 0; i < N; i++) {
        x[i] = A[i][N];
    }

    // Print the solution
    printf("The solution is:\n");
    for (i = 0; i < N; i++) {
        printf("x[%d] = %.2f\n", i, x[i]);
    }

    return 0;
}