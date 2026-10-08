/*
 * Experiment 9.3: Matrix multiplication
 * Idea: C[i][j] = sum of A[i][k] * B[k][j]. Needs columns of A == rows of B.
 */

#include <stdio.h>

#define MAX 10

int main(void) {
    int a[MAX][MAX], b[MAX][MAX], c[MAX][MAX];
    int r1, c1, r2, c2, i, j, k;

    printf("Enter rows and columns of the first matrix: ");
    if (scanf("%d %d", &r1, &c1) != 2 || r1 < 1 || r1 > MAX || c1 < 1 || c1 > MAX) {
        printf("Invalid size. Rows and columns must be between 1 and %d.\n", MAX);
        return 0;
    }
    printf("Enter rows and columns of the second matrix: ");
    if (scanf("%d %d", &r2, &c2) != 2 || r2 < 1 || r2 > MAX || c2 < 1 || c2 > MAX) {
        printf("Invalid size. Rows and columns must be between 1 and %d.\n", MAX);
        return 0;
    }

    if (c1 != r2) {
        printf("Multiplication is not possible: columns of the first matrix "
               "must equal rows of the second.\n");
        return 0;
    }

    printf("Enter the elements of the first matrix:\n");
    for (i = 0; i < r1; i++) {
        for (j = 0; j < c1; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    printf("Enter the elements of the second matrix:\n");
    for (i = 0; i < r2; i++) {
        for (j = 0; j < c2; j++) {
            scanf("%d", &b[i][j]);
        }
    }

    for (i = 0; i < r1; i++) {
        for (j = 0; j < c2; j++) {
            c[i][j] = 0;
            for (k = 0; k < c1; k++) {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }

    printf("Product of the matrices (%d x %d):\n", r1, c2);
    for (i = 0; i < r1; i++) {
        for (j = 0; j < c2; j++) {
            printf("%4d", c[i][j]);
        }
        printf("\n");
    }
    return 0;
}
