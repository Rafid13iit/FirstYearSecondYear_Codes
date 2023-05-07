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

    // Apply Gauss elimination
    for (j = 0; j < N-1; j++) {
        for (i = j+1; i < N; i++) {
            float factor = A[i][j]/A[j][j];
            for (k = j; k < N+1; k++) {
                A[i][k] -= factor * A[j][k];
            }
        }
    }

    // Apply back substitution to find the solution
    x[N-1] = A[N-1][N] / A[N-1][N-1];
    for (i = N-2; i >= 0; i--) {
        float sum = A[i][N];
        for (j = i+1; j < N; j++) {
            sum -= A[i][j] * x[j];
        }
        x[i] = sum / A[i][i];
    }

    // Print the solution
    printf("The solution is:\n");
    for (i = 0; i < N; i++) {
        printf("x[%d] = %.2f\n", i, x[i]);
    }

    return 0;
}
