/*
 * Experiment 11.1: malloc()
 * malloc(size) reserves size bytes on the heap. The memory is NOT initialised.
 */
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int n, i;
    int *arr;
    int sum = 0;

    printf("Enter number of elements: ");
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
        sum += arr[i];
    }

    printf("Elements: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\nSum = %d\n", sum);

    free(arr);
    arr = NULL;
    return 0;
}
