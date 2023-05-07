#include <stdio.h>

#define N 3 // size of matrix

int main() {
    float A[N][N], L[N][N], U[N][N], b[N], x[N], y[N]; // matrices and vectors
    int i, j, k;

    // Read in the matrix and the right-hand side vector
    printf("Enter the elements of the matrix:\n");
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            scanf("%f", &A[i][j]);
        }
    }
    printf("Enter the elements of the right-hand side vector:\n");
    for (i = 0; i < N; i++) {
        scanf("%f", &b[i]);
    }

    // Initialize L and U
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            if (i == j) {
                L[i][j] = 1.0; // diagonal elements of L are 1
            } else {
                L[i][j] = 0.0;
            }
            U[i][j] = A[i][j];
        }
    }

    // Perform Gaussian elimination with partial pivoting
    for (j = 0; j < N-1; j++) {
        for (i = j+1; i < N; i++) {
            float factor = U[i][j]/U[j][j];
            L[i][j] = factor;
            for (k = j; k < N; k++) {
                U[i][k] -= factor * U[j][k];
            }
            b[i] -= factor * b[j];
        }
    }

    // Solve Ly = b by forward substitution
    for (i = 0; i < N; i++) {
        y[i] = b[i];
        for (j = 0; j < i; j++) {
            y[i] -= L[i][j] * y[j];
        }
    }

    // Solve Ux = y by back substitution
    for (i = N-1; i >= 0; i--) {
        x[i] = y[i];
        for (j = i+1; j < N; j++) {
            x[i] -= U[i][j] * x[j];
        }
        x[i] /= U[i][i];
    }

    // Print the solution vector
    printf("The solution vector is:\n");
    for (i = 0; i < N; i++) {
        printf("%.2f ", x[i]);
    }
    printf("\n");

    return 0;
}
