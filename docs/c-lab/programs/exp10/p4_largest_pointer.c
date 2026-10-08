/*
 * Experiment 10.4: Find the largest element in an array using pointers.
 */
#include <stdio.h>

int largest(int *arr, int n);

int main(void) {
    int arr[100];
    int n, i;

    printf("Enter number of elements (max 100): ");
    if (scanf("%d", &n) != 1 || n < 1 || n > 100) {
        printf("Invalid size\n");
        return 1;
    }

    printf("Enter %d integers: ", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Largest element = %d\n", largest(arr, n));
    return 0;
}

int largest(int *arr, int n) {
    int max = *arr;          /* start with the first element */
    int *p;

    for (p = arr + 1; p < arr + n; p++) {
        if (*p > max) {
            max = *p;
        }
    }
    return max;
}
