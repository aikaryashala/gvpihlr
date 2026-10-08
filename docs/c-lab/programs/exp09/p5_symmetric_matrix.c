/*
 * Experiment 9.5: Check whether a matrix is symmetric
 * A matrix is symmetric if it is square and A[i][j] == A[j][i] for all i, j.
 */

#include <stdio.h>

#define MAX 10

int main(void) {
    int a[MAX][MAX];
    int rows, cols, i, j, symmetric = 1;

    printf("Enter rows and columns of the matrix: ");
    if (scanf("%d %d", &rows, &cols) != 2 || rows < 1 || rows > MAX || cols < 1 || cols > MAX) {
        printf("Invalid size. Rows and columns must be between 1 and %d.\n", MAX);
        return 0;
    }

    if (rows != cols) {
        printf("A non-square matrix cannot be symmetric. The matrix must be square.\n");
        return 0;
    }

    printf("Enter the elements of the matrix:\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    for (i = 0; i < rows && symmetric; i++) {
        for (j = 0; j < i; j++) {
            if (a[i][j] != a[j][i]) {
                symmetric = 0;
                break;
            }
        }
    }

    printf("The matrix:\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("%4d", a[i][j]);
        }
        printf("\n");
    }
    if (symmetric) {
        printf("The matrix is symmetric.\n");
    } else {
        printf("The matrix is not symmetric.\n");
    }
    return 0;
}
