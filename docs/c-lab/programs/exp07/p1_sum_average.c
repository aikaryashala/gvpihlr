/*
 * Experiment 7.1: Find sum and average of array elements
 */

#include <stdio.h>

#define MAX 100

int main(void) {
    int arr[MAX];
    int n, i, sum = 0;

    printf("Enter the number of elements: ");
    if (scanf("%d", &n) != 1 || n < 1 || n > MAX) {
        printf("Invalid size. Enter a number between 1 and %d.\n", MAX);
        return 0;
    }

    printf("Enter %d elements: ", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        sum += arr[i];
    }

    printf("Sum = %d\n", sum);
    printf("Average = %.2f\n", (float)sum / n);
    return 0;
}
