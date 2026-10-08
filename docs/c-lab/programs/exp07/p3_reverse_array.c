/*
 * Experiment 7.3: Reverse an array
 * Idea: swap the first and last elements, then the second and second-last, and so on.
 */

#include <stdio.h>

#define MAX 100

int main(void) {
    int arr[MAX];
    int n, i, temp;

    printf("Enter the number of elements: ");
    if (scanf("%d", &n) != 1 || n < 1 || n > MAX) {
        printf("Invalid size. Enter a number between 1 and %d.\n", MAX);
        return 0;
    }

    printf("Enter %d elements: ", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    for (i = 0; i < n / 2; i++) {
        temp = arr[i];
        arr[i] = arr[n - 1 - i];
        arr[n - 1 - i] = temp;
    }

    printf("Reversed array: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}
