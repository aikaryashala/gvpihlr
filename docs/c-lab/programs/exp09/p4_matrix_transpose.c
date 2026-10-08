/*
 * Experiment 9.4: Matrix transpose
 * Idea: rows become columns: T[j][i] = A[i][j].
 */

#include <stdio.h>

#define MAX 10

int main(void) {
    int a[MAX][MAX], t[MAX][MAX];
    int rows, cols, i, j;

    printf("Enter rows and columns of the matrix: ");
    if (scanf("%d %d", &rows, &cols) != 2 || rows < 1 || rows > MAX || cols < 1 || cols > MAX) {
        printf("Invalid size. Rows and columns must be between 1 and %d.\n", MAX);
        return 0;
    }

    printf("Enter the elements of the matrix:\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            t[j][i] = a[i][j];
        }
    }

    printf("Transpose of the matrix (%d x %d):\n", cols, rows);
    for (i = 0; i < cols; i++) {
        for (j = 0; j < rows; j++) {
            printf("%4d", t[i][j]);
        }
        printf("\n");
    }
    return 0;
}
