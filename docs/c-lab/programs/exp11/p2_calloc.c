/*
 * Experiment 11.2: calloc()
 * calloc(count, size) reserves memory and sets every byte to zero.
 */
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int n, i;
    int *arr;

    printf("Enter number of elements: ");
    if (scanf("%d", &n) != 1 || n < 1) {
        printf("Invalid size\n");
        return 1;
    }

    arr = calloc(n, sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    printf("Values right after calloc: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);       /* all zeros */
    }
    printf("\n");

    for (i = 0; i < n; i++) {
        arr[i] = (i + 1) * 5;
    }
    printf("Values after filling:      ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    free(arr);
    arr = NULL;
    return 0;
}
