/*
 * Experiment 7.5: Remove duplicate elements in an array
 * Idea: keep an element only if it has not already appeared earlier.
 */

#include <stdio.h>

#define MAX 100

int main(void) {
    int arr[MAX], unique[MAX];
    int n, i, j, count = 0, found;

    printf("Enter the number of elements: ");
    if (scanf("%d", &n) != 1 || n < 1 || n > MAX) {
        printf("Invalid size. Enter a number between 1 and %d.\n", MAX);
        return 0;
    }

    printf("Enter %d elements: ", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    for (i = 0; i < n; i++) {
        found = 0;
        for (j = 0; j < count; j++) {
            if (unique[j] == arr[i]) {
                found = 1;
                break;
            }
        }
        if (!found) {
            unique[count++] = arr[i];
        }
    }

    printf("Array after removing duplicates: ");
    for (i = 0; i < count; i++) {
        printf("%d ", unique[i]);
    }
    printf("\n");
    return 0;
}
