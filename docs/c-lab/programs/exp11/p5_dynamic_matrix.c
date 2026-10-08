/*
 * Experiment 11.5: Dynamically allocate memory for a matrix
 * A matrix is an array of row pointers, and each row is its own int array.
 */
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int rows, cols, i, j;
    int **matrix;

    printf("Enter number of rows and columns: ");
    if (scanf("%d %d", &rows, &cols) != 2 || rows < 1 || cols < 1) {
        printf("Invalid size\n");
        return 1;
    }

    matrix = malloc(rows * sizeof(int *));
    if (matrix == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    for (i = 0; i < rows; i++) {
        matrix[i] = malloc(cols * sizeof(int));
        if (matrix[i] == NULL) {
            printf("Memory allocation failed\n");
            while (i > 0) {          /* free the rows already allocated */
                i--;
                free(matrix[i]);
            }
            free(matrix);
            return 1;
        }
    }

    printf("Enter %d elements:\n", rows * cols);
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    printf("Matrix:\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("%4d", matrix[i][j]);
        }
        printf("\n");
    }

    /* Free each row first, then the array of row pointers */
    for (i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);
    matrix = NULL;
    return 0;
}
