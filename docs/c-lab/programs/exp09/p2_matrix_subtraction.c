/*
 * Experiment 9.2: Matrix subtraction
 * Idea: subtract the elements at the same position: C[i][j] = A[i][j] - B[i][j].
 */

#include <stdio.h>

#define MAX 10

int main(void) {
    int a[MAX][MAX], b[MAX][MAX], c[MAX][MAX];
    int r1, c1, r2, c2, i, j;

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

    if (r1 != r2 || c1 != c2) {
        printf("Subtraction is not possible: both matrices must have the same size.\n");
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
        for (j = 0; j < c1; j++) {
            c[i][j] = a[i][j] - b[i][j];
        }
    }

    printf("Difference of the matrices (first - second):\n");
    for (i = 0; i < r1; i++) {
        for (j = 0; j < c1; j++) {
            printf("%4d", c[i][j]);
        }
        printf("\n");
    }
    return 0;
}
