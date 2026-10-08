/*
 * Experiment 11.3: realloc()
 * realloc(ptr, new_size) resizes a block and keeps the old values.
 */
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int n, extra, i;
    int *arr, *temp;

    printf("Enter initial number of elements: ");
    if (scanf("%d", &n) != 1 || n < 1) {
        printf("Invalid size\n");
        return 1;
    }

    arr = malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    printf("Enter %d integers: ", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("How many more elements to add? ");
    if (scanf("%d", &extra) != 1 || extra < 1) {
        printf("Invalid size\n");
        free(arr);
        return 1;
    }

    /* Use a temporary pointer: if realloc fails, arr is still valid */
    temp = realloc(arr, (n + extra) * sizeof(int));
    if (temp == NULL) {
        printf("Reallocation failed\n");
        free(arr);
        return 1;
    }
    arr = temp;

    printf("Enter %d more integers: ", extra);
    for (i = n; i < n + extra; i++) {
        scanf("%d", &arr[i]);
    }
    n += extra;

    printf("Array after realloc (%d elements): ", n);
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    free(arr);
    arr = NULL;
    return 0;
}
