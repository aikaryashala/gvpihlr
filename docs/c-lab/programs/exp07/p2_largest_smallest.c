/*
 * Experiment 7.2: Find largest and smallest element in an array
 * Idea: start with the first element, then compare it with all the others.
 */

#include <stdio.h>

#define MAX 100

int main(void) {
    int arr[MAX];
    int n, i, largest, smallest;

    printf("Enter the number of elements: ");
    if (scanf("%d", &n) != 1 || n < 1 || n > MAX) {
        printf("Invalid size. Enter a number between 1 and %d.\n", MAX);
        return 0;
    }

    printf("Enter %d elements: ", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    largest = smallest = arr[0];
    for (i = 1; i < n; i++) {
        if (arr[i] > largest) {
            largest = arr[i];
        }
        if (arr[i] < smallest) {
            smallest = arr[i];
        }
    }

    printf("Largest element = %d\n", largest);
    printf("Smallest element = %d\n", smallest);
    return 0;
}
