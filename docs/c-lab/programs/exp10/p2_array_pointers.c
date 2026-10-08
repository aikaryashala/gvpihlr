/*
 * Experiment 10.2: Access one-dimensional arrays using pointers.
 * arr[i] and *(arr + i) mean the same thing.
 */
#include <stdio.h>

int main(void) {
    int arr[100];
    int n, i;
    int *p = arr;

    printf("Enter number of elements (max 100): ");
    if (scanf("%d", &n) != 1 || n < 1 || n > 100) {
        printf("Invalid size\n");
        return 1;
    }

    printf("Enter %d integers: ", n);
    for (i = 0; i < n; i++) {
        scanf("%d", p + i);          /* p + i is the address of arr[i] */
    }

    printf("Elements using pointer notation *(p + i): ");
    for (i = 0; i < n; i++) {
        printf("%d ", *(p + i));
    }
    printf("\n");

    printf("Elements by moving the pointer p++:      ");
    for (p = arr; p < arr + n; p++) {
        printf("%d ", *p);
    }
    printf("\n");

    return 0;
}
